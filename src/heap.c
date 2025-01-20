#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1024

typedef struct Node {
    char val;
    int freq;
    struct Node *left, *right, *parent;
} Node;

typedef struct HEAP {
    int size, capacity;
    Node **nodes;
} HEAP;

HEAP *create_heap(int capacity) {
    if (capacity > HEAP_SIZE) {
        printf("Capacity cannot exceed %d\n", HEAP_SIZE);
        return NULL;
    }
    HEAP *h = (HEAP *)malloc(sizeof(HEAP));
    h->capacity = capacity;
    h->size = 0;
    h->nodes = (Node **)malloc(sizeof(Node *) * capacity);
    return h;
}

Node *create_node(char val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->freq = 0;
    n->left = n->right = n->parent = NULL;
    return n;
}

int found(HEAP *h, char value) {
    for (int i = 0; i < h->size; i++) {
        if (h->nodes[i]->val == value) return i;
    }
    return -1;
}

void swap(HEAP *h, int a, int b) {
    Node *temp = h->nodes[a];
    h->nodes[a] = h->nodes[b];
    h->nodes[b] = temp;
}

void heapify_up(HEAP *h, int idx) {
    int parent = (idx - 1) / 2;
    while (idx > 0 && h->nodes[idx]->freq < h->nodes[parent]->freq) {
        swap(h, idx, parent);
        idx = parent;
        parent = (idx - 1) / 2;
    }
}

void heapify(HEAP *h, int idx) {
    int small = idx, left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < h->size && h->nodes[left]->freq < h->nodes[small]->freq) small = left;
    if (right < h->size && h->nodes[right]->freq < h->nodes[small]->freq) small = right;
    if (small != idx) {
        swap(h, idx, small);
        heapify(h, small);
    }
}

int insert(HEAP *h, char val) {
    if (h->size == h->capacity) return 0;
    Node *n = create_node(val);
    n->freq = 1;
    h->nodes[h->size++] = n;
    heapify_up(h, h->size - 1);
    return 1;
}


Node *extract_min(HEAP *h)
{
    if(h->size <= 0)
    {
        printf("No nodes in heao\n");
        return NULL;
    }
    Node *min = h->nodes[0];
    h->nodes[0] = h->nodes[h->size -1];
    h->size--;
    heapify(h, 0);

    return min;
}
void build_min_heap(HEAP *h, char *vals) {
    for (int i = 0; vals[i] != '\0'; i++) {
        int index = found(h, vals[i]);
        if (index != -1) {
            h->nodes[index]->freq++;
            heapify(h, index);
        } else {
            if (!insert(h, vals[i])) {
                printf("Heap is full; cannot process '%c'.\n", vals[i]);
            }
        }
    }
}

Node *build_huffman_tree(HEAP *h) {
    while (h->size > 1) {
        // Extract the two smallest nodes
        Node *left = extract_min(h);
        Node *right = extract_min(h);

        // Create a new internal node
        Node *new_node = create_node('\0'); // '\0' for non-leaf internal nodes
        new_node->freq = left->freq + right->freq;
        new_node->left = left;
        new_node->right = right;

        // Insert the new node back into the heap
        h->nodes[h->size++] = new_node;
        heapify_up(h, h->size - 1);
    }

    // The remaining node in the heap is the root of the Huffman tree
    return extract_min(h);
}

int main(void)
{
    HEAP *h = create_heap(1000);

    char vals[] = "aacbbs";
    build_min_heap(h, vals);

    for(int i = 0; i< h->size; i++)
    {
        printf("{%c:%d}\n", h->nodes[i]->val,h->nodes[i]->freq );
    }

    return 0;
}
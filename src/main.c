#include "../include/heap.h"
#include <stdio.h>


int main(void) {
    char vals[] = "abbcdd";
    HEAP *h = create_heap(100);
    build_min_heap(h, vals);
    for (int i = 0; i < h->size; i++) {
        printf("{%c:%d}\n", h->nodes[i]->val, h->nodes[i]->freq);
    }
    return 0;
}

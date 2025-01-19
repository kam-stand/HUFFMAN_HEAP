/**
 * @file heap.h
 * @author Kam Hassan
 * @brief 
 * @version 0.1
 * @date 2025-01-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef HEAP_H
#define HEAP_H

typedef struct Node Node;

struct Node
{
    char val;
    Node *parent;
    Node *left;
    Node *right;
    int freq;
};

typedef struct HEAP HEAP;

struct HEAP
{
    Node **nodes;
    int capacity;
    int size;

};


/**
 * @brief return index if char found in heap -1 else
 * 
 * @param h 
 * @param val 
 * @return int 
 */
int found(HEAP *h, char val);


/**
 * @brief Create a heap object
 * 
 * @param capacity 
 * @return HEAP* 
 */
HEAP *create_heap(int capacity);


/**
 * @brief Create a node object
 * 
 * @param val 
 * @return Node* 
 */
Node *create_node(char val);


/**
 * @brief Swap elements in the heap to maintain min property
 * 
 * @param h 
 * @param a 
 * @param b 
 */
void swap(HEAP *h, int a , int b);


/**
 * @brief Inserts into the heap
 * 
 * @param h 
 * @param val 
 */
void insert(HEAP *h, char val);



/**
 * @brief Maintain the min heap propery after insertion
 * 
 * @param h 
 * @param idx 
 */
void heapify_up(HEAP *h, int idx);


/**
 * @brief Main min heap from top down
 * 
 * @param h 
 * @param idx 
 */
void heapify(HEAP *h, int idx);


/**
 * @brief Build min heap from input
 * 
 * @param h 
 * @param vals 
 */
void build_min_heap(HEAP *h, char *vals);

#endif
/**
 * @file main.c
 * @author kam-stand
 * @brief a driver file to given an example of how the library works
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "../include/heap.h"
#include <stdio.h>
int main(void) {
    char input[] = "aaaaabbbbbbbbbccccccccccccdddddddddddddeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffff";
    HEAP *h = create_heap(100);
    build_min_heap(h, input);

    // Build Huffman tree
    Node *root = build_huffman_tree(h);

    // Generate Huffman codes
    char codes[256][256] = {0}; // Array to store codes for each character
    char current_code[256];     // Temporary buffer for the current code
    generate_codes(root, current_code, 0, codes);

    // Print the Huffman codes
    printf("Huffman Codes:\n");
    for (int i = 0; i < 256; i++) {
        if (codes[i][0] != '\0') { // Print only non-empty codes
            printf("%c: %s\n", (char)i, codes[i]);
        }
    }

    return 0;
}

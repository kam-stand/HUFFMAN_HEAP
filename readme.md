# Huffman Coding using Min Heap

This repository contains an implementation of Huffman Coding using a Min Heap. Huffman Coding is a popular algorithm used for lossless data compression. The Min Heap is utilized to efficiently build the Huffman Tree, which is essential for encoding and decoding processes.

## Features

- Implementation of Min Heap data structure
- Construction of Huffman Tree using Min Heap
- Encoding and decoding of data using Huffman Coding

## Files

- `heap.c` - Implementation of Min Heap operations
- `huffman.c` - Implementation of Huffman Coding algorithm
- `main.c` - Example usage of Huffman Coding

## How to Run

1. Clone the repository:
   ```sh
   git clone <repository-url>
   ```
2. Navigate to the directory:
   ```sh
   cd /home/kamhassan/Desktop/Computer_Science/C-PROGRAMMING/DATA_STRUCTURES/HEAP
   ```
3. Compile the code:
   ```sh
   gcc -o huffman main.c heap.c huffman.c
   ```
4. Run the executable:
   ```sh
   ./huffman
   ```

## License

This project is licensed under the MIT License.

## Acknowledgements

- This implementation is based on the principles of Huffman Coding and Min Heap data structures.

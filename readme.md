# Huffman Coding using Min Heap

This repository contains an implementation of Huffman Coding using a Min Heap. Huffman Coding is a popular algorithm used for lossless data compression. The Min Heap is utilized to efficiently build the Huffman Tree, which is essential for encoding and decoding processes.

## Features

- Implementation of Min Heap data structure
- Construction of Huffman Tree using Min Heap
- `Encoding` and `decoding` of data using Huffman Coding

## Files

- `heap.c` - Implementation of Min Heap operations
- `heap.h` - Function prototypes
- `main.c` - Example usage of Huffman Coding
- `run.sh` - Script to compile and run the program

## To Implement

- [x] Emit Huffman tree
- [x] Proper `main.c` file to run tests
- [x] Fix `run.sh` script
- [ ] Decoding huffman
- [ ] parse input buffer to decode huffman

## How to Run

1. Clone the repository:
   ```sh
   git clone https://github.com/kam-stand/HUFFMAN_HEAP.git
   ```
2. Navigate to the directory:
   ```sh
   cd HEAP
   ```
3. Compile the code:
   ```sh
   ./run.sh
   ```

## Example Usage

After running the script, you can see the encoded and decoded output in the terminal. Modify `main.c` to test with different input data.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgements

- This implementation is based on the principles of Huffman Coding and Min Heap data structures.
- Inspired by various data structure and algorithm resources.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## Contact

For any questions or suggestions, feel free to reach out to the repository owner.

# get_next_line

## Description
A C function that reads a line from a file descriptor, implementing efficient file reading functionality.

## Purpose
This project is part of the 42 school curriculum. The goal is to implement a function that returns a line read from a file descriptor. This project teaches students about static variables, file manipulation, memory management, and buffer handling.

## Technologies Used
- C programming language
- File I/O operations
- Static variables
- Dynamic memory allocation

## Key Features
- Reads from file descriptors (files, stdin, etc.)
- Handles multiple file descriptors simultaneously
- Efficient buffer management
- Returns one line at a time
- Memory leak-free implementation

## Function Prototype
```c
int get_next_line(int fd, char **line);
```

### Parameters
- `fd`: The file descriptor to read from
- `line`: The address of a pointer to store the line read

### Return Value
- `1`: A line has been read
- `0`: EOF has been reached
- `-1`: An error occurred

## Installation

### Prerequisites
- GCC compiler
- Make utility

### Compilation
```bash
# Clone the repository
git clone https://github.com/kaisen1337/get_next_line.git

# Navigate to the project directory
cd get_next_line

# Compile the project
make
```

## Usage Example
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    int ret;

    fd = open("test.txt", O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Project Structure
```
get_next_line/
├── get_next_line.c       # Main function implementation
├── get_next_line.h       # Header file
├── get_next_line_utils.c # Utility functions
└── Makefile              # Build configuration
```

## Learning Objectives
- File descriptor manipulation
- Static variable usage
- Memory management
- Buffer handling
- Reading from multiple file descriptors

## Author
**kaisen1337**
- GitHub: [@kaisen1337](https://github.com/kaisen1337)

## License
This project is part of the 42 school curriculum and is available for educational purposes.

---
*A 42 school project focused on file reading and memory management in C.*

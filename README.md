0x19. C - Stacks, Queues - LIFO, FIFO


Summary of the Monty Program:

The Monty program is a command-line utility with the following usage:

makefile
Copy code
Usage: monty file
file is the path to a file containing Monty byte code.
Program Behavior:

If the user does not provide a file or provides more than one argument, it prints the error message "USAGE: monty file," followed by a new line, and exits with the status EXIT_FAILURE.
If it's not possible to open the specified file, it prints the error message "Error: Can't open file <file>," followed by a new line, and exits with the status EXIT_FAILURE. <file> is the name of the file.
If the file contains an invalid instruction, it prints the error message "L<line_number>: unknown instruction <opcode>," followed by a new line, and exits with the status EXIT_FAILURE. <line_number> represents the line number where the invalid instruction appears, and line numbers always start at 1.
The Monty program processes the bytecodes in the file line by line and stops if one of the following conditions is met:
It successfully executes every line of the file.
It encounters an error in the file.
An error related to memory allocation (malloc failure) occurs.
If the program cannot allocate more memory using malloc, it prints the error message "Error: malloc failed," followed by a new line, and exits with the status EXIT_FAILURE.
The program is required to use malloc and free for memory management and is not allowed to use other memory-related functions such as realloc or calloc.

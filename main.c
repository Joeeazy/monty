#include "monty.h"
/**
* main - Entry point for processing Monty bytecode files
* @argc: Number of arguments (expects 2: program name and bytecode file name)
* @argv: Array of strings containing program name and bytecode file name
* Return: 0 on success, EXIT_FAILURE on error
*/

int main(int argc, char *argv[])
{
checkArgumentCount(argc);
openMontyFile(argv[1]);
custom_execute();
return (0);
}

/**
* checkArgumentCount - Checks the number of command-line arguments
* @argc: Number of arguments
* If argc is not 2, displays error message and exits with EXIT_FAILURE
* Otherwise, it does nothing.
*/
void checkArgumentCount(int argc)
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
}

/**
* openMontyFile - Opens a Monty bytecode file
* @fileName: Name of the file to open
* Attempts to open the Monty bytecode file. If it fails, it displays an error
* and exits with EXIT_FAILURE. Otherwise, it does nothing.
*/
void openMontyFile(char *fileName)
{
mem.input_file = fopen(fileName, "r");
if (mem.input_file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", fileName);
exit(EXIT_FAILURE);
}
}

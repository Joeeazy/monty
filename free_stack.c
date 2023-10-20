#include "monty.h"
/**
* free_memory - free allocated memory
* @stack: the linked list containing the elements
* free operation_name: memory allocated to getline()
*/
void free_memory(stack_t **stack)
{
stack_t *temp;

while (*stack)
{
temp = *stack;
*stack = (*stack)->next;
free(temp);
}
free(mem.current_line);
fclose(mem.input_file);
}

#include "main.h"
/**
  * free_memory - free allocated memory
  * @stack: linked list
  * free linked list
  * free op_name: line by getline
  * close file that has name m_file
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
	free(mem.str);
	fclose(mem.mem_file);
}

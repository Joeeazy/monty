#include "main.h"

/**
  * func_swap - fuction that swaps the top two elements of the stack.
  * @stack: the stack with the elements
  * @line_number: the line number to be interpreted in file
  */
void func_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_numb
				er);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->i;
	(*stack)->i = (*stack)->next->i;
	(*stack)->next->i = temp;
}
/**
 * func_add -  adds the top two elements of the stack.
 * @stack: stack containing the elements
 * @line_number: the line number of the interpreted file
 */
void func_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_numbe
				r);
		free_memory(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->i += (*stack)->i;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * func_nop - opcode function does not do anything
 * @stack: stack to be implemented
 * @line_number: line number of the interpreted file
 */
void func_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

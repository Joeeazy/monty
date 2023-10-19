#include "main.h"

/**
 * func_sub - Subtract second top node from the top node.
 * @stack: Pointer to the stack
 * @line_number: Line number from the opened interpreted file
 */
void func_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: Error - Stack too short to perform subtraction\n", line_number);
		free_memory(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * func_div - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the stack
 * @line_number: Line number in the opened interpreted file
 */
void func_div(stack_t **stack, unsigned int line_number)
{
	char *error_message = NULL;
	
	if (*stack == NULL || (*stack)->next == NULL)
		error_message = "Stack is too short to perform division";
	else if ((*stack)->n == 0)
		error_message = "Division by zero";
	if (error_message)
	{
		fprintf(stderr, "L%u: %s\n", line_number, error_message);
		free_memory(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * func_mul - product of  second top element with the top element of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number from the opened interpreted file
 */
void func_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: Error - Stack too short to perform multiplication\n", line_number);
		free_memory(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * func_mod - Calculates the remainder of the division of
 * the second top element of the stack by the top element of the stack.
 * @stack: The stack
 * @line_number: The line number in the opened interpreted file
 */
void func_mod(stack_t **stack, unsigned int line_number)
{
	char *error_message = NULL;
	
	if (*stack == NULL || (*stack)->next == NULL)
		error_message = "can't mod, stack too short";
	else if ((*stack)->n == 0)
		error_message = "division by zero";
	
	if (error_message)
	{
		fprintf(stderr, "L%u: %s\n", line_number, error_message);
		free_memory(stack);
	       	exit(EXIT_FAILURE);
	}
	
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * func_pchar - Print the character at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the interpreted file.
 */
void func_pchar(stack_t **stack, unsigned int line_number)
{
	char *error_message = NULL;
       
	if (*stack == NULL)
		error_message = "Stack is empty; can't print character.";
	else if ((*stack)->n < 0 || (*stack)->n > 127)
		error_message = "Value is out of the printable character range.";
	
	if (error_message)
	{
		fprintf(stderr, "L%u: %s\n", line_number, error_message);
		free_memory(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

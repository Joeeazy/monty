#include "main.h"

/**
 * func_rotr - function that rotates element to the bottom
 * @stack: the head of the stack
 * @src_line: the line number count
 */
void func_rotr(stack_t **stack, unsigned int src_line)
{
	stack_t *copy;
	(void) src_line;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	copy = *stack;
	while (copy->next != NULL)
		copy = copy->next;
	copy->prev->next = NULL;
	copy->prev = NULL;
	copy->next = *stack;
	(*stack)->prev = copy;
	*stack = copy;
}
/**
  * func_pstr -  prints the string starting at the top of the stack
  * @stack: head position of the satck
  * @src_line: the line number count
  */
void func_pstr(stack_t **stack, unsigned int src_line)
{
	stack_t *temp = *stack;
	(void) src_line;

	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
		printf("\n");
}

/**
  * func_rotl - top element goes last while the second element becomes first
  * @stack: head of the stack in the linked list
  * @src_line: the line number count
  */
void func_rotl(stack_t **stack, unsigned int src_line)
{
	stack_t *tmp, *prev_head;
	(void) src_line;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	prev_head = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = prev_head;
	prev_head->prev = tmp;
	prev_head->next = NULL;
}

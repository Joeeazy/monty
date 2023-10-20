#include "monty.h"

/**
* func_pall - print the data in stack
* @stack: stack
* @src_line: the line number of interpreted opened file
*/
void func_pall(stack_t **stack, unsigned int src_line)
{
stack_t *temp = *stack;
(void) src_line;

while (temp)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}

/**
* check_num - checks if i(the number) can be converted to number
* @n: actual string to check
* Return: (0) if not number (1) if is number
*/
int check_num(char *n)
{
int j;

if (n == NULL)
return (0);
for (j = 0; n[j]; j++)
{
if (j == 0 && (n[j] == '-' || n[j] == '+'))
continue;
if (n[j] < '0' || n[j] > '9')
return (0);
}
return (1);
}
/**
* func_push - push new node to the top of the stack
* @stack: stack top
* @src_line: the actual line number in opened file to interpret
*/
void func_push(stack_t **stack, unsigned int src_line)
{
stack_t *org_node;
stack_t *temp_node;

if (check_num(mem.operation_arg) == 0)
{
fprintf(stderr, "L%u: usage: push integer\n", src_line);
free_memory(stack);
exit(EXIT_FAILURE);
}
org_node = malloc(sizeof(stack_t));
if (org_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
free_memory(stack);
exit(EXIT_FAILURE);
}
org_node->n = atoi(mem.operation_arg);
if (mem.stack_mode == 0)
{
org_node->prev = NULL;
org_node->next = *stack;
if (*stack)
(*stack)->prev = org_node;
*stack = org_node;
}
else
{
temp_node = *stack;
while (temp_node && temp_node->next != NULL)
temp_node = temp_node->next;
org_node->prev = temp_node;
org_node->next = NULL;
if (temp_node)
temp_node->next = org_node;
else
*stack = org_node;
}
}

/**
* func_pint - opcodeprints the value top of the stack,followed by a new line
* @stack: stack
* @src_line: line number at opened interpreted file
*/
void func_pint(stack_t **stack, unsigned int src_line)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", src_line);
free_memory(stack);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
/**
* func_pop - deletes the top element of the stack.
* @stack: stack
* @src_line: The line number at opened interpreted file
*/
void func_pop(stack_t **stack, unsigned int src_line)
{
stack_t *temp;

if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", src_line);
free_memory(stack);
exit(EXIT_FAILURE);
}
temp = *stack;
*stack = (*stack)->next;
free(temp);
}

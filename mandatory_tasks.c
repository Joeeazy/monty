include "main.h"

/**
  * func_pall - print the data in stack
  * @stack: stack
  * @line_number: line number of interpreted opened file
  */
void func_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * is_num - check if n can be converted to number
 * @n: string to check
 * Return: (0) if not number (1) if is number
 */
int check_num(char *i)
{
	int j;

	if (i == NULL)
		return (0);
	for (j = 0; i[j]; j++)
	{
		if (j == 0 && (i[j] == '-' || i[j] == '+'))
			continue;
		if (i[j] < '0' || i[j] > '9')
			return (0);
	}
	return (1);
}
/**
 * sq_push - push new node to stack
 * @stack: stack top
 * @line_number: line number in opened file to interpret
 */
void func_push(stack_t **stack, unsigned int line_number)
{
	stack_t *org_node;
	stack_t *temp_node;

	if (check_num(mem.operation_arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
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
	org_node->i = atoi(mem.op_arg);
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



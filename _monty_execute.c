#include "monty.h"

/**
 * custom_execute - function that executes the whole program.
 */
void custom_execute(void)
{
	char *line_store = NULL;
	size_t buffer_size = 0;
	unsigned int x, line_count = 0;
	stack_t *stackTop = NULL;
	instruction_t arr[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"pop", func_pop},
		{"swap", func_swap},
		{"add", func_add},
		{"nop", func_nop},
		{"sub", fun_sub},
		{"div", fun_div},
		{"mul", func_mul},
		{"mod", func_mod},
		{"monty", func_monty},
		{"pchar", func_pchar},
		{"pstr", func_pstr},
		{"rotl", func_rotl},
		{"rotr", func_rotr},
		{"stack", func_stack},
		{"queue", func_queue},
	};
	while (getline(line_store, &buffer_size, mem.input_file) != -1)
	{
		line_count++;
		mem.current_line = line_store;
		mem.operation_name = custom_strtok(line_store, " \n");
			if (mem.operation_name == NULL || mem.operation_name[0] == '#')
				continue;
		mem.operation_arg = custom_strtok(NULL, " \n");
		for (x = 0; arr[x].opcode; x++)
		{
			if (custom_strcmp(arr[x].opcode, mem.operation_name) == 0)
			{
				arr[x].f(&stackTop, line_count);
				break;
			}
		}

		if (arr[x].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_store, mem.operation_name);
			free_memory(&stackTop);
			exit(EXIT_FAILURE);
		}
	}

	free_memory(&stackTop);
}

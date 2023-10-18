#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  *struct my_memory - has the monty script
  *current_line: used to free the allocated space by getline
  *operation_name: finds the operations names e.g push pop
  *operation_arg: operation arguments
  *my_file: the file that has the lines being interpreted
  *@stack_mode: if 0 thats a stack else it is a queue
  */
typedef struct my_memory
{
	char *current_line;
	char *operation_name;
	char *operation_arg;
	FILE *input_file;
	int stack_mode;
}monty_memory;

/* a global variable */
monty_memory mem;



/* Run or Execute monty program */
void custom_execute(void);
/*function that pushses an element to the stack*/
void func_push(stack_t **stack, unsigned int line_number);
/*function that removes an element to the stack*/
void func_pop(stack_t **stack, unsigned int line_number);
/*function that prints elements to the stack*/
void func_pint(stack_t **stack, unsigned int line_number);
/*function that prints values on the stack*/
void func_pall(stack_t **stack, unsigned int line_number);
/*function that swaps element to the stack*/
void func_swap(stack_t **stack, unsigned int line_number);
#endif

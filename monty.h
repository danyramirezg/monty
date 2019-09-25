#ifndef HOLBERTON
#define HOLBERTON

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define USAGE "USAGE: monty file\n"


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void queue_push(stack_t **rear, stack_t **front, int n);
void queue_pop(stack_t **rear, stack_t **front);

/* opcode execution */
void execute_opcode(char *token, stack_t **top, unsigned int line);
void push(stack_t **top, unsigned int line);
void pall(stack_t **top, unsigned int line);
void pint(stack_t **top, unsigned int line);
void pop(stack_t **top, unsigned int line);
void swap(stack_t **top, unsigned int line);
void add(stack_t **top, unsigned int line);
void nop(stack_t **top, unsigned int line);
/* error handler functions */
void usage_err();
void open_err(char *file);
void invalid_err(char *opcode, unsigned int line);
void malloc_err();
void pint_err(unsigned int);
void pop_err(unsigned int);
void swap_err(unsigned int);
void add_err(unsigned int);
#endif

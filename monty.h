#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


void open1(char *filena);
int parseln(char *buf, int lnnum, int forr);
void rdf(FILE *);
int len_chars(FILE *);
void find1(char *, char *, int, int);

stack_t *createnod(int m);
void free1(void);
void printst(stack_t **, unsigned int);
void addtost(stack_t **, unsigned int);
void addtoqu(stack_t **, unsigned int);

void callf(op_func, char *, char *, int, int);
void printtop(stack_t **, unsigned int);
void poptop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swapn(stack_t **, unsigned int);


void addn(stack_t **, unsigned int);
void subn(stack_t **, unsigned int);

void divn(stack_t **, unsigned int);
void muln(stack_t **, unsigned int);
void modn(stack_t **, unsigned int);


void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void root(stack_t **, unsigned int);


void error1(int error_code, ...);
void error2(int error_code, ...);
void error3(int error_code, ...);
void root2(stack_t **, unsigned int);

#endif

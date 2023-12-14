#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open1(argv[1]);
	free1();
	return (0);
}

/**
 * createnod - Create node
 * @m: Number inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *createnod(int m)
{
	stack_t *no;

	no = malloc(sizeof(stack_t));
	if (no == NULL)
		error1(4);
	no->next = NULL;
	no->prev = NULL;
	no->n = m;
	return (no);
}

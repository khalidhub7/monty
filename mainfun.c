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
 * creatnod - Create node
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

/**
 * free1 - Free nodes in stack
 */
void free1(void)
{
	stack_t *tmpe;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmpe = head;
		head = head->next;
		free(tmpe);
	}
}


/**
 * addtoqu - Add node to queue.
 * @newno: Ptr to new node.
 * @lne: line number of opcode.
 */
void addtoqu(stack_t **newno, __attribute__((unused))unsigned int lne)
{
	stack_t *tmpe;

	if (newno == NULL || *newno == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newno;
		return;
	}
	tmpe = head;
	while (tmpe->next != NULL)
		tmpe = tmpe->next;

	tmpe->next = *newno;
	(*newno)->prev = tmpe;
}

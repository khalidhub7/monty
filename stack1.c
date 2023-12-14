#include "monty.h"


/**
 * addtost - Add node to stack.
 * @newno: Pointer to new node.
 * @lne: Int represent line number of the opcode.
 */
void addtost(stack_t **newno, __attribute__((unused))unsigned int lne)
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
	head = *newno;
	head->next = tmpe;
	tmpe->prev = head;
}


/**
 * printst - Add node to stack.
 * @sta: Ptr to a ptr pointing to top node of the stack
 * @lnnum: line number of  the opcode.
 */
void printst(stack_t **sta, unsigned int lnnum)
{
	stack_t *tmpe;

	(void) lnnum;
	if (sta == NULL)
		exit(EXIT_FAILURE);
	tmpe = *sta;
	while (tmpe != NULL)
	{
		printf("%d\n", tmpe->n);
		tmpe = tmpe->next;
	}
}

/**
 * poptop - Add node to stack
 * @st: Ptr to a ptr pointing to top node of stack.
 * @lnnum: Int represent the line number of opcode.
 */
void poptop(stack_t **st, unsigned int lnnum)
{
	stack_t *tmp;

	if (st == NULL || *st == NULL)
		error2(7, lnnum);

	tmp = *st;
	*st = tmp->next;
	if (*st != NULL)
		(*st)->prev = NULL;
	free(tmp);
}

/**
 * printtop - Print top node of stack.
 * @st: Ptr to a ptr pointing to top node of the stack.
 * @lnnum: Int represent the line number of of the opcode.
 */
void printtop(stack_t **st, unsigned int lnnum)
{
	if (st == NULL || *st == NULL)
		error2(6, lnnum);
	printf("%d\n", (*st)->n);
}

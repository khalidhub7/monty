#include "monty.h"

/**
 * pchar - Print Ascii value.
 * @st: Ptr to a ptr pointing to top node of the stack.
 * @lnnum: Int represent the line number of of the opcode.
 */
void pchar(stack_t **st, unsigned int lnnum)
{
	int ascii;

	if (st == NULL || *st == NULL)
		error3(11, lnnum);

	ascii = (*st)->n;
	if (ascii < 0 || ascii > 127)
		error3(10, lnnum);
	printf("%c\n", ascii);
}

/**
 * pstr - Prints a string.
 * @st: Ptr to a ptr pointing to top node of the stack.
 * @lne: Interger representing the line number of of the opcode.
 */
void pstr(stack_t **st, __attribute__((unused))unsigned int lne)
{
	int ascii;
	stack_t *tmpe;

	if (st == NULL || *st == NULL)
	{
		printf("\n");
		return;
	}

	tmpe = *st;
	while (tmpe != NULL)
	{
		ascii = tmpe->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmpe = tmpe->next;
	}
	printf("\n");
}

/**
 * root - Rotate first node of the stack to  bottom.
 * @st: Ptr to a ptr pointing to top node of stack.
 * @lne: Int represent the line number of of opcode.
 */
void root(stack_t **st, __attribute__((unused))unsigned int lne)
{
	stack_t *tmpe;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		return;

	tmpe = *st;
	while (tmpe->next != NULL)
		tmpe = tmpe->next;

	tmpe->next = *st;
	(*st)->prev = tmpe;
	*st = (*st)->next;
	(*st)->prev->next = NULL;
	(*st)->prev = NULL;
}


/**
 * root2 - Rotate last node of stack to the top.
 * @st: Ptr to a ptr pointing to top node of the stack.
 * @lne: Int represent the line number of of the opcode.
 */
void root2(stack_t **st, __attribute__((unused))unsigned int lne)
{
	stack_t *tmpe;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		return;

	tmpe = *st;

	while (tmpe->next != NULL)
		tmpe = tmpe->next;

	tmpe->next = *st;
	tmpe->prev->next = NULL;
	tmpe->prev = NULL;
	(*st)->prev = tmpe;
	(*st) = tmpe;
}

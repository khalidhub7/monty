#include "monty.h"

/**
 * muln - Add the top two elements of the stack.
 * @st: Pointer to a pointer pointing to top node of the stack.
 * @lnnum: Interger representing the line number of of the opcode.
 */
void muln(stack_t **st, unsigned int lnnum)
{
	int sum;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		error2(8, lnnum, "mul");

	(*st) = (*st)->next;
	sum = (*st)->n * (*st)->prev->n;
	(*st)->n = sum;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * modn - Adds the top two elements of the stack.
 * @st: Pointer to a pointer pointing to top node of the stack.
 * @lnnum: Int representing the line number of of the opcode.
 */
void modn(stack_t **st, unsigned int lnnum)
{
	int sum;

	if (st == NULL || *st == NULL || (*st)->next == NULL)

		error2(8, lnnum, "mod");


	if ((*st)->n == 0)
		error2(9, lnnum);
	(*st) = (*st)->next;
	sum = (*st)->n % (*st)->prev->n;
	(*st)->n = sum;
	free((*st)->prev);
	(*st)->prev = NULL;
}

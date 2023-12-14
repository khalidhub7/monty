#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swapn - Swap the top two elements of the stack.
 * @st: Pointer to a pointer pointing to top node of the stack.
 * @lnnum: Interger representing the line number of of the opcode.
 */
void swapn(stack_t **st, unsigned int lnnum)
{
	stack_t *tmpe;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		error2(8, lnnum, "swap");
	tmpe = (*st)->next;
	(*st)->next = tmpe->next;
	if (tmpe->next != NULL)
		tmpe->next->prev = *st;
	tmpe->next = *st;
	(*st)->prev = tmpe;
	tmpe->prev = NULL;
	*st = tmpe;
}

/**
 * addn - Add top two elements of the stack.
 * @st: Ptr to a ptr pointing to top node of the stack.
 * @lnnum: Int represent the line number of of the opcode.
 */
void addn(stack_t **st, unsigned int lnnum)
{
	int sum;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		error2(8, lnnum, "add");

	(*st) = (*st)->next;
	sum = (*st)->n + (*st)->prev->n;
	(*st)->n = sum;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * subn - Adds the top two elements of the stack.
 * @st: Ptr to a ptr pointing to top node of the stack.
 * @lnnum: Int representing the line number of of the opcode.
 */
void subn(stack_t **st, unsigned int lnnum)
{
	int sum;

	if (st == NULL || *st == NULL || (*st)->next == NULL)

		error2(8, lnnum, "sub");


	(*st) = (*st)->next;
	sum = (*st)->n - (*st)->prev->n;
	(*st)->n = sum;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * divn - Add the top two elements of the stack.
 * @st: Ptr to a ptr pointing to top node of the stack.
 * @lnnum: Int represent the line number of of the opcode.
 */
void divn(stack_t **st, unsigned int lnnum)
{
	int sum;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		error2(8, lnnum, "div");

	if ((*st)->n == 0)
		error2(9, lnnum);
	(*st) = (*st)->next;
	sum = (*st)->n / (*st)->prev->n;
	(*st)->n = sum;
	free((*st)->prev);
	(*st)->prev = NULL;
}

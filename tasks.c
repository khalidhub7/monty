#include "monty.h"


/**
 * push_task1 - Add node to stack
 * @node_to_push: Pointer to the new node.
 * @line_numm: int represent line num of opcode.
 */
void push_task1(stack_t **node_to_push, unsigned int line_numm)
{
	stack_t *file_temp;
	(void) line_numm;

	if (*node_to_push == NULL || node_to_push == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node_to_push;
		return;
	}
	file_temp = head;
	head = *node_to_push;
	head->next = file_temp;
	file_temp->prev = head;
}

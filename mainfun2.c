#include "monty.h"
stack_t *head = NULL;

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

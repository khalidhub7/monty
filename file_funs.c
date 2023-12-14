#include "monty.h"

/**
 * open1 - opens file
 * @filena: file namepath
 * Return: void
 */

void open1(char *filena)
{
	FILE *fd = fopen(filena, "r");

	if (filena == NULL || fd == NULL)
		error1(2, filena);

	rdf(fd);
	fclose(fd);
}


/**
 * rdf - read file
 * @fid: ptr to file descriptor
 * Return: void
 */

void rdf(FILE *fid)
{
	int lnnum, forr = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (lnnum = 1; getline(&buffer, &len, fid) != -1; lnnum++)
	{
		forr = parseln(buffer, lnnum, forr);
	}
	free(buffer);
}


/**
 * parseln - tokenize
 * @buf: line from file
 * @lnnum: line
 * @forr:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseln(char *buf, int lnnum, int forr)
{
	char *opra, *valu;
	const char *de = "\n ";

	if (buf == NULL)
		error1(4);

	opra = strtok(buf, de);
	if (opra == NULL)
		return (forr);
	valu = strtok(NULL, de);

	if (strcmp(opra, "stack") == 0)
		return (0);
	if (strcmp(opra, "queue") == 0)
		return (1);

	find1(opra, valu, lnnum, forr);
	return (forr);
}

/**
 * find1 - find the appropriate function for the opcode
 * @opc: opcode
 * @valu: argument of opcode
 * @forr:  storage format. If 0 Nodes will be entered as a stack.
 * @lne: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find1(char *opc, char *valu, int lne, int forr)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", addtost},
		{"pall", printst},
		{"pint", printtop},
		{"pop", poptop},
		{"nop", nop},
		{"swap", swapn},
		{"add", addn},
		{"sub", subn},
		{"div", divn},
		{"mul", muln},
		{"mod", modn},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", root},
		{"rotr", root2},
		{NULL, NULL}
	};

	if (opc[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opc, func_list[i].opcode) == 0)
		{
			callf(func_list[i].f, opc, valu, lne, forr);
			flag = 0;
		}
	}
	if (flag == 1)
		error1(3, lne, opc);
}

/**
 * callf - Call required function
 * @func: Ptr to the function that is about to be called.
 * @p: string representing the opcode.
 * @vale: string represent a numeric value.
 * @lne: line numeber for the instruction.
 * @forr: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void callf(op_func func, char *p, char *vale, int lne, int forr)
{
	stack_t *no;
	int flag;
	int i;

	flag = 1;
	if (strcmp(p, "push") == 0)
	{
		if (vale != NULL && vale[0] == '-')
		{
			vale = vale + 1;
			flag = -1;
		}
		if (vale == NULL)
			error1(5, lne);
		for (i = 0; vale[i] != '\0'; i++)
		{
			if (isdigit(vale[i]) == 0)
				error1(5, lne);
		}
		no = createnod(atoi(vale) * flag);
		if (forr == 0)
			func(&no, lne);
		if (forr == 1)
			addtoqu(&no, lne);
	}
	else
		func(&head, lne);
}

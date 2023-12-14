#include "monty.h"

/**
 * error1 - Print error messages determined by their error code.
 * @error_code: The error for 1 tal 8:
 * (1) => user does not give any file or more than one file to the program.
 * (2) => file is not a file that can be opened or read.
 * (3) => file provided contains  invalid instruction.
 * (4) => When  program is unable to malloc more memory.
 * (5) => When  parameter passed to the instruction "push" is not an int.
 * (6) => When  stack it empty for pint.
 * (7) => When  stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void error1(int error_code, ...)
{
	va_list ag;
	char *oop;
	int ln;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			ln = va_arg(ag, int);
			oop = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, oop);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free1();
	exit(EXIT_FAILURE);
}

/**
 * error2 - handle errors.
 * @error_code: The error codes are following:
 * (6) => When stack it empty for pint.
 * (7) => When stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void error2(int error_code, ...)
{
	va_list ag;
	char *oop;
	int ln;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			ln = va_arg(ag, unsigned int);
			oop = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", ln, oop);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free1();
	exit(EXIT_FAILURE);
}

/**
 * error3 - handle errors.
 * @error_code: error codes are following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> if stack is empty.
 */
void error3(int error_code, ...)
{
	va_list ag;
	int ln;

	va_start(ag, error_code);
	ln = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
			break;
		default:
			break;
	}
	free1();
	exit(EXIT_FAILURE);
}

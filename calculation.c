#include "monty.h"

/**
 * add - function that adds the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int a, b, sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;
	sum = a + b;

	pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * sub - function subtracts the top element of stack from the second
 * element of stack
 * @stack: pointer to the top of stack
 * @line_number: error line number
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int a, b, diff;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;
	diff = b - a;
	pop(stack, line_number);
	(*stack)->n = diff;
}

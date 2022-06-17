#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the top of stack
 * @line_number: error line number
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	char *str_num;
	int num;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "error allocating memory");
		exit(EXIT_FAILURE);
	}
	str_num = strtok(NULL, DELIMS);
	if (str_num == NULL || _isdigit(str_num) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(top);
		exit(EXIT_FAILURE);
	}
	num = atoi(str_num);
	top->n = num;
	top->prev = NULL;

	if (stack == NULL || *stack == NULL)
	{
		*stack = top;
		top->next = NULL;
		return;
	}
	top->next = (*stack);
	(*stack)->prev = top;
	*stack = top;
}


/**
 * pall - function that prints all the values in the stack, starting from
 * the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: unused
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void) line_number;
	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

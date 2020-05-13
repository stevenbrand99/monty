#include "monty.h"

/**
 * add - a function that add the elements of the input parameters.
 * @stack: This is the head of the parameters
 * @line_number: is a number of the line when there is a wrong.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t (*tmp) = (*stack)->next;
	int add;

	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	add = tmp->n + tmp->prev->n;
	tmp->n = add;
	free(tmp->prev);
	*stack = tmp;
	tmp->prev = NULL;
}

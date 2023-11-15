#include "monty.h"

/**
 * print_char_top - print top in the stack as char
 * @stack: head
 * @line_number: line of number
 * Return: nothing
 */

void print_char_top(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 32 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * print_str - prints str starting at the top of the stack
 * @stack: head
 * @line_number: line of number
 * Return: nothing
 */

void print_str(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *ex = *stack;

	if (!stack || !*stack)
		printf("\n");
	while (ex)
	{
		if (ex->n < 32 || ex->n > 126)
			break;
		printf("%c\n", ex->n);
		ex = ex->next;
	}
}

#include "tester.h"

int	get_ins(char *ins, t_both **t)
{
	if (ins[0] == 's')
		return (swap_read(ins, t));
	else if (ins[0] == 'p')
		return (push_read(ins, t));
	else if (ins[0] == 'r')
		return (rotate_read(ins, t));
	else
		write(2, "Error\n", 6);
	return (0);
}
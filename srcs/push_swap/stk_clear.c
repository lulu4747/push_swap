#include "ps.h"

void	stk_free(t_stk *stk)
{
	t_stk	*fre;
	t_stk	*nxt;

	fre = stk->next;
	while (fre != stk)
	{
		nxt = fre->next;
		free(fre);
		fre = nxt;
	}
	free(stk);
}

void	both_free(t_both *t)
{
	if (t->a != NULL)
		stk_free(t->a);
	if (t->b != NULL)
		stk_free(t->b);
	free(t);
}

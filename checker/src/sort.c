#include "../includes/push_swap.h"

void    sort(t_stack *stack)
{
    t_node  *check;

    check = stack->top;
    while (check && check->next)
    {
        if (check->value < check->next->value)
        {
            check = check->next;
        }
        else
        {
            ft_printf("KO\n");
            return ;
        }
    }
    ft_printf("OK\n");
}

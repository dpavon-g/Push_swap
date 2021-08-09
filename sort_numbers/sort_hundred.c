#include "../push_swap.h"

int number_of_chunk(total)
{
    if (total % 5 == 0)
        return (5);
    else if (total % 4 == 0)
        return (4);
    else if (total % 3 == 0)
        return (3);
    else if (total % 2 == 0)
        return (2);
    else
        return (1);
}

void    sort_array(t_num **pilea, int *array, int total)
{
    int i;
    int k;
    int aux;

    k = 0;
    i = 0;
    while (i < total)
    {
        k = i + 1;
        while (k < total)
        {
            if (array[i] > array[k])
            {
                aux = array[k];
                array[k] = array[i];
                array[i] = aux;
            }
            k++;
        }
        i++;
    }
    *pilea = (*pilea)->next;
    ft_printf("%d", number_of_chunk(total));
    // separate_piles(pilea, array, total);
}

int order_hundred(t_num **pilea, int total)
{
    int     array[total];
    int     i;
    t_num   *aux;

    i = 0;
    aux = *pilea;
    while (aux)
    {
        array[i] = aux->content;
        aux = aux->next;
        i++;
    }
    sort_array(pilea, array, total);
    return (0);
}
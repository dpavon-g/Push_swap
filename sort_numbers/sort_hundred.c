#include "../push_swap.h"

int number_of_chunk(t_values *content)
{
	if (content->total % 5 == 0)
		return (5);
	else if (content->total % 4 == 0)
		return (4);
	else if (content->total % 3 == 0)
		return (3);
	else if (content->total % 2 == 0)
		return (2);
	else
		return (1);
}

int     **array_in_chunks(int total, int *array, t_values *content)
{
	int **array_chunks;
	int i;
	int l;
	int k;

	i = 0;
	content->columns = total / content->chunks;
	array_chunks = (int**) malloc(sizeof(int*) * content->chunks);
	while (i < content->chunks)
		array_chunks[i++] = (int*)malloc(sizeof(int) * content->columns);
	i = 0;
	l = 0;
	while (i < total)
	{
		k = 0;
		while (k < content->columns)
		{
			array_chunks[l][k] = array[i];
			k++;
			i++;
		}
		l++;
	}
	return (array_chunks);
}

int	*order_array(int *array, t_values *content)
{
	int		*sort_array;
	int		k;
	int		i;
	int		aux;

	sort_array = (int*) malloc(sizeof(int) * content->total);
	i = 0;
	while (i < content->total)
	{
		k = i + 1;
		while (k < content->total)
		{
			if (array[i] > array[k])
			{
				aux = array[i];
				array[i] = array[k];
				array[k] = aux;
			}
			k++;
		}
		i++;
	}
	i = 0;
	while (i < content->total)
	{
		sort_array[i] = array[i];
		i++;
	}
	return (sort_array); 
}

void	ordenate_piles(t_num **pilea, t_num **pileb, t_values *content, int *array)
{
	int	i;

	i = 0;
	while (i < content->total)
	{
		if (array[i] == (*pilea)->content)
		{
			content->movements += pa_pb(pilea, pileb);
			ft_printf("pb\n");
			i++;
		}
		else
		{
			content->movements += ra_rb(pilea);
			ft_printf("ra\n");
		}
	}
	i = 0;
	while (i < content->total)
	{
		content->movements += pa_pb(pileb, pilea);
		ft_printf("pa\n");
		i++;
	}
}

void    separate_piles(t_num **pilea, t_num **pileb, int *array, int total, t_values *content)
{
	int     	**array_chunks;
	int     	*sort_array;
	int			i;

	i = 0;
	content->total = total;
	content->chunks = number_of_chunk(content);
	array_chunks = array_in_chunks(total, array, content);
	sort_array = order_array(array, content);
	ordenate_piles(pilea, pileb, content, sort_array);
	// while (i < content->chunks)
	// {
	// 	free(array_chunks[0]);
	// 	i++;
	// }
	// free(array_chunks);
	// free(sort_array);
}


int order_hundred(t_num **pilea, t_num **pileb, int total)
{
	int    		array[total];
	t_values	content;
	int			i;
	t_num  		*aux;

	i = 0;
	aux = *pilea;
	ft_bzero(&content, sizeof(content));
	while (aux)
	{
		array[i] = aux->content;
		aux = aux->next;
		i++;
	}
	separate_piles(pilea, pileb, array, total, &content);
	return (content.movements);
}
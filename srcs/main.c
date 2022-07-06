/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:19:30 by gborne            #+#    #+#             */
/*   Updated: 2022/07/06 16:12:15 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_list(char **list)
{
	int		i;

	i = 0;
	if (list == NULL)
		return;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list[i]);
	free(list);
}

static char	**create_list(int argc, char **argv)
{
	char	**list;
	char	*str;
	int		i;

	list = NULL;
	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = ' ';
	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			str = ft_strjoin(str, argv[i]);
			str = ft_strjoin(str, " ");
			i++;
		}
	}
	list = ft_split(str, ' ');
	free(str);
	return (list);
}

int	is_sort(t_p	*p)
{
	int	i;
	
	i = 0;
	while (++i <= p->size)
		if (p->nbr[i] < p->nbr[i - 1])
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_p 	a;
	t_p 	b;
	char	**list;

	list = create_list(argc, argv);
	if (list == NULL || argc < 2 || !check(list))
	{
		free_list(list);
		return (1);
	}
	a = pile_create(list);
	free_list(list);
	b = pile_init(a.size);
	if (a.nbr == NULL || b.nbr == NULL)
		return (write(1, "Error\nLa pile n'a pas pu être créer\n", 39));
	//printf("\nInitialisation : \n");
	//pile_print(a);
	if (!is_sort(&a))
		sort(&a, &b);
	//printf("\nPile de %d nombres triée en %d coups :\n", a.size + 1, sort_pile(&a, &b));
	//pile_print(a);
	//pile_print(b);
	pile_destroy(&b);
	pile_destroy(&a);
	return (0);
}

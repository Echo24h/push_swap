/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:19:30 by gborne            #+#    #+#             */
/*   Updated: 2022/02/01 06:00:12 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**create_list(int argc, char **argv)
{
	char	**list;
	char	*str;
	int		i;

	list = NULL;
	str = (char *)malloc(sizeof(char));
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

int	main(int argc, char **argv)
{
	t_p a;
	t_p b;
	char	**list;

	list = create_list(argc, argv);
	if (argc < 2 || !check_list(list))
		return (ft_printf("ERROR : La pile n'est pas valide.\n"));
	a = pile_create(list);
	free(list);
	b = pile_init(a.size);
	ft_printf("\nInitialisation : ");
	pile_print(a);
	ft_printf("\n\nPile de %d nombres triée en %d coups : ", a.size + 1, sort_pile(&a, &b));
	pile_print(a);
	pile_destroy(&a);
	pile_destroy(&b);
}

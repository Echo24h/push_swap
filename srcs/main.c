/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:19:30 by gborne            #+#    #+#             */
/*   Updated: 2022/01/26 05:28:48 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_p a;
	t_p b;
	if (argc < 2 || !check_arg(argv))
		return (0);
	a = pile_create(argv);
	b = pile_init(a.size);
	ft_putchar('\n');
	pile_print(a);
	pile_print(b);
	pile_destroy(&a);
	pile_destroy(&b);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 04:05:01 by gborne            #+#    #+#             */
/*   Updated: 2022/01/29 04:09:07 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	**box_init(int nb, int size)
{
	int **box;

	box = (int **)malloc(sizeof(int *) * (nb + 1));
	box[nb + 1] = NULL;
	while (nb > 0)
	{
		box[nb] = (int *)malloc(sizeof(int) * size);
		nb--;
	}
	return (box);
}

void	box_free(int **box)
{
	int nb;

	nb = -1;
	while(box[++nb])
			free(box[nb]);
	free(box);
}

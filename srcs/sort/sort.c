/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/07/06 15:55:43 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sort(t_p *a, t_p *b)
{

	if (a->size < 6)
		return (sort_small(a, b));
	else if (a->size < 16)
		return (sort_big(a, b, 5));
	else if (a->size < 32)
		return (sort_big(a, b, 16));
	else if (a->size < 64)
		return (sort_big(a, b, 32));
	else if (a->size < 128)
		return (sort_big(a, b, 50));
	else if (a->size < 1024)
		return (sort_big(a, b, 64));
	else if (a->size < 4096)
		return (sort_big(a, b, 256));
	else
		return (sort_big(a, b, 1024));
}


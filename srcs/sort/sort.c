/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/02/02 16:12:21 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sort_pile(t_p *a, t_p *b)
{
	if (a->size < 6)
		return (sort_small_stack(a, b));
	else if (a->size < 10)
		return (sort_big_stack(a, b));
	else
		return (sort_bigbig_stack(a, b));
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/07/03 14:20:16 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sort_pile(t_p *a, t_p *b)
{

	if (a->size < 6)
		return (sort_small_stack(a, b));
	else if (a->size < 16)
		return (sort_bigbig_stack(a, b, 5));
	else if (a->size < 32)
		return (sort_bigbig_stack(a, b, 16));
	else if (a->size < 64)
		return (sort_bigbig_stack(a, b, 32));
	else if (a->size < 128)
		return (sort_bigbig_stack(a, b, 50));
	else if (a->size < 1024)
		return (sort_bigbig_stack(a, b, 64));
	else if (a->size < 4096)
		return (sort_bigbig_stack(a, b, 256));
	else
		return (sort_bigbig_stack(a, b, 1024));
}


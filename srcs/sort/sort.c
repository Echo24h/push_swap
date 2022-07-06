/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/07/06 18:18:34 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sort(t_p *a, t_p *b)
{

	if (a->size < 6)
		return (sort_small(a, b));
	else if ( a->size < 400)
		return (sort_big(a, b, ((a->size + 1) / 4)));
	else if ( a->size < 1000)
		return (sort_big(a, b, ((a->size + 1) / 10)));
	else
		return (sort_big(a, b, ((a->size + 1) / 20)));
}


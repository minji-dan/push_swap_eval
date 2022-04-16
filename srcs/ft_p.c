/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:56:51 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 15:57:00 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_deque *dq_to, t_deque *dq_from)
{
	if (dq_from->head == NULL)
		return (0);
	push_front(dq_to, pop_front(dq_from));
	ft_putendl_fd("pa", 1);
	return (1);
}

int	pb(t_deque *dq_to, t_deque *dq_from)
{
	if (dq_from->head == NULL)
		return (0);
	push_front(dq_to, pop_front(dq_from));
	ft_putendl_fd("pb", 1);
	return (1);
}

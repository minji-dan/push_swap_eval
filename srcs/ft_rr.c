/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:53:43 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 15:53:53 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_deque *dq)
{
	push_front(dq, pop_back(dq));
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_deque *dq)
{
	push_front(dq, pop_back(dq));
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_deque *dq_a, t_deque *dq_b)
{
	push_front(dq_a, pop_back(dq_a));
	push_front(dq_b, pop_back(dq_b));
	ft_putendl_fd("rrr", 1);
	return (1);
}

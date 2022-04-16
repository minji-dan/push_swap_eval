/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:57:14 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 15:57:23 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_deque *dq)
{
	push_back(dq, pop_front(dq));
	ft_putendl_fd("ra", 1);
	return (1);
}

int	rb(t_deque *dq)
{
	push_back(dq, pop_front(dq));
	ft_putendl_fd("rb", 1);
	return (1);
}

int	rr(t_deque *dq_a, t_deque *dq_b)
{
	push_back(dq_a, pop_front(dq_a));
	push_back(dq_b, pop_front(dq_b));
	ft_putendl_fd("rr", 1);
	return (1);
}

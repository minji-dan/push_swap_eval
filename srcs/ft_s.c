/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:57:34 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 16:00:32 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_deque *dq)
{
	int	tmp;

	if (dq->head == NULL || dq->head->rlink == NULL)
		return (0);
	tmp = dq->head->data;
	dq->head->data = dq->head->rlink->data;
	dq->head->rlink->data = tmp;
	ft_putendl_fd("sa", 1);
	return (1);
}

int	sb(t_deque *dq)
{
	int	tmp;

	if (dq->head == NULL || dq->head->rlink == NULL)
		return (0);
	tmp = dq->head->data;
	dq->head->data = dq->head->rlink->data;
	dq->head->rlink->data = tmp;
	ft_putendl_fd("sb", 1);
	return (1);
}

int	ss(t_deque *dq_a, t_deque *dq_b)
{
	int	tmp;

	if (!(dq_a->head == NULL || dq_a->head->rlink == NULL))
	{
		tmp = dq_a->head->data;
		dq_a->head->data = dq_a->head->rlink->data;
		dq_a->head->rlink->data = tmp;
	}
	if (!(dq_a->head == NULL || dq_a->head->rlink == NULL))
	{
		tmp = dq_b->head->data;
		dq_b->head->data = dq_b->head->rlink->data;
		dq_b->head->rlink->data = tmp;
	}
	ft_putendl_fd("ss", 1);
	return (1);
}

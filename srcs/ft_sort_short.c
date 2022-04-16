/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:03:45 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 16:05:15 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_deque *dq)
{
	int	bot;
	int	mid;
	int	top;

	bot = dq->head->data;
	mid = dq->head->rlink->data;
	top = dq->head->rlink->rlink->data;
	if (bot < mid && mid < top)
		return ;
	if (bot > mid && mid < top && bot < top)
		sa(dq);
	else if (bot < mid && mid > top && bot < top)
	{
		rra(dq);
		sa(dq);
	}
	else if (bot > mid && bot > top && mid < top)
		ra(dq);
	else if (bot > mid && mid > top)
	{
		ra(dq);
		sa(dq);
	}
	else if (bot < mid && bot > top && mid > top)
		rra(dq);
}

void	ft_shortsort(t_deque *dq, int num)
{
	if (num <= 1)
		return ;
	else if (num == 2 && dq->head->data > dq->head->rlink->data)
		sa(dq);
	else if (num == 3)
		sort_three(dq);
	else
		return ;
}

int	find_pos(t_deque *dq)
{
	int		pos;
	t_Node	*tmp;

	pos = 0;
	tmp = dq->head;
	while (tmp)
	{
		if (dq->head->data > tmp->data)
			++pos;
		tmp = tmp->rlink;
	}
	return (pos);
}

void	change_pos(t_deque *dq)
{
	int	pos;

	pos = find_pos(dq);
	if (!pos)
		return ;
	else if (pos == 1)
		sa(dq);
	else if (pos == 2)
	{
		sa(dq);
		ra(dq);
		sa(dq);
		rra(dq);
	}
	else if (pos == 3 && dq->num == 4)
		ra(dq);
	else if (pos == 3 && dq->num == 5)
	{
		rra(dq);
		sa(dq);
		ra(dq);
		ra(dq);
	}
	else
		ra(dq);
}

void	sort_five(t_deque *dq_a, t_deque *dq_b)
{
	pb(dq_b, dq_a);
	pb(dq_b, dq_a);
	sort_three(dq_a);
	pa(dq_a, dq_b);
	change_pos(dq_a);
	pa(dq_a, dq_b);
	change_pos(dq_a);
}

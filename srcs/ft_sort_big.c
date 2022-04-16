/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:54:05 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 15:55:10 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pv(t_deque *dq, int cnt, t_Cnt *count)
{
	t_Node	*tmp;
	int		*arr;
	int		i;

	i = 0;
	tmp = dq->head;
	arr = (int *)malloc(sizeof(int) * cnt);
	if (!arr)
		ft_error(1);
	while (i < cnt && tmp)
	{
		arr[i] = tmp->data;
		tmp = tmp->rlink;
		++i;
	}
	bubble_sort(arr, cnt);
	count->pv1 = arr[i / 3];
	count->pv2 = arr[i * 2 / 3];
	free(arr);
}

void	rreverse(t_deque *dq_a, t_deque *dq_b, int ra_cnt, int rb_cnt)
{
	int	i;

	i = 0;
	while (i < ra_cnt && i < rb_cnt)
	{
		rrr(dq_a, dq_b);
		++i;
	}
	while (i < ra_cnt)
	{
		rra(dq_a);
		++i;
	}
	while (i < rb_cnt)
	{
		rrb(dq_b);
		++i;
	}
}

void	sort_lowcase(t_deque *dq_a, t_deque *dq_b, int cnt, int flag)
{
	if (flag == 1 && cnt == 2)
	{
		if (dq_a->head->data > dq_a->head->rlink->data)
			sa(dq_a);
	}
	if (flag == 0)
	{
		if (cnt == 1)
			pa(dq_a, dq_b);
		else if (cnt == 2)
		{
			if (dq_b->head->data > dq_b->head->rlink->data)
			{
				pa(dq_a, dq_b);
				pa(dq_a, dq_b);
			}
			else
			{
				sb(dq_b);
				pa(dq_a, dq_b);
				pa(dq_a, dq_b);
			}
		}
	}
}

void	sort_BtoA(t_deque *dq_a, t_deque *dq_b, int cnt)
{
	t_Cnt	count;

	if (cnt <= 2)
		return (sort_lowcase(dq_a, dq_b, cnt, 0));
	init_cnt(&count);
	find_pv(dq_b, cnt, &count);
	while (cnt--)
	{
		if (dq_b->head->data < count.pv1)
			count.rb_cnt += rb(dq_b);
		else
		{
			count.pa_cnt += pa(dq_a, dq_b);
			if (dq_a->head->data < count.pv2)
				count.ra_cnt += ra(dq_a);
		}
	}
	sort_AtoB(dq_a, dq_b, count.pa_cnt - count.ra_cnt);
	rreverse(dq_a, dq_b, count.ra_cnt, count.rb_cnt);
	sort_AtoB(dq_a, dq_b, count.ra_cnt);
	sort_BtoA(dq_a, dq_b, count.rb_cnt);
}

void	sort_AtoB(t_deque *dq_a, t_deque *dq_b, int cnt)
{
	t_Cnt	count;

	if (cnt <= 2)
		return (sort_lowcase(dq_a, dq_b, cnt, 1));
	if (check_sorted(dq_a, cnt) == 1)
		return ;
	init_cnt(&count);
	find_pv(dq_a, cnt, &count);
	while (cnt && !remain_all_big(dq_a, cnt, count.pv2))
	{
		if (dq_a->head->data >= count.pv2)
			count.ra_cnt += ra(dq_a);
		else
		{
			count.pb_cnt += pb(dq_b, dq_a);
			if (dq_b->head->data >= count.pv1)
				count.rb_cnt += rb(dq_b);
		}
		cnt--;
	}
	rreverse(dq_a, dq_b, count.ra_cnt, count.rb_cnt);
	count.ra_cnt += cnt;
	sort_AtoB(dq_a, dq_b, count.ra_cnt);
	sort_BtoA(dq_a, dq_b, count.rb_cnt);
	sort_BtoA(dq_a, dq_b, count.pb_cnt - count.rb_cnt);
}

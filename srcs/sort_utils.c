/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:55:52 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 15:56:39 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cnt(t_Cnt *count)
{
	count->pv1 = 0;
	count->pv2 = 0;
	count->ra_cnt = 0;
	count->rb_cnt = 0;
	count->pa_cnt = 0;
	count->pb_cnt = 0;
}

void	bubble_sort(int *arr, int cnt)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < cnt)
	{
		j = 0;
		while (j < cnt - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			++j;
		}
		++i;
	}
}

int	check_sorted(t_deque *dq, int cnt)
{
	t_Node	*tmp;
	int		i;

	tmp = dq->head;
	i = 1;
	while (i++ < cnt)
	{
		if (tmp->data > tmp->rlink->data)
			return (0);
		tmp = tmp->rlink;
	}
	return (1);
}

int	remain_all_big(t_deque *dq, int cnt, int pv)
{
	int		i;
	t_Node	*tmp;

	tmp = dq->head;
	i = 0;
	while (i < cnt)
	{
		if (tmp->data < pv)
			return (0);
		tmp = tmp->rlink;
		++i;
	}
	return (1);
}

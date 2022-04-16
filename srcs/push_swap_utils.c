/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:01:25 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 16:03:20 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_deque *dq)
{
	t_Node	*tmp;
	t_Node	*del;

	tmp = dq->head;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->rlink;
		free(del);
		del = NULL;
	}
}

void	ft_error(int n)
{
	if (n == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	check_dups(t_deque *dq)
{
	t_Node	*cur;
	t_Node	*tmp;

	cur = dq->head;
	while (cur)
	{
		tmp = cur->rlink;
		while (tmp)
		{
			if (tmp->data == cur->data)
				ft_error(1);
			tmp = tmp->rlink;
		}
		cur = cur->rlink;
	}
}

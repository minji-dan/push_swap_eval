/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:55:25 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 15:55:47 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_deque *dq_a, t_deque *dq_b)
{
	if (dq_a->num < 4)
		ft_shortsort(dq_a, dq_a->num);
	else if (dq_a->num == 5)
		sort_five(dq_a, dq_b);
	else
		sort_AtoB(dq_a, dq_b, dq_a->num);
}

int	main(int argc, char **argv)
{
	t_deque	dq_a;
	t_deque	dq_b;

	if (1 < argc)
	{
		dq_init(&dq_a);
		dq_init(&dq_b);
		copy_argv_deq(argc, argv, &dq_a);
		push_swap(&dq_a, &dq_b);
		ft_free(&dq_a);
		ft_free(&dq_b);
		return (0);
	}
	else
		return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:51:09 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 15:51:11 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "libft.h"

typedef struct s_cnt
{
	int	pv1;
	int	pv2;
	int	ra_cnt;
	int	rb_cnt;
	int	pa_cnt;
	int	pb_cnt;
}	t_Cnt;

typedef struct s_node
{
	long			data;
	struct s_node	*llink;
	struct s_node	*rlink;
}	t_Node;

typedef struct s_deque
{
	t_Node	*head;
	t_Node	*tail;
	int		num;
}	t_deque;

void	dq_init(t_deque *dq);
void	push_back(t_deque *dq, int item);
void	push_front(t_deque *dq, int item);
int		pop_front(t_deque *dq);
int		pop_back(t_deque *dq);

int		pa(t_deque *dq_to, t_deque *dq_from);
int		pb(t_deque *dq_to, t_deque *dq_from);

int		ra(t_deque *dq);
int		rb(t_deque *dq);
int		rr(t_deque *dq_a, t_deque *dq_b);

int		rra(t_deque *dq);
int		rrb(t_deque *dq);
int		rrr(t_deque *dq_a, t_deque *dq_b);

int		sa(t_deque *dq);
int		sb(t_deque *dq);
int		ss(t_deque *dq_a, t_deque *dq_b);

void	sort_three(t_deque *dq);
int		find_pos(t_deque *dq);
void	change_pos(t_deque *dq);
void	sort_five(t_deque *dq_a, t_deque *dq_b);
void	ft_shortsort(t_deque *dq, int num);

void	init_cnt(t_Cnt *count);
void	bubble_sort(int *arr, int cnt);
int		check_sorted(t_deque *dq, int cnt);
int		remain_all_big(t_deque *dq, int cnt, int pv);

void	find_pv(t_deque *deq, int cnt, t_Cnt *count);
void	rreverse(t_deque *dq_a, t_deque *dq_b, int ra_cnt, int rb_cnt);
void	sort_lowcase(t_deque *dq_a, t_deque *dq_b, int cnt, int flag);
void	sort_BtoA(t_deque *dq_a, t_deque *dq_b, int cnt);
void	sort_AtoB(t_deque *dq_a, t_deque *dq_b, int cnt);

long	ft_atol(char **str);
void	ft_parsing(char *str, t_deque *dq);

void	ft_free(t_deque *dq);
void	ft_error(int n);
void	check_dups(t_deque *deq);
void	copy_argv_deq(int argc, char **argv, t_deque *dq);

void	push_swap(t_deque *dq_a, t_deque *dq_b);

#endif

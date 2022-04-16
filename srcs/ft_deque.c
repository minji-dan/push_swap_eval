/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:51:40 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 15:52:36 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dq_init(t_deque *dq)
{
	dq->head = NULL;
	dq->tail = NULL;
	dq->num = 0;
}

void	push_back(t_deque *dq, int item)
{
	t_Node	*node;

	node = (t_Node *)malloc(sizeof(t_Node));
	if (!node)
		ft_error(1);
	node->data = item;
	node->llink = dq->tail;
	if (dq->num == 0)
		dq->head = node;
	else
		dq->tail->rlink = node;
	node->rlink = NULL;
	dq->tail = node;
	++(dq->num);
}

void	push_front(t_deque *dq, int item)
{
	t_Node	*node;

	node = (t_Node *)malloc(sizeof(t_Node));
	if (!node)
		ft_error(1);
	node->data = item;
	node->rlink = dq->head;
	if (dq->num == 0)
		dq->tail = node;
	else
		dq->head->llink = node;
	node->llink = NULL;
	dq->head = node;
	++(dq->num);
}

int	pop_front(t_deque *dq)
{
	int		item;
	t_Node	*node;

	if (dq->num == 0)
		ft_error(1);
	node = dq->head;
	item = dq->head->data;
	dq->head = dq->head->rlink;
	free(node);
	if (dq->head == NULL)
		dq->tail = NULL;
	else
		dq->head->llink = NULL;
	--(dq->num);
	return (item);
}

int	pop_back(t_deque *dq)
{
	int		item;
	t_Node	*node;

	if (dq->num == 0)
		ft_error(1);
	node = dq->tail;
	item = dq->tail->data;
	dq->tail = dq->tail->llink;
	free(node);
	if (dq->tail == NULL)
		dq->head = NULL;
	else
		dq->tail->rlink = NULL;
	--(dq->num);
	return (item);
}

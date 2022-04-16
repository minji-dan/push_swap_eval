/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:52:44 by mkim2             #+#    #+#             */
/*   Updated: 2022/03/19 15:53:37 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char **str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	if (**str && !(**str == '+' || **str == '-') && !(ft_isdigit(**str)))
		ft_error(1);
	if (**str == '-')
		sign = -1;
	if (**str == '+' || **str == '-')
	{
		++(*str);
	}
	if (**str && !ft_isdigit(**str))
		ft_error(1);
	while (ft_isdigit(**str))
	{
		ret = ret * 10 + **str - '0';
		++(*str);
	}
	return ((long)sign * ret);
}

void	copy_argv_deq(int argc, char **argv, t_deque *dq)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_parsing(argv[i], dq);
		++i;
	}
	check_dups(dq);
}

void	ft_parsing(char *str, t_deque *dq)
{
	long	ret;

	while (*str)
	{
		while (*str == ' ' || (9 <= *str && *str <= 13))
			++str;
		if (*str == '\0')
			break ;
		ret = ft_atol(&str);
		if (ret > INT_MAX || ret < INT_MIN)
			ft_error(1);
		push_back(dq, ret);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:01:53 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/05 11:34:02 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*Called when stack A is sorted in reverse*/
void	ft_solution_reverse(long int **st_a, int size_a,
			long int **st_b, int size_b)
{
	while (size_a > 2)
	{
		ft_reverse_rotate_a((long int **)st_a, size_a);
		ft_pb((long int **)st_a, &size_a, (long int **)st_b, &size_b);
	}
	ft_swap_a((long int **)st_a, size_a);
	while (size_b > 0)
		ft_pa((long int **)st_a, &size_a, (long int **)st_b, &size_b);
}

/*Called when size of stack A is smaller than 4*/
void	ft_solution_s(long int **st_a, int size_a)
{
	int	min;
	int	max;

	min = ft_find_pos_min(st_a, size_a);
	max = ft_find_pos_max(st_a, size_a);
	if ((size_a == 2 && min > max)
		|| (size_a == 3 && min == 1 && max == 2))
		ft_swap_a((long int **)st_a, size_a);
	else
	{
		if (max == 1 && min == 2)
			ft_reverse_rotate_a((long int **)st_a, size_a);
		else if (max == 0 && min == 1)
			ft_rotate_a((long int **)st_a, size_a);
		else if (min == 0 && max == 1)
		{
			ft_reverse_rotate_a((long int **)st_a, size_a);
			ft_swap_a((long int **)st_a, size_a);
		}
		else if (max == 0 && min == 2)
		{
			ft_swap_a((long int **)st_a, size_a);
			ft_reverse_rotate_a((long int **)st_a, size_a);
		}
	}
}

/*Called when size of stack A is smaller than 6*/
void	ft_solution_m(long int **st_a, int size_a,
			long int **st_b, int size_b)
{
	long int	min;
	long int	max;
	long int	middle;

	while (size_a > 1 && ft_is_sorted(st_a, size_a) == -1)
	{
		min = ft_find_pos_min(st_a, size_a);
		max = ft_find_pos_max(st_a, size_a);
		middle = size_a / 2;
		if (min == 1 && ft_is_sorted(st_a, size_a) == -1)
			ft_swap_a((long int **)st_a, size_a);
		else if (max == 0)
			ft_rotate_a((long int **)st_a, size_a);
		else if (min != 0 && min <= middle)
			while (min-- > 0)
				ft_rotate_a((long int **)st_a, size_a);
		else if (min != 0 && min > middle)
			while (min++ < size_a)
				ft_reverse_rotate_a((long int **)st_a, size_a);
		else if (min == 0 && size_a > 1 && ft_is_sorted(st_a, size_a) == -1)
			ft_pb((long int **)st_a, &size_a, (long int **)st_b, &size_b);
	}
	while (size_b > 0 && size_a <= 5)
		ft_pa((long int **)st_a, &size_a, (long int **)st_b, &size_b);
}

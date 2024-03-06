/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_bigger.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:06:40 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/05 10:06:43 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_help_xl(long int **st_a, int size_a, long int **st_b, int size_b)
{
	long int	max;

	while (size_b > 0)
	{
		max = ft_find_pos_max(st_b, size_b);
		if (max <= size_b / 2)
		{
			while (max-- > 0)
				ft_rotate_b((long int **)st_b, size_b);
			ft_pa((long int **)st_a, &size_a, (long int **)st_b, &size_b);
		}
		else
		{
			while (max++ < size_b)
				ft_reverse_rotate_b((long int **)st_b, size_b);
			ft_pa((long int **)st_a, &size_a, (long int **)st_b, &size_b);
		}
	}
}

/*Called when size of stack A is greater than 100*/
void	ft_solution_xl(long int **st_a, int size_a, long int **st_b, int size_b)
{
	long int	range;
	long int	position;

	range = 50;
	while (size_a > 0)
	{
		position = ft_cost_rot(st_a, size_a, range);
		if (position == -1)
			range += 27;
		else if (position <= size_a / 2)
		{
			while (position-- > 0)
				ft_rotate_a((long int **)st_a, size_a);
			ft_pb((long int **)st_a, &size_a, (long int **)st_b, &size_b);
		}
		else
		{
			while (position++ < size_a)
				ft_reverse_rotate_a((long int **)st_a, size_a);
			ft_pb((long int **)st_a, &size_a, (long int **)st_b, &size_b);
		}
		if (size_b > 1 && st_a[0][1] > st_a[1][1] && st_b[0][1] < st_b[1][1])
			ft_ss((long int **)st_a, size_a, (long int **)st_b, size_b);
	}
	ft_help_xl((long int **)st_a, size_a, (long int **)st_b, size_b);
}

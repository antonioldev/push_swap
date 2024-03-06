/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:06:40 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/05 10:06:43 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*Function that calculate if rotate is faster than reverse rotate*/
static long int	ft_which_way(long int *sml, long int big, int size_a)
{
	int	faster;

	if (*sml == -1 && big > -1)
		faster = 1;
	else if (big == -1 && *sml > -1)
		faster = -1;
	else if (*sml < big && *sml <= size_a / 2 && big <= size_a / 2)
		faster = -1;
	else if (*sml > big && *sml > size_a / 2 && big > size_a / 2)
		faster = -1;
	else if (*sml > big && *sml <= size_a / 2 && big <= size_a / 2)
		faster = 1;
	else if (*sml < big && *sml > size_a / 2 && big > size_a / 2)
		faster = 1;
	else if (*sml <= size_a / 2 && size_a - big <= *sml)
		faster = 1;
	else
		faster = 0;
	if (faster == 1)
		*sml = big;
	return (faster);
}

/*Function that rotate the array till smaller number is at the top*/
static void	ft_reorganise(long int **st_a, int size_a)
{
	long int	smaller;

	smaller = ft_find_pos_min((long int **)st_a, size_a);
	if (smaller <= size_a / 2)
		while (smaller-- > 0)
			ft_rotate_a((long int **)st_a, size_a);
	else
		while (smaller++ < size_a)
			ft_reverse_rotate_a((long int **)st_a, size_a);
}

static void	ft_help(long int **st_a, int size_a, long int **st_b, int size_b)
{
	long int	smaller;
	long int	bigger;
	long int	faster;

	while (size_a > 3)
		ft_pb((long int **)st_a, &size_a, (long int **)st_b, &size_b);
	ft_solution_s((long int **)st_a, size_a);
	while (size_b > 0)
	{
		smaller = ft_find_smaller((long int **)st_a, size_a, st_b[0][1]);
		bigger = ft_find_greater((long int **)st_a, size_a, st_b[0][1]);
		faster = ft_which_way(&smaller, bigger, size_a);
		if (faster != 0 && smaller <= size_a / 2)
			while (smaller-- > 0)
				ft_rotate_a((long int **)st_a, size_a);
		else if (faster != 0)
			while (smaller++ < size_a)
				ft_reverse_rotate_a((long int **)st_a, size_a);
		ft_pa((long int **)st_a, &size_a, (long int **)st_b, &size_b);
		if (faster == -1 && size_b > 1 && st_b[0][1] < st_b[1][1])
			ft_ss((long int **)st_a, size_a, (long int **)st_b, size_b);
		else if (faster == -1)
			ft_swap_a((long int **)st_a, size_a);
	}
	ft_reorganise((long int **)st_a, size_a);
}

/*Called when size of stack A is smaller or equal than 100*/
void	ft_solution_l(long int **st_a, int size_a, long int **st_b, int size_b)
{
	int	range_min;
	int	range_max;

	range_min = size_a / 3;
	range_max = size_a - range_min;
	while (size_a > range_min)
	{
		if (st_a[0][1] > range_max)
			ft_rotate_a((long int **)st_a, size_a);
		else
		{
			ft_pb((long int **)st_a, &size_a, (long int **)st_b, &size_b);
			if (st_b[0][1] < range_min)
			{
				if (st_a[0][1] > range_max)
					ft_rr((long int **)st_a, size_a, (long int **)st_b, size_b);
				else
					ft_rotate_b((long int **)st_b, size_b);
			}
			else if (st_a[0][1] > range_min && st_a[0][1] > st_a[1][1] &&
						st_b[0][1] < st_b[1][1])
				ft_ss((long int **)st_a, size_a, (long int **)st_b, size_b);
		}
	}
	ft_help((long int **)st_a, size_a, (long int **)st_b, size_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:02:00 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/05 08:02:02 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/*Find the position of of the first smaller value??????????????????????????*/
long int	ft_find_smaller(long int **st_a, int size_a, long int index)
{
	long int	result;

	result = -1;
	while (--size_a >= 0)
	{
		if (st_a[size_a][1] < index && result == -1)
			result = size_a;
		else if (st_a[size_a][1] < index && st_a[size_a][1] > st_a[result][1])
			result = size_a;
	}
	return (result);
}

/*Find the position of of the first greater value??????????????????????????*/
long int	ft_find_greater(long int **st_a, int size_a, long int index)
{
	long int	result;

	result = -1;
	while (--size_a >= 0)
	{
		if (st_a[size_a][1] > index && result == -1)
			result = size_a;
		else if (st_a[size_a][1] > index && st_a[size_a][1] < st_a[result][1])
			result = size_a;
	}
	return (result);
}

/*Find the smallest value in the array*/
long int	ft_find_pos_min(long int **st_a, int size_a)
{
	int	i;
	int	pos_min;

	i = 0;
	if (size_a == 1)
		return (i);
	pos_min = i;
	while (++i < size_a)
		if (st_a[pos_min][0] > st_a[i][0])
			pos_min = i;
	return (pos_min);
}

/*Find the largest value in the array*/
long int	ft_find_pos_max(long int **st_a, int size_a)
{
	int	i;
	int	pos_max;

	i = 0;
	if (size_a == 1)
		return (i);
	pos_max = i;
	while (++i < size_a)
		if (st_a[pos_max][0] < st_a[i][0])
			pos_max = i;
	return (pos_max);
}

/*Function that calculate if rotate is faster than reverse rotate*/
long int	ft_cost_rot(long int **st_a, long int size_a, long int range)
{
	long int	top;
	long int	bottom;
	long int	i;

	i = 0;
	top = -1;
	bottom = -1;
	while ((i <= size_a / 2) && top == -1)
	{
		if (st_a[i][1] <= range && top == -1)
			top = i;
		i++;
	}
	i = size_a - 1;
	while ((i > size_a / 2) && bottom == -1)
	{
		if (st_a[i][1] <= range && bottom == -1)
			bottom = i;
		i--;
	}
	if (bottom > -1 && (size_a - 1 - bottom) < top)
		return (bottom);
	else if (top > -1)
		return (top);
	return (-1);
}

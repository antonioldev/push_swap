/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:57:21 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/05 08:57:23 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/*Function that take the argument and convert it in integer*/
long int	ft_to_int(char *nptr)
{
	long int	i;
	long int	neg;
	long long	result;

	i = 0;
	neg = 0;
	result = 0;
	if (*(nptr + i) == '+')
		i++;
	else if (*(nptr + i) == '-')
	{
		neg++;
		i++;
	}
	while (*(nptr + i) != '\0')
	{
		if ((*(nptr + i) < '0') || (*(nptr + i) > '9'))
			return (LONG_MAX);
		result *= 10;
		result += (*(nptr + i) - 48);
		i++;
	}
	if (neg == 1)
		result = -result;
	return (result);
}

/*--Check if there are duplicates or out of range values*/
int	ft_error(long int **st_a, int size_a)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while (i < size_a)
	{
		if ((st_a[i][0] < INT_MIN) || (st_a[i][0] > INT_MAX))
			check = -1;
		j = i + 1;
		while (j < size_a)
		{
			if ((st_a[i][0] == st_a[j][0]) ||
				(st_a[j][0] < INT_MIN) || (st_a[j][0] > INT_MAX))
				check = -1;
			j++;
		}
		i++;
	}
	if (check == 0)
		return (0);
	write(1, "Error\n", 6);
	return (-1);
}

/*--Check if the array is already sorted*/
int	ft_is_sorted(long int **stack, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (stack[i][0] > stack[i + 1][0])
			return (-1);
		i++;
	}
	return (0);
}

/*--Check if the array is reverse sorted*/
int	ft_is_reverse_sorted(long int **stack, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (stack[i][0] < stack[i + 1][0])
			return (-1);
		i++;
	}
	return (0);
}

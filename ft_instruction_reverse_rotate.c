/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_reverse_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:01:29 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/05 08:06:56 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*Shift down all elements of stack A by 1.
The last element becomes the first one*/
void	ft_reverse_rotate_a(long int **st_a, int size_a)
{
	int			i;
	long int	temp;
	long int	temp_index;

	i = size_a - 1;
	temp = st_a[i][0];
	temp_index = st_a[i][1];
	while (i > 0)
	{
		st_a[i][0] = st_a[i - 1][0];
		st_a[i][1] = st_a[i - 1][1];
		i--;
	}
	st_a[i][0] = temp;
	st_a[i][1] = temp_index;
	write (1, "rra\n", 4);
}

/*Shift down all elements of stack B by 1.
The last element becomes the first one*/
void	ft_reverse_rotate_b(long int **st_b, int size_b)
{
	int			i;
	long int	temp;
	long int	temp_index;

	i = size_b - 1;
	temp = st_b[i][0];
	temp_index = st_b[i][1];
	while (i > 0)
	{
		st_b[i][0] = st_b[i - 1][0];
		st_b[i][1] = st_b[i - 1][1];
		i--;
	}
	st_b[i][0] = temp;
	st_b[i][1] = temp_index;
	write (1, "rrb\n", 4);
}

/*Shift down all elements of stack A and B by 1.
The last element becomes the first one*/
void	ft_rrr(long int **st_a, int size_a, long int **st_b, int size_b)
{
	int			i;
	long int	temp[2];

	i = size_a;
	temp[0] = st_a[size_a - 1][0];
	temp[1] = st_a[size_a - 1][1];
	while (--i > 0)
	{
		st_a[i][0] = st_a[i - 1][0];
		st_a[i][1] = st_a[i - 1][1];
	}
	st_a[i][0] = temp[0];
	st_a[i][1] = temp[1];
	i = size_b;
	temp[0] = st_b[size_b - 1][0];
	temp[1] = st_b[size_b - 1][1];
	while (--i > 0)
	{
		st_b[i][0] = st_b[i - 1][0];
		st_b[i][1] = st_b[i - 1][1];
	}
	st_b[i][0] = temp[0];
	st_b[i][1] = temp[1];
	write (1, "rrr\n", 4);
}

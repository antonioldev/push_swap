/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:01:40 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/05 08:16:18 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* Shift up all elements of stack A by 1.
The first element becomes the last one.*/
void	ft_rotate_a(long int **st_a, int size_a)
{
	int			i;
	long int	temp;
	long int	temp_index;

	i = 0;
	temp = st_a[i][0];
	temp_index = st_a[i++][1];
	while (i < size_a)
	{
		st_a[i - 1][0] = st_a[i][0];
		st_a[i - 1][1] = st_a[i][1];
		i++;
	}
	st_a[i - 1][0] = temp;
	st_a[i - 1][1] = temp_index;
	write (1, "ra\n", 3);
}

/* Shift up all elements of stack B by 1.
The first element becomes the last one.*/
void	ft_rotate_b(long int **st_b, int size_b)
{
	int			i;
	long int	temp;
	long int	temp_index;

	i = 0;
	temp = st_b[i][0];
	temp_index = st_b[i++][1];
	while (i < size_b)
	{
		st_b[i - 1][0] = st_b[i][0];
		st_b[i - 1][1] = st_b[i][1];
		i++;
	}
	st_b[i - 1][0] = temp;
	st_b[i - 1][1] = temp_index;
	write (1, "rb\n", 3);
}

/* Shift up all elements of stack A and B by 1.
The first element becomes the last one.*/
void	ft_rr(long int **st_a, int size_a, long int **st_b, int size_b)
{
	int			i;
	long int	temp[2];

	i = 0;
	temp[0] = st_a[i][0];
	temp[1] = st_a[i][1];
	while (++i < size_a)
	{
		st_a[i - 1][0] = st_a[i][0];
		st_a[i - 1][1] = st_a[i][1];
	}
	st_a[i - 1][0] = temp[0];
	st_a[i - 1][1] = temp[1];
	i = 0;
	temp[0] = st_b[i][0];
	temp[1] = st_b[i][1];
	while (++i < size_b)
	{
		st_b[i - 1][0] = st_b[i][0];
		st_b[i - 1][1] = st_b[i][1];
	}
	st_b[i - 1][0] = temp[0];
	st_b[i -1][1] = temp[1];
	write (1, "rr\n", 3);
}

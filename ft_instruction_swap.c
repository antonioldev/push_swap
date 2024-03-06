/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:01:09 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/05 08:01:11 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*Swap the first 2 elements at the top of stack A.
Do nothing if there is only one or no elements*/
void	ft_swap_a(long int **st_a, int size_a)
{
	long int	temp;
	long int	temp_index;

	if (size_a >= 2)
	{
		temp = st_a[0][0];
		temp_index = st_a[0][1];
		st_a[0][0] = st_a[1][0];
		st_a[0][1] = st_a[1][1];
		st_a[1][0] = temp;
		st_a[1][1] = temp_index;
		write(1, "sa\n", 3);
	}
}

/*Swap the first 2 elements at the top of stack B.
Do nothing if there is only one or no elements*/
void	ft_swap_b(long int **st_b, int size_b)
{
	long int	temp;
	long int	temp_index;

	if (size_b >= 2)
	{
		temp = st_b[0][0];
		temp_index = st_b[0][1];
		st_b[0][0] = st_b[1][0];
		st_b[0][1] = st_b[1][1];
		st_b[1][0] = temp;
		st_b[1][1] = temp_index;
		write(1, "sb\n", 3);
	}
}

/*Swap the first 2 elements at the top of stack A and stack B.
Do nothing if there is only one or no elements*/
void	ft_ss(long int **st_a, int size_a, long int **st_b, int size_b)
{
	long int	temp;
	long int	temp_index;

	if (size_a >= 2)
	{
		temp = st_a[0][0];
		temp_index = st_a[0][1];
		st_a[0][0] = st_a[1][0];
		st_a[0][1] = st_a[1][1];
		st_a[1][0] = temp;
		st_a[1][1] = temp_index;
	}
	if (size_b >= 2)
	{
		temp = st_b[0][0];
		temp_index = st_b[0][1];
		st_b[0][0] = st_b[1][0];
		st_b[0][1] = st_b[1][1];
		st_b[1][0] = temp;
		st_b[1][1] = temp_index;
	}
	write (1, "ss\n", 3);
}

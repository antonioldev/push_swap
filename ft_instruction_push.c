/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:01:00 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/05 08:01:04 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/* Take the first element at the top of B and put it at the top of A.
Do nothing if b is empty*/
void	ft_pa(long int **st_a, int *size_a,
		long int **st_b, int *size_b)
{
	int	i;

	i = *size_a;
	if (*size_b > 0)
	{
		while (i > 0)
		{
			st_a[i][0] = st_a[i - 1][0];
			st_a[i][1] = st_a[i - 1][1];
			i--;
		}
		st_a[i][0] = st_b[i][0];
		st_a[i][1] = st_b[i][1];
		i++;
		while (i < *size_b)
		{
			st_b[i - 1][0] = st_b[i][0];
			st_b[i - 1][1] = st_b[i][1];
			i++;
		}
		*size_a += 1;
		*size_b -= 1;
		write(1, "pa\n", 3);
	}
}

/* Take the first element at the top of A and put it at the top of B.
Do nothing if a is empty*/
void	ft_pb(long int **st_a, int *size_a,
		long int **st_b, int *size_b)
{
	int	i;

	i = *size_b;
	if (*size_a > 0)
	{
		while (i > 0)
		{
			st_b[i][0] = st_b[i - 1][0];
			st_b[i][1] = st_b[i - 1][1];
			i--;
		}
		st_b[i][0] = st_a[i][0];
		st_b[i][1] = st_a[i][1];
		i++;
		while (i < *size_a)
		{
			st_a[i - 1][0] = st_a[i][0];
			st_a[i - 1][1] = st_a[i][1];
			i++;
		}
		*size_b += 1;
		*size_a -= 1;
		write(1, "pb\n", 3);
	}
}

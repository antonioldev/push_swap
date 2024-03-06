/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:01:21 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/05 08:01:23 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*Function that take the arguments, fill stack A with converted integer*/
static long int	**ft_fill_st_a(int size_a, char **argv)
{
	int			i;
	long int	**st_a;

	i = 0;
	st_a = (long int **)malloc(size_a * sizeof(long int *));
	if (!st_a)
		return (NULL);
	while (i < size_a)
	{
		st_a[i] = (long int *)malloc(2 * sizeof(long int));
		st_a[i][0] = ft_to_int(argv[i + 1]);
		i++;
	}
	return (st_a);
}

/*--Function that allocate memory for stack B*/
static long int	**ft_fill_st_b(int size_a)
{
	int			i;
	long int	**st_b;

	i = 0;
	st_b = (long int **)malloc(size_a * sizeof(long int *));
	if (!st_b)
		return (NULL);
	while (i < size_a)
	{
		st_b[i] = (long int *)malloc(2 * sizeof(long int));
		i++;
	}
	return (st_b);
}

static void	ft_find_index(long int **st_a, int size_a)
{
	int	smaller;
	int	i;
	int	j;

	i = 0;
	while (i < size_a)
	{
		smaller = 0;
		j = 0;
		while (j < size_a)
		{
			if (j != i && (st_a[j][0] < st_a[i][0]))
				smaller++;
			j++;
		}
		st_a[i][1] = smaller;
		i++;
	}
}

static void	ft_free(long int **st, int st_count)
{
	int	i;

	i = 0;
	while (i < st_count)
	{
		free(st[i]);
		i++;
	}
	free(st);
}

/*--using 2D array & Integer sorts are sometimes called counting sorts*/
int	main(int argc, char **argv)
{
	long int	**st_a;
	long int	**st_b;

	if (argc < 2)
		return (0);
	st_a = ft_fill_st_a(argc - 1, argv);
	if ((ft_error(st_a, argc - 1) != -1)
		&& ft_is_sorted(st_a, argc - 1) == -1)
	{
		ft_find_index(st_a, argc - 1);
		st_b = ft_fill_st_b(argc - 1);
		if (ft_is_reverse_sorted(st_a, argc - 1) == 0 && argc - 1 > 3)
			ft_solution_reverse(st_a, argc - 1, st_b, 0);
		else if (argc - 1 <= 3)
			ft_solution_s(st_a, argc - 1);
		else if (argc - 1 <= 5)
			ft_solution_m(st_a, argc - 1, st_b, 0);
		else if (argc - 1 <= 100)
			ft_solution_l(st_a, argc - 1, st_b, 0);
		else
			ft_solution_xl(st_a, argc - 1, st_b, 0);
		ft_free(st_b, argc - 1);
	}
	ft_free(st_a, argc - 1);
	return (0);
}

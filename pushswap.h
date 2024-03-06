/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:02:18 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/05 09:11:36 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

long int	ft_find_smaller(long int **st_a, int size_a, long int index);
long int	ft_find_greater(long int **st_a, int size_a, long int index);
long int	ft_cost_rot(long int **st_a, long int size_a, long int range);
long int	ft_find_pos_min(long int **st_a, int size_a);
long int	ft_find_pos_max(long int **st_a, int size_a);
long int	ft_to_int(char *nptr);
int			main(int argc, char **argv);
int			ft_error(long int **st_a, int size_a);
int			ft_is_sorted(long int **stack, int count);
int			ft_is_reverse_sorted(long int **stack, int count);
void		ft_solution_reverse(long int **st_a, int size_a,
				long int **st_b, int size_b);
void		ft_solution_s(long int **st_a, int size_a);
void		ft_solution_m(long int **st_a, int size_a,
				long int **st_b, int size_b);
void		ft_solution_l(long int **st_a, int size_a,
				long int **st_b, int size_b);
void		ft_solution_xl(long int **st_a, int size_a,
				long int **st_b, int size_b);
void		ft_swap_a(long int **st_a, int size_a);
void		ft_swap_b(long int **st_b, int size_b);
void		ft_ss(long int **st_a, int size_a,
				long int **st_b, int size_b);
void		ft_pa(long int **st_a, int *size_a,
				long int **st_b, int *size_b);
void		ft_pb(long int **st_a, int *size_a,
				long int **st_b, int *size_b);
void		ft_rotate_a(long int **st_a, int size_a);
void		ft_rotate_b(long int **st_b, int size_b);
void		ft_rr(long int **st_a, int size_a,
				long int **st_b, int size_b);
void		ft_reverse_rotate_a(long int **st_a, int size_a);
void		ft_reverse_rotate_b(long int **st_b, int size_b);
void		ft_rrr(long int **st_a, int size_a,
				long int **st_b, int size_b);
#endif

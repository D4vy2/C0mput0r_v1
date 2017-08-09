/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:19:07 by dea               #+#    #+#             */
/*   Updated: 2015/06/13 14:29:02 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

static void	ft_usage(char *s)
{
	if (0 == ft_strcmp(s, "-h"))
	{
		ft_putstr("\nusage: [coeff] ['*'] ['X^'][nb] -opt[operator]");
		ft_putstr("->repeat ['=']");
		ft_putstr(" [coeff] ['*'] ['X^'][nb]\n\n  h : help syntax\n\n");
		exit(0);
	}
}

int			main(int argc, char **argv)
{
	t_data	e;
	char	**split;
	char	*save;
	char	*final;

	if (argc != 2)
	{
		ft_putstr("\033[0;31mInvalid argument!\n");
		return (0);
	}
	ft_usage(argv[1]);
	ft_error(argv[1]);
	ft_putchar('\n');
	ft_putstr("\n\033[1;34mOriginal form: \033[0;m");
	ft_putstr(argv[1]);
	e.original_str = ft_strdup(argv[1]);
	ft_init(&e);
	split = ft_split_and_sort(&e);
	save = ft_return_str_by_split(&e, e.nb_pow, split, e.f_tab);
	final = ft_final_str(&e);
	ft_polynomial_degree(save, &e);
	ft_calcul_delta(&e);
	return (0);
}

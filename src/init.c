/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:53:20 by dea               #+#    #+#             */
/*   Updated: 2015/06/12 21:32:47 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

void	ft_init(t_data *e)
{
	e->a = 0;
	e->b = 0;
	e->c = 0;
	e->polynomial = 0;
	e->nospace_str = ft_nospace(e->original_str);
	e->respace_str = ft_respace(e->nospace_str);
	e->reduce_str = ft_reduce_form(e->respace_str);
	e->nb_pow = ft_count_pow(e->reduce_str);
}

char	**ft_split_and_sort(t_data *e)
{
	int		i;
	char	**split;
	double	*tab;

	i = 0;
	tab = ft_return_powtab(e->reduce_str);
	sort_double_tab(tab, e->nb_pow);
	e->nb_pow_diff = erase_double(tab, e->nb_pow);
	if (NULL == (e->f_tab = (double*)malloc(sizeof(double) * e->nb_pow_diff)))
		return (NULL);
	split = ft_strsplit(e->reduce_str, ' ');
	sort_array_by_pow(split, e->nb_pow);
	return (split);
}

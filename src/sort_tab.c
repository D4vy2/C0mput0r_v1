/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 14:32:07 by dea               #+#    #+#             */
/*   Updated: 2015/06/12 16:06:21 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

void		sort_double_tab(double *tab, int size)
{
	int		i;
	double	temp;

	i = 0;
	temp = 0;
	while (i < size - 1)
	{
		if (tab[i] <= tab[i + 1])
			i++;
		else
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
	}
}

static void	strswap(char **s1, char **s2)
{
	char	*temp;

	temp = ft_strdup(*s1);
	free(*s1);
	*s1 = ft_strdup(*s2);
	free(*s2);
	*s2 = temp;
}

void		sort_array_by_pow(char **tab, int size)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size - 1)
	{
		j = 0;
		k = 0;
		while (tab[i][j] != '^')
			j++;
		while (tab[i + 1][k] != '^')
			k++;
		j++, k++;
		if (atof(&tab[i][j]) <= atof(&tab[i + 1][k]))
			i++;
		else
		{
			strswap(&tab[i], &tab[i + 1]);
			i = 0;
		}
	}
}

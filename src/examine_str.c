/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examine_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 16:20:02 by dea               #+#    #+#             */
/*   Updated: 2015/06/12 13:24:37 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

int		ft_is_neg(char *s)
{
	int i;

	i = 0;
	while (s[i] && (0 == ft_isdigit(s[i])))
	{
		if (s[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_pow(char *s)
{
	int i;
	int pow;

	i = 0;
	pow = 0;
	while (s[i])
	{
		if (s[i] == '^')
			pow++;
		i++;
	}
	return (pow);
}

double	*ft_return_powtab(char *s)
{
	int		i;
	int		n;
	double	*tab;
	int		index;

	i = 0;
	n = 0;
	index = 0;
	if (NULL == (tab = (double*)malloc(sizeof(double) * ft_count_pow(s))))
		return (NULL);
	while (i < ft_count_pow(s))
		tab[i++] = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != '^' && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		i++;
		tab[index++] = atof(&s[i]);
		i++;
	}
	return (tab);
}

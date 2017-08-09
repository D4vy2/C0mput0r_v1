/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 12:57:31 by dea               #+#    #+#             */
/*   Updated: 2015/06/12 16:02:27 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

double		ft_return_pow(char *s)
{
	int		i;
	double	pow;

	i = 0;
	pow = 0;
	while (s[i])
	{
		while (s[i] != '^')
			i++;
		i++;
		pow = atof(&s[i]);
		break ;
	}
	return (pow);
}

double		ft_return_coeff(char *s)
{
	double coeff;

	coeff = atof(s);
	return (coeff);
}

size_t		erase_double(double *tab, size_t len)
{
	double *read;
	double *write;

	read = tab + 1;
	write = tab;
	while (read < tab + len)
	{
		if (*read != *write)
			*++write = *read;
		read++;
	}
	return (write - tab + 1);
}

double		ft_calcul_tab(char **tab, double pow)
{
	int		i;
	double	save;

	i = 0;
	save = 0;
	while (tab[i] != NULL)
	{
		if (ft_return_pow(tab[i]) == pow)
			save += ft_return_coeff(tab[i]);
		i++;
	}
	return (save);
}

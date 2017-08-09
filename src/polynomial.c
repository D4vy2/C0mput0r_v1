/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 14:27:29 by dea               #+#    #+#             */
/*   Updated: 2015/06/13 17:20:01 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

static void	ft_greater(int max)
{
	if (max > 2)
	{
		ft_putstr("The polynomial degree is stricly greater than 2, ");
		ft_putstr("I can't solve.\n\n");
		exit(0);
	}
}

void		ft_polynomial_degree(char *s, t_data *e)
{
	int max;
	int i;

	i = 0;
	max = 0;
	while (s[i])
	{
		while (s[i] != '^' && s[i])
			i++;
		i++;
		if (atoi(&(s[i])) > max)
			max = atoi(&(s[i]));
		i++;
	}
	if (max > 2)
		ft_putstr("\033[0;31m\nPolynomial degree: ");
	else
		ft_putstr("\033[0;32m\nPolynomial degree: ");
	ft_putnbr(max);
	e->polynomial = max;
	ft_putstr("\033[0;m\n\n");
	ft_greater(max);
}

static char	*ft_flash(char *s)
{
	int i = 0;
	int j = 0;
	char *f;

	if (NULL == (f = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == '0' && (1 == ft_isdigit(s[i - 1]) && s[i - 1] != 0))
		{
			while (s[i] == '0' && s[i])
				i++;
		}
		f[j++] = s[i++];
	}
	f[j] = '\0';
	return (f);
}

static int	ft_only_zero(char *s)
{
	int i;

	i = 1;
	while (s[i] != ' ' && s[i])
	{
		if (s[i] != '0' && s[i])
			return (0);
		i++;
	}
	return (1);
}

void		ft_reform_pt(t_data *e, int i, int j, char *final)
{
	while (e->save[i])
	{
		if (e->save[i] == '.')
		{
			if (1 == ft_only_zero(&e->save[i]))
			{
				while (e->save[i] != ' ' && e->save[i])
					i++;
			}
		}
		if (e->save[i] == '-' && i > 1)
		{
			final[j++] = e->save[i++];
			final[j++] = ' ';
		}
		final[j++] = e->save[i++];
	}
	final[j] = '\0';
}

char		*ft_final_str(t_data *e)
{
	int		len;
	char	*final;
	int		i;
	int		j;
	char 	*flash;

	i = 0;
	j = 0;
	len = ft_strlen(e->save);
	if (NULL == (final = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((e->save[i] != '-' && 0 == ft_isdigit(e->save[i])) && e->save[i])
		i++;
	ft_reform_pt(e, i, j, final);
	flash = ft_flash(final);
	ft_putstr("\n\033[1;34mReduced form: \033[0;m");
	ft_putstr(flash);
	ft_putchar('\n');
	return (final);
}

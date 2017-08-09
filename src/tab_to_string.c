/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 16:49:25 by dea               #+#    #+#             */
/*   Updated: 2015/06/13 14:39:55 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

void	ft_fill_coeff(t_data *e, int z)
{
	if (e->pow == 2)
		e->a = e->f_tab[z];
	else if (e->pow == 1)
		e->b = e->f_tab[z];
	else if (e->pow == 0)
		e->c = e->f_tab[z];
}

char	*ft_create_str(t_data *e, double d)
{
	char *new;
	char *new2;

	sprintf(e->buf, "%f", d);
	if (d >= 0)
	{
		new2 = "+ ";
		new = ft_strjoin(new2, e->buf);
	}
	else
		new = e->buf;
	new2 = ft_strjoin(new, " * X^");
	new = ft_strjoin(new2, ft_itoa(e->pow));
	free(new2);
	new2 = ft_strjoin(new, " ");
	free(new);
	return (new2);
}

char	*ft_return_str_by_split(t_data *e, int len, char **split, double *f_tab)
{
	int		i;
	int		z;
	char	*first_str;

	i = 0;
	z = 0;
	e->pow = -1;
	while (i < len)
	{
		if (e->pow != ft_return_pow(split[i]))
		{
			e->pow = ft_return_pow(split[i]);
			f_tab[z] = ft_calcul_tab(split, e->pow);
			ft_fill_coeff(e, z);
			first_str = ft_create_str(e, f_tab[z]);
			if (z > 0)
				e->save = ft_strjoin(e->save, first_str);
			else
				e->save = ft_strdup(first_str);
			z++;
		}
		i++;
	}
	e->save = ft_strjoin(e->save, "= 0");
	return (e->save);
}

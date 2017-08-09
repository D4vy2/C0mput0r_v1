/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 16:57:50 by dea               #+#    #+#             */
/*   Updated: 2015/06/13 14:32:32 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

void	ft_check_before(t_data *e)
{
	if ((e->b != 0 && e->c != 0) && e->a == 0)
	{
		e->x3 = -e->c / e->b;
		ft_putstr("\033[0;33mThe solution is: \n\n");
		printf("%f\n\n", e->x3);
		exit(0);
	}
	else if (e->a == 0 && e->b == 0 && e->c == 0)
	{
		ft_putstr("All real numbers are solutions.\n\n");
		exit(0);
	}
	else if ((e->a == 0 && e->b == 0) && e->c != 0)
	{
		ft_putstr("Impossible to solve, there is no solution.\n\n");
		exit(0);
	}
}

double	ft_sqrt(double n)
{
	double	a;
	double	x;
	int		i;

	a = n;
	i = 0;
	x = 1;
	while (i < n)
	{
		x = 0.5 * (x + a / x);
		i++;
	}
	return (x);
}

double	ft_pow(double nb, int pow)
{
	int		i;
	double	mul;

	i = 1;
	mul = nb;
	if (pow == 0)
		return (1);
	while (i < pow)
	{
		nb *= mul;
		i++;
	}
	return (nb);
}

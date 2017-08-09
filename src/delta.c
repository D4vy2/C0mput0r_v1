/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 15:23:16 by dea               #+#    #+#             */
/*   Updated: 2015/06/13 14:30:08 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

void	ft_calcul_delta(t_data *e)
{
	ft_check_before(e);
	e->delta = (e->b * e->b) - (4 * e->a * e->c);
	if (e->delta == 0)
	{
		ft_putstr("\033[0;mDiscriminant is nul, there is an unique ");
		ft_putstr("solution:\n\n\033[0;33m");
		ft_delta_nul(e);
	}
	else if (e->delta > 0)
	{
		ft_putstr("\033[0;mDiscriminant is strictly positive, ");
		ft_putstr("the two solutions are:\n\n\033[0;33m");
		ft_delta_positive(e);
	}
	else if (e->delta < 0)
	{
		ft_putstr("\033[0;mDiscriminant is strictly negative, ");
		ft_putstr("there is two complex solutions:\n\n\033[0;33m");
		ft_delta_neg(e);
	}
}

void	ft_delta_positive(t_data *e)
{
	e->x1 = (-e->b - ft_sqrt(e->delta)) / (2 * e->a);
	e->x2 = (-e->b + ft_sqrt(e->delta)) / (2 * e->a);
	printf("x1 = (-b - sqrt(delta)) / (2 * a)\n");
	printf("x2 = (-b + sqrt(delta)) / (2 * a)\n\n");
	printf("x1 = -(%f) - sqrt(%f) / (2 * %f)\n", e->b, e->delta, e->a);
	printf("x2 = -(%f) + sqrt(%f) / (2 * %f)\n\n", e->b, e->delta, e->a);
	printf("x1 = %f\n", e->x1);
	printf("x2 = %f\n\n", e->x2);
}

void	ft_delta_nul(t_data *e)
{
	if (e->a == 0)
		e->x3 = -e->c / e->b;
	else
	{
		e->x3 = (-e->b / (2 * e->a));
		printf("x = -b / (2 * a)\n\n");
		printf("x = %f / (2 * (%f))\n\n", -e->b, e->a);
	}
	printf("x = %f\n\n", e->x3);
}

void	ft_delta_neg(t_data *e)
{
	double abs;

	abs = 0;
	if (e->delta < 0)
		abs = -e->delta;
	else
		abs = e->delta;
	abs = ft_sqrt(abs);
	printf("x1 = (-b - i * sqrt(delta)) / (2 * a)\n");
	printf("x2 = (-b + i * sqrt(delta)) / (2 * a)\n\n");
	printf("x1 = (%f - i * sqrt(%f)) / (2 * %f)\n", -e->b, e->delta, e->a);
	printf("x2 = (%f + i * sqrt(%f)) / (2 * %f)\n\n", -e->b, e->delta, e->a);
	printf("x1 = (%f - i * %f) / %f\n", -e->b, abs, e->a * 2);
	printf("x2 = (%f + i * %f) / %f\n\n", -e->b, abs, e->a * 2);
}

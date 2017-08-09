/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 13:00:46 by dea               #+#    #+#             */
/*   Updated: 2015/06/13 15:33:35 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

void	ft_error(char *s)
{
	ft_check_beggining(s);
	ft_check_character(s);
	ft_check_end(s);
	ft_check_x_and_equal(s);
	ft_check_double_sign(s);
	ft_check_pow(s);
	ft_check_mul(s);
	ft_check_moins(s);
	ft_check_x_bef(s);
	ft_check_equal_bef(s);
}

void	ft_display_error(void)
{
	ft_putstr("\033[0;31mInvalid syntax!\n");
	exit(0);
}

void	ft_check_x_and_equal(char *s)
{
	int i;
	int x;
	int equ;

	i = 0;
	x = 0;
	equ = 0;
	while (s[i])
	{
		if (s[i] == 'X')
		{
			x = 1;
			if ((s[i - 1] != ' ' && 0 == ft_isdigit(s[i - 1])) ||
				s[i + 1] != '^')
				ft_display_error();
		}
		else if (s[i] == '=')
			equ++;
		i++;
	}
	if (x == 0 || equ != 1)
		ft_display_error();
}

void	ft_check_equal_bef(char *s)
{
	int i;
	int equ;

	i = 0;
	equ = 0;
	while (s[i] != '=' && s[i])
	{
		if (s[i] == 'X')
			equ = 1;
		i++;
	}
	if (equ == 0)
		ft_display_error();
}

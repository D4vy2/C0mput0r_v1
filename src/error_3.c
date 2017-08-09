/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 13:03:05 by dea               #+#    #+#             */
/*   Updated: 2015/06/12 13:19:00 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

void	ft_check_mul(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '*')
		{
			if (s[i - 1] != ' ' || s[i + 1] != ' ')
				ft_display_error();
		}
		i++;
	}
}

void	ft_check_end(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	i--;
	if (1 == ft_isdigit(s[i]))
	{
		ft_putchar(s[i - 1] != '^');
		if (s[i - 1] != '^')
			ft_display_error();
	}
	else if (0 == ft_isdigit(s[i]))
		ft_display_error();
}

void	ft_check_double_sign(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (1 == ft_issign(s[i]))
		{
			if (s[i + 1] == ' ')
			{
				if (s[i + 2] != 'X' && 0 == ft_isdigit(s[i + 2]))
				{
					if (s[i] == '=' && s[i + 2] == '-')
					{
						i++;
						continue;
					}
					ft_display_error();
				}
			}
			else if (1 == ft_issign(s[i + 1]))
				ft_display_error();
		}
		i++;
	}
}

void	ft_check_beggining(char *s)
{
	int i;

	i = 0;
	if (s[i] != '-' && 0 == ft_isdigit(s[i]))
		ft_display_error();
}

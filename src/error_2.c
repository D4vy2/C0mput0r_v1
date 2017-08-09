/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 13:00:15 by dea               #+#    #+#             */
/*   Updated: 2015/06/12 13:17:24 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

void	ft_check_character(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (0 == ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '*' &&
			s[i] != 'X' && s[i] != '^' && s[i] != '=' &&
			s[i] != '+' && s[i] != '-' && s[i] != '.')
		{
			ft_display_error();
		}
		i++;
	}
}

void	ft_check_x_bef(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != 'X' && s[i])
			i++;
		j = i;
		i--;
		if (s[i] == ' ' && s[i])
		{
			i--;
			if (s[i] != '*' && s[i])
				ft_display_error();
		}
		i = j;
		i++;
	}
}

int		ft_issign(char c)
{
	if (c == '+' || c == '-' || c == '^' || c == '*' || c == '=')
		return (1);
	else
		return (0);
}

void	ft_check_pow(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '^')
		{
			if (s[i - 1] != 'X' || 0 == ft_isdigit(s[i + 1]))
				ft_display_error();
			i++;
			while (s[i] != ' ' && s[i])
			{
				if (0 == ft_isdigit(s[i]))
					ft_display_error();
				i++;
			}
		}
		i++;
	}
}

void	ft_check_moins(char *s)
{
	int i;

	i = 0;
	while (s[i] != '=')
		i++;
	while (0 == ft_isdigit(s[i]))
	{
		if (s[i] == '-')
		{
			if (0 == ft_isdigit(s[i + 1]))
				ft_display_error();
		}
		i++;
	}
}

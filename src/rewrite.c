/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:18:58 by dea               #+#    #+#             */
/*   Updated: 2015/06/12 21:40:44 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cv1.h"

char	*ft_nospace(char *s)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			j++;
		i++;
	}
	if (NULL == (dup = (char*)malloc(sizeof(char) * (ft_strlen(s) - j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i])
			dup[j++] = s[i];
		i++;
	}
	dup[j] = '\0';
	return (dup);
}

int		ft_count_sign(char *dup)
{
	int i;
	int sign;

	i = 0;
	sign = 0;
	while (dup[i])
	{
		if (dup[i] == '+' || dup[i] == '-' || dup[i] == '=')
			sign++;
		i++;
	}
	return (sign);
}

char	*ft_respace(char *dup)
{
	char	*f;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(dup) + ft_count_sign(dup);
	if (NULL == (f = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (dup[i])
	{
		if ((dup[i] == '+' || dup[i] == '-') && dup[i] && i != 0)
			f[j++] = ' ';
		else if (dup[i] == '=' && dup[i])
		{
			f[j++] = dup[i++];
			f[j++] = ' ';
		}
		f[j++] = dup[i++];
	}
	f[j] = '\0';
	return (f);
}

void	ft_change_sign(char *s, char *re, int i, int j)
{
	while (s[i])
	{
		while (s[i] != '=')
			re[j++] = s[i++];
		re[j++] = ' ';
		i++;
		while (s[i] == ' ')
			i++;
		re[j] = (1 == ft_isdigit(s[i])) ? '-' : ' ';
		j++;
		while (s[i])
		{
			if (s[i] == '+' && s[i++])
				re[j++] = '-';
			else if (s[i] == '-' && s[i++])
				re[j++] = '+';
			re[j++] = s[i++];
		}
	}
	re[j] = '\0';
}

char	*ft_reduce_form(char *s)
{
	int		i;
	int		j;
	char	*re;

	i = 0;
	j = 0;
	if (NULL == (re = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	ft_change_sign(s, re, i, j);
	return (re);
}

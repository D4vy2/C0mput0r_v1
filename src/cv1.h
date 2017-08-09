/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 16:10:06 by dea               #+#    #+#             */
/*   Updated: 2015/06/13 15:34:13 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CV1_H
# define CV1_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct	s_data
{
	double		a;
	double		b;
	double		c;
	char		**tab;
	double		*f_tab;
	int			nb_pow;
	int			nb_pow_diff;
	double		pow;
	char		*original_str;
	char		*nospace_str;
	char		*respace_str;
	char		*reduce_str;
	char		*save;
	char		*final;
	int			polynomial;
	double		delta;
	double		x1;
	double		x2;
	double		x3;
	char		buf[2048];
}				t_data;

double			*ft_return_powtab(char *s);
int				ft_count_pow(char *s);
int				ft_is_neg(char *s);

void			ft_init(t_data *e);
char			*ft_create_str(t_data *e, double d);

void			ft_error(char *s);
void			ft_check_x_and_equal(char *s);
void			ft_display_error(void);
void			ft_check_equal_bef(char *s);

void			ft_check_double_sign(char *s);
void			ft_check_end(char *s);
void			ft_check_mul(char *s);
void			ft_check_beggining(char *s);

void			ft_check_character(char *s);
int				ft_issign(char c);
void			ft_check_x_bef(char *s);
void			ft_check_pow(char *s);
void			ft_check_moins(char *s);

char			*ft_nospace(char *s);
int				ft_count_sign(char *dup);
char			*ft_respace(char *dup);
char			*ft_reduce_form(char *s);
void			ft_change_sign(char *s, char *re, int i, int j);

void			ft_polynomial_degree(char *s, t_data *e);
char			*ft_final_str(t_data *e);
void			ft_reform_pt(t_data *e, int i, int j, char *final);

void			sort_double_tab(double *tab, int size);
void			sort_array_by_pow(char **tab, int size);

double			ft_return_pow(char *s);
double			ft_return_coeff(char *s);
double			ft_calcul_tab(char **tab, double pow);
size_t			erase_double(double *tab, size_t len);

void			ft_fill_coeff(t_data *e, int z);
char			*ft_return_str_by_split(t_data *e, int l, char **t, double *f);
char			*ft_create_str(t_data *e, double d);

char			*ft_reduce_save(char *s);
char			**ft_split_and_sort(t_data *e);

double			ft_sqrt(double n);
double			ft_pow(double nb, int pow);
void			ft_check_before(t_data *e);
void			ft_calcul_delta(t_data *e);

void			ft_delta_positive(t_data *e);
void			ft_delta_nul(t_data *e);
void			ft_delta_neg(t_data *e);
#endif

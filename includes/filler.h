/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:14:29 by myarovoy          #+#    #+#             */
/*   Updated: 2018/07/03 16:14:31 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../src/libft/includes/libft.h"
# include <stdlib.h>

typedef struct	s_fpiece
{
	char		*figure;
	int			x_offset;
	int			y_offset;
	int			x_size;
	int			y_size;
	int			ty_size;
}				t_fpiece;

typedef struct	s_fplayg
{
	char		*play_grnd;
	int			x_size;
	int			y_size;
	int			smbl;
	int			curr_i;
}				t_fplayg;

typedef struct	s_algo
{
	int			smbl;
	int			(*f)(t_fpiece *, t_fplayg *);
}				t_algo;

void			ft_get_next_figure(t_fpiece *figure);
void			ft_get_next_playg(t_fplayg *playg);
void			ft_get_player(t_fplayg *play_smbl, t_fpiece *figure);
void			ft_get_offsetof_figure(t_fpiece *figure);
void			ft_get_tsizeof_figure(t_fpiece *figure);
int				ft_parse_playg_x(t_fpiece *figure, t_fplayg *playg);
int				ft_parse_playg_o(t_fpiece *figure, t_fplayg *playg);
int				ft_place_figure_x(t_fpiece *figure, t_fplayg *playg, \
									int pl, int y);
int				ft_place_figure_o(t_fpiece *figure, t_fplayg *playg, \
									int pl, int y);
int				ft_print_res_x(t_fpiece *figure, t_fplayg *playg, \
									int same, int y);
int				ft_print_res_o(t_fpiece *figure, t_fplayg *playg, \
									int same, int y);
void			ft_unify_smbls(t_fplayg *playg);
void			ft_clear_structs(t_fpiece *figure, t_fplayg *playg);

#endif

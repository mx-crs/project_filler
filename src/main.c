/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:42:30 by myarovoy          #+#    #+#             */
/*   Updated: 2018/09/16 15:42:32 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_algo	g_take_algo[] =
{
	{'X', &ft_parse_playg_x},
	{'O', &ft_parse_playg_o}
};

int		ft_parse_playg_o(t_fpiece *figure, t_fplayg *playg)
{
	int		i;
	int		y;

	y = 0;
	i = (int)ft_strlen(playg->play_grnd);
	while (i > 1)
	{
		playg->curr_i = i;
		if (playg->play_grnd[i] == '\n')
			y++;
		if (ft_place_figure_o(figure, playg, i, y) == 1)
			return (1);
		i--;
	}
	ft_printf("%d %d\n", 0, 0);
	return (0);
}

int		ft_parse_playg_x(t_fpiece *figure, t_fplayg *playg)
{
	int		i;
	int		y;

	y = 0;
	i = 0;
	while (playg->play_grnd[i] != '\0')
	{
		playg->curr_i = i;
		if (playg->play_grnd[i] == '\n')
			y++;
		if (ft_place_figure_x(figure, playg, i, y) == 1)
			return (1);
		i++;
	}
	ft_printf("%d %d\n", 0, 0);
	return (0);
}

int		main(void)
{
	t_fpiece	figure;
	t_fplayg	playg;
	int			s;

	ft_get_player(&playg, &figure);
	s = (playg.smbl == g_take_algo[0].smbl) ? 0 : 1;
	while (1)
	{
		ft_get_next_playg(&playg);
		ft_get_next_figure(&figure);
		if (g_take_algo[s].f(&figure, &playg) == 0)
			break ;
		ft_clear_structs(&figure, &playg);
	}
	ft_clear_structs(&figure, &playg);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:41:44 by myarovoy          #+#    #+#             */
/*   Updated: 2018/09/10 17:41:46 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_get_next_figure(t_fpiece *figure)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	figure->y_size = ft_atoi(line + 6);
	figure->x_size = ft_atoi(line + 8) + 1;
	figure->figure = ft_strnew(figure->y_size *
								figure->x_size + figure->y_size + 1);
	while (i < figure->y_size)
	{
		get_next_line(0, &line);
		ft_strncat(figure->figure, line, ft_strlen(line));
		ft_strncat(figure->figure, "\n", 1);
		i++;
	}
	ft_get_offsetof_figure(figure);
}

void	ft_get_next_playg(t_fplayg *playg)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	playg->y_size = ft_atoi(line + 8);
	playg->x_size = ft_atoi(line + 11) + 1;
	playg->play_grnd = ft_strnew(playg->y_size *
								playg->x_size + playg->y_size + 1);
	get_next_line(0, &line);
	while (i < playg->y_size)
	{
		get_next_line(0, &line);
		ft_strncat(playg->play_grnd, line + 4, ft_strlen(line) - 4);
		ft_strncat(playg->play_grnd, "\n", 1);
		i++;
	}
	ft_unify_smbls(playg);
}

void	ft_get_player(t_fplayg *play_smbl, t_fpiece *figure)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	play_smbl->smbl = (line[10] == '1') ? 'O' : 'X';
	play_smbl->play_grnd = NULL;
	figure->figure = NULL;
}

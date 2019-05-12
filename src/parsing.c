/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:25:56 by myarovoy          #+#    #+#             */
/*   Updated: 2018/09/19 19:25:57 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_print_res_x(t_fpiece *figure, t_fplayg *playg, int same, int y)
{
	if (same == 1)
	{
		ft_printf("%d %d\n", y - figure->y_offset,
							playg->curr_i % playg->x_size - figure->x_offset);
		return (1);
	}
	return (0);
}

int		ft_print_res_o(t_fpiece *figure, t_fplayg *playg, int same, int y)
{
	if (same == 1)
	{
		ft_printf("%d %d\n", playg->y_size - y - figure->y_offset,
							playg->curr_i % playg->x_size - figure->x_offset);
		return (1);
	}
	return (0);
}

int		ft_place_figure_x(t_fpiece *figure, t_fplayg *playg, int pl, int y)
{
	int		same;
	int		fi;

	same = 0;
	fi = figure->y_offset * figure->x_size + figure->x_offset;
	if (playg->y_size - y < figure->ty_size)
		return (0);
	while (figure->figure[fi] != '\0')
	{
		if (figure->figure[fi] == '*' && playg->play_grnd[pl] == playg->smbl)
			same++;
		if (figure->figure[fi] == '*' && (playg->play_grnd[pl] !=
		playg->smbl && playg->play_grnd[pl] != '.'))
			return (0);
		if (figure->figure[fi] == '\n' && figure->figure[fi + 1] != '\0')
		{
			fi += figure->x_offset;
			pl += playg->x_size - figure->x_size + figure->x_offset + 1;
		}
		else if (figure->figure[fi + 1] != '\0')
			pl++;
		fi++;
	}
	return (ft_print_res_x(figure, playg, same, y));
}

int		ft_place_figure_o(t_fpiece *figure, t_fplayg *playg, int pl, int y)
{
	int		same;
	int		fi;

	same = 0;
	fi = figure->y_offset * figure->x_size + figure->x_offset;
	if (y < figure->ty_size)
		return (0);
	while (figure->figure[fi] != '\0')
	{
		if (figure->figure[fi] == '*' && playg->play_grnd[pl] == playg->smbl)
			same++;
		if (figure->figure[fi] == '*' && (playg->play_grnd[pl] !=
		playg->smbl && playg->play_grnd[pl] != '.'))
			return (0);
		if (figure->figure[fi] == '\n' && figure->figure[fi + 1] != '\0')
		{
			fi += figure->x_offset;
			pl += playg->x_size - figure->x_size + figure->x_offset + 1;
		}
		else if (figure->figure[fi + 1] != '\0')
			pl++;
		fi++;
	}
	return (ft_print_res_o(figure, playg, same, y));
}

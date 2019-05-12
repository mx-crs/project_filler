/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:43:48 by myarovoy          #+#    #+#             */
/*   Updated: 2018/09/10 17:43:49 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_get_tsizeof_figure(t_fpiece *figure)
{
	int		i;
	char	*tmp;

	i = 0;
	figure->ty_size = 1;
	while (figure->figure[i] != '*')
		i++;
	while (ft_strchr(figure->figure + i, '*'))
	{
		if (figure->figure[i] == '\n')
			figure->ty_size++;
		i++;
	}
	while (figure->figure[i] != '\n')
		i++;
	tmp = ft_strndup(figure->figure, i);
	ft_strdel(&figure->figure);
	figure->figure = ft_strdup(tmp);
}

void	ft_get_offsetof_figure(t_fpiece *figure)
{
	int		n;
	int		i;
	int		min;

	min = 1000;
	i = -1;
	n = 0;
	while (figure->figure[++i] != '*')
	{
		if (figure->figure[i] == '\n')
			n++;
	}
	figure->y_offset = n;
	i = -1;
	n = 0;
	while (figure->figure[++i] != '\0')
	{
		if (figure->figure[i] == '\n')
			n = -1;
		else if (figure->figure[i] == '*')
			min = (n < min) ? n : min;
		n++;
	}
	figure->x_offset = min;
	ft_get_tsizeof_figure(figure);
}

void	ft_unify_smbls(t_fplayg *playg)
{
	int		i;

	i = 0;
	while (playg->play_grnd[i] != '\0')
	{
		if (playg->play_grnd[i] > 96)
			playg->play_grnd[i] -= 32;
		i++;
	}
}

void	ft_clear_structs(t_fpiece *figure, t_fplayg *playg)
{
	ft_strdel(&figure->figure);
	ft_strdel(&playg->play_grnd);
}

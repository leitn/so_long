/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:49:01 by blax              #+#    #+#             */
/*   Updated: 2023/05/27 15:38:39 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	compt_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	j = 0;
	cpt = 0;
	while (i < game->map->size.y)
	{
		while (j < game->map->size.x)
		{
			if (game->map->tab[i][j] == 'C')
				cpt++;
			j++;
		}
		i++;
		j = 0;
	}
	return (cpt);
}

void	init_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map->tab[i][j])
		j++;
	while (game->map->tab[i])
		i++;
	game->map->size.y = i;
	game->map->size.x = j;
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->size.y)
	{
		while (j < game->map->size.x)
		{
			if (game->map->tab[i][j] == 'P')
			{
				game->map->player.pos.y = i;
				game->map->player.pos.x = j;
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	// game->map->player.moves = 0;
}

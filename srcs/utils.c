/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:49:01 by blax              #+#    #+#             */
/*   Updated: 2023/06/01 18:15:06 by letnitan         ###   ########.fr       */
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
}

int	ft_click(t_game *game)
{
	free_all(game);
	write(1, "You have just left the game !\n", 31);
	exit (EXIT_SUCCESS);
	return (0);
}

int	ft_small_error(char *msg)
{
	write(2, "\nError\n", 7);
	write(2, msg, ft_strlen(msg));
	exit (EXIT_FAILURE);
}

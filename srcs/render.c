/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:37:04 by blax              #+#    #+#             */
/*   Updated: 2023/05/30 18:45:57 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < game->map->size.y)
	{
		while (j < game->map->size.x)
		{
			draw_image(game, i * 50, j * 50, game->map->tab[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
	put_string_moves(game);
	return (0);
}

int	put_string_moves(t_game *game)
{
	char	*mv_count;
	char	*mv_count_minus;

	mv_count = ft_itoa(game->map->player.moves);
	mv_count_minus = ft_itoa((game->map->player.moves) - 1);
	mlx_set_font(game->mlx_ptr, game->win_ptr, "10x20");
	mlx_string_put(game->mlx_ptr, game->win_ptr, ((game->width) / 2) - 100,
		((game->height) - 25 ), 0x00BFFF, "The number of steps : ");
	mlx_string_put(game->mlx_ptr, game->win_ptr,((game->width) / 2) + 100,
		((game->height) - 25 ), 0x000000, mv_count_minus);
	mlx_string_put(game->mlx_ptr, game->win_ptr, ((game->width) / 2) + 100,
		((game->height) - 25 ), 0x00BFFF, mv_count);
 	if((game->map->collectibles) == (game->map->max_collectibles))
		mlx_string_put(game->mlx_ptr, game->win_ptr, ((game->width) / 2) - 80,
			((game->height) - 5 ), 0x00BFFF, "Go the cauldron !");
	return (free(mv_count), free(mv_count_minus), 0);
}

void	draw_image(t_game *game, int i, int j, char letter)
{
	if (letter == '1')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->map->wall.img1.img, j, i);
	else if (letter == '0')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->map->ground.img, j, i);
	else if (letter == 'P')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->map->player.backfacing[0].img, j, i);
	else if (letter == 'C')
		draw_collectible(game, j, i);
	else if ((letter == 'E') && (game->map->collectibles < game->map->max_collectibles))
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->map->exit.img1.img, j, i);
	else if ((letter == 'E') && (game->map->collectibles == game->map->max_collectibles))
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->map->exit.img2.img, j, i);
	else if (letter == 'M')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->map->ennemi.img1.img, j, i);
}

void	draw_collectible(t_game	*game, int j, int i)
{

	mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->map->collect.img1.img, j, i);
}

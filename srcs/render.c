/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:37:04 by blax              #+#    #+#             */
/*   Updated: 2023/05/27 18:33:30 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Charge une image XPM
void	charge_images(t_game *game)
{
	game->img_ppixel.x = game->width / (game->map->size.x);
	game->img_ppixel.y = game->height / (game->map->size.y);

	game->img_player.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, \
		"graphics/all_xpm/character_xpm_assets/backfacing_hero_xpm_assets/sand_backfacing_idle_hero.xpm", &game->img_ppixel.x,  &game->img_ppixel.y);
	game->img_collect.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, \
		"graphics/all_xpm/collectibles_xpm_assets/sand_floating_bottle_01.xpm", &game->img_ppixel.x, &game->img_ppixel.y);
	game->img_wall.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, \
		"graphics/all_xpm/wall_xpm_assets/wall_borderless_xpm_assets/borderless_wall_bottom.xpm", &game->img_ppixel.x, &game->img_ppixel.y);
	game->img_ennemi.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, \
		"graphics/all_xpm/enemy_xpm_assets/aggro_xpm_assets/sand_ghost_rightfacing_aggro_02.xpm", &game->img_ppixel.x, &game->img_ppixel.y);
	game->img_exit.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, \
		"graphics/all_xpm/door_xpm_assets/sand_cauldron_closed.xpm", &game->img_ppixel.x, &game->img_ppixel.y);
	game->img_ground.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, \
		"graphics/all_xpm/ground_xpm_assets/sand_tile.xpm", &game->img_ppixel.x, &game->img_ppixel.y);
	if (game->img_player.mlx_img == NULL \
		|| game->img_collect.mlx_img == NULL \
		|| game->img_wall.mlx_img == NULL\
		|| game->img_ennemi.mlx_img == NULL \
		|| game->img_exit.mlx_img == NULL \
		|| game->img_ground.mlx_img == NULL)
	{
		ft_printf("Erreur lors du chargement de l'image\n");
		return ;
	}
}

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
			game->mlx_ptr, game->win_ptr, game->img_wall.mlx_img, j, i);
	else if (letter == '0')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->img_ground.mlx_img, j, i);
	else if (letter == 'P')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->img_player.mlx_img, j, i);
	else if (letter == 'C')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->img_collect.mlx_img, j, i);
	else if (letter == 'E')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->img_exit.mlx_img, j, i);
	else if (letter == 'M')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->img_ennemi.mlx_img, j, i);
}

// mlx_string_put(game->mlx_ptr, game->win_ptr, 225, 275, 0x00BFFF, "The number of steps : ");
// mlx_string_put(game->mlx_ptr, game->win_ptr, 425, 275, 0x000000, mv_count_minus);
// mlx_string_put(game->mlx_ptr, game->win_ptr, 50, 50, 0x000000, mv_count);
// mlx_string_put(game->mlx_ptr, game->win_ptr, 425, 275, 0x00BFFF, mv_count);
// mlx_string_put(game->mlx_ptr, game->win_ptr, 50, 50, 0x000000, mv_count);

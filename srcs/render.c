/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:37:04 by blax              #+#    #+#             */
/*   Updated: 2023/05/23 22:26:33 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void charge_images(t_game *game)
{
    game->img_ppixel.x = game->width / game->map->size.x;
    game->img_ppixel.y = game->height / game->map->size.y;
    
    // Charge une image XPM
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
     || game->img_collect.mlx_img == NULL\
     || game->img_wall.mlx_img == NULL\
     || game->img_ennemi.mlx_img == NULL \
     || game->img_exit.mlx_img == NULL \
     || game->img_ground.mlx_img == NULL)
    {
        printf("Erreur lors du chargement de l'image\n");
        return;
    }
}

int draw_map(t_game *game)
{
    int i;
    int j;

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

void draw_image(t_game *game, int i, int j, char letter)
{
    if (letter == '1')
        mlx_put_image_to_window(
            game->mlx_ptr, game->win_ptr, game->img_wall.mlx_img, j, i);
    else if(letter == '0')
        mlx_put_image_to_window(
            game->mlx_ptr, game->win_ptr, game->img_ground.mlx_img, j, i);
    else if (letter == 'P')
        mlx_put_image_to_window(
            game->mlx_ptr, game->win_ptr, game->img_player.mlx_img, j, i);
    else if(letter == 'C')
        mlx_put_image_to_window(
            game->mlx_ptr, game->win_ptr, game->img_collect.mlx_img, j, i);
    else if(letter == 'E')
        mlx_put_image_to_window(
            game->mlx_ptr, game->win_ptr, game->img_exit.mlx_img, j, i);
    else if(letter == 'M')
        mlx_put_image_to_window(
            game->mlx_ptr, game->win_ptr, game->img_ennemi.mlx_img, j, i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:09:06 by letnitan          #+#    #+#             */
/*   Updated: 2023/06/01 17:59:22 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_image_collectibles(t_game *game)
{
	destroy_image(game, &game->map->collect[0]);
	destroy_image(game, &game->map->collect[1]);
	destroy_image(game, &game->map->collect[2]);
}

void	destroy_image_ennemi(t_game *game)
{
	destroy_image(game, &game->map->ennemi.img1);
	destroy_image(game, &game->map->ennemi.img2);
	destroy_image(game, &game->map->ennemi.img3);
}

void	destroy_image_exit(t_game *game)
{
	destroy_image(game, &game->map->exit.img1);
	destroy_image(game, &game->map->exit.img2);
	destroy_image(game, &game->map->exit.img3);
}

void	destroy_image_player(t_game *game)
{
	destroy_image(game, &game->map->player.backfacing[0]);
	destroy_image(game, &game->map->player.backfacing[1]);
	destroy_image(game, &game->map->player.backfacing[2]);
	destroy_image(game, &game->map->player.rightfacing[0]);
	destroy_image(game, &game->map->player.rightfacing[1]);
	destroy_image(game, &game->map->player.rightfacing[2]);
	destroy_image(game, &game->map->player.frontfacing[0]);
	destroy_image(game, &game->map->player.frontfacing[1]);
	destroy_image(game, &game->map->player.frontfacing[2]);
	destroy_image(game, &game->map->player.leftfacing[0]);
	destroy_image(game, &game->map->player.leftfacing[1]);
	destroy_image(game, &game->map->player.leftfacing[2]);
}

void	destroy_image_wall(t_game *game)
{
	destroy_image(game, &game->map->wall.img1);
	destroy_image(game, &game->map->wall.img2);
	destroy_image(game, &game->map->wall.img3);
}

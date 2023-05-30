/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_image_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:18:41 by letnitan          #+#    #+#             */
/*   Updated: 2023/05/30 15:50:29 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	charge_image_collectibles(t_game *game)
{
	charge_image(game, &game->map->collect.img1, COLLECT_1);
	charge_image(game, &game->map->collect.img2, COLLECT_2);
	charge_image(game, &game->map->collect.img3, COLLECT_3);
}

void	charge_image_ennemi(t_game *game)
{
	charge_image(game, &game->map->ennemi.img1, ENNEMI_1);
	charge_image(game, &game->map->ennemi.img2, ENNEMI_2);
	charge_image(game, &game->map->ennemi.img3, ENNEMI_3);
}

void	charge_image_exit(t_game *game)
{
	charge_image(game, &game->map->exit.img1, EXIT_1);
	charge_image(game, &game->map->exit.img2, EXIT_2);
	charge_image(game, &game->map->exit.img3, EXIT_3);
}

void	charge_image_player(t_game *game)
{
	charge_image(game, &game->map->player.backfacing[0], PLAYER_BACKFACING_IDLE);
	charge_image(game, &game->map->player.backfacing[1], PLAYER_BACKFACING_WALK_1);
	charge_image(game, &game->map->player.backfacing[2], PLAYER_BACKFACING_IDLE);
	charge_image(game, &game->map->player.rightfacing[0], PLAYER_RIGHTFACING_IDLE);
	charge_image(game, &game->map->player.rightfacing[1], PLAYER_RIGHTFACING_WALK_1);
	charge_image(game, &game->map->player.rightfacing[2], PLAYER_RIGHTFACING_IDLE);
	charge_image(game, &game->map->player.frontfacing[0], PLAYER_FRONTFACING_IDLE);
	charge_image(game, &game->map->player.frontfacing[1], PLAYER_FRONTFACING_WALK_1);
	charge_image(game, &game->map->player.frontfacing[2], PLAYER_FRONTFACING_IDLE);
	charge_image(game, &game->map->player.leftfacing[0], PLAYER_LEFTFACING_IDLE);
	charge_image(game, &game->map->player.leftfacing[1], PLAYER_LEFTFACING_WALK_1);
	charge_image(game, &game->map->player.leftfacing[2], PLAYER_LEFTFACING_IDLE);
}

void	charge_image_wall(t_game *game)
{
	charge_image(game, &game->map->wall.img1, WALL_1);
	charge_image(game, &game->map->wall.img2, WALL_2);
	charge_image(game, &game->map->wall.img3, WALL_3);
}

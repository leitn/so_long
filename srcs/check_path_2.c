/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:36:02 by letnitan          #+#    #+#             */
/*   Updated: 2023/05/31 19:15:43 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_path_image_collectibles(t_game *game)
{
	check_path_image(game, COLLECT_1);
	check_path_image(game, COLLECT_2);
	check_path_image(game, COLLECT_3);
}

void	check_path_image_ennemi(t_game *game)
{
	check_path_image(game, ENNEMI_1);
	check_path_image(game, ENNEMI_2);
	check_path_image(game, ENNEMI_3);
}

void	check_path_image_exit(t_game *game)
{
	check_path_image(game, EXIT_1);
	check_path_image(game, EXIT_2);
	check_path_image(game, EXIT_3);
}

void	check_path_image_player(t_game *game)
{
	check_path_image(game, PLAYER_BACKFACING_IDLE);
	check_path_image(game, PLAYER_BACKFACING_WALK_1);
	check_path_image(game, PLAYER_BACKFACING_WALK_2);
	check_path_image(game, PLAYER_FRONTFACING_IDLE);
	check_path_image(game, PLAYER_FRONTFACING_WALK_1);
	check_path_image(game, PLAYER_FRONTFACING_WALK_2);
	check_path_image(game, PLAYER_LEFTFACING_IDLE);
	check_path_image(game, PLAYER_LEFTFACING_WALK_1);
	check_path_image(game, PLAYER_LEFTFACING_WALK_2);
	check_path_image(game, PLAYER_RIGHTFACING_IDLE);
	check_path_image(game, PLAYER_RIGHTFACING_WALK_1);
	check_path_image(game, PLAYER_RIGHTFACING_WALK_2);
}

void	check_path_image_wall(t_game *game)
{
	check_path_image(game, WALL_1);
	check_path_image(game, WALL_2);
	check_path_image(game, WALL_3);
}

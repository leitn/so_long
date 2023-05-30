/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:08:39 by letnitan          #+#    #+#             */
/*   Updated: 2023/05/30 17:28:59 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_image(t_game *game, t_img *img)
{
	if (img->img != NULL)
		mlx_destroy_image(game->mlx_ptr, img->img);
}

void	destroy_images(t_game *game)
{
	destroy_image_collectibles(game);
	destroy_image_ennemi(game);
	destroy_image_exit(game);
	destroy_image_player(game);
	destroy_image_wall(game);
	destroy_image(game, &game->map->ground);
}

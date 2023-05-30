/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:34:55 by letnitan          #+#    #+#             */
/*   Updated: 2023/05/27 19:35:02 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_path_image(t_game *game, char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        write(2, path, ft_strlen(path));
        ft_error(game, "The file does not exist or there was an error opening it !\n");
    }
    else
        close(fd);
}

void check_path_images(t_game *game)
{
    check_path_image_collectibles(game);
    check_path_image_ennemi(game);
    check_path_image_exit(game);
    check_path_image_player(game);
    check_path_image_wall(game);
    check_path_image(game, GROUND);
}

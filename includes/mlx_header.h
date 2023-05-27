/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:47:58 by blax              #+#    #+#             */
/*   Updated: 2023/05/27 18:15:13 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HEADER_H
# define MLX_HEADER_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx_linux/mlx.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define MLX_ERROR 1

// #define True 1
// #define False 0

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_point{
	int x;
	int y;
} t_point;

typedef struct s_player
{
	int vies;
	int moved;
	int moves;
	t_point pos;
} t_player;

typedef struct s_data
{
	char **tab;
	int max_collectibles;
	int collectibles;
	int find;
	t_point size;
	t_player player;
} t_data;

typedef struct s_img
{
	void	*mlx_img;
}	t_img;

typedef struct s_game{
    void *mlx_ptr;
    void *win_ptr;
	char *filename;
	t_data *map;
    t_img img_collect;
    t_img img_wall;
	t_img img_ground;
    t_img img_player;
    t_img img_exit;
    t_img img_ennemi;
	t_point img_ppixel;
    int width;
    int height;
} t_game;

void charge_images(t_game *game);
int draw_map(t_game *game);
void draw_image(t_game *game, int i, int j, char letter);
int loop_hook(t_game *game);
int put_string_moves(t_game *game);

#endif

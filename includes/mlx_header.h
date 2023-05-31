/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:47:58 by blax              #+#    #+#             */
/*   Updated: 2023/05/31 19:09:41 by letnitan         ###   ########.fr       */
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
# include <sys/time.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define MLX_ERROR 1

# define PLAYER_BACKFACING_IDLE "graphics/P_back/back00.xpm"
# define PLAYER_BACKFACING_WALK_1 "graphics/P_back/back01.xpm"
# define PLAYER_BACKFACING_WALK_2 "graphics/P_back/back02.xpm"
# define PLAYER_FRONTFACING_IDLE "graphics/P_front/front00.xpm"
# define PLAYER_FRONTFACING_WALK_1 "graphics/P_front/front01.xpm"
# define PLAYER_FRONTFACING_WALK_2 "graphics/P_front/front02.xpm"
# define PLAYER_LEFTFACING_IDLE "graphics/P_left/left00.xpm"
# define PLAYER_LEFTFACING_WALK_1 "graphics/P_left/left01.xpm"
# define PLAYER_LEFTFACING_WALK_2 "graphics/P_left/left02.xpm"
# define PLAYER_RIGHTFACING_IDLE "graphics/P_right/right00.xpm"
# define PLAYER_RIGHTFACING_WALK_1 "graphics/P_right/right01.xpm"
# define PLAYER_RIGHTFACING_WALK_2 "graphics/P_right/right02.xpm"

# define COLLECT_1 "graphics/collect/b01.xpm"
# define COLLECT_2 "graphics/collect/b02.xpm"
# define COLLECT_3 "graphics/collect/b03.xpm"

# define EXIT_1 "graphics/exit/exit_closed.xpm"
# define EXIT_2 "graphics/exit/exit_open00.xpm"
# define EXIT_3 "graphics/exit/exit_open02.xpm"

# define ENNEMI_1 "graphics/enemy/left_aggro00.xpm"
# define ENNEMI_2 "graphics/enemy/left_aggro01.xpm"
# define ENNEMI_3 "graphics/enemy/right_aggro00.xpm"

# define WALL_1 "graphics/map/wall_bottom.xpm"
# define WALL_2 "graphics/map/block.xpm"
# define WALL_3 "graphics/map/block.xpm"

# define GROUND "graphics/ground/sand.xpm"

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void	*img;
}	t_img;

typedef struct s_objet
{
	t_img	img1;
	t_img	img2;
	t_img	img3;
}	t_objet;

typedef struct s_point{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	int		moved;
	int		moves;
	t_point	pos;
	t_img	backfacing[3];
	t_img	frontfacing[3];
	t_img	rightfacing[3];
	t_img	leftfacing[3];
}	t_player;

typedef struct s_data
{
	char		**tab;
	int			max_collectibles;
	int			collectibles;
	int			find;
	t_point		size;
	t_player	player;
	t_img		collect[3];
	t_objet		wall;
	t_objet		exit;
	t_objet		ennemi;
	t_img		ground;
}	t_data;

typedef struct s_game{
	void				*mlx_ptr;
	void				*win_ptr;
	char				*filename;
	t_data				*map;
	t_point				img_ppixel;
	int					width;
	int					height;
	int					ctrl_bool;
	// struct timeval		now_time;
	// struct timeval		previous_time;
}	t_game;

#endif

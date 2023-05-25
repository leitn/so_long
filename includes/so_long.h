/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:13:47 by blax              #+#    #+#             */
/*   Updated: 2023/05/23 22:49:54 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

# include "mlx_header.h"
# include "../libft/libft.h"
# include "get_next_line.h"

// enum direction {
//     UP = 1,
//     RIGHT = 2,
//     DOWN = 3,
// 	LEFT = 4
// };

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

void print_map(t_data *map);

//free.c
int ft_small_error(char *msg);
int ft_error_map(t_game *game, char *msg);
int ft_error(t_game *game, char *msg);
void free_map(t_data **map);
void free_images(t_game *game);
void free_all(t_game *game);

//move.c
void ft_move_player(t_game *game, int offset_x, int offset_y);
void ft_move(t_game *game, int direction);
int	handle_keypress(int keycode, t_game *game);

// init.c
void ft_init_game(t_game *game);
void ft_init_mlx(t_game *game);
void ft_init_map(t_game *game);
int	ft_check_map_extension(char *str, char *ext);

// (PARSING) FONCTIONS DE VALIDATION DE LA MAP
//ft_valid_map.c
int is_valid_elems(t_data *map);
int is_exist_elem(t_data *map, char letter);
int is_map_rectangle(t_data *map);
int is_map_duplicates(t_data *map, char letter);
int is_map_close(t_data *map, char letter);

// ft_utils.c
void init_size(t_game *game);
int compt_collectibles(t_game *game);
void init_player(t_game *game);

// valid_path.c
void cpy_map(t_data *map, t_data *tmp_map);
int is_exitable(t_game *game);
void f_efill(t_data *map, int row, int col);
int is_collectables(t_game *game);
void f_cfill(t_data *map, int row, int col);

//utils_2.c
char **make_area(char **zone, int _x, int _y);
void verif_map(t_game *game);

#endif

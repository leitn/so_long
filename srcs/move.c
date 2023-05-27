/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:33:33 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/27 18:32:10 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_move_player(t_game *game, int offset_x, int offset_y)
{
	int	i;
	int	j;

	i = game->map->player.pos.y + offset_y;
	j = game->map->player.pos.x + offset_x;
	ft_printf("pos.x : %d\n", game->map->player.pos.x);
	ft_printf("pos.y : %d\n", game->map->player.pos.y);
	ft_printf("nb_collect : %d\n", game->map->collectibles);
	if (i <= 0 || j <= 0 || i >= game->map->size.y - 1 ||
		j >= game->map->size.x - 1)
		return ;
	if (game->map->tab[i][j] == '1')
		return ;
	if (game->map->tab[i][j] == '0' || game->map->tab[i][j] == 'C')
	{
		if (game->map->tab[i][j] == 'C')
			game->map->collectibles++;
		game->map->tab[i][j] = 'P';
		game->map->tab[i - offset_y][j - offset_x] = '0';
		game->map->player.pos.x = j;
		game->map->player.pos.y = i;
	}
	if (game->map->tab[i][j] == 'M')
	{
		free_all(game);
		write(1, "you lose.. !\n", 14);
		exit (EXIT_SUCCESS);
	}
	if (game->map->tab[i][j] == 'E' &&
		game->map->collectibles == game->map->max_collectibles)
	{
		free_all(game);
		write(1, "SUCCESS !\n", 11);
		exit (EXIT_SUCCESS);
	}
	print_map(game->map);
}

void ft_move(t_game *game, int direction)
{
	if (direction == UP)
		ft_move_player(game, 0, -1);
	if (direction == RIGHT)
		ft_move_player(game, 1, 0);
	if (direction == DOWN)
		ft_move_player(game, 0, 1);
	if (direction == LEFT)
		ft_move_player(game, -1, 0);
	game->map->player.moved = 1;
	game->map->player.moves = game->map->player.moves + 1;
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_a || keycode == XK_Left || keycode == XK_A)
		ft_move(game, LEFT);
	if (keycode == XK_d || keycode == XK_Right || keycode == XK_D)
		ft_move(game, RIGHT);
	if (keycode == XK_w || keycode == XK_Up || keycode == XK_W)
		ft_move(game, UP);
	if (keycode == XK_s || keycode == XK_Down || keycode == XK_S)
		ft_move(game, DOWN);
	if (keycode == XK_Escape)
	{
		free_all(game);
		write(1, "You have just left the game !\n", 31);
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int loop_hook(t_game *game)
{
	if (game->map->player.moved == 1)
	{
		draw_map(game);
		put_string_moves(game);
		game->map->player.moved = 0;
	}
	return (0);
}

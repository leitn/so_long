/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:33:33 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/02 14:48:25 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_move_player(t_game *game, int offset_x, int offset_y)
{
	int	i;
	int	j;

	i = game->map->player.pos.y + offset_y;
	j = game->map->player.pos.x + offset_x;
	ft_printf("pos.x : %d\n", game->map->player.pos.x);
	ft_printf("pos.y : %d\n", game->map->player.pos.y);
	ft_printf("nb_collect : %d\n", game->map->collectibles);
	if (i <= 0 || j <= 0 || i >= game->map->size.y - 1
		|| j >= game->map->size.x - 1)
		return (0);
	if (game->map->tab[i][j] == '1')
		return (0);
	if (game->map->tab[i][j] == '0' || game->map->tab[i][j] == 'C')
	{
		if (ft_move_character(game, offset_x, offset_y) == 0)
			return (0);
	}
	if (game->map->tab[i][j] == 'E' &&
		game->map->collectibles == game->map->max_collectibles)
	{
		free_all(game);
		exit (EXIT_SUCCESS);
	}
	return (1);
}

int	ft_move_character(t_game *game, int offset_x, int offset_y)
{
	int	i;
	int	j;

	i = game->map->player.pos.y + offset_y;
	j = game->map->player.pos.x + offset_x;
	if (game->map->tab[i][j] == 'C')
		game->map->collectibles++;
	if (game->map->tab[i][j] == '1')
		return (0);
	game->map->tab[i][j] = 'P';
	game->map->tab[i - offset_y][j - offset_x] = '0';
	game->map->player.pos.x = j;
	game->map->player.pos.y = i;
	return (1);
}

void	ft_move(t_game *game, int direction)
{
	if (direction == UP)
	{
		if (ft_move_player(game, 0, -1) == 1)
			game->map->player.moves = game->map->player.moves + 1;
	}
	if (direction == RIGHT)
	{
		if (ft_move_player(game, 1, 0) == 1)
			game->map->player.moves = game->map->player.moves + 1;
	}
	if (direction == DOWN)
	{
		if (ft_move_player(game, 0, 1) == 1)
			game->map->player.moves = game->map->player.moves + 1;
	}
	if (direction == LEFT)
	{
		if (ft_move_player(game, -1, 0) == 1)
			game->map->player.moves = game->map->player.moves + 1;
	}
	game->map->player.moved = 1;

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
	if (keycode == XK_Control_L || keycode == XK_Control_R)
		game->ctrl_bool = 1;
	else if ((keycode == XK_C || keycode == XK_c) && game->ctrl_bool == 1)
	{
		free_all(game);
		write(1, "You have just left the game !\n", 31);
		exit (EXIT_SUCCESS);
	}
	else
		game->ctrl_bool = 0;
	return (0);
}

int	loop_hook(t_game *game)
{
	if (game->map->player.moved == 1)
	{
		draw_map(game);
		game->map->player.moved = 0;
	}
	return (0);
}

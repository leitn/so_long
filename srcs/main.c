/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:20:46 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/23 22:53:00 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void print_map(t_data *map)
{
	for (int i = 0; i < map->size.y; i++)
	{
		for (int j = 0; j < map->size.x; j++)
		{
			if (j != 0)
				printf(" ");
			printf("%c", map->tab[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	t_game game;
	
	if (argc != 2)
		ft_small_error("Invalid number of arguments !\n");
	game.filename = argv[1];
	ft_init_game(&game);
	verif_map(&game);
	if(!is_exitable(&game) || !is_collectables(&game))
        ft_error_map(&game, "No valid path for this map was found !\n");
	ft_init_mlx(&game);
	charge_images(&game);
	draw_map(&game);
	mlx_loop_hook(game.mlx_ptr, loop_hook, &game);
	mlx_key_hook(game.win_ptr, handle_keypress, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
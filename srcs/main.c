/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:20:46 by letnitan          #+#    #+#             */
/*   Updated: 2023/06/01 18:17:36 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size.y)
	{
		j = 0;
		while (j < map->size.x)
		{
			if (j != 0)
				ft_printf(" ");
			ft_printf("%c", map->tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_small_error("Invalid number of arguments !\n");
	game.filename = argv[1];
	ft_init_game(&game);
	verif_map(&game);
	if (!is_exitable(&game) || !is_collectables(&game))
		ft_error_map(&game, "No valid path for this map was found !\n");
	ft_init_mlx(&game);
	charge_images(&game);
	draw_map(&game);
	mlx_loop_hook(game.mlx_ptr, loop_hook, &game);
	mlx_key_hook(game.win_ptr, handle_keypress, &game);
	mlx_hook(game.win_ptr, 17, 0, ft_click, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:13:49 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/26 15:27:17 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_game(t_game *game)
{
	game->map = (t_data *) malloc(sizeof(t_data));
	if (!game->map)
		ft_small_error("Memory allocation of the map failed !\n");
	ft_init_map(game);
	init_size(game);
	game->width = game->map->size.x * 50;
	game->height = game->map->size.y * 50;
	init_player(game);
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map->find = 0;
	game->map->collectibles = 0;
	game->map->max_collectibles = compt_collectibles(game);
	game->map->player.moved = 0;
	ft_printf("INITIALISATION:\n");
	ft_printf("    size.x : %d\n", game->map->size.x);
	ft_printf("    size.y : %d\n", game->map->size.y);
	ft_printf("    player.pos.x : %d\n", game->map->player.pos.x);
	ft_printf("    player.pos.y : %d\n", game->map->player.pos.y);
	ft_printf("    nb_max_collect : %d\n", game->map->max_collectibles);
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game->map);
		ft_small_error("Mlx Error init !\n");
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width, game->height,
			"So Long Project");
	if (!game->win_ptr)
	{
		free(game->map);
		ft_small_error("Mlx Error window !\n");
	}
}

void	ft_init_map(t_game *game)
{
	char	*line;
	char	*tmp;
	int		fd;

	tmp = NULL;
	fd = open(game->filename, O_RDONLY);
	if (fd < 0 || !ft_check_map_extension(game->filename, ".ber"))
	{
		free(game->map);
		ft_small_error("Error with map '.ber' extension!\n");
	}
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(tmp, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game->map->tab = ft_split(tmp, '\n');
	free(tmp);
}

int	ft_check_map_extension(char *str, char *ext)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(str) - 4;
	j = 0;
	while (str[i] && ext[j] && str[i] == ext[j])
	{
		i++;
		j++;
	}
	if (j == 4)
		return (1);
	return (0);
}

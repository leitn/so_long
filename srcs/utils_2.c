/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:48:15 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/02 17:16:53 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verif_map(t_game *game)
{
	if (!is_map_rectangle(game->map))
		ft_error_map(game, "Map is not rectangular !\n");
	if (!is_valid_elems(game->map))
		ft_error_map(game, "Elements in the map is not correct !\n");
	if (!is_exist_elem(game->map, 'E'))
		ft_error_map(game, "Element E is missing from the map !\n");
	if (!is_exist_elem(game->map, 'P'))
		ft_error_map(game, "Element P is missing from the map !\n");
	if (!is_exist_elem(game->map, 'C'))
		ft_error_map(game, "Element C is missing from the map !\n");
	if (!is_map_duplicates(game->map, 'P'))
		ft_error_map(game, "Element P is double in the map !\n");
	if (!is_map_duplicates(game->map, 'E'))
		ft_error_map(game, "Element E is double in the map !\n");
	if (is_map_close(game->map, '1') == 1)
		{
			ft_error_map(game, "The map is not close !\n");
			//BUG
		}
}

char	**make_area(char **zone, int x, int y)
{
	char	**area;
	int		i;
	int		j;

	i = 0;
	area = (char **) malloc(sizeof(char *) * y);
	while (i < y)
	{
		area[i] = (char *) malloc(sizeof(char) * x);
		j = 0;
		while (j < x)
		{
			area[i][j] = zone[i][j];
			j++;
		}
		i++;
	}
	return (area);
}

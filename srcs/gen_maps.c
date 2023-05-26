/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:32:18 by blax              #+#    #+#             */
/*   Updated: 2023/05/26 15:09:38 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define WIDTH 10
#define HEIGHT 10

char	**generate_map(int width, int height)
{
	int		i;
	int		j;
	int		special_positions;
	int		x;
	int		y;
	char	**map = (char **)malloc(height * sizeof(char *));

	if (map == NULL)
	{
		ft_printf("Erreur d'allocation de mémoire\n");
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		map[i] = (char *)malloc(width * sizeof(char));
		if (map[i] == NULL)
		{
			ft_printf("Erreur d'allocation de mémoire\n");
			return (NULL);
		}
		j = 0;
		while (j < width)
		{
			// Les bordures de la carte sont définies à 1
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				map[i][j] = '1';
			}
			else
			{
			/*L'intérieur est généré de manière aléatoire avec des valeurs de 0 ou 1*/
				map[i][j] = '0' + rand() % 2;
			}
			j++;
		}
		i++;
	}

	// Positionner le joueur 'P', la sortie 'E' et les collectibles 'C'
	// P + E + 2 à 4 C
	special_positions = 1 + 1 + (rand() % 3 + 2);
	while (special_positions > 0)
	{
		x = rand() % (height - 2) + 1;
		y = rand() % (width - 2) + 1;
		if (map[x][y] == '0')
		{
			if (special_positions == 1)
			{
				map[x][y] = 'E';
			}
			else if (special_positions == 2)
			{
				map[x][y] = 'P';
			}
			else
			{
				map[x][y] = 'C';
			}
			special_positions--;
		}
	}
	return (map);
}

void	print_map(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	main()
{
	srand(time(NULL));
	// Initialiser le générateur de nombres aléatoires
	char	**map = generate_map(WIDTH, HEIGHT);

	if (map != NULL)
	{
		print_map(map, WIDTH, HEIGHT);
		// Libérer la mémoire allouée pour la carte
		for (int i = 0; i < HEIGHT; i++)
		{
			free(map[i]);
		}
		free(map);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:32:18 by blax              #+#    #+#             */
/*   Updated: 2023/05/25 15:41:52 by letnitan         ###   ########.fr       */
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

	for (i = 0; i < height; i++)
	{
		map[i] = (char *)malloc(width * sizeof(char));
		if (map[i] == NULL)
		{
			ft_printf("Erreur d'allocation de mémoire\n");
			return (NULL);
		}
		for (j = 0; j < width; j++)
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
		}
	}

	// Positionner le joueur 'P', la sortie 'E' et les collectibles 'C'

	special_positions = 1 + 1 + (rand() % 3 + 2); // P + E + 2 à 4 C
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

void print_map(char **map, int width, int height)
{
	int	i;
	int	j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			ft_printf("%c ", map[i][j]);
		}
		ft_printf("\n");
    }
}

int	main()
{
	srand(time(NULL)); // Initialiser le générateur de nombres aléatoires
	char	**map = generate_map(WIDTH, HEIGHT);
	if(map != NULL)
	{
		print_map(map, WIDTH, HEIGHT);
		// Libérer la mémoire allouée pour la carte
		for (int i = 0; i < HEIGHT; i++)
		{
			free(map[i]);
		}
		free(map);
	}
	return 0;
}

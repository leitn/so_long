/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:45:06 by blax              #+#    #+#             */
/*   Updated: 2023/05/23 22:18:56 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int is_valid_elems(t_data *map)
{
    int i;
    int j;


    i = 0;
    j = 0;
    while (i < map->size.y)
    {
        while (j < map->size.x)
        {
            if (map->tab[i][j] != '0' && map->tab[i][j] != '1' && 
                map->tab[i][j] != 'C' && map->tab[i][j] != 'E' &&
                map->tab[i][j] != 'P')
                return (0);
            j++;
        }
        i++;
        j = 0;
    }
    return (1);
}

int is_exist_elem(t_data *map, char letter)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < map->size.y)
    {
        while (j < map->size.x)
        {
            if (map->tab[i][j] == letter)
                return (1);
            j++;
        }
        i++;
        j = 0;
    }
    return (0);
}

int is_map_rectangle(t_data *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < map->size.y)
    {
        while (map->tab[i][j] != '\0')
            j++;
        if (j != map->size.x)
            return (0);
        i++;
        j = 0;
    }
    return (1);
}

int is_map_duplicates(t_data *map, char letter)
{
    int i;
    int j;
    int cpt;

    i = 0;
    j = 0;
    cpt = 0;
    while (i < map->size.y)
    {
        while (j < map->size.x)
        {
            if (map->tab[i][j] == letter)
            {
                cpt++;
                if (cpt == 2)
                    return (0);
            }
            j++;
        }
        i++;
        j = 0;
    }
    return (1);
}

int is_map_close(t_data *map, char letter)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < map->size.y)
    {
        while (j < map->size.x)
        {
            if ((i == 0 || i == map->size.y) && map->tab[i][j] != letter)
                return (0);
            if ((j == 0 || j == map->size.x) && map->tab[i][j] != letter)
                return (0);
            j++;
        }
        i++;
        j = 0;
    }
    return (1);
}
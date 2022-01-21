/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paw <paw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:13:21 by paw               #+#    #+#             */
/*   Updated: 2022/01/19 11:14:34 by paw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* STRUCTURE OF MAP.C
 * In this file, we will have the helper functions related to the map:
 * - new_map: to create a fresh map on the heap, full of '.'
 * - print_map: to print the solved map on the screen
 * - free_map: to free the memory allocated on the t_map at different levels
 * - min_map_size: to calculate based on the number of pieces the min map size
 * - count_pieces: we need that for the previous function
*/

/*
 * Create an array of strings full of '.' of the size indicated
*/

t_map	*new_map(int map_size)
{
	t_map	*map;
	int	i;
	i = 0;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->array = (char**)ft_memalloc(sizeof(char *) * map_size);
	while (i < map_size)
	{
		map->array[i] = ft_strnew(map_size);
		ft_memset(map->array[i], '.', map_size);
		i++;
	}
	return (map);
}

/*
 * Calculates the minimum map size based on the number of pieces:
 * square root of the number of '#', ie of blocks that compose the pieces.
 * We round it up to the next integer.
*/

int	min_map_size(t_piece *piecelist)
{
	int	i;
	int	nb_blocks;
	
	nb_blocks = count_pieces(piecelist) * 4;
	i = 2;
	while (i * i < nb_blocks)
		i++;
	return (i);
}
	
int	count_pieces(t_piece *piecelist)
{
	int	i;

	i = 0;
	while (piecelist)
	{
		piecelist = piecelist->next;
		i++;
	}
	return (i);	
}

void	print_map(t_map	*map, int map_size)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
 * To free all the heap allocated memory for map, we need to free at each level
 * - at the typedef struct level: t_map
 * - at the array level within the struct: char** array
 * - at each string level within the array. 
 * We will start at the string level, then array, then t_map.
 *
 * We will use ft_memdel, which needs a pointer's address, and it  will 
 * free its memory and also puts the pointer to NULL.
*/

void	free_map(t_map *map, int map_size)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

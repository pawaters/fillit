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

/*
 * Create an array of strings full of '.' of the size indicated
*/

t_map	*new_map(int map_size)
{
	t_map	*map;
	int	i;
	i = 0;

	map = (t_map *)ft_memalloc(size_of(t_map));
	map->array = (char**)ft_memalloc(size_of(char *) * map_size);
	while (i < map_size)
	{
		map->array[i] = ft_strnew(map_size);
		map->array[i] = ft_memset(map->array[i], '.', map_size);
		i++;
	}
	return (map);
}


	

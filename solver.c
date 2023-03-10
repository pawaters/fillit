/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*  									            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   									               #+#    #+#             */
/*   										           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * STRUCTURE OF SOLVER.C
 * The solver will take a list of tetromino as input and:
 * 1) in_bounds: check if in that position it fits in the current map,
 * 2) overlap: check if it does not overlap in that position with another piece,
 * 3) place: put in the map,
 * 4) next piece: use linked list to do the same with next piece.
 *
 * Backtracking recursion method to find a solution:
 * If it does not work with that position and piece,try at the next position. 
 * If it does not work with any position, try next position with previous piece.
 * If still it does not work, we increase the size of the map by 1.
*/

int	in_bounds(t_piece *piece, int map_size, char axis)
{
	if (axis == 'y')
		return (piece->blockcoords[1] + piece->y_offset < map_size && \
			piece->blockcoords[3] + piece->y_offset < map_size && \
			piece->blockcoords[5] + piece->y_offset < map_size && \
			piece->blockcoords[7] + piece->y_offset < map_size);
	else
		return (piece->blockcoords[0] + piece->x_offset < map_size && \
			piece->blockcoords[2] + piece->x_offset < map_size && \
			piece->blockcoords[4] + piece->x_offset < map_size && \
			piece->blockcoords[6] + piece->x_offset < map_size);
}

/*
 * We check if there is any overlap by counting if we do find 8 '.' 
 * at the positions 
 * we would place the letter of the piece. 
*/

int	overlap(t_map *map, t_piece *piece)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = piece->blockcoords[i] + piece->x_offset;
	y = piece->blockcoords[i + 1] + piece->y_offset;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		x = piece->blockcoords[i] + piece->x_offset;
		y = piece->blockcoords[i + 1] + piece->y_offset;
	}
	return (i != 8);
}

/*
 * If there piece is not out of bounds and fits with the other pieces 
 * (no overlap), 
 * we place it our map, following the coordinates and offset of the piece.
*/

void	place(t_piece *piece, t_map *map, char letter)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = piece->blockcoords[i] + piece->x_offset;
		y = piece->blockcoords[i + 1] + piece->y_offset;
		map->array[y][x] = letter;
		i += 2;
	}
}

/*
 * The function that tests each tetrimino at top left position
 * is in bounds or overlap.
 * If all is good, goes to next tetrimino. 
 * If a check fails, it comes back one loop before, to try another position.
 * Or if all positions fail for that piece, the previous piece at another place
*/

int	solve_map(t_map *map, t_piece *piece, int map_size)
{
	if (!piece)
		return (1);
	piece->x_offset = 0;
	piece->y_offset = 0;
	while (in_bounds(piece, map_size, 'y'))
	{
		while (in_bounds(piece, map_size, 'x'))
		{
			if (!overlap(map, piece))
			{
				place (piece, map, piece->piece_letter);
				if (solve_map(map, piece->next, map_size))
					return (1);
				else
				{
					place(piece, map, '.');
				}
			}
			piece->x_offset++;
		}
		piece->x_offset = 0;
		piece->y_offset++;
	}
	return (0);
}

/*
 * MAIN FUNCTION OF SOLVER.C
 * Start with Min possible size of map: square root of nb of '#' (pieces*4)
 * Uses solve_map, and if no solution, increases map size by 1.
*/

void	solve(t_piece *piecelist)
{
	t_map	*map;
	int		map_size;

	map_size = min_map_size(piecelist);
	map = new_map(map_size);
	while (!solve_map(map, piecelist, map_size))
	{
		free_map(map, map_size);
		map_size++;
		map = new_map(map_size);
	}
	print_map(map, map_size);
	free_map(map, map_size);
}

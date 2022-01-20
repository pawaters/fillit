/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:57:14 by msilen            #+#    #+#             */
/*   Updated: 2022/01/20 13:55:43 by msilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks for invalid chars, wrong-length lines
** counts numbers of '#' per block
** If any checks are failed, returns false
*/

int	validate_characters(char *tetri)
{
	int	i;
	int	height;
	int	blocks;
	int	characters;

	i = 0;
	height = 0;
	blocks = 0;
	characters = 0;
	while ((tetri[i] == '.' || tetri[i] == '#' || tetri[i] == '\n') \
			&& tetri[i] && (height != 4))
	{
		if (tetri[i] == '.' || tetri[i] == '#')
		{
			if (tetri[i] == '#')
				blocks++;
			characters++;
		}
		if (tetri[i++] == '\n')
			height++;
	}
	if ((characters == 4 * 4) && (height == 4) && \
			(blocks == 4) && (tetri[i] == '\n' || tetri[i] == '\0'))
		return (1);
	return (0);
}

/*
** Checks if tetrimino is right shape and returns 6 or 8 adjacencies
*/

int	validate_tetri(char **tetri)
{
	int	count;
	int	row;
	int	col;

	count = 0;
	row = -1;
	while (4 > ++row)
	{
		col = -1;
		while (4 > ++col)
		{
			if (tetri[row][col] == '#' && row < 3)
				tetri[row + 1][col] == '#' ? count++ : count;
			if (tetri[row][col] == '#' && row > 0)
				tetri[row - 1][col] == '#' ? count++ : count;
			if (tetri[row][col] == '#' && col < 3)
				tetri[row][col + 1] == '#' ? count++ : count;
			if (tetri[row][col] == '#' && col > 0)
				tetri[row][col - 1] == '#' ? count++ : count;
		}
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

/*
** Checks that everything is valid
*/

int	validate_input(char *map)
{
	if (validate_input(map))
		if (validate_tetri((ft_strsplit(map, '\n'))))
			return (1);
	return (0);
}

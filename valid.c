/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:57:14 by msilen            #+#    #+#             */
/*   Updated: 2022/01/24 10:08:23 by msilen           ###   ########.fr       */
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
	int	count;
	
	i = 0;
	count = 0;
	while (i < 19)
	{
		if (tetri[i] && tetri[i] != '\n' && tetri[i] != '#' && tetri[i] != '.')
			return (0);
		if (tetri[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (tetri[i] == '#')
			count++;
		i++;
	}
	if (!tetri[i] || tetri[i] != '\n')
		return (0);
	return (count);
}
/*
** Checks if tetrimino is right shape and counts how many adjacencies
** it has.
*/

int	validate_tetri(char *tetri)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (i < 19)
	{
		if (tetri[i] == '#')
		{
			if (i + 1 <= 18 && tetri[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && tetri[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && tetri[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && tetri[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

/*
** Checks that everything is valid by iterating through buf 21 chars
** at a time
*/

int	validate_input(char *tetri, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		if (validate_characters(tetri + 1) != 4)
			return (0);
		if (validate_tetri(tetri + i) != 6 && validate_tetri(tetri + 1) != 8)
			return (0);
		i += 21;
	}
	return (1);
}

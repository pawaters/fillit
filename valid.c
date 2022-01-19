/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:57:14 by msilen            #+#    #+#             */
/*   Updated: 2022/01/19 12:46:28 by msilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks for invalid chars, wrong-length lines
** counts numbers of '#' per block
** If any checks are failed, returns false
*/

int	check_tetri_chars(char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (i < 19) // block, including \n
	{
		if (str[i] && str[i] != '\n' && str[i] != '#' && str[i] != '.')
			return (0);
		if (str[i] == '\n' && (((i + 1) % 5) == 0))
			return (0);
		if (str[i] == '#')
			count++;
		i++;
	}
	if (!str[i] || str[i] != '\n')
		return (0);
	return (count);
}

/*
** Checks if tetrimino is right shape and returns 6 or 8
** First checks if '#' connects to other '#' above, second checks right side
** third checks down and fourth on the left side.
** While checks connections of every '#' characters of one block
*/

static int check_tetri_shape(char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (i < 16)
	{
		if (str[i] == '#')
		{
			if ((str[i - 4] == '#') && (i > 3)) // above
				count++;
			if ((str[i + 1] == '#') && ((i + 1) % 4 != 0) && (i < 16)) //right
				count++;
			if ((str[i + 4] == '#') && (i > 12)) //down
				count++;
			if ((str[i - 1] == '#') && (i % 4 != 0) && (i != 0)) //left
				count++;
		}
		i++;
	}
	return (count);
}

/*
** The functions checks that we have the right amount of '.' and '#' chars.
*/

static int check_block_chars(char *str)
{
	static int	block_count;
	int			hash;
	int			dots;
	int			i;
	
	block_count = 1;
	hash = 0;
	dots = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dots++;
		if (str[i] == '#')
			hash++;
		i++;
	}
	if (dots == 12 && hash == 4)
	{
		check_tetri_shape(str);
		if (check_tetri_shape(str) != 8 && check_tetri_shape(str) != 6)
			return (0);
		return (1);
	}
	return (0);
}

/*
** Checks that everything is valid
** 
*/

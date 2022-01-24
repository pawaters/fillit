/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:38:51 by msilen            #+#    #+#             */
/*   Updated: 2022/01/24 15:11:56 by msilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Moves the piece to upperleft corner of its block using shifter functions.
*/

t_piece	*upperleft_corner(t_piece *piece)
{
	while (piece->blockcoords[0] != 0 && \
				piece->blockcoords[2] != 0 && \
				piece->blockcoords[4] != 0 && \
				piece->blockcoords[6] != 0)
		shift_x(piece, -1);
	while (piece->blockcoords[1] != 0 && \
				piece->blockcoords[3] != 0 && \
				piece->blockcoords[5] != 0 && \
				piece->blockcoords[7] != 0)
		shift_y(piece, -1);
	return (piece);
}

/*
** The function assigns the tetriminos cordinates
*/

void	assign_coords(char *str, t_piece *piece)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 1;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i >= 5)
				piece->blockcoords[x] = (i % 5);
			else
				piece->blockcoords[x] = i;
			piece->blockcoords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
}

/*
** Creates and mallocs a new piece. Finds and stores the coordinates of '#'
** chars. Returns aligned piece
*/

t_piece	*makepiece(char *str, char piece_letter)
{
	t_piece	*piece;

	piece = (t_piece *)malloc(sizeof(t_piece));
	if (piece == NULL)
		return (NULL);
	assign_coords(str, piece);
	piece->x_offset = 0;
	piece->y_offset = 0;
	piece->piece_letter = piece_letter;
	return (upperleft_corner(piece));
}

/*
** Passes the string to makepiece and assigns a letter to the piece
** Return a linked list of piece structs
*/

t_piece	*makelist(char *str, int size)
{
	t_piece	*current;
	t_piece	*beginning;
	int		i;
	char	piece_letter;

	i = 0;
	piece_letter = 'A';
	while (i < size)
	{
		if (piece_letter == 'A')
		{
			beginning = makepiece(str + i, piece_letter);
			current = beginning;
		}
		else
		{
			current->next = makepiece(str + i, piece_letter);
			current = current->next;
		}
		piece_letter++;
		i += 21;
	}
	current->next = NULL;
	return (beginning);
}

/*
** Control all parsing functions
** Open and reads file into a buffer of size 545 (max file size + 1)
** If a file is too small or large, it rejects it
** returns a list of piece structs
*/

t_piece	*parser(char *filename)
{
	char	buf[545];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, 545);
	close(fd);
	if (bytecount > 544 || bytecount < 19)
		return (NULL);
	buf[bytecount] = '\0';
	if (!validate_input(bytecount, buf))
		return (NULL);
	return (makelist(buf, bytecount));
}

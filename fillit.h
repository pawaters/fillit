/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:12:38 by paw               #+#    #+#             */
/*   Updated: 2022/01/24 10:35:30 by msilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef	struct		s_piece
{
	int		blockcoords[8];
	char		piece_letter;
	int		x_offset;
	int		y_offset;
	struct s_piece	*next;
}			t_piece;

typedef struct	s_map
{
	char	**array;
}		t_map;

int	in_bounds(t_piece *piece, int map_size, char axis);
int	overlap(t_map *map, t_piece *piece);
void	place(t_piece *piece, t_map *map, char letter);
int	solve_map(t_map *map, t_piece *piece, int map_size);
void	solve(t_piece *piecelist);
t_map	*new_map(int map_size);
int	min_map_size(t_piece *piecelist);
int	count_pieces(t_piece *piecelist);
void	print_map(t_map *map, int map_size);
void	free_map(t_map *map, int map_size);

void	free_piecelist(t_piece *list);
t_piece	*upperleft_corner(t_piece *piece);
t_piece	*makepiece(char *str, char piece_letter);
t_piece	*makelist(char *str, int size);
t_piece	*parser(char *filename);
int	validate_characters(char *tetri);
int	validate_tetri(char *tetri);
int	validate_input(int size, char *tetri);
void	shift_x(t_piece *piece, int n);
void	shift_y(t_piece *piece, int n);

#endif

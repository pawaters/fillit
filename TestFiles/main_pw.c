#include "../fillit.h"

/* TEST FILE FOR SOLVER.C & MAP.C - STRUCTURE
 * Compenent tests:
 * - create a sample piece_list, with 3 pieces;
 * - print that piece_list coordinates, and tetrimino.
 * - print a sample 5*5 empty map,
 *
 * Solver tests:
 * - with 3 pieces that only need horizontal moves
 * - with 4 pieces that requires map growth
 * - with 4 pieces, requires 1st piece shifted with backtracking
*/

//printcoords, printpiece and printpiecelist to check the struct

void	printcoords(t_piece *piece)
{
	int	i;

	i = 0;
	ft_putstr("Coordinates of piece:\n");
	while (i <= 6)
	{
		ft_putstr("- block number ");
		ft_putnbr(i % 2 + 1);
		ft_putstr(": x = ");
		ft_putnbr(piece->blockcoords[i]);
		ft_putstr(", y = ");
		i++;
		ft_putnbr(piece->blockcoords[i]);
		ft_putstr(".\n");
		i++;
	}
}

void	printpiece(t_piece *piece)
{
	char	piecemap[4][5] = {"....\0", "....\0", "....\0", "....\0"};
	int	i;

	i = 0;
	while (i < 8)
	{
		piecemap[piece->blockcoords[i + 1]][piece->blockcoords[i]] = piece->piece_letter;
		i += 2;
	}
	i = 0;
	while (i < 4)
	{
		ft_putstr(piecemap[i]);
		ft_putchar('\n');
		i++;
	}
}

t_piece	*printpiecelist(t_piece *piecelist)
{
	t_piece	*head = piecelist;

	while (piecelist->next)
	{
		ft_putstr("Piece letter is :\n");
		ft_putchar(piecelist->piece_letter);
		ft_putchar('\n');
		printcoords(piecelist);
		printpiece(piecelist);
		piecelist = piecelist->next;
	}
		ft_putstr("Piece letter is :\n");
		ft_putchar(piecelist->piece_letter);
		ft_putchar('\n');
		printcoords(piecelist);
		printpiece(piecelist);

	return (head);
}

int	main (void)
{

// Test: new_map, print_map, map_size 5	
	
//	t_map	*map;
//	int	map_size = 5;
//	
//	map = new_map(map_size);
//	print_map(map, map_size);

// Test: create a sample piece list and print elements of struct

	t_piece first = {{0, 0, 0, 1, 0, 2, 0, 3}, 'A', 0, 0, NULL};
	t_piece second = {{0, 0, 0, 1, 0, 2, 0, 3}, 'B', 0, 0, NULL};
	t_piece third = {{0, 0, 0, 1, 0, 2, 0, 3}, 'C', 0, 0, NULL};
	t_piece fourth = {{0, 0, 0, 1, 0, 2, 0, 3}, 'D', 0, 0, NULL};
	first.next = &second;
	second.next = &third;
	third.next = &fourth;
	t_piece *head = &first;

// Print blockcoord

//	(void)head;
//	printcoords(&first);
//	printcoords(&second);
//	printcoords(&third);
//	printcoords(&fourth);

// Print piece as a tetrimino

	//(void)head;
	//printpiece(&first);
	//printpiece(&second);
	//printpiece(&third);
	//printpiece(&fourth);

// Print piece_list as tetriminoes with letter

	//printpiecelist(head);

// Test solve

	solve(head);
}

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

int	main (void)
{

// Test: new_map, print_map, map_size 5	
	
//	t_map	*map;
//	int	map_size = 5;
//	
//	map = new_map(map_size);
//	print_map(map, map_size);

// Test: create a sample piece list and print elements of struct

	t_piece first = {{0, 0, 0, 1, 1, 0, 1, 1}, 'A', 0, 0, NULL};
	t_piece second = {{0, 0, 0, 1, 0, 2, 0, 3}, 'B', 0, 0, NULL};
	t_piece third = {{0, 0, 0, 1, 0, 2, 0, 3}, 'C', 0, 0, NULL};
	t_piece fourth = {{0, 0, 0, 1, 0, 2, 0, 3}, 'D', 0, 0, NULL};
	first.next = &second;
	second.next = &third;
	third.next = &fourth;
	t_piece *head = &first;

	solve(head);
}

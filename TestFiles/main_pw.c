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
	t_map	*map;
	int	map_size = 5;
	
	map = new_map(map_size);
	print_map(map, map_size);
}

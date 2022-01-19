/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paw <paw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:07:05 by paw               #+#    #+#             */
/*   Updated: 2022/01/19 11:14:36 by paw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * The solver will take a list of tetromino as input and:
 * 1) in_bounds: check if in that position it fits in the current map
 * 2) overlap: check if it does not overlap in that position with another piece,
 * 3) place: put in the map.
 * 4) next piece: use linked list to do the same with next piece
 *
 * Backtracking recursion method to find a solution:
 * If it does not work with that position and piece,try at the next position, 
 * 
 * If it does not work with any position, then try next position with previous piece
 * If previous piece does not work either, then we try the same with every piece, until we have tried all. 
 * If still it does not work, we increase the size of the map by 1.

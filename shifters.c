/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:03:52 by msilen            #+#    #+#             */
/*   Updated: 2022/01/20 14:06:54 by msilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Moves a piece n places along the x-axis
*/

void	shift_x(t_piece *piece, int n)
{
	piece->blockcoord[0] += n;
	piece->blockcoord[2] += n;
	piece->blockcoord[4] += n;
	piece->blockcoord[6] += n;
}

/*
** Moves a piece n places along the y-axis
*/

void	shift_y(t_piece *piece, int n)
{
	piece->blockcoord[1] += n;
	piece->blockcoord[3] += n;
	piece->blockcoord[5] += n;
	piece->blockcoord[7] += n;
}



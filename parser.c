/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:38:51 by msilen            #+#    #+#             */
/*   Updated: 2022/01/20 14:01:11 by msilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Frees the piecelist
*/

void	free_piecelist(t_piece *list)
{
	t_piece *tmp;
	
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_piece	*corner(t_piece *piece)
{
	while (piece->blockcoord[0] != 0 && \
				piece->blockcoord[2] != 0 && \
				piece->blockcoord[4] != 0 && \
				piece->blockcoord[6] != 0)
		shift
}
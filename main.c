/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilen <msilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 07:33:20 by msilen            #+#    #+#             */
/*   Updated: 2022/01/24 07:38:47 by msilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_piece	*piecelist;
	
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	if ((piecelist = parser(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	solve(piecelist);
	free_piecelist(piecelist);
	return (0);
}

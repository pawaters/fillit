/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pawaters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:43:59 by pawaters          #+#    #+#             */
/*   Updated: 2021/12/14 13:29:46 by pwaters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		k;
	char				**tab;

	i = ((k = 0), 0);
	tab = (char **)malloc(sizeof(char *) * ((ft_wc(s, c)) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strndup(s + j, i - j);
			if (!tab[k++])
				return (ft_freetab(tab));
		}
	}
	tab[k] = NULL;
	return (tab);
}

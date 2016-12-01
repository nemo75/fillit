/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:13:57 by thedupuy          #+#    #+#             */
/*   Updated: 2016/12/01 00:13:59 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_tab(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

void		ft_deltab(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&tab[i]);
		i++;
	}
	ft_memdel((void **)&tab);
}

char		**ft_map(int size)
{
	int		x;
	int		i;
	char	**tab;

	x = 0;
	i = 0;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	while (x < size)
	{
		if (!(tab[x] = (char *)ft_memalloc(sizeof(char *) * size)))
			return (NULL);
		i = 0;
		while (i < size)
		{
			tab[x][i] = '.';
			i++;
		}
		x++;
	}
	return (tab);
}

t_coord		*ft_coord_size(int x, int y)
{
	t_coord *nb;

	nb = ft_memalloc(sizeof(t_coord));
	nb->x = x;
	nb->y = y;
	return (nb);
}

void		ft_clean_lst(t_tetri **alst)
{
	t_tetri *tmp;
	t_tetri *tmp2;

	tmp = *alst;
	while (tmp)
	{
		tmp2 = tmp->next;
		ft_memdel((void **)alst);
		tmp = tmp2;
	}
	*alst = NULL;
}

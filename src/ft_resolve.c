/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:42:21 by thedupuy          #+#    #+#             */
/*   Updated: 2016/11/24 09:42:22 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_place(t_tetri *l, char **tab, t_coord *nb, char c)
{
	tab[nb->x + l->t[0].x][nb->y + l->t[0].y] = c;
	tab[nb->x + l->t[1].x][nb->y + l->t[1].y] = c;
	tab[nb->x + l->t[2].x][nb->y + l->t[2].y] = c;
	tab[nb->x + l->t[3].x][nb->y + l->t[3].y] = c;
	ft_memdel((void **)&nb);
}

static int		ft_check(t_tetri *l, char **tab, int x, int y)
{
	int i;

	i = 0;
	tab[x + l->t[0].x][y + l->t[0].y] == '.' ? i++ : 0;
	tab[x + l->t[1].x][y + l->t[1].y] == '.' ? i++ : 0;
	tab[x + l->t[2].x][y + l->t[2].y] == '.' ? i++ : 0;
	tab[x + l->t[3].x][y + l->t[3].y] == '.' ? i++ : 0;
	if (i == 4)
	{
		ft_place(l, tab, ft_coord_size(x, y), l->c);
	}
	return (i == 4 ? 1 : 0);
}

static int		ft_resolve(t_tetri *list, char **tab, int size)
{
	int			x;
	int			y;
	t_tetri		*tmp;

	tmp = list;
	x = 0;
	if (list == NULL)
		return (1);
	while (x < size - tmp->mn.min)
	{
		y = 0;
		while (y < size - tmp->mn.max)
		{
			if (ft_check(tmp, tab, x, y))
			{
				if (ft_resolve(list->next, tab, size))
					return (1);
				else
					ft_place(tmp, tab, ft_coord_size(x, y), '.');
			}
			y++;
		}
		x++;
	}
	return (0);
}

void			ft_create_min_max(t_tetri *node)
{
	int i;

	i = 0;
	node->mn.min = node->t[i].x;
	node->mn.max = node->t[i].y;
	while (i < 4)
	{
		i++;
		if (node->mn.min < node->t[i].x)
			node->mn.min = node->t[i].x;
		if (node->mn.max < node->t[i].y)
			node->mn.max = node->t[i].y;
	}
}

void			ft_fillit(char *ag)
{
	t_tetri		*list;
	size_t		i;
	int			a;
	char		**tab;

	if (check_tetriminos(ag) == TRUE)
	{
		i = ft_count_d(ag);
		a = ft_sqrt(i);
		list = ft_create_lst(ag, i / 4);
		tab = ft_map(a);
		while (!ft_resolve(list, tab, a))
		{
			ft_deltab(tab, a);
			a++;
			tab = ft_map(a);
		}
		ft_print_tab(tab, a);
		ft_deltab(tab, a);
		ft_clean_lst(&list);
	}
	else
		ft_putstr("error\n");
}

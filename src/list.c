/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:39:26 by thedupuy          #+#    #+#             */
/*   Updated: 2016/11/24 08:41:07 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_create_coord(t_tetri *node, const char *s, int index)
{
	int i;
	int a;
	int	compt;

	i = 0;
	a = 0;
	compt = 0;
	while (compt != 4)
	{
		if (s[index] == '\n')
		{
			a = -1;
			i++;
		}
		if (s[index] == '#')
		{
			node->t[compt].x = i;
			node->t[compt].y = a;
			compt++;
		}
		a++;
		index++;
	}
}

static void			ft_replace_coord(t_tetri *node)
{
	t_tetri *tmp;

	tmp = node;
	while (tmp)
	{
		while (tmp->t[0].x != 0 && tmp->t[1].x != 0
			&& tmp->t[2].x != 0 && tmp->t[3].x != 0)
		{
			tmp->t[0].x = tmp->t[0].x - 1;
			tmp->t[1].x = tmp->t[1].x - 1;
			tmp->t[2].x = tmp->t[2].x - 1;
			tmp->t[3].x = tmp->t[3].x - 1;
		}
		while (tmp->t[0].y != 0 && tmp->t[1].y != 0
			&& tmp->t[2].y != 0 && tmp->t[3].y != 0)
		{
			tmp->t[0].y = tmp->t[0].y - 1;
			tmp->t[1].y = tmp->t[1].y - 1;
			tmp->t[2].y = tmp->t[2].y - 1;
			tmp->t[3].y = tmp->t[3].y - 1;
		}
		ft_create_min_max(tmp);
		tmp = tmp->next;
	}
}

static void			ft_add_to_list(t_tetri **lst, t_tetri *new)
{
	t_tetri	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
}

static t_tetri		*ft_create_node(const char *s, int index, char c)
{
	t_tetri	*node;
	int		i;
	int		b;
	int		a;

	i = 0;
	b = 0;
	a = index;
	if ((node = (t_tetri *)ft_memalloc(sizeof(t_tetri))) == NULL)
		return (NULL);
	node->c = c;
	node->next = NULL;
	ft_create_coord(node, s, a);
	return (node);
}

t_tetri				*ft_create_lst(const char *s, size_t i)
{
	t_tetri *lst;
	int		c;
	int		index;

	index = 0;
	c = 65;
	lst = NULL;
	while (i != 0)
	{
		ft_add_to_list(&lst, ft_create_node(s, index, c));
		c++;
		i--;
		index = index + 21;
	}
	ft_replace_coord(lst);
	return (lst);
}

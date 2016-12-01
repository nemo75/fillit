/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_error_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:09:14 by thedupuy          #+#    #+#             */
/*   Updated: 2016/12/01 03:27:28 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_height(const char *s, int a)
{
	int b;

	b = 0;
	while (s[a + 1] != '\0')
	{
		if (s[a] == '.' || s[a] == '#')
			a++;
		else if (s[a] == '\n' && (s[a + 1] == '.' || s[a + 1] == '#'))
		{
			b++;
			a++;
		}
		else if ((s[a] == '\n') && (s[a + 1] == '\n')
				&& (s[a + 2] == '.' || s[a + 2] == '#'))
		{
			if (b != 3)
				return (FALSE);
			a = a + 2;
			b = 0;
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

int			check_carac(const char *s)
{
	int i;
	int b;

	b = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			s[i + 1] == '#' ? b++ : 0;
			s[i - 1] == '#' ? b++ : 0;
			s[i + 5] == '#' ? b++ : 0;
			s[i - 5] == '#' ? b++ : 0;
			if (b < 1)
				return (FALSE);
		}
		b = 0;
		i++;
	}
	return (TRUE);
}

int			check_return(const char *s)
{
	int b;
	int len;

	b = 0;
	len = 0;
	while (s[len])
	{
		if (s[len] == '\n')
			b++;
		if (b == 3 && s[len + 1] == '\0')
			return (TRUE);
		if (b == 4 && s[len + 1] == '\n')
			b = -1;
		if (b == 4 && s[len + 1] != '\n' && s[len + 1] != '\0')
			return (FALSE);
		len++;
	}
	return (TRUE);
}

int			check_pos(const char *s, size_t i)
{
	if ((s[i - 5] == '#' && s[i + 1] == '#') ||
			(s[i + 5] == '#' && s[i - 1] == '#')
			|| (s[i + 1] == '#' && s[i - 1] == '#')
			|| (s[i + 5] == '#' && s[i - 5] == '#')
			|| (s[i + 1] == '#' && s[i + 5] == '#')
			|| (s[i - 1] == '#' && s[i - 5] == '#'))
		return (TRUE);
	return (FALSE);
}

int			cc2(const char *s, int n, size_t p, size_t k)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == '#')
			if (check_pos(s, i) == 1)
				k++;
		if ((s[i] == '\n' && s[i + 1] == '\n')
			|| (s[i] == '\n' && s[i - 1] == '\n'))
		{
			k = 0;
			n = 0;
		}
		s[i] == '\n' ? n++ : 0;
		if ((n == 4 || ((n == 3) && i < 20)) && k >= 1)
		{
			p++;
			n = 0;
			k = 0;
		}
		i++;
	}
	return (p >= (ft_count_d(s) / 4) ? TRUE : FALSE);
}

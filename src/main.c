/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 07:25:21 by thedupuy          #+#    #+#             */
/*   Updated: 2016/11/28 07:25:29 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strlen(read_file(argv[1])) < 545)
		{
			ft_fillit(read_file(argv[1]));
		}
		else
			ft_putstr("error\n");
		return (0);
	}
	else
		write(2, "Usage : Fillit don't have a good number of input.\n", 50);
}

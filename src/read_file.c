/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbricqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:52:26 by thbricqu          #+#    #+#             */
/*   Updated: 2016/11/03 16:52:27 by thbricqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*read_file(const char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*file_read;

	fd = open(argv, O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if ((file_read = (char *)malloc(sizeof(char) * ret)) == NULL)
		return (NULL);
	close(fd);
	file_read = buf;
	return (file_read);
}

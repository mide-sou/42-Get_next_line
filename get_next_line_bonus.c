/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-sou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:32:21 by mide-sou          #+#    #+#             */
/*   Updated: 2022/04/05 15:05:39 by mide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE];
	char		*line;
	int			i;
	int			docsize;	

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1 || fd > 1024)
		return (0);
	line = NULL;
	i = 1;
	/* Enquanto o documento ainda não tiver chegado ao fim docsize > 0 e a linha nao tiver chegado ao fim \n */
	while (i)
	{
		docsize = 1;
		if (!buff[fd][0])
			docsize = read(fd, buff[fd], BUFFER_SIZE);
		i = (check_line_end(buff[fd]) && docsize > 0);
		if (docsize > 0)
			line = get_line(line, buff[fd]);
		clean_buff(buff[fd]);
	}
	return (line);
}

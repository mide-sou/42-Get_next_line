/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-sou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:33:15 by mide-sou          #+#    #+#             */
/*   Updated: 2022/03/31 17:33:16 by mide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*get_line(char *line, char *buff)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = line;
	line = malloc(sizeof(char) * ft_strlen(buff) + ft_strlen(line) + 1);
	if (!line)
		return (NULL);
	while (temp && temp[i])
	{
		line[i] = temp[i];
		i++;
	}
	while (buff[j])
	{
		line[i + j] = buff[j];
		if (buff[j++] == '\n')
			break ;
	}
	line[i + j] = '\0';
	if (temp)
		free(temp);
	return (line);
}

void	clean_buff(char *buff)
{
	int	i;
	int	j;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			buff[i] = 0;
			i++;
			break ;
		}
		buff[i] = 0;
		i++;
	}
	j = 0;
	while (buff[i])
	{
		buff[j] = buff[i];
		buff[i] = 0;
		i++;
		j++;
	}
}

int	check_line_end(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	return (buff[i] != '\n');
}

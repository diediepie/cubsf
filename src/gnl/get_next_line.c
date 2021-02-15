/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:29:22 by am-khant          #+#    #+#             */
/*   Updated: 2021/01/26 19:50:15 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"

int	check_save(char **save, char **line)
{
	char *str;
	char *tmp;

	str = NULL;
	if (*save)
	{
		if ((str = ft_strchr(*save, '\n')))
		{
			*str = '\0';
			*line = ft_strjoin(*line, *save);
			tmp = ft_strdup(++str);
			free(*save);
			*save = tmp;
			return (1);
		}
		else
		{
			*line = ft_strjoin(*line, *save);
			free(*save);
			*save = NULL;
		}
	}
	return (0);
}

int	check_error(int fd, char **line)
{
	char	c;

	if (fd < 0 || read(fd, &c, 0) < 0 || BUFFER_SIZE < 0 || !line)
		return (-1);
	return (0);
}

int	free_return(char *buf, int b)
{
	free(buf);
	return (b);
}

int	get_next_line(int fd, char **line)
{
	static char *save;
	char		*buf;
	char		*str;
	int			ret;

	*line = ft_strdup("");
	if (check_error(fd, line) == -1)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (check_save(&save, line) == 1)
		return (free_return(buf, 1));
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		if ((str = ft_strchr(buf, '\n')))
		{
			*str = '\0';
			save = ft_strdup(++str);
			*line = ft_strjoin(*line, buf);
			return (free_return(buf, 1));
		}
		*line = ft_strjoin(*line, buf);
	}
	return (free_return(buf, 0));
}
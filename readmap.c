/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:53:52 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 16:15:36 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

int		check_file(char *file, char *found)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (file[i] != '\0')
	{
		if (file[i] == found[0])
		{
			j = 1;
			while (found[j] != '\0' && file[i + j] == found[j])
				j++;
			if (found[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int		spacemap(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i++] == ' ')
			continue;
		else
			return (0);
	}
	return (1);
}

int		trimexist(char *str, int i)
{
	if (str[i + 1] == ' ')
		return (1);
	return (0);
}

int		count_char(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[j] != '\0')
	{
		if (str[j] == c)
			i++;
		j++;
	}
	return (i);
}

void	number_line(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (ft_strlen(line) > g_cols)
		g_cols = ft_strlen(line);
	if (line[i] == '1')
	{
		st_map = 1;
		end_map = end_map == -1 ? 0 : end_map;
		g_line += 1;
	}
	else
		return (ft_error("PROBLEM IN MAP BORDER"));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_readmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:15:04 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 17:33:39 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	checkendreadmap(void)
{
	if (g_info < 8)
		return (ft_error("PROBLEM IN MAP FILE INFO STRUCTURE"));
	else
		return (ft_error("MAP STARTED WITH WRONG CARACTERE"));
}

void	teck_cond(int i, char *line)
{
	if (line[i] == '\n')
		return ;
	else if (line[i] == 'R')
		take_r(line);
	else if (line[i] == 'N' && line[i + 1] == 'O')
		take_no(line);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		take_so(line);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		take_we(line);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		take_ea(line);
	else if (line[i] == 'S')
		take_s(line);
	else if (line[i] == 'F')
		take_f(line);
	else if (line[i] == 'C')
		take_c(line);
	else if (g_info >= 8 && line[i] == '1')
		number_line(line);
	else if (line[i])
		checkendreadmap();
}

void	get_info_map(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (st_map == 1 && line[0] != '\n' && spacemap(line))
	{
		i = 0;
		line[i] = ft_strlen(line) > 0 ? '1' : '\0';
	}
	teck_cond(i, line);
}

void	read_map(char *filename)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (ft_error("PROBLEM IN FILE"));
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (st_map == 1 && spacemap(line) == 1)
			end_map = (line[0] == '\0' && end_map == 0) ? 1 : end_map;
		if (st_map == 1 && spacemap(line) == 1 && line[0] == ' ')
			push(g_emptylines, g_line);
		get_info_map(line);
		free(line);
		if (ret == 0)
			break ;
	}
	readmap_g_check();
	if (!(g_map = (char **)malloc(sizeof(char*) * (g_line + 1))))
		return (ft_error("PROBLEM IN MAP"));
}

void	get_map(char *filename)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	ret = 0;
	i = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return ((void)ft_error("WRONG IN FILE"));
	end_map = -1;
	st_map = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		gstcheck(line, i);
		if (st_map == 1 && (line[0] == ' ' || line[0] == '1'))
			check_map(line);
		i += (st_map == 1 && (line[0] == ' ' || line[0] == '1')) ? 1 : 0;
		free(line);
		if (ret == 0)
			break ;
	}
	check_map_error();
}

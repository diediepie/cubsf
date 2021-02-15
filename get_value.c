/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:52:12 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/12 19:44:25 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	take_r(char *line)
{
	int		i;
	char	**info;

	if (g_wid >= 0 && g_height >= 0)
		return (ft_error("Duplicated R config"));
	i = 0;
	info = ft_split(line, ' ');
	if (line[0] != 'R')
		return (ft_error("Something wrong Before R"));
	while (info[i] != NULL)
		i++;
	if (i != 3)
		return (ft_error("Something wrong in R"));
	if (ft_atoi(info[1]) < 0 || ft_atoi(info[2]) < 0)
		return (ft_error("Negative  R config"));
	g_wid = btwn(ft_atoi(info[1]), 0, 80) == 1 ? 80 : ft_atoi(info[1]);
	g_height = btwn(ft_atoi(info[2]), 0, 80) == 1 ? 80 : ft_atoi(info[2]);
	ft_free(info, 3);
	g_info++;
}

void	take_no(char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (g_path_no != NULL)
		return (ft_error("Duplicated NO config"));
	if (line[0] != 'N')
		return (ft_error("Something wrong Before NO"));
	if (!check_file(line, ".xpm"))
		return (ft_error("WRONG IN NO FILE"));
	i += 2;
	if (!trimexist(line, i - 1))
		return (ft_error("Something wrong after NO"));
	while (line[i] && line[i] == ' ')
		i++;
	g_path_no = (char*)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	while (line[i++])
		g_path_no[j++] = line[i - 1];
	g_path_no[j--] = '\0';
	while (g_path_no[j] && g_path_no[j] == ' ')
		g_path_no[j--] = '\0';
	if (open(g_path_no, O_RDONLY) < 0)
		return (ft_error("NO FILE Not Exist"));
	g_info++;
}

void	take_so(char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (g_path_so != NULL)
		return (ft_error("Duplicated SO config"));
	if (line[0] != 'S')
		return (ft_error("Something wrong Before SO"));
	if (!check_file(line, ".xpm"))
		return (ft_error("WRONG IN SO FILE"));
	i += 2;
	if (!trimexist(line, i - 1))
		return (ft_error("Something wrong after SO"));
	while (line[i] && line[i] == ' ')
		i++;
	g_path_so = (char*)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	while (line[i++])
		g_path_so[j++] = line[i - 1];
	g_path_so[j--] = '\0';
	while (g_path_so[j] && g_path_so[j] == ' ')
		g_path_so[j--] = '\0';
	if (open(g_path_so, O_RDONLY) < 0)
		return (ft_error("NO FILE Not Exist"));
	g_info++;
}

void	take_we(char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (g_path_we != NULL)
		return (ft_error("Duplicated WE config"));
	if (line[0] != 'W')
		return (ft_error("Something wrong Before WE"));
	if (!check_file(line, ".xpm"))
		return (ft_error("WRONG IN WE FILE"));
	i += 2;
	if (!trimexist(line, i - 1))
		return (ft_error("Something wrong after WE"));
	while (line[i] && line[i] == ' ')
		i++;
	g_path_we = (char*)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	while (line[i++])
		g_path_we[j++] = line[i - 1];
	g_path_we[j--] = '\0';
	while (g_path_we[j] && g_path_we[j] == ' ')
		g_path_we[j--] = '\0';
	if (open(g_path_we, O_RDONLY) < 0)
		return (ft_error("WE FILE Not Exist"));
	g_info++;
}

void	take_ea(char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (g_path_ea != NULL)
		return (ft_error("Duplicated EA config"));
	if (line[0] != 'E')
		return (ft_error("Something wrong Before EA"));
	if (!check_file(line, ".xpm"))
		return (ft_error("WRONG IN EA FILE"));
	i += 2;
	if (!trimexist(line, i - 1))
		return (ft_error("Something wrong after EA"));
	while (line[i] && line[i] == ' ')
		i++;
	g_path_ea = (char*)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	while (line[i++])
		g_path_ea[j++] = line[i - 1];
	g_path_ea[j--] = '\0';
	while (g_path_ea[j] && g_path_ea[j] == ' ')
		g_path_ea[j--] = '\0';
	if (open(g_path_ea, O_RDONLY) < 0)
		return (ft_error("EA FILE Not Exist"));
	g_info++;
}

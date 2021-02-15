/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_check_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:23:58 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/12 12:39:50 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

int		check_char(char c)
{
	if (c == '1' || c == '0' || c == '2' || c == 'N'
			|| c == 'W' || c == 'E' || c == 'S' || c == ' ')
		return (1);
	return (0);
}

int		notinfo(char *line)
{
	int		i;

	i = 0;
	if (g_info < 8)
		ft_error("missing information");
	while (line[i] || line[i] == ' ')
		i++;
	if (line[i] == 'N' || line[i] == 'W' || line[i] == 'E' || line[i] == 'S' ||
		line[i] == 'R' || line[i] == 'F' || line[i] == 'C')
		return (1);
	return (0);
}

int		around_map(int i, int j)
{
	if (g_map[i][j - 1] == ' ')
		return (0);
	if (g_map[i][j + 1] == ' ')
		return (0);
	if (g_map[i - 1][j] == ' ' || g_map[i - 1][j] == '\0')
		return (0);
	if (g_map[i + 1][j] == ' ' || g_map[i + 1][j] == '\0')
		return (0);
	return (1);
}

void	checkround(void)
{
	if (ck_horizontal(g_map[0]) == 0)
		return ((void)ft_error("WRONG IN MAP in first Line"));
	if (!spacemap(g_map[g_line - 1]))
	{
		if (ck_horizontal(g_map[g_line - 1]) == 0)
			return ((void)ft_error("WRONG IN MAP in Last Line"));
	}
	else
	{
		if (checklastline(g_line - 1) == 1)
			return ((void)ft_error("WRONG IN MAP last Line RC"));
	}
}

void	check_map_error(void)
{
	int	i;
	int j;

	i = -1;
	while (++i < g_line)
	{
		ck_empty_line(i, g_emptylines);
		j = -1;
		if (g_map[i])
		{
			while (g_map[i][++j] != '\0')
			{
				if (check_char(g_map[i][j]) == 0)
					ft_error("WRONG IN CHAR IN MAP");
				if ((g_map[i][j] == '0' || g_map[i][j] == '2' ||
					check_player(g_map[i][j]) == 1) && around_map(i, j) == 0)
					ft_error("WRONG IN MAP something not secured");
			}
			if (g_map[i][j - 1] != '1' && g_map[i][j - 1] != ' ')
				return ((void)ft_error("WRONG IN MAP not 1"));
		}
	}
}

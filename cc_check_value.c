/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_check_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:39:36 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 17:33:53 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

int		check_sprite(int x, int y)
{
	int index_x;
	int index_y;

	index_x = (int)floor(x / TILE_SIZE);
	index_y = (int)floor(y / TILE_SIZE);
	if (index_x > g_cols || index_x < 0 || index_y < 0 || index_y > g_line)
		return (0);
	if (g_map[index_y][index_x] == '2')
		return (1);
	return (0);
}

void	checkduplicat(char c, char *line)
{
	if (c == 'F')
	{
		if (g_clr_f[0] >= 0 && g_clr_f[1] >= 0 && g_clr_f[2] >= 0)
			return (ft_error("Duplicated F config"));
		if (!trimexist(line, 0))
			return (ft_error("Something wrong after F"));
	}
	if (c == 'C')
	{
		if (g_clr_c[0] >= 0 && g_clr_c[1] >= 0 && g_clr_c[2] >= 0)
			return (ft_error("Duplicated C config"));
		if (!trimexist(line, 0))
			return (ft_error("Something wrong after C"));
	}
}

int		skipnull(char **heap)
{
	int	i;

	i = 0;
	while (heap[i] != NULL)
		i++;
	return (i);
}

void	gstcheck(char *line, int i)
{
	st_map = ((line[0] == '1' || line[0] == ' ') &&
			!spacemap(line) && st_map == 0) ? 1 : st_map;
	end_map = (st_map == 1 && end_map == -1) ? 0 : end_map;
	end_map = (st_map == 2 && line[0] == '\0') ? 1 : end_map;
	if (st_map == 1 && end_map == 0 && line[0] == '\0' && i < g_line)
		ft_error("newline in map\n");
}

void	readmap_g_check(void)
{
	if (g_info != 8)
		return (ft_error("NO INFO ENOUGH"));
	if (ft_strlen(g_path_no) == 0 || ft_strlen(g_path_so) == 0
	|| ft_strlen(g_path_we) == 0 || ft_strlen(g_path_ea) == 0
	|| ft_strlen(g_path_s) == 0)
		return (ft_error("WRONG IN INFO"));
	if (g_line == 0)
		return (ft_error("NO MAP"));
}

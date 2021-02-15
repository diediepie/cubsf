/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:56:58 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 16:09:18 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	inchar(int i, int j)
{
	g_map[i][j] = (g_map[i][j] == ' ' ||
	g_map[i][j] == '\0') ? '1' : g_map[i][j];
}

void	fill_with_wall(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->player.direction = '\0';
	while (i < g_row)
	{
		j = 0;
		while (j < g_cols)
		{
			inchar(i, j);
			if (check_player(g_map[i][j]))
			{
				if (check_player(info->player.direction))
					return ((void)ft_error("THERE IS MULTI PLAYER"));
				info->player.x = (j + 0.5) * TILE_SIZE;
				info->player.y = (i + 0.5) * TILE_SIZE;
				info->player.direction = g_map[i][j];
			}
			j++;
		}
		i++;
	}
	if (!info->player.direction)
		return ((void)ft_error("WHERE IS PLAYER?"));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ft_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:38:54 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/12 16:40:40 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	draw_2d(t_info *info)
{
	int		i;
	int		j;
	int		color;
	t_icord	tile;
	t_idim	diment;

	i = 0;
	while (i < g_row)
	{
		j = 0;
		tile.y = i * TILE_SIZE;
		while (j < g_cols)
		{
			color = g_map[i][j] == '1' ?
			create_rgb(255, 255, 255) : create_rgb(0, 0, 0);
			initpoint(&tile, tile.x * MAP_RATIO, tile.y * MAP_RATIO);
			initdim(&diment, TILE_SIZE * MAP_RATIO, TILE_SIZE * MAP_RATIO);
			tile.x = j * TILE_SIZE;
			ft_rect(info, tile, diment, color);
			j++;
		}
		i++;
	}
}

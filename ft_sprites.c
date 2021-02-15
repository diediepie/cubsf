/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:59:07 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/12 18:52:33 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	draw_sprite(t_info *info, float txt_x, float txt_y, int id)
{
	int i;
	int	j;
	int c;
	int size;

	i = -1;
	size = info->sprite[id].size;
	while (++i < size)
	{
		if (txt_x + i < 0 || txt_x + i > g_wid
		|| info->ray[(int)(txt_x + i)].distance <= info->sprite[id].distance)
			continue ;
		j = -1;
		while (++j < size)
		{
			if ((int)(j + txt_y) * g_wid +
			(int)(i + txt_x) >= g_height * g_wid
			|| txt_y + j < 0 || txt_y + j > g_height)
				continue;
			c = info->sprite_buff[info->width_spt * (info->height_spt * j /
			size) + (info->width_spt * i / size)];
			if (c != 0)
				info->img.data[(int)(j + txt_y) * g_wid + (int)(i + txt_x)] = c;
		}
	}
}

void	draw_sprites(t_info *info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_sprite)
	{
		info->sprite[i].distance = dist_points(info->player.x
			, info->player.y, info->sprite[i].x, info->sprite[i].y);
		i++;
	}
	sort_sprites(info->sprite);
	while (j < g_sprite)
	{
		norm_angle_spt(info, j);
		info->sprite[j].size = g_wid / info->sprite[j].distance * TILE_SIZE;
		cal_sprite_texture(info, j);
		draw_sprite(info, info->sprite[j].txt_x, info->sprite[j].txt_y, j);
		j++;
	}
}

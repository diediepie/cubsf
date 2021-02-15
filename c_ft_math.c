/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ft_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:44:03 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/14 18:58:54 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

float	pitg(float h, float w)
{
	return (sqrt(pow(h, 2) + pow(w, 2)));
}

void	sort_sprites(t_sprite *sprite)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < g_sprite)
	{
		j = 0;
		while (j < g_sprite - i)
		{
			if (sprite[j].distance < sprite[j + 1].distance)
			{
				temp = sprite[j];
				sprite[j] = sprite[j + 1];
				sprite[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	cal_sprite_texture(t_info *info, int j)
{
	info->sprite[j].txt_x = (DEG(info->sprite[j].angle) -
	DEG(info->player.rotation_angle)) * g_wid / DEG(FOV_ANGLE) +
	((g_wid / 2) - (info->sprite[j].size / 2));
	info->sprite[j].txt_y = g_height / 2 - info->sprite[j].size / 2;
}

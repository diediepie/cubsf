/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:07:06 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 19:21:59 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

unsigned long	create_rgb(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}

void			my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;

	if (x < g_wid && y < g_height && y >= 0 && x >= 0)
	{
		dst = info->img.addr + (y * info->img.line_length + x *
				(info->img.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void			ft_rect(t_info *info, t_icord pnt, t_idim dim, int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < dim.h)
	{
		j = 0;
		while (j < dim.w)
		{
			my_mlx_pixel_put(info, pnt.x + j, pnt.y + i, color);
			j++;
		}
		i++;
	}
}

void			draw_ori(t_info *info, double angle, int color, double dist)
{
	int length;

	length = 0;
	while (length < dist)
	{
		my_mlx_pixel_put(info, (info->player.x + cos(angle) * length),
						(info->player.y + sin(angle) * length), color);
		length++;
	}
}

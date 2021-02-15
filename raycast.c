// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   raycast.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/02/09 19:49:21 by am-khant          #+#    #+#             */
// /*   Updated: 2021/02/14 18:57:30 by am-khant         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "src/cub3d.h"

// void	cast_ray_hor2(t_rays *rays)
// {
// 	float x;
// 	float y;

// 	while (mapborder(rays->next_x, rays->next_y))
// 	{
// 		x = rays->next_x;
// 		y = rays->next_y + (rays->is_up ? -1 : 0);
// 		if (is_wall(x, y) == 1)
// 		{
// 			rays->horzwall_x = rays->next_x;
// 			rays->horzwall_y = rays->next_y;
// 			rays->found_hor = 1;
// 			break ;
// 		}
// 		else
// 		{
// 			rays->next_x += rays->xstep;
// 			rays->next_y += rays->ystep;
// 		}
// 	}
// }

// void	cast_ray_hor(t_info *info, t_rays *rays, float angle)
// {
// 	rays->yintercept = floor(info->player.y / TILE_SIZE) * TILE_SIZE;
// 	rays->yintercept += rays->is_down ? TILE_SIZE : 0;
// 	rays->xintercept = info->player.x + (rays->yintercept - info->player.y) /
// 						tan(angle);
// 	rays->ystep = TILE_SIZE;
// 	rays->ystep *= rays->is_up ? -1 : 1;
// 	rays->xstep = TILE_SIZE / tan(angle);
// 	rays->xstep *= (rays->is_left && rays->xstep > 0) ? -1 : 1;
// 	rays->xstep *= (rays->is_right && rays->xstep < 0) ? -1 : 1;
// 	rays->next_x = rays->xintercept;
// 	rays->next_y = rays->yintercept;
// 	cast_ray_hor2(rays);
// }

// void	cast_ray_ver2(t_rays *rays)
// {
// 	float x;
// 	float y;

// 	while (rays->next_ver_x > 0 && rays->next_ver_x < TILE_SIZE * g_cols &&
// 			rays->next_ver_y > 0 && rays->next_ver_y < TILE_SIZE * g_line)
// 	{
// 		x = rays->next_ver_x + (rays->is_left ? -1 : 0);
// 		y = rays->next_ver_y;
// 		if (is_wall(x, y) == 1)
// 		{
// 			rays->vertwall_x = rays->next_ver_x;
// 			rays->vertwall_y = rays->next_ver_y;
// 			rays->found_vert = 1;
// 			break ;
// 		}
// 		else
// 		{
// 			rays->next_ver_x += rays->xstep;
// 			rays->next_ver_y += rays->ystep;
// 		}
// 	}
// }

// void	cast_ray_ver(t_info *info, t_rays *rays, float angle)
// {
// 	rays->xintercept = floor(info->player.x / TILE_SIZE) * TILE_SIZE;
// 	rays->xintercept += rays->is_right ? TILE_SIZE : 0;
// 	rays->yintercept = info->player.y
// 	+ (rays->xintercept - info->player.x) * tan(angle);
// 	rays->xstep = TILE_SIZE;
// 	rays->xstep *= rays->is_left ? -1 : 1;
// 	rays->ystep = TILE_SIZE * tan(angle);
// 	rays->ystep *= (rays->is_up && rays->ystep > 0) ? -1 : 1;
// 	rays->ystep *= (rays->is_down && rays->ystep < 0) ? -1 : 1;
// 	rays->next_ver_x = rays->xintercept;
// 	rays->next_ver_y = rays->yintercept;
// 	cast_ray_ver2(rays);
// }

// float	dist_btwn_pnts(float x1, float y1, float x2, float y2)
// {
// 	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
// }

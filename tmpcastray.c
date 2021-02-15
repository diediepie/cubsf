/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmpcastray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:23:05 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/15 11:56:06 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	cast_r_hor2(t_rays *rays, float angle)
{
	t_fcord	tocheck;

	rays->found_hor = 0;
	rays->next_hor.x = rays->inter.x;
	rays->next_hor.y = rays->inter.y;
	while (is_inside_map(rays->next_hor.x, rays->next_hor.y)) {
		tocheck.x = rays->next_hor.x;
		tocheck.y = rays->next_hor.y + (is_rayfacing_up(angle) ? -1 : 0);

		if (is_wall(tocheck.x, tocheck.y)) {
			rays->horzwall.x = rays->next_hor.x;
			rays->horzwall.y = rays->next_hor.y;
			rays->found_hor = 1;
			break;
		} else {
			rays->next_hor.x += rays->step.x;
			rays->next_hor.y += rays->step.y;
		}
	}
}

void	cast_r_ver2(t_rays *rays, float angle)
{
	t_fcord	tocheck;

	rays->found_vert  = 0;
	rays->next_ver.x = rays->inter.x;
	rays->next_ver.y = rays->inter.y;
	while (is_inside_map(rays->next_ver.x, rays->next_ver.y)) {
		tocheck.x = rays->next_ver.x + (is_rayfacing_left(angle) ? -1 : 0);
		tocheck.y = rays->next_ver.y;

		if (is_wall(tocheck.x, tocheck.y)) {
			rays->vertwall.x = rays->next_ver.x;
			rays->vertwall.y = rays->next_ver.y;
			rays->found_vert  = 1;
			break;
		} else {
			rays->next_ver.x += rays->step.x;
			rays->next_ver.y += rays->step.y;
		}
	}
}

void	cast_r_hor(t_info *info, t_rays *rays, float angle)
{

	rays->inter.y = floor(info->player.y / TILE_SIZE) * TILE_SIZE;
	rays->inter.y += is_rayfacing_down(angle) ? TILE_SIZE : 0;
	rays->inter.x = info->player.x + (rays->inter.y - info->player.y) / tan(angle);
	rays->step.y = TILE_SIZE;
	rays->step.y *= is_rayfacing_up(angle) ? -1 : 1;
	rays->step.x = TILE_SIZE / tan(angle);
	rays->step.x *= (is_rayfacing_left(angle) && rays->step.x > 0) ? -1 : 1;
	rays->step.x *= (is_rayfacing_right(angle) && rays->step.x < 0) ? -1 : 1;
	rays->next_hor.x = rays->inter.x;
	rays->next_hor.y = rays->inter.y;
	cast_r_hor2(rays, angle);
}

void	cast_r_ver(t_info *info, t_rays *rays, float angle)
{
	rays->inter.x = floor(info->player.x / TILE_SIZE) * TILE_SIZE;
	rays->inter.x += is_rayfacing_right(angle) ? TILE_SIZE : 0;
	rays->inter.y = info->player.y + (rays->inter.x - info->player.x) * tan(angle);
	rays->step.x = TILE_SIZE;
	rays->step.x *= is_rayfacing_left(angle) ? -1 : 1;
	rays->step.y = TILE_SIZE * tan(angle);
	rays->step.y *= (is_rayfacing_up(angle) && rays->step.y > 0) ? -1 : 1;
	rays->step.y *= (is_rayfacing_down(angle) && rays->step.y < 0) ? -1 : 1;
	rays->next_ver.x = rays->inter.x;
	rays->next_ver.y = rays->inter.y;
	cast_r_ver2(rays, angle);

}
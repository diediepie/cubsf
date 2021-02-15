/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_tmpcastray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:48:36 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/15 12:05:05 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

float	dist_btwn_pnts(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	mesure_dist(t_info *info, t_rays *rays)
{
	rays->horzHitDist = rays->found_hor
		? dist_btwn_pnts(info->player.x, info->player.y, rays->horzwall.x, rays->horzwall.y)
		: INT_MAX;
	rays->vertHitDist = rays->found_vert
		? dist_btwn_pnts(info->player.x, info->player.y, rays->vertwall.x, rays->vertwall.x)
		: INT_MAX;
}

void	cast_ray(t_info *info, t_rays *rays,  float rayangl, int strpid)
{
	rayangl = normalize_angle(rayangl);
	cast_r_ver(info, rays, rayangl);
	cast_r_hor(info, rays, rayangl);
	mesure_dist(info, rays);
	if (rays->vertHitDist < rays->horzHitDist) {
		rays[strpid].distance = rays->vertHitDist;
		rays[strpid].wall.x = rays->vertwall.x;
		rays[strpid].wall.y = rays->vertwall.y;
		rays[strpid].is_vert = 1;
		rays[strpid].angle = rayangl;
		printf("V-ray[%d]= %f \n",strpid,rays[strpid].distance);
	} else {
		rays[strpid].distance = rays->horzHitDist;
		rays[strpid].wall.x = rays->horzwall.x;
		rays[strpid].wall.y = rays->horzwall.y;
		rays[strpid].is_vert = 0;
		rays[strpid].angle = rayangl;
		printf("H-ray[%d]= %f \n",strpid,rays[strpid].distance);
	}
}
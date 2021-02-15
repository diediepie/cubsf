/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:56:57 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 19:20:10 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	norm_angle_spt(t_info *info, int j)
{
	float	angle;

	angle = atan2(info->sprite[j].y - info->player.y
		, info->sprite[j].x - info->player.x);
	while (angle - info->player.rotation_angle > M_PI)
		angle -= 2 * M_PI;
	while (angle - info->player.rotation_angle <= -M_PI)
		angle += 2 * M_PI;
	info->sprite[j].angle = angle;
}

float	normalize_angle(float angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

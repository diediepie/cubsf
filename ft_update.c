/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:17:46 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 19:18:05 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	update_player(t_info *info)
{
	int		sprite;
	float	arrow_lr;
	float	move_step;

	move_step = info->player.walk_dir * info->player.walk_speed;
	arrow_lr = info->player.arrow_lr * info->player.walk_speed;
	info->player.rotation_angle += info->player.turn_dir *
	info->player.rot_speed;
	info->player.next_x = info->player.x + (info->player.walk_dir *
	info->player.walk_speed * cos(info->player.rotation_angle))
	+ (info->player.arrow_lr * info->player.walk_speed *
	cos(info->player.rotation_angle + RAD(90)));
	info->player.next_y = info->player.y + (info->player.walk_dir *
	info->player.walk_speed * sin(info->player.rotation_angle))
	+ (info->player.arrow_lr * info->player.walk_speed *
	sin(info->player.rotation_angle + RAD(90)));
	sprite = check_sprite(info->player.next_x, info->player.next_y);
	if (is_wall(info->player.next_x, info->player.next_y) == 0 && !sprite)
	{
		info->player.x = info->player.next_x;
		info->player.y = info->player.next_y;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:04:05 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/12 16:42:41 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

int		key_press(int key, t_info *info)
{
	if (key == KEY_UP)
		info->player.walk_dir = +1;
	else if (key == KEY_DOWN)
		info->player.walk_dir = -1;
	else if (key == KEY_RIGHT)
		info->player.turn_dir = +1;
	else if (key == KEY_LEFT)
		info->player.turn_dir = -1;
	else if (key == RIGHT)
		info->player.arrow_lr = +1;
	else if (key == LEFT)
		info->player.arrow_lr = -1;
	else if (key == ESC)
	{
		mlx_destroy_window(info->mlx_ptr, info->mlx_win);
		free_window(info);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int		key_release(int key, t_info *info)
{
	if (key == KEY_UP)
		info->player.walk_dir = 0;
	else if (key == KEY_DOWN)
		info->player.walk_dir = 0;
	else if (key == KEY_RIGHT)
		info->player.turn_dir = 0;
	else if (key == KEY_LEFT)
		info->player.turn_dir = 0;
	else if (key == RIGHT)
		info->player.arrow_lr = 0;
	else if (key == LEFT)
		info->player.arrow_lr = 0;
	return (1);
}

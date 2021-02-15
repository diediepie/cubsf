/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:47:19 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/12 12:20:59 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

int	is_rayfacing_down(float angle)
{
	return (angle > 0 && angle < M_PI);
}

int	is_rayfacing_up(float angle)
{
	return (!is_rayfacing_down(angle));
}

int	is_rayfacing_right(float angle)
{
	return (angle < 0.5 * M_PI || angle > 1.5 * M_PI);
}

int	is_rayfacing_left(float angle)
{
	return (!is_rayfacing_right(angle));
}

int	is_inside_map(float x, float y)
{
	return (x >= 0 && x <= g_cols * TILE_SIZE && y >= 0 &&
			y <= g_row * TILE_SIZE);
}

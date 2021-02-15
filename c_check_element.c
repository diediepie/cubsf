/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_check_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:17:10 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/12 12:22:16 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

int	is_wall(float x, float y)
{
	int	index_x;
	int	index_y;

	index_x = (int)floor(x / TILE_SIZE);
	index_y = (int)floor(y / TILE_SIZE);
	if (index_x > g_cols || index_x < 0 || index_y < 0 || index_y >= g_line)
		return (1);
	if (g_map[index_y][index_x] == '1')
		return (1);
	return (0);
}

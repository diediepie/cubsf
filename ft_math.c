/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:40:58 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/14 18:58:35 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

int		btwn(float n, float star, float end)
{
	if (n >= star && n <= end)
		return (1);
	return (0);
}

void	count_sprite(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '2')
			g_sprite++;
		i++;
	}
}

int		dist_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int		mapborder(float x, float y)
{
	if (btwn(x, 0, TILE_SIZE * g_cols) &&
		btwn(y, 0, TILE_SIZE * g_line))
		return (1);
	return (0);
}

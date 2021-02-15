/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:19:11 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/15 11:58:28 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	initialise_ray(t_rays *rays)
{
	rays->angle = 0;
	rays->distance = 0;
	rays->is_vert = 0;
	rays->is_up = 0;
	rays->is_down = 0;
	rays->is_left = 0;
	rays->is_right = 0;
	rays->found_hor = 0;
	f_initpoint(&rays->wall, 0, 0);
	f_initpoint(&rays->inter, 0, 0);
	f_initpoint(&rays->step, 0, 0);
	f_initpoint(&rays->next, 0, 0);
	f_initpoint(&rays->horzwall, 0, 0);
	f_initpoint(&rays->vertwall, 0, 0);
	f_initpoint(&rays->next_ver, 0, 0);
	f_initpoint(&rays->next_hor, 0, 0);
	f_initpoint(&rays->check, 0, 0);
	rays->found_vert = 0;
}

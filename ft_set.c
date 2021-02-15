/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:05:36 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 19:49:53 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	initpoint(t_icord *point, double x, double y)
{
	point->x = x;
	point->y = y;
}

void	f_initpoint(t_fcord *point, double x, double y)
{
	point->x = x;
	point->y = y;
}

void	initdim(t_idim *dim, int w, int h)
{
	dim->w = w;
	dim->h = h;
}

char	*ft_strdup2(char *s)
{
	char	*temp;
	int		i;
	int		c;

	if ((temp = (char*)malloc(sizeof(char) * (g_cols + 1))) == NULL)
		return (NULL);
	i = 0;
	c = 49;
	while (s[i])
	{
		temp[i] = s[i];
		i++;
	}
	while (i < g_cols)
	{
		temp[i] = 0;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

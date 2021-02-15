/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:33:49 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/14 19:40:46 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	init_empty_strct(void)
{
	if (!(g_emptylines = (t_lnkd *)malloc(sizeof(t_lnkd))))
		ft_error("Empy line alloc  erroc");
	g_emptylines->val = 0;
	g_emptylines->next = NULL;
}

void	initialise_map(void)
{
	int i;

	g_wid = -1;
	g_height = -1;
	g_line = 0;
	g_sprite = 0;
	g_row = 0;
	g_cols = 0;
	g_info = 0;
	i = 0;
	while (i < 3)
		g_clr_c[i++] = -1;
	i = 0;
	while (i < 3)
		g_clr_f[i++] = -1;
	st_map = 0;
	end_map = -1;
	init_empty_strct();
}

void	init_sprite(t_info *info)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	if (!(info->sprite = (t_sprite*)malloc(sizeof(t_sprite) * (g_sprite + 1))))
		return ((void)ft_error("ERROR: PROBLEM IN ALLOCATION"));
	while (i < g_line)
	{
		j = 0;
		while (g_map[i][j])
		{
			if (g_map[i][j] == '2')
			{
				info->sprite[k].x = (j + 0.5) * TILE_SIZE;
				info->sprite[k].y = (i + 0.5) * TILE_SIZE;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	initialise_mlx(t_info *info)
{
	info->mlx_ptr = mlx_init();
	mlx_get_screen_size(info->mlx_ptr, &g_sizex, &g_sizey);
	if (g_wid < 80 || g_height < 80)
		return ((void)ft_error("ERROR: Too small < 80"));
	g_wid = g_wid > g_sizex ? g_sizex : g_wid;
	g_height = g_height > g_sizey ? g_sizey : g_height;
	info->mlx_win = mlx_new_window(info->mlx_ptr, g_wid, g_height, "cub3d");
	info->img.img = mlx_new_image(info->mlx_ptr, g_wid, g_height);
	info->img.addr = mlx_get_data_addr(info->img.img, &info->img.bits_per_pixel
		, &info->img.line_length, &info->img.endian);
	info->img.data = (int *)info->img.addr;
	ft_texture(info);
	init_sprite(info);
	if (!(info->ray = malloc(sizeof(t_rays) * (NUM_RAYS + 1))))
		return ((void)ft_error("ERROR: PROBLEM IN ALLOCATION"));
}

void	initialise_player(t_info *info)
{
	if (info->player.direction == 'N')
		info->player.rotation_angle = RAD(270);
	else if (info->player.direction == 'W')
		info->player.rotation_angle = RAD(180);
	else if (info->player.direction == 'S')
		info->player.rotation_angle = RAD(90);
	else if (info->player.direction == 'E')
		info->player.rotation_angle = RAD(0);
	info->player.rot_speed = 5 * (M_PI / 180);
	info->player.turn_dir = 0;
	info->player.walk_dir = 0;
	info->player.walk_speed = g_wid * SPD;
	info->player.arrow_lr = 0;
}

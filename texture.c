/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:05:27 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 17:53:28 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	ft_texturesize(int height, int width)
{
	if (height != TILE_SIZE || width != TILE_SIZE)
		ft_error("ERROR: PROBLEM IN TEXTURE SIZE (64x64)");
}

void	ft_texture2(t_info *info)
{
	void	*image;
	int		end;

	image = mlx_xpm_file_to_image(info->mlx_ptr, g_path_ea
		, &info->txt.width[3], &info->txt.height[3]);
	ft_texturesize(info->txt.height[3], info->txt.width[3]);
	if (image == (void*)0)
		return (ft_error("ERROR: PROBLEM IN TEXTURE EA"));
	info->txt.buff[3] = (int*)mlx_get_data_addr(image, &info->txt.bpp[3]
		, &info->txt.length[3], &end);
	image = mlx_xpm_file_to_image(info->mlx_ptr, g_path_s
		, &info->width_spt, &info->height_spt);
	if (image == (void*)0)
		return (ft_error("ERROR: PROBLEM IN TEXTURE S"));
	info->sprite_buff = (int*)mlx_get_data_addr(image, &end, &end, &end);
}

void	ft_texture(t_info *info)
{
	void	*image;
	int		end;

	image = mlx_xpm_file_to_image(info->mlx_ptr, g_path_no
		, &info->txt.width[0], &info->txt.height[0]);
	ft_texturesize(info->txt.height[0], info->txt.width[0]);
	if (image == (void*)0)
		return (ft_error("ERROR: PROBLEM IN TEXTURE NO"));
	info->txt.buff[0] = (int*)mlx_get_data_addr(image, &info->txt.bpp[0]
		, &info->txt.length[0], &end);
	image = mlx_xpm_file_to_image(info->mlx_ptr, g_path_so
		, &info->txt.width[1], &info->txt.height[1]);
	ft_texturesize(info->txt.height[1], info->txt.width[1]);
	if (image == (void*)0)
		return (ft_error("ERROR: PROBLEM IN TEXTURE SO"));
	info->txt.buff[1] = (int*)mlx_get_data_addr(image, &info->txt.bpp[1]
		, &info->txt.length[1], &end);
	image = mlx_xpm_file_to_image(info->mlx_ptr, g_path_we
		, &info->txt.width[2], &info->txt.height[2]);
	ft_texturesize(info->txt.height[2], info->txt.width[2]);
	if (image == (void*)0)
		return (ft_error("ERROR: PROBLEM IN TEXTURE WE"));
	info->txt.buff[2] = (int*)mlx_get_data_addr(image, &info->txt.bpp[2]
		, &info->txt.length[2], &end);
	ft_texture2(info);
}

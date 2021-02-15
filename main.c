/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 17:57:04 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/15 12:08:49 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"




int	get_color(t_info *info, int x, int y, int id)
{
	char	*dst;
	int color;
	dst = (char*)info->txt.buff[id] + (y * info->txt.length[id] + x * (info->txt.bpp[id] / 8));
	color  = *(unsigned int*)dst;
	return color;
}


void	generate_3d(t_info *info, float ray_angle, int i)
{
	float ray_distance =  info->ray[i].distance * cos(info->ray[i].angle - info->player.rotation_angle);	
	float distance_from_player_proj = (g_wid / 2) / tan(FOV_ANGLE / 2);
	
	float wall_height = (TILE_SIZE /  ray_distance) * distance_from_player_proj;
	int wallStripHeight = (int)wall_height;
	int wall_top = (g_height / 2) - (wallStripHeight / 2);
	if(wall_top < 0){
		wall_top = 0;
	}
	int wall_bottom = (g_height / 2) + (wallStripHeight / 2);
	if(wall_bottom > g_height)
		wall_bottom = g_height;

	int j = wall_top;
	for (int y = 0; y < wall_top; y++) {
			my_mlx_pixel_put(info, i, y, create_rgb(g_clr_c[0],g_clr_c[1],g_clr_c[2]));
	}
	int wall = 0;
	int color;
	if (info->ray[i].is_vert && is_rayfacing_left(info->ray[i].angle))
		wall = 2;
	else if (info->ray[i].is_vert && is_rayfacing_right(info->ray[i].angle))
		wall = 3;
	else if (!info->ray[i].is_vert && is_rayfacing_up(info->ray[i].angle))
		wall = 0;
	else if (!info->ray[i].is_vert && is_rayfacing_down(info->ray[i].angle))
		wall = 1;
	info->txt.txt_x = info->ray[i].is_vert ? ((int)info->ray[i].wall.y %
	info->txt.width[wall]) * (info->txt.width[wall] / TILE_SIZE) :
	((int)info->ray[i].wall.x % info->txt.width[wall]) * (info->txt.width[wall]
	/ TILE_SIZE);
	for (int y = wall_top; y < wall_bottom; y++)
	{
		info->txt.txt_y = y + (wall_height / 2) - (g_height / 2);
		info->txt.txt_y *= info->txt.height[wall] / wall_height;
		color = get_color(info, info->txt.txt_x, info->txt.txt_y, wall);
		my_mlx_pixel_put(info, i, y, color);
	}
	for (int y = wall_bottom; y < g_height; y++) {
		my_mlx_pixel_put(info, i, y, create_rgb(g_clr_f[0],g_clr_f[1],g_clr_f[2]));
	}

}

void rays_casting(t_info *info){
	float ray_angle;
	int i;

	i = 0;

	ray_angle = info->player.rotation_angle - (FOV_ANGLE / 2);
	while(i < NUM_RAYS ){
		cast_ray(info, info->ray, ray_angle, i);
		// draw_ori(info, ray_angle, create_rgb(255,0,0), info->ray[i].distance);
		generate_3d(info, ray_angle, i);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		i++;
	}
}

void fill_header(t_info *info)
{
	//must always be set to 'BM' to declare that this is a .bmp-file.
	info->header[0] = 'B';
	info->header[1] = 'M';
	//specifies the size of the file in bytes.
	info->header[2] = (unsigned char)(info->filesize);
	info->header[3] = (unsigned char)(info->filesize>> 8); //shift
	info->header[4] = (unsigned char)(info->filesize>>16);
	info->header[5] = (unsigned char)(info->filesize>>24);

	info->header[10] = 54; //specifies the offset from the beginning of the file to the bitmap data.
	info->header[14] = 40; //specifies the size of the BITMAPINFOHEADER structure, in bytes. stdvalue is 40
	//	specifies the width of the image, in pixels.
	info->header[18] = (unsigned char)(g_wid);
	info->header[19] = (unsigned char)(g_wid>> 8);
	info->header[20] = (unsigned char)(g_wid>>16);
	info->header[21] = (unsigned char)(g_wid>>24);
	//specifies the height of the image, in pixels.
	info->header[22] = (unsigned char)(g_height);
	info->header[23] = (unsigned char)(g_height>> 8);
	info->header[24] = (unsigned char)(g_height>>16);
	info->header[25] = (unsigned char)(g_height>>24);
	//specifies the number of planes of the target device set default to 1
	info->header[26] = 1; // number color planes
	//	specifies the number of bits per pixel. 24 (16.7 million colors)
	info->header[28] = 24;// bits per pixel
}

void colorconverter(t_rgb *g_color, int value)
{

	g_color->r = ((value >> 16) & 0xFF);
	g_color->g = ((value >> 8) & 0xFF);
	g_color->b = ((value) & 0xFF);
}

int   get_color_scr(t_info *info, int x, int y)
{
	char	*dst;
	int color;
	dst = info->img.addr + (y * info->img.line_length + x * (info->img.bits_per_pixel / 8));
	color =  *(unsigned int*)dst;
	return (color);
}
void fill_img_sc(t_info *info)
{
	int i;
	t_rgb g_color;
	
	i = 0;
	info->imgs = (unsigned char *)malloc(info->imagesize);
	ft_memset(info->imgs,0,info->imagesize);
	for(int i=0; i< g_wid; i++)
	{
		for(int j=0; j< g_height; j++)
		{
			int x=i; 
			int y=(g_height-1)-j;
			int color = get_color_scr(info, x, y);
			colorconverter(&g_color, color);
			info->imgs[(x+y*g_wid)*3+2] = (unsigned char)(g_color.r);
			info->imgs[(x+y*g_wid)*3+1] = (unsigned char)(g_color.g);
			info->imgs[(x+y*g_wid)*3+0] = (unsigned char)(g_color.b);
		}
	}
}
void ft_screen(t_info *info)
{
	unsigned char *img;
	int fd;
	//BYTES_PER_PIXEL = 3; /// red, green, & blue
	//const int FILE_HEADER_SIZE = 14; const int INFO_HEADER_SIZE = 40;
	// 54 = 14 bits for file and 40 for info
	if(g_wid < 80 || g_height < 80)
		ft_error("GAME RESOLUTION UGLY  (TOO SMALL <80)");
	info->filesize = 54 + 3 * g_wid * g_height; 
	//info->imagesize = (((g_wid * 24 + 31) / 32) * 4) * g_height;
	info->imagesize = g_wid * 3 * g_height;
	ft_bzero(info->header, 54);
	fill_header(info);
	fill_img_sc(info);
	fd = open("screen.bmp", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	write(fd, info->header, 54);
	for(int i=0; i< g_height; i++)
	{
		write(fd, info->imgs+(g_wid*(g_height-i-1)*3), g_wid * 3);
	}
	
	close(fd);
	free(info->imgs);
}
int		draw(t_info *info){
	update_player(info);
	draw_2d(info);
	rays_casting(info);
	draw_sprites(info);
	if (g_screenshot == 1)
	{
		printf("screeen");
		ft_screen(info);
		ft_putstr("NOTICE : ");
		ft_putstr("screen done");
		ft_putchar('\n');
		exit(EXIT_SUCCESS);
	}
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img.img, 0, 0);
	clear_window(info);
	return (1);
}

int		destroy(t_info *info)
{
		mlx_destroy_window(info->mlx_ptr, info->mlx_win);
		free_window(info);
		exit(EXIT_SUCCESS);
}
// map read ended
int main(int argc, char **argv){
	t_info *info;

	g_screenshot = 0;
	if (!(info = malloc(sizeof(t_info))))
		return (-1);
	read_check_map(info, argc, argv);

	// print_result();
	// printf("nline = %d\n",g_line);
	// printf("nline = %d\n",countlnk(g_emptylines));
	initialise_mlx(info);
	initialise_player(info);
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img.img, 0, 0);
	mlx_hook(info->mlx_win, 2, 1L << 0, key_press, info);
	mlx_hook(info->mlx_win, 3, 1L << 1, key_release, info);
	mlx_hook(info->mlx_win, 17, 0L, destroy, info);
	mlx_loop_hook(info->mlx_ptr, draw, info);
	mlx_loop(info->mlx_ptr);
}
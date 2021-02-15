
#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

signed	int		g_wid;
signed	int		g_height;
int		g_sizex;
int		g_sizey;
char	**g_map;
char	*g_path_no;
char	*g_path_so;
char	*g_path_we;
char	*g_path_ea;
char	*g_path_s;
signed int		g_clr_f[3];
signed int		g_clr_c[3];
int		g_sprite;
int		g_row;
int		g_cols;
int		g_info;
int		g_line;
int		g_screenshot;
int		g_error;
int 	st_map;
signed int end_map;

	int				bpp_sprite;
	int				buff_length;

# define ESC 53
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define LEFT 0
# define RIGHT 2
# define TILE_SIZE 64
# define SPD 0.02
# define MAP_RATIO 1
# define RAD(x) x * M_PI / 180
# define DEG(x) x * 180 / M_PI
# define Wall_STRIPE_WIDTH 10
# define FOV_ANGLE RAD(60)
# define NUM_RAYS g_wid 

typedef struct		s_lnkd
{
	int val;
	struct s_lnkd * next;
}					t_lnkd;

t_lnkd			* g_emptylines;

typedef struct		s_fcord
{
	float			x;
	float			y;
}					t_fcord;

typedef struct		s_icord
{
	int			x;
	int			y;
}					t_icord;

typedef struct		s_idim
{
	int			h;
	int			w;
}					t_idim;

typedef struct		s_player
{
	float			x;
	float			y;
	float			next_x;
	float			next_y;
	int				size;
	float			rotation_angle;
	float			rot_speed;
	float			walk_speed;
	float			turn_dir;
	float			walk_dir;
	float			arrow_lr;
	char			direction;
}					t_player;
typedef struct		s_txt
{
	float			*walltxt;
	int				width[4];
	int				height[4];
	int				*buff[4];
	int				txt_x;
	int				txt_y;
	int				bpp[4];
	int				length[4];
}					t_txt;
typedef struct		s_data
{
	void			*img;
	int				*data;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;
typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_rays
{
	float			angle;
	t_fcord			wall;
	float			distance;
	int				is_up;
	int				is_down;
	int				is_left;
	int				is_right;
	t_fcord			inter;
	t_fcord			step;
	t_fcord			next;
	t_fcord			horzwall;
	int				found_hor;
	t_fcord			check;
	int				is_vert;
	t_fcord			next_ver;
	t_fcord			next_hor;
	t_fcord			vertwall;
	int				found_vert;
	float			horzHitDist;
	float			vertHitDist;
}					t_rays;

typedef struct		s_ray
{
	float			angle;
	float			wall_x;
	float			wall_y;
	float			distance;
	int				is_up;
	int				is_down;
	int				is_left;
	int				is_right;
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
	float			next_x;
	float			next_y;
	float			horzwall_x;
	float			horzwall_y;
	int				found_hor;
	float			x_check;
	float			y_check;
	int				is_vert;
	float			next_ver_x;
	float			next_ver_y;
	float			vertwall_x;
	float			vertwall_y;
	int				found_vert;
}					t_ray;


typedef struct		s_sprite
{
	int				*buff;
	float			x;
	float			y;
	float			txt_x;
	float			txt_y;
	float			size;
	float			distance;
	float			angle;
}					t_sprite;
typedef struct		s_info
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_data			img;
	t_player		player;
	t_txt			txt;
	t_rays			*ray;
	t_sprite		*sprite;
	int				*sprite_buff;
	int				width_spt;
	int				height_spt;
	int				wall_height;
	float			top_wall;
	float			bottom_wall;
	unsigned char	header[54];
	unsigned char	*imgs;
	int				filesize;
	int				imagesize;
}					t_info;


void 			push(t_lnkd * head, int val);
void			printlink(t_lnkd *head);
int				countlnk(t_lnkd *head);
void			ft_error(char *message);
void 			initialise_map(void);
void			init_empty_strct(void);
void			readmap_g_check(void);
void			read_map(char *filename);
int				trimexist(char *str,int i);
int				btwn(float n,float star,float end);
void			initpoint(t_icord *point, double x, double y);
void			f_initpoint(t_fcord *point, double x, double y);
void			initdim(t_idim *dim, int w, int h);
int				spacemap(char *line);
void			ft_free(char **heap, int j);
void			get_info_map(char *line);
void			checkduplicat(char c, char *line);
int				skipnull(char **heap);
void			freetake(char **mem2, char **mem3, char line_c, char c);
void			take_r(char *line);
void			take_no(char *line);
void			take_so(char *line);
void			take_we(char *line);
void			take_ea(char *line);
void			take_s(char *line);
void			take_f(char *line);
void			take_c(char *line);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				check_file(char *file, char *found);
int				count_char(char *str,char c);
int				check_arg_save(char *str, char *found);
void			number_line(char *line);
void			gstcheck(char *line, int i);
void			get_map(char *filename);
void			check_map(char *line);
void			count_sprite(char *line);
char			*ft_strdup2(char *s);
void			checkround(void);
void			check_map_error(void);
int				ck_horizontal(char *str);
int				checklastline(int line);
int				check_player(char c);
void			inchar(int i, int j);
void 			fill_with_wall(t_info *info);
void 			read_check_map(t_info *info, int argc, char **argv);
void 			free_window(t_info *info);
void 			ck_empty_line(int linenumb,t_lnkd *head);
int				check_char(char c);
int				around_map(int i, int j);
int 			notinfo(char *line);
int 			key_press(int key, t_info *info);
int				key_release(int key, t_info *info);
void			ft_texturesize(int	height,int	width);
void			ft_texture(t_info *info);
void 			initialise_mlx(t_info *info);
void			init_sprite(t_info *info);
unsigned long	create_rgb(int r, int g, int b);
void			my_mlx_pixel_put(t_info *info, int x, int y, int color);
void 			ft_rect(t_info *info, t_icord pnt, t_idim dim, int color);
void 			ft_line(t_info *info,int xs,int ys,int xe,int ye);
void 			draw_ori(t_info *info, double angle, int color, double dist);
void 			draw_2d(t_info *info);
void 			initialise_player(t_info *info);
void			clear_window(t_info *data);
int				check_sprite(int x, int y);
int 			is_wall(float x, float y);
void 			initialise_ray(t_rays *rays);
int	 			dist_points(float x1, float y1, float x2, float y2);
int 			mapborder(float x,float y);
// void			cast_ray_hor2(t_rays *rays);
// void			cast_ray_hor(t_info *info, t_rays *rays, float angle);
// void			cast_ray_ver2(t_rays *rays);
// void			cast_ray_ver(t_info *info, t_rays *rays, float angle);
////////////////////
void			cast_r_ver2(t_rays *rays, float angle);
void			cast_r_hor2(t_rays *rays, float angle);
void			cast_r_ver(t_info *info, t_rays *rays, float angle);
void			cast_r_hor(t_info *info, t_rays *rays, float angle);
void			mesure_dist(t_info *info, t_rays *rays);
void			cast_ray(t_info *info, t_rays *rays,  float rayangl, int strpid);
////////////////////
float 			pitg(float h,float w);
float			dist_btwn_pnts(float x1, float y1, float x2, float y2);
int				is_rayfacing_down(float angle);
int 			is_rayfacing_up(float angle);
int				is_rayfacing_right(float angle);
int				is_rayfacing_left(float angle);
int				is_inside_map(float x, float y);
void			norm_angle_spt(t_info *info, int j);
void			sort_sprites(t_sprite *sprite);
void			cal_sprite_texture(t_info *info, int j);
void			draw_sprite(t_info *info, float txt_x, float txt_y, int id);
void			draw_sprites(t_info *info);
void			update_player(t_info *info);
float			normalize_angle(float angle);
#endif

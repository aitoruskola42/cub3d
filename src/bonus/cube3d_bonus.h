/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:04:59 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/27 13:42:46 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_BONUS_H
# define CUBE3D_BONUS_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef MLX_H
#  include "../../minilibx-linux/mlx.h"
#  include "../../minilibx-linux/mlx_int.h"
# endif
# ifndef GET_NEXT_LINE_BONUS_H
#  include "get_next_line_bonus.h"
# endif

# define MLX_ERROR 1
# define MAP3D 1
# define GAME_NAME "Cub3D"
# define MAX_X_SIZE 1080
# define MAX_Y_SIZE 1080
# define MAX_COLS 100
# define MAX_ROWS 100
# define WIDTH_3D_IMAGE 300
# define FOV 66
# define RAY_SEPARATOR 1
# define MINIMAP_CUBE_SIZE 20
# define COLOR_RAY_PLAYER 0xff0000
# define COLOR_RAY_WALL 0x5c4033
# define COLOR_RAY 0xd3d3d3
# define COLOR_RAY_COLLISION 0x00FF00
# define DEBUG2DMAP 15
# define DEBUG2DMAPSMALL 20
# define BONUS 1
# define BONUS_RAY 1
# define CORRECT_HEIGHT 100
# define CAMERA_MOVE_SPEED 1
# define PLAYER_MOVE_SPEED 20
# define COLISION_DETECTOR 50

typedef unsigned long	t_size_t;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		previous_pos_x;
	int		previous_pos_y;
	double	direction_x;
	double	direction_y;
	double	camera_x;
	double	camera_y;
	double	ray_direction_x;
	double	ray_direction_y;
	double	map_x;
	double	map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	plane_x;
	double	plane_y;
	double	time;
	double	old_time;
	double	square_x;
	double	square_y;
}	t_player;

typedef struct s_mi_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		rows;
	int		cols;
	int		endian;
}	t_mi_img;

typedef struct s_colors
{
	int		red;
	int		green;
	int		blue;
	char	*color;
}	t_colors;

typedef struct s_debug
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		posx;
	int		posy;
	int		hit;
	int		columna2;
	int		linea20;
	int		inicial_x;
	int		inicial_y;
	int		pos_jugador_x;
	int		pos_jugador_y;
	double	dist_correct;
	int		contador;
	double	grados;
	double	rayangle;
	double	distancia;
	int		linea2;
	int		k;
}	t_debug;

typedef struct s_data
{
	int			i;
	int			j;
	char		*argv_map;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_copy_ptr;
	t_mi_img	*img_copy;
	char		*img_copy_buffer;
	char		**check_map;
	int			check_pos[MAX_X_SIZE][MAX_Y_SIZE];
	int			started_map_values;
	int			rows;
	int			cols;
	int			res;
	int			frames;
	int			window_width;
	int			window_height;
	char		*north_pic;
	char		*south_pic;
	char		*east_pic;
	char		*west_pic;
	t_colors	floor_color;
	t_colors	cell_color;
	int			debug_mode;
	int			this_row;
	int			this_col;
	int			previous_row;
	int			previous_col;
	char		**map;//[200][200];
	t_mi_img	img;
	void		*mlx;
	char		*game_title;
	long		rending;
	int			animation;
	t_player	player;
	int			you_win;
	int			you_lost;
	t_mi_img	*background_img;
	t_mi_img	*background_pic;
	t_mi_img	*north_img;
	int			north;
	int			south;
	int			east;
	int			west;
	int			north_cols[WIDTH_3D_IMAGE][WIDTH_3D_IMAGE];
	int			south_cols[WIDTH_3D_IMAGE][WIDTH_3D_IMAGE];
	int			east_cols[WIDTH_3D_IMAGE][WIDTH_3D_IMAGE];
	int			west_cols[WIDTH_3D_IMAGE][WIDTH_3D_IMAGE];
	t_mi_img	*south_img;
	t_mi_img	*west_img;
	t_mi_img	*east_img;	
	t_mi_img	*player_img;	
	t_mi_img	*empty_img;
	t_mi_img	*wall_img;
	t_mi_img	*cell_img;
	t_mi_img	*floor_img;
	float		move_speed;
	float		rot_speed;
	int			rotate;
	int			started;
	int			altitud;
	int			up;
	int			down;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
	int			pixel_bits;
	int			line_bits;
	int			pixel_bits2;
	int			line_bits2;
	int			endian;
	int			image_posy;
	int			player_x_pos_check;
	int			player_y_pos_check;
	int			colision_check;
	int			made_malloc;
	int			paso_x;
	int			paso_y;
	int			movimiento_x;
	int			movimiento_y;
	t_debug		my_debug;
}	t_data;

int			check_argc(t_data *data, int number, char *argv[]);
char		**ft_split(char *s, char c);
void		map_error(t_data *data, char *description, int reason);
void		load_memory_images(t_data *data);
int			load_file(t_data *data, int row, int fd);
int			check_char(t_data *data, char key);
int			check_map_chars(t_data *data);
int			check_map(t_data *data, char *text);
int			check_map_line(t_data *data, char *text, int row);
int			check_map_line2(t_data *data, char *text, int row);
void		debug_map_definitions(t_data *data);
void		check_map_player(t_data *data, int x);
char		*ltrim(char *s);
char		*rtrim(char *s);
char		*trim(char *s);
int			ft_isspace(char c);
void		load_mlx(t_data *data);
int			render(t_data *data);
void		*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int			free_malloc1(t_data *data);
int			free_malloc2(t_data *data);
int			handle_keypress(int keysym, t_data *data);
int			handle_mouse(int keysym, t_data *data);
void		animate_background(t_data *data);
void		print_text_on_screen(t_data *data, char *text, int x, int y);
void		print_image_from_memory(t_data *data, t_mi_img *image);
void		time_exit(t_data *data);
void		animate_array_images(t_data *data, int x, int y);
char		*rgb_to_hex(unsigned int r, unsigned int g, unsigned int b);
void		img_pix_put(t_mi_img *img, int x, int y, int color);
void		write_on_file(char *str, const char *file_name);
void		empty_file(const char *file_name);
int			characters(long n);
char		*convert_str(char *str, long n, int numbers, int counter);
char		*ft_itoa(int valor);
int			check_map_finished(t_data *new_map);
int			check_mark(t_data *new_map, int x, int y);
int			check_valid_road(t_data *data);
void		bucle_on_file( const char *file_name);
void		load_height_and_width(t_data *data);
char		*ft_strtrim(char *s1, char *set);
size_t		ft_strlcpy(char *dst, char *src, size_t size);
void		debug_map(t_data *data);
void		print_animation_data2d(t_data *data);
void		print_animation_images2d(t_data *data);
void		print_animation_data3d(t_data *data);
void		print_animation_images3d(t_data *data, int x, int y);
void		rotate_image(t_data *data);
void		print_pixel(t_data *data, int x, int y, int color);
void		print_this_image(t_data *data, t_mi_img *img, int x, int y);
void		print_pixel_image(t_data *data, int x, int y, int color);
void		debug_cols(t_data *data);
void		copy_pixel_buffer(t_data *data, int x, int y, int color);
void		debug_ray(t_data *data);
void		debug_ray3d(t_data *data);
void		copy_image_buffer3d(t_data *data, t_mi_img *image, int pos_y);
void		copy_image_buffer_cols(t_data *d, t_mi_img *im, int (*m_c)[300]);
void		get_pixel2(t_data *data, int **mapa_cols, int cont, int altitud);
void		obtener_colores(t_data *data, char *cadena, char where);
void		load_initial_data(t_data *data);
void		load_initial_data2(t_data *data);
int			free_malloc(t_data *d);
void		make_malloc(t_data *d);
void		load_images(t_data *data);
double		calculate_distance(t_data *data, int x, int y);
void		get_pixel3(t_data *data, int (*m_c)[300], int cont, int hit_pos);
int			calculate_height(int distancia);
int			exit_click(t_data *data);
void		make_malloc2(t_data *d);
void		make_malloc3(t_data *d);
void		make_malloc4(t_data *d);
void		make_malloc5(t_data *d);
void		make_malloc6(t_data *d);
void		make_malloc7(t_data *d);
int			ft_key_press(int keysym, t_data *data);
int			ft_key_hook_release(int keysym, t_data *data);
void		make_move(t_data *data, double cosValue, double sinValue);
void		make_move2(t_data *data);
void		make_move3(t_data *data);
int			move_finish(t_data *data);
void		copy_image_buffer_cols2(t_data *data, int x, int y, int color);
void		option_check_camera_x(t_data *data);
void		print_hit_color(t_data *data, int resultado, int x, int y);
double		check_radian_angle(t_data *data, double pos);
int			print_ray(t_data *data, double distance, double radianAngle);
void		buffer_helper(t_data *data, t_mi_img *img, int *colo, int li_bits);
void		bucle_on_file2(int this_file, char *size);
int			check_map_char(t_data *data, char key, char *error_message);
void		load_memory_images2(t_data *data);
void		load_memory_images3(t_data *data);
void		load_memory_images4(t_data *data);
void		load_height_and_width2(t_data *data, char *text);
void		check_map_line_2(t_data *data, char *trimed, char *err_mess);
void		wrong_img(t_data *data, char *img_card);
void		check_map_line_3(t_data *data, char *trimed, char *err_mess);
void		check_map_line_4(t_data *data, char *trimed);
void		check_map_line_6(t_data *data, char *trimed, char *err_mess);
void		check_valid_road2(t_data *data);
void		check_map_error(t_data *data, int i, int j);
void		check_map_player(t_data *data, int x);
void		debug_cols_hit0(t_data *data);
void		debug_cols_hit1_1_1(t_data *data);
void		debug_cols_hit1_1(t_data *data);
void		debug_cols_hit1_2(t_data *data);
void		debug_cols_hit1_3(t_data *data, int p, int o);
void		start_cols_data1(t_data *data);
void		debug_cols_hit_0_1(t_data *data);
void		debug_cols_hit_0_2(t_data *data);
void		debug_cols_bucle_2(t_data *data);
void		make_move1(t_data *data, double cosValue, double sinValue);
void		make_move1_2(t_data *data, double cosValue, double sinValue);
void		make_move1(t_data *data, double cosValue, double sinValue);
void		make_move2(t_data *data);
void		make_move3(t_data *data);
void		make_move(t_data *data, double cosValue, double sinValue);
void		parse_hit_out(t_data *data);
void		load_textures_bonus(t_data *data);
void		debug_cols_hit_patch(t_data *data);
#endif

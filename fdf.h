/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:37:15 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/05 15:45:46 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HEIGHT 1600
#define WIDTH 2560
#define PI 3.1415926

typedef struct s_map
{
	char			*file;
	int				fd;
	int				map_y;
	int				map_x;
}					t_map;

typedef struct s_coordinates
{
	float			x;
	float			y;
	float			z;
}					t_coordinates;

typedef struct s_vector
{
	int				trans_z;
	int				tx;
	int				ty;
	int				tz;
	int				ax;
	int				ay;
	int				scale;
	int				proj;
}					t_vector;

typedef struct s_screen
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				bpp;
	int				endian;
	int				size_line;
	char			*position;
	int				prev_x;
	int				prev_y;
}					t_screen;

typedef struct s_data
{
	t_coordinates	*matrix;
	t_vector		*vector;
	t_screen		*screen;
	t_map			*map;
	t_coordinates	news;
	t_coordinates	prints;
}					t_data;

// matrix-vector math
void				trans_x(t_data *data, int i);
void				trans_y(t_data *data);
void				trans_z(t_data *data);
void				rotate(t_data *data, int i);
void				z_up_down(t_data *data, float num);
void				random_position(t_data *data);
void				dynamics(t_data *data);

// bresenham
void				row_lines(t_data *data, t_coordinates old,
						t_coordinates new, int i);
void				col_lines(t_data *data, t_coordinates old,
						t_coordinates new, int i);
void				bres_select(t_data *data, t_coordinates old,
						t_coordinates new, int i);
void				bres_x(t_data *data);
void				bres_y(t_data *data);
void				swap(t_coordinates *old, t_coordinates *new, int let);

// screen - map
void				map_size(t_map *map);
void				matrix_population(t_coordinates **matrix, t_map *map);
void				screen_init(t_screen *screen);
void				node_init(t_data *data, t_coordinates **matrix,
						t_vector *vector, t_screen *screen);
int					fdf_free(t_data *data);

// key gestion
void				keypress(int key, t_data *data);
int					key_knot(int key, t_data *data);
void				keypress_para(int key, t_data *data);

// transformations
float				rad(int degrees);
void				traslation(t_data *data, int dir);
void				x_rotation(t_data *data, int sign);
void				y_rotation(t_data *data, int sign);
void				z_rotation(t_data *data, int sign);
void				up_scale(t_data *data);
void				down_scale(t_data *data);

// parallel projection
void				x_rotation_para(t_data *data, int sign);
void				y_rotation_para(t_data *data, int sign);
void				z_rotation_para(t_data *data, int sign);

// render
void				render(t_data *data);
void				start(t_data *data);

// utils
void				print_vars(t_data *data);
void				my_pixel(t_data *data, float x, float y, int i);

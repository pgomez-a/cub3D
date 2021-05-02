/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:37:02 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/30 16:34:52 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <math.h>
# include <fcntl.h>

# define PI	3.141592654

typedef struct s_rep {
	int	re;
	int	no;
	int	so;
	int	ea;
	int	we;
	int	sp;
	int	fl;
	int	cl;
}	t_rep;

typedef struct s_re {
	int	x_axis;
	int	y_axis;
}	t_re;

typedef struct s_no {
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
	int		width;
	int		height;
}	t_no;

typedef struct s_so {
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
	int		width;
	int		height;
}	t_so;

typedef struct s_we {
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
	int		width;
	int		height;
}	t_we;

typedef struct s_ea{
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
	int		width;
	int		height;
}	t_ea;

typedef struct s_sp {
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
	int		width;
	int		height;
	int		tot;
	double	**buf;
	double	*zbuf;
	double	*dist;
	double	*order;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	int		screenX;
	int		startY;
	int		endY;
	int		startX;
	int		endX;
}	t_sp;

typedef struct s_cl {
	char	*floor;
	char	*ceiling;
	int		fl_red;
	int		fl_green;
	int		fl_blue;
	int		cl_red;
	int		cl_green;
	int		cl_blue;
}	t_cl;

typedef struct s_elem {
	t_rep	rep;
	t_re	res;
	t_no	north;
	t_so	south;
	t_we	west;
	t_ea	east;
	t_sp	sprite;
	t_cl	color;
}	t_elem;

typedef struct s_map {
	char	**matrix;
	int		x_axis;
	int		y_axis;
	int		player;
}	t_map;

typedef struct s_pl {
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	lirX;
	double	lirY;
	double	plnX;
	double	plnY;
}	t_pl;

typedef struct s_ry {
	double	dirX;
	double	dirY;
	double	sdistX;
	double	sdistY;
	double	ddistX;
	double	ddistY;
	double	stepX;
	double	stepY;
	double	wallDist;
	double	lineH;
}	t_ry;

typedef struct s_mp {
	char	**world;
	int		x;
	int		y;
	int		side;
	int		ceil;
	int		wall;
	int		floor;
}	t_mp;

typedef struct s_tx {
	double	wallX;
	double	step;
	double	texPos;
	int		texX;
	int		texY;
}	t_tx;

typedef struct s_mx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		end;
}	t_mx;

typedef struct s_ky {
	int		mv_up;
	int		mv_down;
	int		mv_left;
	int		mv_right;
	int		rt_left;
	int		rt_right;
}	t_ky;

typedef struct s_data {
	int		screen_W;
	int		screen_H;
	t_pl	ply;
	t_ry	ray;
	t_mp	map;
	t_tx	tex;
	t_mx	mlx;
	t_ky	key;
	t_no	nor;
	t_so	sou;
	t_ea	eas;
	t_we	wes;
	t_sp	spr;
}	t_data;

/* main.c */
void	ft_error(char *str);

/* cb_errors.c */
void	cb_check_elements(const char *str, t_elem *elems);

/* cb_err_txts.c */
void	cb_err_north(char **line, t_elem *elems);
void	cb_err_south(char **line, t_elem *elems);
void	cb_err_west(char **line, t_elem *elems);
void	cb_err_east(char **line, t_elem *elems);
void	cb_err_sprite(char **line, t_elem *elems);

/* cb_err_colres.c */
void	cb_copy_path(int count, char **str, char **line);
void	cb_err_resolution(char **line, t_elem *elems);
void	cb_err_floor(char **line, t_elem *elems);
void	cb_err_ceiling(char **line, t_elem *elems);

/* cb_err_map.c */
void	cb_check_map(const char *str, t_map *map);

/* cb_err_imap.c */
void	cb_create_map(const char *str, t_map *map);

/* cb_read_map.c */
void	cb_map_first(char **line, t_map *map);
void	cb_map_body(int fd, char **line, t_map *map);
void	cb_map_last(char **line, t_map *map);

/* cb_map_body.c */
void	cb_map_space(int pos, int count_x, char **line, t_map *map);
void	cb_map_other(int pos, int count_x, char **line, t_map *map);
void	cb_map_x(int pos, int count_x, char **line, t_map *map);

/* cb_cub.c  */
void	cb_cub(int verif, t_elem *elems, t_map *map);

/* cb_save.c */
void	cb_save(t_data *data);

/* cb_findspr.c */
void	cb_find_sprites(t_data *dt, t_map *map);
void	cb_sort_sprites(double *order, double *dist, int tot);

/* cb_renderframe.c */
int		cb_render_frame(t_data *dt);

/* cb_textures.c */
void	cb_north_texture(t_data *dt);
void	cb_south_texture(t_data *dt);
void	cb_east_texture(t_data *dt);
void	cb_west_texture(t_data *dt);
void	cb_sprite_texture(t_data *dt);

/* cb_texel.c */
void	cb_buff_no_wall(int x, int **buffer, t_data *dt);
void	cb_find_texX(t_data *dt);
void	cb_find_texPos(t_data *dt);
void	cb_buff_wall(int x, int **buffer, t_data *dt);

/* cb_sprites.c */
void	cb_sprites(int **buffer, t_data *dt);

/* cb_setdir.c */
void	cb_set_dir(char c, t_data *dt);

/* cb_keypress.c */
int		cb_key_press(int keycode, t_data *dt);
int		cb_key_release(int keycode, t_data *dt);

/* cb_change_move.c */
void	cb_mv_up(double mv, t_data *dt);
void	cb_mv_down(double mv, t_data *dt);
void	cb_mv_left(double mv, t_data *dt);
void	cb_mv_right(double mv, t_data *dt);
void	cb_change_values(t_data *data);

/* cb_change_rot.c */
void	cb_rot_right(double rot, t_data *dt);
void	cb_rot_left(double rot, t_data *dt);

/* err_utils.c */
void	cb_look_path(char *path);
int		cb_look_color(int *red, int *green, char *color);

/* utils.c */
void	my_mlx_pixel_put(t_data *dt, int x, int y, int color);
void	cb_init_buffer(int mode, int ***buffer, t_data *dt);
void	cb_draw_buffer(int **buffer, t_data *dt);
void	cb_draw_sprites(int width, int height, int **buffer, t_data *dt);

#endif

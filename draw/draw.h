/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:40:12 by alhote            #+#    #+#             */
/*   Updated: 2016/02/23 20:54:41 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "mlx.h"
# include "math.h"
# include <stdlib.h>

typedef struct	s_point
{
	double				x2d;
	double				y2d;
	double				x3d;
	double				y3d;
	double				z3d;
	char				enable;
	int					color;
	struct s_point		*next;
	struct s_point		*prev;
}				t_point;

typedef struct	s_segment
{
	t_point				**p;
	int					color;
	struct s_segment	*next;
	struct s_segment	*prev;
}				t_segment;

typedef struct	s_surface
{
	t_segment	**s;
	int			color;
}				t_surface;

typedef struct	s_camera
{
	double	x3d;
	double	y3d;
	double	z3d;
	double	vx;
	double	vy;
	double	vz;
	double	panx;
	double	pany;
	double	panz;
	double	zoom;
}				t_camera;

typedef struct	s_world
{
	void		*mlx;
	void		*win;
	int			sx;
	int			sy;
	double		centerx;
	double		centery;
	double		centerz;
	double		h;
	t_camera	*cam;
	t_point		*p;
	t_segment	*seg;
}				t_world;

t_world			*init_world(int screen_x, int screen_y, void *mlx, void *win);
int				add_point(t_world *w, double x, double y, double z);
int				add_segment_with_last_pts(t_world *w);
int				update_world_projection(t_world *w);
int				draw_world(t_world *w);
int				draw_point(t_point *point, t_world *w);
t_point			*init_point(double x, double y, double z, t_point *prev);
int				draw_segment(t_segment *seg, t_world *w);
t_segment		*init_segment(t_point *p1, t_point *p2, t_segment *prev);
int				draw_surface(t_point *point, void *mlx, void *win);
t_surface		*init_surface(int x, int y);
t_camera		*init_camera(double x, double y, double z);
int				project3dto2d_point(t_point *p, t_camera *cam, t_world *w);
void			cam_move_forward(t_camera *cam, double speed);
int				safe_pixel_put(t_world *w, int x, int y, int color);
int				rotate(t_world *w, double rx, double ry, double rz);
int				next_color(int color, int final, int dist);
double			cosfd(double v);
double			sinfd(double v);
double			cospc(double v);
double			sinpc(double v);
double			efmod(double a, double base);
#endif

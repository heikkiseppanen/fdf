/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:52:15 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/15 15:26:23 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "input.h"
#include "ft_math.h"

#include <libft.h>
#include <mlx.h>
#include <math.h> // for M_PI

static void gfx_init(t_draw_param *param, t_framebuf *buf)
{
	const	float	fov = M_PI / 2; 
	const	t_float3	view_pos = {0, 200, 200};
	const	t_float3	view_rot = {M_PI / 4, 0.0, 0.0}; 

	param->pos= (t_float3){0.0, 0.0, 0.0};
	param->rot= (t_float3){0.0, 0.0, 0.0};
	param->scale = (t_float3){1.0, 0.1, 1.0};
	param->project = float4x4_persp(fov, buf->height / buf->width, 0.1, 600);
	param->view = float4x4_view(&view_pos, &view_rot);
}

int	app_init(t_app *instance, char *map_path)
{
	ft_bzero(instance, sizeof(*instance));
	if (!window_init(&instance->win, 1024, 1024, "FdF"))
		return (0);
	if (!mesh_from_map(&instance->map, map_path))
		return (0);
	mlx_key_hook(instance->win.mlxwin, key_hook, instance);
	mlx_loop_hook(instance->win.mlx, app_mlx_loop, instance);
	mlx_hook(instance->win.mlxwin, ON_DESTROY, 0, app_terminate, instance);
	gfx_init(&instance->gfx, &instance->win.buf);
	return (1);
}

int	app_terminate(t_app *instance)
{
	mesh_destroy(&instance->map);
	window_destroy(&instance->win);
	exit(0);
	return (1);
}

int	app_mlx_loop(void *param)
{
	t_app *const	app = param;

	framebuf_clear(&app->win.buf);
	if (app->gfx.rot.y > 2 * M_PI)
		app->gfx.rot.y = 0;
	app->gfx.rot.y += 0.001;
	draw_wireframe(&app->win.buf, &app->map, &app->gfx);
	mlx_put_image_to_window(app->win.mlx, app->win.mlxwin, app->win.mlximg, 0, 0);
	return (1);
}

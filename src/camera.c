/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:31:54 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/09 12:07:10 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	cam_init(t_cam *empty, float fov, int is_ortho)
{
	empty->fov = fov;
	empty->orthographic = is_ortho;
	empty->clip_near = 0.1;
	empty->clip_far = 100;
	empty->x_axis = (t_float3){1.0, 0.0, 0.0};
	empty->y_axis = (t_float3){0.0, 1.0, 0.0};
	empty->z_axis = (t_float3){0.0, 0.0, -1.0};
}

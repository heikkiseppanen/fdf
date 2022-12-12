/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:48:33 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/12 13:50:32 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

#include <libft.h>

#include <fcntl.h>
#include <unistd.h>

#define MAP_READ_CHUNK_SIZE 64
#define MIN_VERTS 4

static t_dynarr	read_map(const char *filepath)
{
	const int	fd = open(filepath, O_RDONLY);
	ssize_t		read_output;
	t_dynarr	buf;

	buf.ptr = NULL;
	if (!dynarr_init(&buf, MAP_READ_CHUNK_SIZE, sizeof(char)))
		return (buf);
	read_output = 1;
	while (read_output > 0)
		read_output = dynarr_read(&buf, fd, MAP_READ_CHUNK_SIZE);
	dynarr_pushback(&buf, "\0", 1);
	close(fd);
	return (buf);
}

static int parse_map(t_mesh *empty, const t_dynarr *map_data)
{
	t_float3	vert;
	const char	*it = map_data->ptr;

	empty->width = 0;
	empty->depth = 0;
	while (*it)
	{
		vert = (t_float3){empty->width, empty->depth, ft_atoi(it)};
		dynarr_pushback(&empty->vertex_arr, &vert, 1);
		empty->width++;
		while (ft_isdigit(*it) || ',')
			it++;
		while (*it == ' ')
			it++;
		if (*it == '\n')
		{
			empty->width = 0;
			empty->depth++;
			it++;
		}
	}
	empty->width = empty->vertex_arr.size / empty->depth;
	return (1);
}

static void center_mesh(t_mesh *mesh)
{
	const float	offset_x = mesh->height / 2;
	const float	offset_y = mesh->depth / 2;
	t_float3	*it;
	t_float3	*end;
	
	it = mesh->vertex_array.ptr;
	end = it + mesh->vertex_array.size;
	while (it != end)
	{
		it->x -= offset_x;
		it->y -= offset_y;
		it++;
	}
}

int	mesh_from_map(t_mesh *empty, const char *filepath)
{
	t_dynarr	map_data;

	map_data = read_map(filepath);
	if (!map_data.size)
	{
		dynarr_del(&map_data);
		return (0);
	}
	dynarr_init(&empty->vertex_arr, MIN_VERTS * 3, sizeof(t_float3));
	if (!parse_map(empty, &map_data))
	{
		dynarr_del(&map_data);
		return (0);
	}
	center_mesh(empty);
	return (1);
}

void	mesh_destroy(t_mesh *mesh)
{
	dynarr_del(&mesh->vertex_arr);
}
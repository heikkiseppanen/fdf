/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:15:17 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/09 10:31:14 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNARR_H
# define DYNARR_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_dynarr
{
	void	*ptr;
	size_t	type_size;
	size_t	size;
	size_t	cap;
}			t_dynarr;

void	*dynarr_init(t_dynarr *arr, size_t size, size_t type_size);
void	dynarr_del(t_dynarr *arr);
void	*dynarr_resize(t_dynarr *arr, size_t new_cap);
ssize_t	dynarr_read(t_dynarr *arr, int fd, size_t bytes);

#endif

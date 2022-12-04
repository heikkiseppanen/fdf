/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:38:42 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/03 17:58:15 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

// TODO This is not portable, should use X11 directly to find these out

enum e_key
{
	KEY_ESCAPE = 0xFF1B,
	KEY_TEST = 0xFFFF
};

#endif
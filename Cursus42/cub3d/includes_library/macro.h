/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:02:14 by jepatern          #+#    #+#             */
/*   Updated: 2024/12/04 19:02:17 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

// Error Messages
# define MALLOC_ERR "Memory allocation failed"
# define MAP_ERR "Map error"

// Macros
# define WIDTH 1500
# define HEIGHT 1500
# define ESC 65307
# define BREAK -1
# define OK 0
# define KO 1
# define CONTINUE 2
# define NO 0
# define EA 1
# define SO 2
# define WE 3
# define DO 4
# define F 4
# define C 5
# define N 0
# define E 90
# define S 180
# define W 270
# define SKY_COLOR 0x87CEEB
# define GROUND_COLOR 0x8B4513

#endif
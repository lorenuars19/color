/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 13:27:15 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/24 20:38:06 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# define PI 3.14159265358979323846264338327950288419716939937510582097494459230

/*
** ******* **
** Include **
** ******* **
*/
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_rgb_str
{
	char		*r;
	char		*g;
	char		*b;
}				t_rgb;

enum			e_bg_fg
{
	FG, BG
};

typedef struct	s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_irgb;

typedef struct	s_hsv
{
	double		h;
	double		s;
	double		v;
}				t_hsv;

/*
** ********* **
** Functions **
** ********* **
*/

int				get_next_line(int fd, char **line);
size_t			hasto(char *s, char c);
char			*jointo(char *s1, char *s2, char **tofree);

int				strtoi(const char *s);
size_t			str_len(const char *s);
int				str_cmp(const char *s1, const char *s2);
int				checkinput(char *s);
void			put_color(t_rgb input, int bg_fg);
int				err(char *s);

int				puts_rainbow();
int				puts_color(t_rgb fg, t_rgb bg);

#endif

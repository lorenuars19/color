/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 13:27:15 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/24 16:49:12 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# define NULL_RGB NULL, NULL, NULL

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
	char	*r;
	char	*g;
	char 	*b;
} 				t_rgb;

enum			e_bg_fg
{
	FG, BG
};

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
int 			str_cmp(const char *s1, const char *s2);

int 			checkinput(char *s);
int 			puts_color(t_rgb fg, t_rgb bg);
int 			put_color(t_rgb input, int bg_fg);

#endif

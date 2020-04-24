/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 13:40:16 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/24 16:49:10 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		checkinput(char *s)
{
	ssize_t n;

	if (s == NULL)
	{
		return (-1);
	}
	n = strtoi(s);
	if (n >= 0 && n <= 255)
	{
		return (n);
	}
	else
	{
		return (-1);
	}
	return (0);
}

int		put_color(t_rgb input, int bg_fg)
{
	int	r;
	int	g;
	int	b;

	if (
	((r = checkinput(input.r)) == -1) ||
	((g = checkinput(input.g)) == -1) ||
	((b = checkinput(input.b)) == -1))
	{
		return (1);
	}
	if (bg_fg == BG)
	{
		printf("\x1b[48;2;%d;%d;%dm", r, g, b);
	}
	else if (bg_fg == FG)
	{
		printf("\x1b[38;2;%d;%d;%dm", r, g, b);
	}
	return (0);
}

int		puts_color(t_rgb fg, t_rgb bg)
{
	int		r;
	char	*s;

	s = NULL;
	while ((r = get_next_line(&s, 1)))
	{
		if (r == -1)
		{
			return (1);
		}
		put_color(fg, FG);
		put_color(bg, BG);
		printf("%s\x1b[0m\n", s);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 4)
	{
		if (puts_color((t_rgb){argv[1], argv[2], argv[3]}, (t_rgb){NULL_RGB}))
		{
			return (1);
		}
	}
	else if (!str_cmp(argv[1], "-b"))
	{
		if (argc == 5)
		{
			if (puts_color((t_rgb){NULL_RGB},
			(t_rgb){argv[2], argv[3], argv[4]}))
			{
				return (1);
			}
		}
		else if (argc == 8)
		{
			if (puts_color((t_rgb){argv[5], argv[6], argv[7]},
			(t_rgb){argv[2], argv[3], argv[4]}))
			{
				return (1);
			}
		}
	}
	else if (!str_cmp(argv[1], "-r"))
	{
		if (puts_rainbow())
		{
			return (1);
		}
	}
	else
	{
		printf("Usage :\n"
		" %s [R(0-255)] [G(0-255] [B(0-255)]"
		"                                      set foreground color only\n"
		" %s -b [R(0-255)] [G(0-255] [B(0-255)]"
		"                                   set background color only\n"
		" %s -b [R(0-255)] [G(0-255] [B(0-255)] [R(0-255)] [G(0-255] [B(0-255)]"
		"   set background and foreground color\n"
		" %s -r\t\t\t\t\tspecial rainbow mode\n"
		, argv[0], argv[0], argv[0], argv[0]);
	}

	return (0);
}

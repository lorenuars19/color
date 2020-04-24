/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 13:40:16 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/24 20:38:17 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"



int		puts_color(t_rgb fg, t_rgb bg)
{
	int		r;
	char	*s;

	s = NULL;
	if (
	(checkinput(fg.r) == -1) ||
	(checkinput(fg.g) == -1) ||
	(checkinput(fg.b) == -1) ||
	(checkinput(bg.r) == -1) ||
	(checkinput(bg.g) == -1) ||
	(checkinput(bg.b) == -1))
	{
		return (err("Color not in range (0-255)"));
	}
	while ((r = get_next_line(1, &s)))
	{

		put_color(fg, FG);
		put_color(bg, BG);
		printf("%s\x1b[0m\n", s);
		free(s);
	}
	free(s);
	if (r == -1)
	{
		return (err("get_next_line allocation"));
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 4)
	{
		if (puts_color((t_rgb){argv[1], argv[2], argv[3]},
		(t_rgb){NULL, NULL, NULL}))
		{
			return (1);
		}
	}
	else if (argc > 1 && !str_cmp(argv[1], "-b"))
	{
		if (argc == 5)
		{
			if (puts_color((t_rgb){NULL, NULL, NULL},
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
	else if (argc > 1 && !str_cmp(argv[1], "-r"))
	{
		if (puts_rainbow())
		{
			return (1);
		}
	}
	else
	{
		printf("Usage :\n"
		"\t%s [R(0-255)] [G(0-255] [B(0-255)]"
		"                                      - set foreground color only\n"
		"\t%s -b [R(0-255)] [G(0-255] [B(0-255)]"
		"                                   - set background color only\n"
		"\t%s -b [R(0-255)] [G(0-255] [B(0-255)] [R(0-255)] [G(0-255] [B(0-255)]"
		"   - set background and foreground color\n"
		"\t%s -r                                    "
		"                               - special rainbow mode\n"
		, argv[0], argv[0], argv[0], argv[0]);
	}

	return (0);
}

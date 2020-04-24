/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 14:09:55 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/24 21:22:17 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		str_tol(const char *s)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while (s && ((*s >= '\t' && *s <= '\r') || *s == ' '))
		s++;
	if (s && *s == '-')
		sign = -1;
	if (s && (*s == '-' || *s == '+'))
		s++;
	while (s && *s >= '0' && *s <= '9')
		num = (num * 10) + (*s++ - '0');
	if (num > LONG_MAX)
		return ((sign == 1) ? -1 : 0);
	return ((sign == 1) ? num : -num);
}

size_t		str_len(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int		str_cmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		checkinput(char *s)
{
	ssize_t n;

	if (s == NULL)
	{
		return (256);
	}
	n = str_tol(s);
	if (n >= 0 && n <= 255)
	{
		return (n);
	}
	return (-1);
}

void	put_color(t_rgb input, int bg_fg)
{
	int	r;
	int	g;
	int	b;

	r = str_tol(input.r);
	g = str_tol(input.g);
	b = str_tol(input.b);
	if (input.r == NULL ||
		input.g == NULL ||
		input.b == NULL)
	{
		return ;
	}
	if (bg_fg == BG)
	{
		printf("\x1b[48;2;%d;%d;%dm", r, g, b);
	}
	else if (bg_fg == FG)
	{
		printf("\x1b[38;2;%d;%d;%dm", r, g, b);
	}
}

int		err(char *s)
{
	printf("\x1b[31;1mError : %s\x1b[0m\n", s);
	return (1);
}

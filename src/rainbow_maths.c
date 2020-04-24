/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:59:04 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/24 22:50:24 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

double sine(double x)
{
	double t;
	double sum;
	size_t i;
	size_t n;

	n = 100000;
	x=x*PI/180;
	t=x;
	sum=x;
	i = 1;
	while (n > 0)
	{
		t=(t * (-1) * x * x ) / ( 2 * i * ( 2 * i + 1 ));
		sum=sum+t;
		n--;
		i++;
	}
	return (sum);
}

double	dabs(double x)
{
	return (((x > 0) ? x : -x ));
}

double	map(double x, double in_max, double out_max)
{
  return (x * out_max / in_max);
}

t_irgb hsv2rgb(double H, double S, double V)
{
	t_irgb	RGB;
	double	P;
	double	Q;
	double	T;
	double	fract;

	(H == 360.)?(H = 0.):(H /= 60.);
	fract = (float)(int)dabs(sine(H));

	P = V*(1. - S);
	Q = V*(1. - S*fract);
	T = V*(1. - S*(1. - fract));

	if      (0. <= H && H < 1.)
		RGB = (t_irgb){.r = V, .g = T, .b = P};
	else if (1. <= H && H < 2.)
		RGB = (t_irgb){.r = Q, .g = V, .b = P};
	else if (2. <= H && H < 3.)
		RGB = (t_irgb){.r = P, .g = V, .b = T};
	else if (3. <= H && H < 4.)
		RGB = (t_irgb){.r = P, .g = Q, .b = V};
	else if (4. <= H && H < 5.)
		RGB = (t_irgb){.r = T, .g = P, .b = V};
	else if (5. <= H && H < 6.)
		RGB = (t_irgb){.r = V, .g = P, .b = Q};
	else
		RGB = (t_irgb){.r = 0., .g = 0., .b = 0.};
	return RGB;
}

int		puts_rainbow(double freq)
{
	int		r;
	char	*s;
	size_t	slen;
	double	hue;
	t_irgb	col = (t_irgb){0,255,0};
	size_t	i;
	double	add;

	r = 0;
	s = NULL;
	while ((r = get_next_line(1, &s)))
	{
		slen = str_len(s);
		hue = 1;
		i = 0;
		while (i < slen && s)
		{
			col = hsv2rgb(hue,1,1);
			printf("\x1b[38;2;%d;%d;%dm%c",
			(int)(col.r * 255.0),
			(int)(col.g * 255.0),
			(int)(col.b * 255.0), s[i++]);
			add = dabs(sine(hue * freq)*(360)/slen);
			hue += add;
			printf("\x1b[0m > freq %f | hue %f | R %f | G %f | B %f | ++ %f | slen %f | sine %f\n",
			freq, hue,
			(col.r * 255.0),
			(col.g * 255.0),
			(col.b * 255.0), add, (double)slen, sine(hue));
		}
		puts("\x1b[0m");
		free(s);
	}
	free(s);
	if (r == -1)
	{
		return (err("get_next_line allocation"));
	}
	return (0);
}

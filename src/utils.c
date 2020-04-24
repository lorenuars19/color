/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 14:09:55 by lorenuar          #+#    #+#             */
/*   Updated: 2020/04/24 15:06:22 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		strtoi(const char *s)
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
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

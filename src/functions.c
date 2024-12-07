/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:35:41 by auskola-          #+#    #+#             */
/*   Updated: 2024/06/14 12:09:49 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

char	*ltrim(char *s)
{
	while (ft_isspace(*s))
		s++;
	return (s);
}

char	*rtrim(char *s)
{
	char	*back;
	int		issp;

	back = s + strlen(s);
	issp = ft_isspace(*--back);
	while (issp)
	{
		issp = ft_isspace(*--back);
	}
	*(back + 1) = '\0';
	issp = ft_isspace(*--back);
	while (issp)
		issp = ft_isspace(*--back);
	*(back + 1) = '\0';
	return (s);
}

char	*trim(char *s)
{
	return (rtrim(ltrim(s)));
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	cur;

	if (size == 0)
		return (ft_strlen(src));
	cur = 0;
	while (src[cur] && cur < (size - 1))
	{
		dst[cur] = src[cur];
		cur++;
	}
	dst[cur] = 0;
	return (ft_strlen(src));
}

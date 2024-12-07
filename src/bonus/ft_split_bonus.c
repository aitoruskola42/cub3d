/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:26:16 by incalero          #+#    #+#             */
/*   Updated: 2024/06/14 11:15:57 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

static void	*ft_del(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(array[i++]);
	free(array);
	return (NULL);
}

static int	ft_findc(char const *s1, char c)
{
	int	i;
	int	ok;

	i = 0;
	ok = 0;
	while (*s1)
	{
		if (*s1 != c && ok == 0)
		{
			ok = 1;
			i++;
		}
		else if (*s1 == c)
			ok = 0;
		s1++;
	}
	return (i);
}

static int	ft_strlenint(const	char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		inicio;
	char	**s2;

	s2 = (char **) malloc (sizeof(char *) * ((ft_findc(s, c)) + 1));
	if (!s || s2 == NULL)
		return (NULL);
	i = -1;
	j = 0;
	inicio = -1;
	while (++i <= ft_strlenint(s))
	{
		if (s[i] != c && inicio < 0)
			inicio = i;
		else if ((s[i] == c || i == ft_strlenint(s)) && inicio >= 0)
		{
			s2[j++] = ft_substr(s, inicio, i - inicio);
			if (s2[j - 1] == NULL)
				return (ft_del(s2, j));
			inicio = -1;
		}
	}
	s2[j] = 0;
	return (s2);
}

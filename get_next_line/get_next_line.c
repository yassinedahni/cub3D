/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:53:19 by ydahni            #+#    #+#             */
/*   Updated: 2022/08/05 23:21:14 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *a)
{
	int		count;
	char	*str;

	str = malloc(1 + 1);
	if (!str)
		return (NULL);
	count = 1;
	while (ft_strchr(a) == 0 && count)
	{
		count = read(fd, str, 1);
		if (count == -1)
		{
			free(str);
			return (NULL);
		}
		str[count] = '\0';
		a = ft_strjoin(a, str);
	}
	free(str);
	return (a);
}

char	*beforline(char *a)
{
	int	i;

	i = 0;
	if (!a[0])
		return (NULL);
	while (a[i] && a[i] != '\n')
	{
		i++;
	}
	return (ft_substr(a, 0, i + 1));
}

char	*afterline(char *a)
{
	int		i;
	char	*str;

	i = 0;
	if (!a)
		return (NULL);
	while (a[i])
	{
		if (a[i] == '\n')
		{
			str = ft_substr(a, i + 1, ft_strlen(a));
			free(a);
			return (str);
		}
		i++;
	}
	free(a);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*a;
	char		*s;

	if (fd < 0)
		return (NULL);
	a = get_line(fd, a);
	if (!a)
		return (NULL);
	s = beforline(a);
	a = afterline(a);
	return (s);
}

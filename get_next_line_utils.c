/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:39:00 by miskirik          #+#    #+#             */
/*   Updated: 2022/06/26 01:17:48 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	c;
	size_t	i;
	char	*pstr;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	pstr = malloc(sizeof(char) * ((ft_strlen(str)) + ft_strlen(buff) + 1));
	if (pstr == NULL)
		return (NULL);
	c = -1;
	i = 0;
	if (str)
		while (str[++c] != '\0')
			pstr[c] = str[c];
	while (buff[i] != '\0')
		pstr[c++] = buff[i++];
	pstr[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (pstr);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*pstr;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	pstr = (char *)malloc(sizeof(char) * (i + 2));
	if (!pstr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		pstr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		pstr[i++] = '\n';
	pstr[i] = '\0';
	return (pstr);
}

char	*ft_last_str(char *str)
{
	int		c;
	int		i;
	char	*pstr;

	c = 0;
	while (str[c] && str[c] != '\n')
		c++;
	if (!str[c])
	{
		free(str);
		return (NULL);
	}
	pstr = (char *)malloc(sizeof(char) * (ft_strlen(str) - c + 1));
	if (!pstr)
		return (NULL);
	c++;
	i = 0;
	while (str[c])
		pstr[i++] = str[c++];
	pstr[i] = '\0';
	free(str);
	return (pstr);
}

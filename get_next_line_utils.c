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
#include <stdio.h>
size_t ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if(!str)
		return(0);
	while(str[c])
		c++;
	return(c);
}
char	*ft_strjoin(char *str, char *buff)
{
	size_t	c;
	size_t	i;
	char	*str;

	if(!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if(!str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(str))))

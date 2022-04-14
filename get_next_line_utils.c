/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:29:22 by yelousse          #+#    #+#             */
/*   Updated: 2022/04/14 00:57:31 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	lendest;
	size_t	index;
	size_t	index1;

	index1 = 0;
	len = ft_strlen(src);
	lendest = ft_strlen(dest);
	index = lendest;
	if (lendest >= size)
		return (len + size);
	while (src[index1] != '\0' && index < size - 1)
	{
		dest[index] = src[index1];
		index1++;
		index++;
	}
	dest[index] = '\0';
	return (len + lendest);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*table;
	int		index;
	int		len1;
	int		len2;

	index = 0;
	table = 0;
	len2 = ft_strlen((char *)str2);
	len1 = ft_strlen((char *)str1);
	table = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (table == 0)
		return (0);
	table[0] = 0;
	if (len1)
	{
		ft_strlcat(table, str1, len1 + 1);
		free(str1);
	}
	if (len2)
		ft_strlcat(table, str2, len1 + len2 + 1);
	return (table);
}

int	line_size(char *stash)
{
	int	i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

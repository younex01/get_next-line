/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:28:59 by yelousse          #+#    #+#             */
/*   Updated: 2022/04/20 21:08:20 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rest(char *stash)
{
	int		i;
	int		len;
	int		j;
	char	*tmp;

	i = ft_line_size(stash);
	j = 0;
	len = ft_strlen(stash);
	if (i >= len)
	{	
		free(stash);
		return (NULL);
	}
	tmp = malloc(len - i + 1);
	if (!tmp)
		return (NULL);
	while (stash[i + j])
	{
		tmp[j] = stash[i + j];
		j++;
	}
	free(stash);
	tmp[j] = 0;
	return (tmp);
}

char	*ft_check_line(char *stash)
{
	char	*line;
	int		i;
	int		len;

	len = ft_line_size(stash);
	if (!len)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		line[i] = stash[i];
		if (stash[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line[i] = 0;
	return (line);
}

int	ft_find_next_line(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_loop(char *stash, int fd)
{
	char	*buffer;
	int		nb;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (1)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb] = 0;
		if (nb == 0)
			break ;
		stash = ft_strjoin(stash, buffer);
		if (ft_find_next_line(stash))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char static	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_loop(stash, fd);
	line = ft_check_line(stash);
	stash = ft_rest(stash);
	return (line);
}

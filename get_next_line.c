#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h> 
#include <string.h>
#include "libft.h"


int	line_size(char *stash)
{
	int	i;

	if (!stash)
		return (0);
	i = 0;
	while(stash[i])
	{
		if (stash[i] == '\n')
			return (i+1);
		i++;
	}
	return (i);
}

char	*rest(char *stash)
{
	int	i;
	int	len;
	int	j;
	char	*tmp;

	i = line_size(stash);
	j = 0;
	len = ft_strlen(stash);
	if(i >= len)
	{	free(stash);
		return (NULL);}
	tmp = malloc(len - i + 1);
	while(stash[i + j])
	{
		tmp[j] = stash[i + j];
		j++;
	}
	free(stash);
	tmp[j] = 0;
	return (tmp);
}
char	*check_line(char *stash)
{
	char	*line;
	int		i;
	int len = line_size(stash);

	if (!len)
		return (NULL);
	line = malloc(len);
	i = 0;
	while(stash[i])
	{
		line[i] = stash[i];
		if(stash[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	line[i] = 0;
	return (line);
}

int	find_next_line(char *stash)
{
	int	i;

	i = 0;
	while(stash[i])
	{
		if(stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char static	*stash;
	char		*line;
	int 		nb;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	while(1)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if(nb == -1)
		{
			free(buffer);
			return NULL;
		}
		buffer[nb] = 0;
		if(nb == 0)
			break;
		stash = ft_strjoin(stash, buffer);
		if(find_next_line(stash))
			break;
	}
	free(buffer);
	line = check_line(stash);
	stash = rest(stash);
	return line;
}

// int main()
// {
// 	int fd1 = open("foo.txt", O_RDONLY);
// 	if (fd1 < 0) 
//     { 
//         perror("c1"); 
//         exit(1); 
//     } 
//     printf("%s", get_next_line(fd1)); 
// 	printf("%s", get_next_line(fd1)); 
// 	printf("%s", get_next_line(fd1));

// }
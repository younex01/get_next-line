#include "libft.h"


size_t	ft_strlen(const char *str)
{
	size_t	index;
	if(!str)
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

void	ft_bzero(void *str, size_t n)
{
	char				*table;

	table = (char *)str;
	if (n > 0)
	{
		while (n-- > 0)
			*table++ = (unsigned char)0;
	}
}


void	*ft_calloc(size_t count, size_t size)
{
	void		*table;

	table = (void *)malloc(count * size);
	if (table == NULL)
		return (0);
	ft_bzero(table, count * size);
	return (table);
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
	table = (char *)ft_calloc(sizeof(char) * ((len1 + len2) + 1), sizeof(char));
	if (table == 0)
		return (0);
	if(len1)
	{
		ft_strlcat(table, str1, len1 + 1);
		free(str1);
	}
	if(len2)
		ft_strlcat(table, str2, len1 + len2 + 1);
	return (table);
}

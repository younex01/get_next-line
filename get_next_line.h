/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:29:28 by yelousse          #+#    #+#             */
/*   Updated: 2022/04/14 00:57:26 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *str1, char *str2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
int		find_next_line(char *stash);
char	*check_line(char *stash);
char	*rest(char *stash);
int		line_size(char *stash);
int		line_size(char *stash);

#endif

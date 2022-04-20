/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:29:28 by yelousse          #+#    #+#             */
/*   Updated: 2022/04/19 21:26:31 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
int		ft_find_next_line(char *stash);
char	*ft_check_line(char *stash);
char	*ft_rest(char *stash);
int		ft_line_size(char *stash);

#endif

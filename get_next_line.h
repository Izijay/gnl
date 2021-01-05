/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:20:05 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/05 18:41:22 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

int				get_next_line(int fd, char **line);
int				fak(char **str, char **newl);
int				ft_strlen_gnl(char *str);
int				ft_check_gnl(char *str, int c);
char			*ft_strcpy(char *dest, char *src);

#endif

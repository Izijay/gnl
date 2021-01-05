/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:29:06 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/05 18:34:46 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_cat_gnl(char *str, char *buff)
{
	int i;
	int j;
	int len;
	char *newl;

	i = 0;
	j = 0;
	len = ft_strlen_gnl(str) + ft_strlen_gnl(buff);
	if (!(newl = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (str)
		newl = ft_strcpy(newl, str);
	i = ft_strlen_gnl(str);
	while (buff[j])
	{
		newl[i + j] = buff[j];
		j++;
	}
	newl[i + j] = '\0';
	free (str);
	return (newl);
}

static char		*ft_newl(char *str, int *end)
{
	int len;
	int i;
	char *line;

	i = 0;
	len = ft_check_gnl(str, '\n') - 1;
	if (len == 0)
		{
		len = ft_check_gnl(str, '\0') - 1;
		*end = -1;
		}
	if (!(line = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		{
			line[i] = str[i];
			i++;
		}
	line[i] = '\0';
	return (line);
}

static char		*ft_nextl(char *str)
{
	char *nextstr;
	int len;
	int start;
	int i;

	i = 0;
	start = ft_check_gnl(str, '\n');
	len = ft_strlen_gnl(str) - start;
	if (!(nextstr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nextstr[len] = '\0';
	while (i < len)
	{
		nextstr[i] = str[start + i];
		i++;
	}
	free (str);
	return (nextstr);
}

static int		ft_okay(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	int gnl;
	int end;
	char *newl;
	static char *str = NULL;

	end = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE == 0 || (read(fd, buff, 0) < 0))
		return (-1);
	while ((gnl = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[gnl] = '\0';
		if (!(str = ft_cat_gnl(str, buff)))
			return (fak(&str, NULL));
		if (ft_check_gnl(buff, '\n') != 0)
			break ;
	}
	if (!(newl = ft_newl(str, &end)))
		return (fak(&str, NULL));
	else if (!(str = ft_nextl(str)))
		return (fak(&str, &newl));
	*line = newl;
	if (end == -1)
		ft_okay(&str);
	return (1);
}

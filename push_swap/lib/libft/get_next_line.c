/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 23:08:54 by minakim           #+#    #+#             */
/*   Updated: 2019/06/26 00:29:05 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_new_line(int fd, char **data, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (data[fd][i] != '\n' && data[fd][i] != '\0')
		i++;
	if (data[fd][i] == '\n')
	{
		*line = ft_strsub(data[fd], 0, i);
		tmp = ft_strdup(data[fd] + i + 1);
		ft_strdel(&data[fd]);
		data[fd] = tmp;
		if (data[fd][0] == '\0')
			ft_strdel(&data[fd]);
	}
	else if (data[fd][i] == '\0')
	{
		*line = ft_strdup(data[fd]);
		ft_strdel(&data[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			nb_bytes_read_from_buf;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*data[1024];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((nb_bytes_read_from_buf = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nb_bytes_read_from_buf] = '\0';
		if (data[fd] == NULL)
			data[fd] = ft_strnew(0);
		tmp = ft_strjoin(data[fd], buf);
		ft_strdel(&data[fd]);
		data[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (nb_bytes_read_from_buf < 0)
		return (-1);
	else if (nb_bytes_read_from_buf == 0 && data[fd] == NULL)
		return (0);
	return (find_new_line(fd, data, line));
}

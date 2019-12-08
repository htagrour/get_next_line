/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:52:32 by htagrour          #+#    #+#             */
/*   Updated: 2019/11/12 17:05:47 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			isthereaback(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

int			add_line(char **str, int fd)
{
	char	*tem;
	int		i;
	char	*ptr;

	i = 1;
	while (i > 0)
	{
		if (!(tem = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)) ||
		(i = read(fd, tem, BUFFER_SIZE)) == -1)
			return (-1);
		tem[i] = '\0';
		ptr = *str;
		if (!(*str = ft_strjoin(*str, tem)))
			return (-1);
		free(ptr);
		free(tem);
		if (isthereaback(*str))
			break ;
	}
	return (i);
}

t_list		*add_new_ele(int fd)
{
	t_list	*list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	list->fd = fd;
	if (!(list->str = ft_strdup("")))
		return (NULL);
	list->next = NULL;
	return (list);
}

t_list		*cherch(int fd, t_list **list)
{
	t_list	*tem;

	tem = *list;
	while (tem->fd != fd)
	{
		if (tem->next == NULL)
		{
			if (!(tem = add_new_ele(fd)))
				return (NULL);
			ft_lstadd_front(&*list, tem);
			return (*list);
		}
		tem = tem->next;
	}
	return (tem);
}

int			get_next_line(int fd, char **line)
{
	static t_list	*list;
	int				counter;
	t_list			*tem;
	int				read_value;
	char			*ptr;

	if (!line || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 0)
		return (-1);
	if (!list && (counter = 0) == 0)
		list = add_new_ele(fd);
	if (!(tem = cherch(fd, &list)))
		return (-1);
	if ((read_value = add_line(&tem->str, fd)) == -1)
		return (-1);
	while (tem->str[counter] != '\n' && tem->str[counter])
		counter++;
	if (!(*line = ft_substr(tem->str, 0, counter)))
		return (-1);
	if (tem->str[counter] != '\n' && !read_value)
		return (ft_strlen(NULL, 1, &(tem->str)));
	ptr = tem->str;
	if (!(tem->str = ft_strdup(tem->str + counter + 1)))
		return (-1);
	free(ptr);
	return (1);
}

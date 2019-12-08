/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 22:24:08 by htagrour          #+#    #+#             */
/*   Updated: 2019/11/12 17:06:10 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s, int a, char **temp);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					get_next_line(int fd, char **line);

#endif

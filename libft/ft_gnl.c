/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:09:04 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/14 12:20:32 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char **s, char c)
{
	char	*out;
	size_t	len;

	len = 0;
	if (*s)
		len = ft_strlen(*s);
	out = ft_calloc(len + 2, sizeof(char));
	if (!out)
	{
		free(*s);
		return (NULL);
	}
	if (*s)
	{
		strcpy(out, *s);
		free(*s);
		*s = NULL;
	}
	out[len] = c;
	out[len + 1] = '\0';
	return (out);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*text;
	int		bytes_read;

	text = NULL;
	if (fd < 0)
		return (NULL);
	bytes_read = read(fd, &c, 1);
	while (bytes_read > 0)
	{
		text = ft_join(&text, c);
		if (!text)
			return (NULL);
		bytes_read = read(fd, &c, 1);
		if (c == '\n')
			return (text);
	}
	if (bytes_read == -1)
	{
		free(text);
		return (NULL);
	}
	return (text);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:16:39 by emtopal           #+#    #+#             */
/*   Updated: 2024/12/02 04:09:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*p2;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	p2 = (char *) malloc((i + 1) * sizeof(char));
	if (p2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		((unsigned char *) p2)[i] = s1[i];
		i++;
	}
	p2[i] = '\0';
	return (p2);
}

static char *reminder_value(char **str)
{
	char *line;
	char *temp;
	int len;

	len = 0;
	if (!*str)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	while ((*str)[len] != '\0')
	{
		if ((*str)[len] == '\n')
		{
			len++;
			break;
		}
		len++;
	}
	line = ft_strndup(*str, len);
	temp = ft_substr(*str, len, ft_strlen(*str) - len);
	free(*str);
	*str = temp;
	return (line);
}

static char *read_file(int fd, char *adrs)
{
    char *buffer;
	char *temp;
	int bytes_count;

	buffer = (char *) malloc((BUFFER_SIZE + 1));
	bytes_count = 1;
	if (buffer == NULL)
		return (NULL);
	if (adrs == NULL)
		adrs = ft_strdup("");
	while (!ft_strchr(adrs, '\n') && adrs)
	{
		bytes_count = read(fd, buffer, BUFFER_SIZE);
		if (bytes_count < 0)
		{
			free(buffer);
			free(adrs);
			return (NULL);
		}
		if (bytes_count == 0)
            break;
		buffer[bytes_count] = '\0';
		temp = ft_strjoin(adrs, buffer);
		free(adrs);
		adrs = temp;
	}
	free(buffer);
	return (adrs);
}

char *get_next_line(int fd)
{
	static char *last_pointer = NULL;
	char *new_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	last_pointer = read_file(fd, last_pointer);
	if (!last_pointer || last_pointer[0] == '\0')
	{
		free(last_pointer);
		last_pointer = NULL;
		return (NULL);
	}
	new_line = reminder_value(&last_pointer);
	if (!new_line)
	{
		free(last_pointer);
		last_pointer = NULL;
	}
	return (new_line);
}
// #include <fcntl.h>
// #include <stdio.h>
// int main() {
//     int fd = open("emirhan.txt", O_RDONLY);
//     char *line;

//     while ((line = get_next_line(fd)) != NULL) {
//         free(line); // Free the line after using it
//     }
//     close(fd);
//     return 0;
// }
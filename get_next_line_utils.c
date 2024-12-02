/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:19:08 by emtopal           #+#    #+#             */
/*   Updated: 2024/12/02 04:49:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)(c))
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if ((unsigned char)(c) == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s12_len;
	char		*ptr;
	size_t		i;
	size_t		j;

	s12_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *) malloc(s12_len);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_arr;
	size_t	str_len;
	size_t	i;

	i = 0;
	str_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (str_len <= start)
		return ((char *) calloc(1, 1));
	if (len > str_len - start)
		len = str_len - start;
	new_arr = (char *) malloc((len + 1) * sizeof(char));
	if (new_arr == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		new_arr[i] = s[start + i];
		i++;
	}
	new_arr[i] = '\0';
	return (new_arr);
}

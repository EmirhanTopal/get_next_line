/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtopal <emtopal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:19:08 by emtopal           #+#    #+#             */
/*   Updated: 2024/11/30 19:32:08 by emtopal          ###   ########.fr       */
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
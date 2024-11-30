/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtopal <emtopal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:16:39 by emtopal           #+#    #+#             */
/*   Updated: 2024/11/30 19:55:01 by emtopal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_file(int fd, char *adrs)
{
    char *buffer;
    int byte_size;

    byte_size = 0;
    buffer = (char *) malloc(BUFFER_SIZE + 1);
    if (buffer == NULL)
        return (NULL);
    while (ft_strchr(adrs, '\n') != NULL)
    {
        byte_size = read(fd, buffer, byte_size);
        if (byte_size < 0)
        {
            free(buffer);
            return (NULL);
        }
        
    }
    
}

char *get_next_line(int fd)
{
    static  char *lst_adr;
    lst_adr = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (NULL);
    read_file(fd, lst_adr);
    return (line);    
}
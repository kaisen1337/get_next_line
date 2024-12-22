/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 06:42:06 by nkasimi           #+#    #+#             */
/*   Updated: 2024/12/03 11:52:53 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_join(int fd, char *text, char *buffer)
{
	int		len;
	char	*tempo;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (!serch_new_line(text))
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buffer[len] = '\0';
		tempo = text;
		text = ft_strjoin(tempo, buffer);
		free(tempo);
		if (!text)
			return (NULL);
	}
	return (text);
}

char	*ft_read_text(int fd, char *text)
{
	char	*buffer;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!text)
		text = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	text = ft_read_join(fd, text, buffer);
	free(buffer);
	if (!text || (text[0] == '\0'))
	{
		free(text);
		return (NULL);
	}
	return (text);
}

char	*ft_our_line(char *the_complet_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!the_complet_line)
		return (NULL);
	while (the_complet_line[i] != '\n' && the_complet_line[i] != '\0')
	{
		i++;
	}
	line = ft_substr(the_complet_line, 0, i + (the_complet_line[i] == '\n'));
	return (line);
}

char	*ft_the_rest_of_line(char *the_complet_line)
{
	int		k;
	int		len;
	char	*rest;

	k = 0;
	if (!the_complet_line)
		return (NULL);
	len = ft_strlen(the_complet_line);
	while (the_complet_line[k] != '\n' && the_complet_line[k] != '\0')
		k++;
	if (the_complet_line[k] == '\0')
	{
		free(the_complet_line);
		return (NULL);
	}
	rest = ft_substr(the_complet_line, k + 1, len - k - 1);
	free(the_complet_line);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*the_static_var[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	the_static_var[fd] = ft_read_text(fd, the_static_var[fd]);
	if (!the_static_var[fd])
		return (NULL);
	line = ft_our_line(the_static_var[fd]);
	if (!line)
		return (NULL);
	the_static_var[fd] = ft_the_rest_of_line(the_static_var[fd]);
	return (line);
}
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include "get_next_line_bonus.h"

// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include "get_next_line_bonus.h"

// int main(void)
// {
//     int fd1, fd2, fd3;
//     char *line;

//     fd1 = open("file1.txt", O_RDONLY);
//     fd2 = open("file2.txt", O_RDONLY);
//     fd3 = open("file3.txt", O_RDONLY);

//     if (fd1 < 0 || fd2 < 0 || fd3 < 0)
//     {
//         perror("Error opening files");
//         return (1);
//     }

//     while (1)
//     {
//         int read_flag = 0;

//         line = get_next_line(fd1);
//         if (line)
//         {
//             printf("File1: %s", line);
//             free(line);
//             read_flag = 1;
//         }

//         line = get_next_line(fd2);
//         if (line)
//         {
//             printf("File2: %s", line);
//             free(line);
//             read_flag = 1;
//         }

//         line = get_next_line(fd3);
//         if (line)
//         {
//             printf("File3: %s", line);
//             free(line);
//             read_flag = 1;
//         }

//         if (!read_flag)
//             break;
//     }

//     close(fd1);
//     close(fd2);
//     close(fd3);

//     return (0);
// }

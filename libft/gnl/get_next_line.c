/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:27:44 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/13 15:02:06 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*garde_reste(char *buffer)
{
	char	*reste;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	reste = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!reste)
		return (NULL);
	i++;
	while (buffer[i])
		reste[j++] = buffer[i++];
	reste[j] = '\0';
	free(buffer);
	return (reste);
}

char	*remplir_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*readfd(int fd, char *stock)
{
	char	*buf;
	ssize_t	count;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	count = 1;
	while (count != 0 && !ft_strchr(stock, '\n'))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free(buf);
			free(stock);
			return (NULL);
		}
		buf[count] = '\0';
		stock = ft_strjoin(stock, buf);
	}
	free(buf);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = readfd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = remplir_line(buffer);
	buffer = garde_reste(buffer);
	return (line);
}

/*int main()
{
  int fd;
  char *line;

  fd = open("texte.txt", O_RDONLY);
  while (1)
  {
	line = get_next_line(fd);
	if (line == NULL)
		break ;
	printf("%s", line);
	free(line);
  }
  return (0);
}*/

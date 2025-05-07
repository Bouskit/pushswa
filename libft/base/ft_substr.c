/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:23:06 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/27 15:24:16 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*str1;
	size_t	str_len;

	if (!str)
		return (0);
	str_len = ft_strlen((char *)str);
	if (start > str_len)
		return (ft_strdup(""));
	if (str_len - start >= len)
		str1 = (char *)malloc((len + 1) * sizeof(char));
	else
		str1 = (char *)malloc((str_len - start + 1) * sizeof(char));
	if (!str1)
		return (0);
	ft_strlcpy(str1, (str + start), (len + 1));
	return (str1);
}

/*char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		len = 0;
	else if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (i < len && start + i < ft_strlen(str))
	{
		s[i] = str[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}*/

/*int main ()
{
	char str[] = "Bonjour comment ça va";
	printf ("%s", ft_substr(str, 5, 8));
	return (0);
}*/
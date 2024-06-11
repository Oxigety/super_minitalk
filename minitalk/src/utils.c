/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:34:27 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/20 18:34:28 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

unsigned char	*ft_calloc(size_t nmemb, size_t size, bool start)
{
	unsigned char	*arr;
	unsigned char	*freetab;
	size_t			length;

	length = nmemb * size;
	if (nmemb == 0 || size == 0 || length > 2147483647)
		return (malloc(0));
	arr = (unsigned char *)malloc(length + 1);
	if (arr == NULL)
	{
		if (start)
			exit(0);
		return (NULL);
	}
	freetab = arr;
	while (length > 0)
	{
		*arr = '0';
		length--;
		arr++;
	}
	*arr = '\0';
	return (freetab);
}

size_t	ft_strlen(const unsigned char *s, size_t n)
{
	size_t	i;
	size_t	cpt;

	i = n;
	cpt = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		cpt++;
		i++;
	}
	return (cpt);
}

unsigned char	*alloc_join(unsigned char const *s1, unsigned char const *s2)
{
	unsigned char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		str = malloc(sizeof(char) * ft_strlen((unsigned char *)s2, 0) + 1);
	else
		str = malloc(sizeof(char) * ft_strlen((unsigned char *)s1, 0)
				+ ft_strlen((unsigned char *)s2, 0) + 1);
	return (str);
}

unsigned char	*ft_strjoin(unsigned char const *s1, unsigned char const *s2,
			int *cpt)
{
	size_t				i;
	unsigned char		*str;

	i = 0;
	str = alloc_join(s1, s2);
	if (str == NULL)
	{
		free((unsigned char *)s1);
		return (NULL);
	}
	while (s1 != NULL && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		str[i++] = '\0';
		s2++;
	}
	*cpt = i;
	free((unsigned char *)s1);
	str[i] = '\0';
	return (str);
}

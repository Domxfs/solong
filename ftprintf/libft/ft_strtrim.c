/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:36:55 by domy              #+#    #+#             */
/*   Updated: 2022/05/19 17:56:41 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	inizio;
	size_t	fine;

	inizio = 0;
	while (s1[inizio] && ft_char_in_set(s1[inizio], set))
		inizio++;
	fine = ft_strlen(s1);
	while (fine > inizio && ft_char_in_set(s1[fine - 1], set))
		fine--;
	str = (char *)malloc(sizeof(*s1) * (fine - inizio + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (inizio < fine)
		str[i++] = s1[inizio++];
	str[i] = 0;
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:08:25 by ychng             #+#    #+#             */
/*   Updated: 2024/04/30 00:21:50 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strins(const char *original, const char *insert, size_t pos)
{
	size_t	totallen;
	char	*result;

	totallen = ft_strlen(original) + ft_strlen(insert) + 1;
	result = malloc(sizeof(char *) * totallen);
	if (!result)
		return (NULL);
	ft_strncpy(result, original, pos);
	result[pos] = '\0';
	ft_strcat(result, insert);
	ft_strcat(result, original + pos);
	return (result);
}

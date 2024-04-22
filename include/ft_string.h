/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:46:19 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 17:47:29 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

char	*ft_rstrchr(const char *str, int c);
int		ft_rstrcspn(const char *str, const char *reject);
int		ft_rstrspn(const char *str, const char *accept);
char	**ft_split(const char *str, const char *delim);

#endif
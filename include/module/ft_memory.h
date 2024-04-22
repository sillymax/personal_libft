/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:27:46 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 18:58:28 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

// Memory Functions
void	ft_bzero(void *str, size_t size);
void	*ft_memset(void *dest, int c, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_realloc(void *ptr, size_t originalsize, size_t newsize);

#endif
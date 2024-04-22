/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:40:16 by ychng             #+#    #+#             */
/*   Updated: 2024/04/23 03:06:55 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef	struct	s_resultinfo
{
	char	*buffer;
	size_t	size;
}	t_resultinfo;

static void	initinfo(t_resultinfo *info, char *buffer, size_t size)
{
	info->buffer = buffer;
	info->size = size;
}

bool	isspecifier(char c)
{
	char	specifiers[10];

	ft_strcpy(specifiers, "cspdiuxX%");
	return (ft_strchr(specifiers, c));
}

void	write_tobuffer(t_resultinfo *info, char c)
{
	if (info->size > 1)
	{
		*(info->buffer) = c;
		(info->buffer)++;
		(info->size)--;
	}
}

void	handlechar(t_resultinfo *info, char c)
{
	write_tobuffer(info, c);
}

void	handlestring(t_resultinfo *info, char *str)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		write_tobuffer(info, *str);
		str++;
	}
}

void	handlepointer(t_resultinfo *info, uintptr_t ptr)
{
	uintptr_t	base;
	char		hexadecimal[17];

	base = 16;
	ft_strcpy(hexadecimal, "0123456789abcdef");
	if (ptr >= base)
		handlepointer(info, ptr / base);
	else
	{
		write_tobuffer(info, '0');
		write_tobuffer(info, 'x');
	}
	write_tobuffer(info, hexadecimal[ptr % base]);
}

void	handledigit(t_resultinfo *info, long long num)
{
	int		base;
	char	decimal[11];

	base = 10;
	ft_strcpy(decimal, "0123456789");
	if (num < 0)
	{
		num = -num;
		write_tobuffer(info, '-');
	}
	if (num >= base)
		handledigit(info, num / base);
	write_tobuffer(info, decimal[num % base]);
}

void	handlelowhex(t_resultinfo *info, unsigned int num)
{
	int		base;
	char	decimal[17];

	base = 16;
	ft_strcpy(decimal, "0123456789abcdef");
	if (num >= base)
		handledigit(info, num / base);
	write_tobuffer(info, decimal[num % base]);
}

void	handleupphex(t_resultinfo *info, unsigned int num)
{
	int		base;
	char	decimal[17];

	base = 16;
	ft_strcpy(decimal, "0123456789ABCDEF");
	if (num >= base)
		handledigit(info, num / base);
	write_tobuffer(info, decimal[num % base]);
}

void	handlepercent(t_resultinfo *info)
{
	write_tobuffer(info, '%');
}

static void	managespecifier(t_resultinfo *info, const char *format, va_list args, int *pos)
{
	if (format[*pos] == 'c')
		handlechar(info, va_arg(args, int));
	else if (format[*pos] == 's')
		handlestring(info, va_arg(args, char *));
	else if (format[*pos] == 'p')
		handlepointer(info, (uintptr_t)va_arg(args, void *));
	else if (format[*pos] == 'd' || format[*pos] == 'i')
		handledigit(info, va_arg(args, int));
	else if (format[*pos] == 'u')
		handledigit(info, va_arg(args, unsigned int));
	else if (format[*pos] == 'x')
		handlelowhex(info, va_arg(args, unsigned int));
	else if (format[*pos] == 'X')
		handleupphex(info, va_arg(args, unsigned int));
	else if (format[*pos] == '%')
		handlepercent(info);
}

static void processformat(t_resultinfo *info, const char *format, va_list args)
{
	int	pos;

	pos = 0;
	while (format[pos])
	{
		if (format[pos] == '%' && isspecifier(format[pos + 1]))
		{
			pos++;
			managespecifier(info, format, args, &pos);
		}
		else
			write_tobuffer(info, format[pos]);
		pos++;
	}
	*(info->buffer) = '\0';
}

int	ft_snprintf(char *buffer, size_t size, const char *format, ...)
{
	va_list			args;
	t_resultinfo	info;

	va_start(args, format);
	initinfo(&info, buffer, size);
	processformat(&info, format, args);
	va_end(args);
	return ((int)(size - info.size));
}

// int main()
// {
// 	char	buffer[100];
// 	int		x;

// 	x = +2147483648;
// 	printf("%d\n", ft_snprintf(buffer, 100, "%s\n", NULL));
// 	printf("%d\n", printf("%s", buffer));
// 	// printf("real hi there %u%%%s\n", 22222147483649);
// }
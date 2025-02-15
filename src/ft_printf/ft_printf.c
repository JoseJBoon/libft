/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 10:21:17 by jboon         #+#    #+#                 */
/*   Updated: 2025/02/01 16:37:52 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

#define PRINT_SIZE 9

static const t_printf	g_print[PRINT_SIZE] = { 
{'c', ft_printf_char}, {'s', ft_printf_str}, {'i', ft_printf_int},
{'d', ft_printf_int}, {'u', ft_printf_uint}, {'x', ft_printf_hex},
{'X', ft_printf_hex}, {'p', ft_printf_ptr}, {'%', ft_printf_char}
};

static void	set_print_data(va_list args, char spec, t_printf_data *p_data)
{
	if (spec == 'c')
		p_data->c = va_arg(args, int);
	else if (spec == 's')
		p_data->str = va_arg(args, char *);
	else if (spec == 'i' || spec == 'd')
		p_data->i = va_arg(args, int);
	else if (spec == 'x' || spec == 'X' || spec == 'u')
		p_data->u_lint = va_arg(args, unsigned int);
	else if (spec == 'p')
		p_data->ptr = va_arg(args, void *);
	else if (spec == '%')
		p_data->c = '%';
	else
		p_data->u_lint = 0;
}

/*
	Select the specifier based on c and write the output.
	@return The amount of printed characters. 0 if no specifier was found.
*/
static int	write_specifier(const char *c, int s_ln, t_format *f, va_list args)
{
	t_printf_data	p_data;
	int				len;
	char			*dst;

	len = -1;
	while (len < PRINT_SIZE && g_print[++len].specifier != *c)
		;
	if (len == PRINT_SIZE)
		return (write(STDOUT_FILENO, (c - 1), s_ln));
	set_print_data(args, g_print[len].specifier, &p_data);
	len = g_print[len].call(p_data, f, &dst);
	if (dst == NULL)
		return (-1);
	return (len = write(STDOUT_FILENO, dst, len), free(dst), len);
}

/*
	Write the format to the output.
	On failure will print out the format string itself.
	@return Pointer s at the end of the format string.
*/
static const char	*write_next(const char *s, va_list args, ssize_t *w_byte)
{
	const char	*start;
	ssize_t		bytes;
	t_format	f;

	start = s;
	s = ft_strchrnul(s, '%');
	bytes = write(STDOUT_FILENO, start, s - start);
	if (bytes == -1)
		return (*w_byte = -1, start);
	*w_byte += bytes;
	if (*s == '\0')
		return (s);
	s = ft_parse_format(++s, &f);
	bytes = write_specifier(s, (s - start) + 1, &f, args);
	if (bytes == -1)
		return (*w_byte = -1, s);
	*w_byte += bytes;
	return (++s);
}

/*
	Write formatted output to stdout.
	@return Successfull return, will return the amount of characters printed.
	@note
		Supports: flags(#0- +.), minumum width, and precision.

		Specifiers: %cspxXiud.

		No support: * or *n$.
*/
int	ft_printf(const char *s, ...)
{
	va_list		args;
	ssize_t		bytes;
	ssize_t		total;

	if (s == NULL)
		return (-1);
	total = 0;
	va_start(args, s);
	while (*s)
	{
		bytes = 0;
		s = write_next(s, args, &bytes);
		if (bytes == -1)
			return (va_end(args), -1);
		total += bytes;
	}
	va_end(args);
	return (total);
}

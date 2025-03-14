#include "../../include/ft_printf.h"

int	print_c(int c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}

int	print_s(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

int	print_p_len(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

void	print_p_write(uintptr_t ptr)
{
	char	c;
	char	*hex;

	hex = "0123456789abcdef";
	if (ptr >= 16)
	{
		print_p_write(ptr / 16);
		print_p_write(ptr % 16);
	}
	else
	{
		c = hex[ptr];
		write(1, &c, 1);
	}
}

int	print_p(void *pointer)
{
	uintptr_t	ptr;
	int			count;

	ptr = (uintptr_t)pointer;
	count = 0;
	if (ptr == 0)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	print_p_write(ptr);
	count += print_p_len(ptr);
	return (count);
}

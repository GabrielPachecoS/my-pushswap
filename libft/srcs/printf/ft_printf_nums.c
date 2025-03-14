#include "../../include/ft_printf.h"

int	print_d_i(int n)
{
	int		count;
	int		i;
	char	*nbr;

	nbr = ft_itoa(n);
	i = 0;
	count = 0;
	while (nbr[i])
	{
		count += write(1, &nbr[i++], 1);
	}
	free(nbr);
	return (count);
}

int	print_x_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	print_x_write(unsigned int n, char format)
{
	char	c;
	char	*hex;
	char	*hexx;

	hex = "0123456789abcdef";
	hexx = "0123456789ABCDEF";
	if (n >= 16)
	{
		print_x_write(n / 16, format);
		print_x_write(n % 16, format);
	}
	else
	{
		if (format == 'x')
		{
			c = hex[n];
			write(1, &c, 1);
		}
		else if (format == 'X')
		{
			c = hexx[n];
			write(1, &c, 1);
		}
	}
}

int	print_x(unsigned int n, char format)
{
	int	count;

	print_x_write(n, format);
	count = print_x_len(n);
	return (count);
}

int	print_u(unsigned int n)
{
	int		count;
	char	*nbr;
	int		i;

	count = 0;
	i = 0;
	nbr = ft_uitoa(n);
	while (nbr[i])
		count += write(1, &nbr[i++], 1);
	free(nbr);
	return (count);
}

#include "../../include/ft_printf.h"

int	p_format(va_list ap, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_c(va_arg(ap, int));
	else if (format == 's')
		count += print_s(va_arg(ap, char *));
	else if (format == 'p')
		count += print_p(va_arg(ap, void *));
	else if (format == 'u')
		count += print_u(va_arg(ap, unsigned int));
	else if (format == 'i' || format == 'd')
		count += print_d_i(va_arg(ap, int));
	else if (format == 'x' || format == 'X')
		count += print_x(va_arg(ap, unsigned int), format);
	else
	{
		write(1, "%", 1);
		count += 1;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	ap;

	if (!str)
		return (-1);
	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && (ft_islower(str[i + 1])
				|| str[i + 1] == '%' || str[i + 1] == 'X'))
		{
			count += p_format(ap, str[i + 1]);
			i++;
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

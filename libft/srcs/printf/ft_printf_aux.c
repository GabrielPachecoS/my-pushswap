#include "../../include/ft_printf.h"

int	ft_unumlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*d;
	int		len;

	len = ft_unumlen(n);
	d = malloc((len + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	d[len] = '\0';
	if (n == 0)
		d[0] = '0';
	while (n > 0)
	{
		d[(--len)] = (n % 10) + '0';
		n = n / 10;
	}
	return (d);
}

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*d;
	int		len;
	long	num;

	num = n;
	len = ft_intlen(num);
	d = malloc((len + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	d[len] = '\0';
	if (num < 0)
	{
		d[0] = '-';
		num = -num;
	}
	else if (num == 0)
		d[0] = '0';
	while (num > 0)
	{
		d[(--len)] = (num % 10) + '0';
		num = num / 10;
	}
	return (d);
}

int	ft_islower(int c)
{
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

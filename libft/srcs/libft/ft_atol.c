#include "../../include/libft.h"

long	ft_atol(const char *nptr)
{
	long	i;
	int		sign;

	i = 0;
	sign = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		i = (i * 10) + (*nptr - 48);
		nptr++;
	}
	return (i * sign);
}

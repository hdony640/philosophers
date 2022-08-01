#include "philosophers.h"

static int	ft_isspace(char a)
{
	if ((a >= 9 && a <= 13) || a == 32)
		return (1);
	return (0);
}

static int	ft_above(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long		r;

	i = 0;
	r = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	if (i > 19 || r >= 9223372036854775807ULL)
		return (ft_above(sign));
	return (r * sign);
}

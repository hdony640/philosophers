#include "philosophers.h"

/* fill the param array of the data struct */

int parsing(char **av, t_data *data)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (av[i])
    {
        data->param[j] = ft_atoi(av[i]);
        i++;
        j++;
    }
    create_philo(data);
    return (0);
}
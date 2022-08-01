#include "philosophers.h"

void    free_mutex(t_data *data)
{
    int i;
    int err;

    i = 0;
    while (i < data->param[0])
    {
        err = pthread_mutex_destroy(&data->ptr[i].mutex_l);
        if (err != 0)
        {
            printf("mutex destroyed failed\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
}
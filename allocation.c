#include "philosophers.h"

/* check right mutex are referenced */

void    check_mutex_referenced(t_data *data)
{
    int i;

    i = 0;
    while (i < data->param[0])
    {
        printf("philo [%d] %p\n", i, &data->ptr[i]);
        printf("thread [%d] %p\n", i, &data->ptr[i].thread);
        printf("mutex_left [%d] %p\n", i, &data->ptr[i].mutex_l);
        printf("mutex_right [%d] %p\n", i, data->ptr[i].mutex_r);
        printf("\n");
        i++;
    }
}

void    init_mutex_right(t_data *data)
{
    int i;
    int j;
        
    i = data->param[0];
    j = (i - 1);
    while (--i >= 0)
    {
        --j;
        if (i == 0)
        {
            j = (data->param[0] - 1);
        }            
        data->ptr[i].mutex_r = &data->ptr[j].mutex_l;
        // printf("i = %d\n", i);
        // printf("j = %d\n", j);
    }
    check_mutex_referenced(data);
}

/* initialize left mutex to control access
** to the eating function */

void    init_mutex_left(t_data *data)
{
    int i;

    i = 0;
    while (i < data->param[0])
    {
        pthread_mutex_init(&data->ptr[i].mutex_l, NULL);
        i++;
    }
    init_mutex_right(data);
}

/* initialize the thread (lw process) */

void    init_thread(t_data *data)
{
    int i;
    int err;

    i = 0;
    while (i < data->param[0])
    {
        err = pthread_create(&data->ptr[i].thread, NULL,
            &philo, (void *)&data->ptr[i]);
        if (err != 0)
        {
            printf("thread creation failed\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
}

void    init_philo_struct(t_philo *alloc)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < data->param[0])
    {
        data->ptr[i].nbr_of_philo = data->param[0];
        data->ptr[i].philo_id = ++j;
        data->ptr[i].time_to_die = data->param[1];
        data->ptr[i].time_to_eat = data->param[2];
        data->ptr[i].time_to_sleep = data->param[3];
        data->ptr[i].nbr_time_must_eat = data->param[4];
        data->ptr[i].nbr_of_meal = 0;
        data->ptr[i].time_since_last_meal = 0;
        i++;
    }
    init_mutex_left(data);
    init_thread(data);    
}

/* one philo is represented as a struct
** allocate mem for xx structures data type */

void    create_philo(t_data *data)
{
    t_philo *alloc;

    alloc = malloc(sizeof(t_philo) * data->param[0]);
    if (!alloc)
        return ;
    // data->ptr = malloc(sizeof(data->ptr) * data->param[0]);
    // if (!data->ptr)
    //     return ;
    // init_philo_struct(data);
    init_philo_struct(alloc);
}
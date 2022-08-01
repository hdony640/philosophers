#include "philosophers.h"

/* the two f's can't get executed simultaneously
** so we use threads */

int main(int ac, char **av)
{
  
    t_data  data;
    int     i;
    int     err;             
        
    i = 0;
    err = 0;
    if (ac < 5 || ac > 6)
        exit(EXIT_FAILURE);
    parsing(av, &data);
    while (i < data.param[0])
    {
        err = pthread_join(data.ptr[i].thread, NULL);
        if (err != 0)
        {
            printf("pthread_join failed\n");
            printf("err: %d\n", err);
            exit(EXIT_FAILURE);
        }
        // printf("thread joined: %p\n", &data.ptr[i].thread);
        i++;       
    }
    return (0);
}
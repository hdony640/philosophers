#include "philosophers.h"

void    lock_mutex(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_l);
    print_messages(philo, "has taken a left fork");
    printf("%p\n", &philo->mutex_l);
    pthread_mutex_lock(philo->mutex_r);
    print_messages(philo, "has taken a right fork");
    printf("%p\n", philo->mutex_r);
}

void    unlock_mutex(t_philo *philo)
{
    pthread_mutex_unlock(&philo->mutex_l);
    pthread_mutex_unlock(philo->mutex_r);
}

void *philo(void *param)
{
    t_philo *philo;
    int i;

    i = 0;
    philo = (t_philo*)param;
    philo->philo_creation_time = get_time();
    if (philo->philo_id % 2 == 0 && philo->nbr_of_philo > 1)
    {
        printf("enter even condition\n");
        usleep(500);
    }
    while (i < philo->nbr_of_philo)
    {
        lock_mutex(philo);
        if (philo_action_eat(philo))
        {
            printf("return (NULL)\n");
            return (NULL);
        }
        unlock_mutex(philo);
        philo_action_sleep(philo);
        philo_action_think(philo);
        i++;
    }
    return (NULL);
}
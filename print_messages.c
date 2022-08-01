#include "philosophers.h"

void    print_messages(t_philo *philo, char *msg)
{
    int delta_time;

    philo->time_message_function = get_time();
    delta_time = philo->time_message_function - philo->philo_creation_time;
    pthread_mutex_lock(&philo->mutex_display);
    printf("%d ms %d %s\n", delta_time, philo->philo_id, msg);
    pthread_mutex_unlock(&philo->mutex_display);
    printf("\n");
}
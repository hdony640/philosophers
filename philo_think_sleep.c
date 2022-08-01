#include "philosophers.h"

void    philo_action_sleep(t_philo *philo)
{
    print_messages(philo, "is sleeping");
    usleep(philo->time_to_sleep);    
}

/* how long a philo should think = the remaining time ? */

void    philo_action_think(t_philo *philo)
{
    print_messages(philo, "is thinking");
}
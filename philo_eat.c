#include "philosophers.h"

/* lock mutex_left then mutex_rigt
** eat for a const time and unlock
** mutex_left and mutex_rigt */

void    handle_1_philo(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_l);
    usleep(philo->time_to_die);
    if (philo->time_since_last_meal > philo->time_to_die)
        pthread_join(philo->thread, NULL);
    exit(EXIT_FAILURE);
}

int check_meal_condition(t_philo *philo)
{
    int err;

    philo->nbr_of_meal++;
    if (philo->nbr_of_meal == philo->nbr_time_must_eat)
    {
        print_messages(philo, "has eaten enough meals");
        return (1);
    }
    return (0);
}

int philo_action_eat(t_philo *philo)
{
    if (philo->nbr_of_philo == 1)
        handle_1_philo(philo);
    print_messages(philo, "is eating");
    if (check_meal_condition(philo))
    {
        printf("return (1)\n");
        return (1);
    }
    philo->time_since_last_meal = get_time();
    usleep(philo->time_to_eat);
    return (0);
}
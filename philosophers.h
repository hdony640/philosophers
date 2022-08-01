#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

/* data type */

typedef struct s_data
{
    int             param[5];
    int             nbr_of_meal;
}   t_data;

typedef struct s_philo
{
    int             nbr_of_philo;
    int             philo_id;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             nbr_time_must_eat;
    int             philo_creation_time;
    int             time_since_last_meal;
    int             time_message_function;
    pthread_t       thread;
    pthread_mutex_t mutex_l;
    pthread_mutex_t *mutex_r;
    pthread_mutex_t mutex_display;
    t_data          *ptr;
}   t_philo;

/* parsing */

int    parsing(char **av, t_data *data);

int	    ft_atoi(const char *str);

/* timing */

int get_time(void);

/* memory allocation */

void    create_philo(t_data *data);

void    *philo(void *param);

/* eating */

int philo_action_eat(t_philo *philo);

/* sleeping */

void    philo_action_sleep(t_philo *philo);

/* thinking */

void    philo_action_think(t_philo *philo);

/* print messages */

void    print_messages(t_philo *philo, char *msg);

/* free */

void    free_mutex(t_data *data);

void    check_mutex_referenced(t_data *data);

#endif
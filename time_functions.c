#include "philosophers.h"

/*  L'argument tv est une structure timeval et donne le nombre
**  de secondes et microsecondes écoulées depuis le 1er janvier 1970
**  Convertir en millisecondes la structure tv. */

int get_time(void)
{
    int             err;
    struct timeval  tv;

    err = gettimeofday(&tv, NULL);
    if (err != 0)
    {
        printf("gettimeofday error\n");
        exit(EXIT_FAILURE);
    }
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
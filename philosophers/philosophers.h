/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:01:02 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/09 12:01:05 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <limits.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <time.h>
# include <unistd.h>

# define MAX_PHILOS 200

struct s_data;
typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				eat_cont;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_nb;
	int				dead;
	int				finished;
	t_philo			*philos;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}					t_data;

void				free_data_struct(t_data *data);
int					ft_atoi(const char *nptr);
void				std_error(char *msg);
int					has_letters(char *str);
int					check_numbers(int *nums, int argc, char **argv);
int					checks(int *nums, int argc, char **argv);
int					check_num_values(int *nums);
t_data				*init_data(int *nums);
void				init_philos(t_data *data);
int					init_forks(t_data *data);
int					get_mem(t_data *data);
t_data				*init(int *nums);
#endif

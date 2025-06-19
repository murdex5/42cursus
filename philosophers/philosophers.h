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
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# define MAX_PHILOS 200

typedef struct s_data
{
	int				num_philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				max_meals;
	bool			death_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t meal_mutex;
	time_t			start_time;
}					t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	time_t			last_meal_time;
	int				meals_eaten;
	t_data			*data;
}					t_philo;

void				destroy_mutex(t_data *data);
int					only_one(t_data *data, t_philo *philo);
void				set_forks(t_philo *philo,
						pthread_mutex_t **first_fork_to_pick,
						pthread_mutex_t **second_fork_to_pick);
int					pick_forks(t_data *data, t_philo *philo,
						pthread_mutex_t *first_fork_to_pick,
						pthread_mutex_t *second_fork_to_pick);
void				update_meals(t_data *data, t_philo *philo);
bool				check_death(t_data *data);
void				ft_usleep(time_t milliseconds, t_data *data);
bool				if_odd(int n);
void				free_data_struct(t_data *data, t_philo **philos);
int					ft_atoi(const char *nptr);
void				log_action(t_data *data, int philo_id, char *msg);
void				std_error(char *msg);
int					has_letters(char *str);
int					check_numbers(int *nums, int argc, char **argv);
int					checks(int *nums, int argc, char **argv);
int					check_num_values(int *nums);
t_data				*init_data(int *nums);
int					init_philos(t_data *data, t_philo **philos);
int					init_forks(t_data *data, t_philo **philos);
time_t				get_time(void);
t_data				*init(int *nums, t_philo **philos);
void				free_philos(t_philo **philos);
t_data				*do_checks_and_parse(t_philo **philos, int *nums);
int					check_death_loop(time_t current_time, t_philo **philos,
						t_data *data, bool *all_philos_eaten);
#endif

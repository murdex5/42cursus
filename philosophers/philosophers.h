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
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	bool			death_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	write_mutex;
	long			start_time;
}					t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal_time;
	int				meals_eaten;
	t_data			*data;
}					t_philo;

void				free_data_struct(t_data *data);
int					ft_atoi(const char *nptr);
void				std_error(char *msg);
int					has_letters(char *str);
int					check_numbers(int *nums, int argc, char **argv);
int					checks(int *nums, int argc, char **argv);
int					check_num_values(int *nums);
t_data				*init_data(int *nums);
int					init_philos(t_data *data, t_philo **philos);
int					init_forks(t_data *data, t_philo **philos);
u_int64_t			get_time(void);
t_data	*init(int *nums, t_data *data, t_philo **philos);
#endif

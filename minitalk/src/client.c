/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:39:13 by lofiorin          #+#    #+#             */
/*   Updated: 2024/05/10 16:29:35 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error_handler(int i)
{
	if (i == 0)
		ft_putstr_fd("Sigaction error.\n", 2);
	else
		ft_putstr_fd("Kill error.\n", 2);
	exit(1);
}

static void	client(int pid, unsigned char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if ((c >> i) & 1)
		{
			if (kill (pid, SIGUSR1) == -1)
				error_handler(1);
		}
		else if (kill (pid, SIGUSR2) == -1)
			error_handler(1);
		usleep(100);
	}
}

static int	pid_get(char *pid)
{
	int	i;

	i = -1;
	while (pid[++i])
		if (pid[i] < '0' || pid[i] > '9')
			return (0);
	return (ft_atoi(pid));
}

int	main(int ac, char **av)
{
	int					pid;
	size_t				i;

	if (ac != 3 || !av[2])
		return (1);
	i = 0;
	pid = pid_get(av[1]);
	if (!pid)
		return (1);
	while (av[2][i])
		client(pid, av[2][i++]);
	client (pid, '\0');
	return (0);
}

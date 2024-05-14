/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:39:13 by lofiorin          #+#    #+#             */
/*   Updated: 2024/05/10 16:22:58 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*g_msg;

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

static void	recived(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("Byte received\n", 1);
		client(info->si_pid, *(g_msg++));
	}
	else
	{
		ft_printf("All done!\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;
	size_t				i;

	if (ac != 3 || !av[2])
		return (1);
	sa = (struct sigaction){0};
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &recived;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error_handler(0);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler(0);
	i = 0;
	pid = pid_get(av[1]);
	if (!pid)
		return (1);
	g_msg = av[2];
	g_msg++;
	client(pid, av[2][0]);
	client (pid, '\0');
	sleep(5);
	ft_putstr_fd("Timeout error\n", 2);
	return (1);
}

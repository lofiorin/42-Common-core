/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:39:27 by lofiorin          #+#    #+#             */
/*   Updated: 2024/05/10 16:22:57 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_server	g_serv;

static void	error_handler(int i)
{
	g_serv = (t_server){0};
	if (i == 0)
	{
		ft_putstr_fd("Sigaction error.\n", 2);
		exit(1);
	}
	else
		ft_putstr_fd("Kill error.\nServer has been reset.\n", 2);
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (info->si_pid != g_serv.client_pid)
		write(1, "\n", 1);
	if (info->si_pid != g_serv.client_pid)
		g_serv = (t_server){0};
	g_serv.client_pid = info->si_pid;
	g_serv.c = g_serv.c + ((sig == SIGUSR1) << g_serv.i);
	if (++g_serv.i == 8)
	{
		if (g_serv.c == 0)
		{
			write(1, "\n", 1);
			if (kill(info->si_pid, SIGUSR2) == -1)
				error_handler(1);
		}
		else
		{
			write(1, &(g_serv.c), 1);
			if (kill(info->si_pid, SIGUSR1) == -1)
				error_handler(1);
		}
		g_serv.c = 0;
		g_serv.i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("pid :\t %d\n", getpid());
	sa = (struct sigaction){0};
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error_handler(0);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler(0);
	while (1)
		pause();
}

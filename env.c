/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:52:37 by hgicquel          #+#    #+#             */
/*   Updated: 2022/01/24 14:00:46 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_env(char **envp)
{
	if (!envp)
		return (1);
	while (*envp)
		printf("%s\n", *envp++);
	return (0);
}

int	ft_unset2(t_state *g, char *arg)
{
	char	**kv;

	kv = ft_split(arg, '=');
	if (ft_ptrlen((void **) kv) != 1)
	{
		printf("unset: \"%s\": not a valid identifier\n", arg);
		ft_freep((void **) kv);
		return (1);
	}
	if (!ft_isenvstr(kv[0]))
	{
		printf("unset: \"%s\": not a valid identifier\n", arg);
		ft_freep((void **) kv);
		return (1);
	}
	ft_freep((void **) kv);
	ft_remenv(&(g->envlst), arg);
	return (0);
}

int	ft_unset(t_state *g, char **args)
{
	int		i;
	bool	e;

	i = 1;
	e = false;
	while (args[i])
		e |= ft_unset2(g, args[i++]);
	return (e);
}

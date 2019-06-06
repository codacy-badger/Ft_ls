/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:55:09 by abarthel          #+#    #+#             */
/*   Updated: 2019/06/06 08:51:05 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "dlist.h"

t_dlist	*create_node(t_dlist *previous, t_dlist *next, struct dirent *s_dir)
{
	t_dlist	*new;

	if ((new = malloc_a_node()))
	{
		new->next = next;
		new->previous = previous;
		new->s_dir = s_dir;
		new->pw_name = NULL;
		new->gr_name = NULL;
		new->file_modif = NULL;
		new->linkname = NULL;
		new->pathname = NULL;
		return (new);
	}
	else
	{
		free_entire_dlist(previous);
		return (NULL);
	}
}

t_dlist	*malloc_a_node(void)
{
	t_dlist	*new;

	if ((new = (t_dlist*)malloc(sizeof(t_dlist))))
		return (new);
	else
		return (NULL);
}

void	free_entire_dlist(t_dlist *somewhere_in_dlist)
{
	t_dlist	*tmp;

	tmp = NULL;
	while (somewhere_in_dlist && somewhere_in_dlist->next)
		somewhere_in_dlist = somewhere_in_dlist->next;
	while (somewhere_in_dlist)
	{
		tmp = somewhere_in_dlist->previous;
		if (somewhere_in_dlist->pw_name)
			free(somewhere_in_dlist->pw_name);
		if (somewhere_in_dlist->gr_name)
			free(somewhere_in_dlist->gr_name);
		if (somewhere_in_dlist->file_modif)
			free(somewhere_in_dlist->file_modif);
		if (somewhere_in_dlist->pathname)
			free(somewhere_in_dlist->pathname);
		free(somewhere_in_dlist);
		somewhere_in_dlist = tmp;
	}
}

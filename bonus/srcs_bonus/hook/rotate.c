/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:26:14 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/10 17:24:40 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	rot_left(t_cub *cub)
{
	cub->p1->angle += 2;
	if (cub->p1->angle > 360)
		cub->p1->angle -= 360;
	return (0);
}

int	rot_right(t_cub *cub)
{
	cub->p1->angle -= 2;
	if (cub->p1->angle < 0)
		cub->p1->angle += 360;
	return (0);
}

int	rotate(t_cub *cub)
{
	cub->p1->angle = ((double)-cub->var->mouse_pos[0] / \
	(cub->var->resolution[0] / 2)) * 360;
	return (0);
}

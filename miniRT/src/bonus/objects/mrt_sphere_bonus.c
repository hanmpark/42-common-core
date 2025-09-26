/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_sphere_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:37:16 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/07 12:44:52 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt_render_bonus.h"

static void	hit_surface_normal(t_hit *hit, t_fvec3 ray, t_obj *o)
{
	t_fvec3	obj_normal;

	compute_spheric_uv(hit, ray, SPHERE);
	hit->pos = mult_mat4x4_fvec3(ray, o->fmat4x4[FORWARD]);
	obj_normal = ray;
	hit->normal = norm_fvec3(mult_mat3x3_fvec3(obj_normal, o->lintfm));
}

static bool	sphere_root(t_hit *hit, t_fvec3 pos, t_fvec3 dir, t_obj *o)
{
	double	root;
	t_fvec3	newray;

	root = solve_quadratic(\
		dot_fvec3(dir, dir), \
		2 * dot_fvec3(pos, dir), \
		dot_fvec3(pos, pos) - 1, -1);
	if (root < 0.0)
		return (false);
	newray = add_fvec3(pos, mult_double_fvec3(dir, root));
	hit_surface_normal(hit, newray, o);
	return (true);
}

bool	hit_sphere(t_obj *object, t_ray ray, t_hit *hit)
{
	t_ray	backray;

	if (object->type != SPHERE)
		return (false);
	backray = ray_apply_matrix(ray, object->fmat4x4[BACKWARD]);
	if (!sphere_root(hit, backray.pos, backray.vec, object))
		return (false);
	set_closest_hit(ray.pos, hit, object);
	return (true);
}

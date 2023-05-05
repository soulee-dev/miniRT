/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:14:05 by soulee            #+#    #+#             */
/*   Updated: 2023/05/05 14:55:05 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hittable_list random_scene(void)
{
	t_hittable_list	world;
	t_material		ground_material;

	t_lambertian	lambertian_ground;
	t_texture		texture_ground;
	ground_material.type = MATERIAL_LAMBERTIAN;
	texture_ground.type = TEXTURE_CHECKER;
	texture_ground.checker.odd = create_vec3_xyz(0.2, 0.3, 0.1);
	texture_ground.checker.even = create_vec3_t(0.9);
	lambertian_ground.albedo = texture_ground;
	ground_material.lambertian = lambertian_ground;

	world.objects[0].type = SHAPE_SPHERE;
	world.objects[0].sphere.center = create_vec3_xyz(0, -1000, 0);
	world.objects[0].sphere.radius = 1000;
	world.objects[0].sphere.mat_ptr = ground_material;

	world.size = 1;
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			double		choose_mat = random_double();
			t_point3	center = create_vec3_xyz((i - 11) + 0.9 * random_double(), 0.2, (j - 11) + 0.9 * random_double());

			if (length(sub_vec3(center, create_vec3_xyz(4, 0.2, 0))) > 0.9)
			{
				if (choose_mat < 0.8)
				{
					// diffuse
					t_color		albedo = mul_vec3(random_vec3(), random_vec3());
					t_material	sphere_material;
					t_vec3		center2 = add_vec3(center, create_vec3_xyz(0, random_double2(0, 0.5), 0));
					
					t_lambertian	lambertian_sphere;
					t_texture		texture_sphere;
					sphere_material.type = MATERIAL_LAMBERTIAN;
					texture_sphere.type = TEXTURE_SOLID_COLOR;
					texture_sphere.solid_color.color = albedo;								
					lambertian_sphere.albedo = texture_sphere;
					sphere_material.lambertian = lambertian_sphere;

					world.objects[world.size].type = SHAPE_MOVING_SPHERE;
					world.objects[world.size].moving_sphere.center0 = center;
					world.objects[world.size].moving_sphere.center1 = center2;
					world.objects[world.size].moving_sphere.time0 = 0.0;
					world.objects[world.size].moving_sphere.time1 = 1.0;
					world.objects[world.size].moving_sphere.radius = 0.2;
					world.objects[world.size].moving_sphere.mat_ptr = sphere_material;
					world.size++;
				}
				else if (choose_mat < 0.95)
				{
					// metal
					t_material	sphere_material;
					t_metal		metal_sphere;
					sphere_material.type = MATERIAL_METAL;
					metal_sphere.albedo = random_vec3_2(0.5, 1);
					metal_sphere.fuzz = random_double2(0, 0.5);
					sphere_material.metal = metal_sphere;

					world.objects[world.size].type = SHAPE_SPHERE;
					world.objects[world.size].sphere.center = center;
					world.objects[world.size].sphere.radius = 0.2;
					world.objects[world.size].sphere.mat_ptr = sphere_material;
					world.size++;
				}
				else
				{
					t_material	sphere_material;
					t_dielectric	dielectric_sphere;
					sphere_material.type = MATERIAL_DIELECTRIC;
					dielectric_sphere.ir = 1.5;
					sphere_material.dielectric = dielectric_sphere;

					world.objects[world.size].type = SHAPE_SPHERE;
					world.objects[world.size].sphere.center = center;
					world.objects[world.size].sphere.radius = 0.2;
					world.objects[world.size].sphere.mat_ptr = sphere_material;
					world.size++;
				}
			}
		}
	}
	t_dielectric	dielectric_material1;
	t_material	material1;
	material1.type = MATERIAL_DIELECTRIC;
	dielectric_material1.ir = 1.5;
	material1.dielectric = dielectric_material1;

	world.objects[world.size - 1].type = SHAPE_SPHERE;
	world.objects[world.size - 1].sphere.center = create_vec3_xyz(0, 1, 0);
	world.objects[world.size - 1].sphere.radius = 1.0;
	world.objects[world.size - 1].sphere.mat_ptr = material1;
	world.size++;

	t_material	material2;
	t_lambertian	lambertian_material2;
	t_texture		texture_2;
	material2.type = MATERIAL_LAMBERTIAN;
	texture_2.type = TEXTURE_SOLID_COLOR;
	texture_2.solid_color.color = create_vec3_xyz(0.4, 0.2, 0.1);
	lambertian_material2.albedo = texture_2;
	material2.lambertian = lambertian_material2;

	world.objects[world.size - 1].type = SHAPE_SPHERE;
	world.objects[world.size - 1].sphere.center = create_vec3_xyz(-4, 1, 0);
	world.objects[world.size - 1].sphere.radius = 1.0;
	world.objects[world.size - 1].sphere.mat_ptr = material2;
	world.size++;

	t_metal		metal_material3;
	t_material	material3;
	material3.type = MATERIAL_METAL;
	metal_material3.albedo = create_vec3_xyz(0.7, 0.6, 0.5);
	metal_material3.fuzz = 0.0;
	material3.metal = metal_material3;

	world.objects[world.size - 1].type = SHAPE_SPHERE;
	world.objects[world.size - 1].sphere.center = create_vec3_xyz(4, 1, 0);
	world.objects[world.size - 1].sphere.radius = 1.0;
	world.objects[world.size - 1].sphere.mat_ptr = material3;
	world.size++;

	t_diffuse_light		metal_material4;
	t_material	material4;
	material4.type = MATERIAL_DIFFUSE_LIGHT;
	metal_material4.emit = create_vec3_t(7.0);
	material4.diffuse_light = metal_material4;

	world.objects[world.size - 1].type = SHAPE_XY_RECT;
	world.objects[world.size - 1].xy_rect.x0 = 3;
	world.objects[world.size - 1].xy_rect.x1 = 5;
	world.objects[world.size - 1].xy_rect.y0 = 1;
	world.objects[world.size - 1].xy_rect.y1 = 3;
	world.objects[world.size - 1].xy_rect.k = -2;
	world.objects[world.size - 1].xy_rect.mat_ptr = material4;
	world.size++;
	return world;
}
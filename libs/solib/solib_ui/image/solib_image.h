/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_image.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 03:10:56 by marvin            #+#    #+#             */
/*   Updated: 2024/03/10 03:10:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//canvas
	// -- t_solib_canvas canvas_name = solib->display->new_canvas(t_solib_display *display, char *name, char *background, enum type d'affichage);
	// -- t_solib_image canvas_background = solib_image(t_solib *solib, float width, float height, char *background);


								//nom de l'image x et y					//renvoie une image vide avec les dimention voulu
	// t_solib_image *image = canvas_name->add_image(canvas_name , char *name  solib_new_vector2(x, y), canvas_name->new_image(float width, float height, char *background) // fonction pour creer l'image return une image vide)


	// -- t_image_image  image  = canvas_name->new_image(solib, char *name, x, y) // ajout dans la liste chainé l'image n'as pas acces au parent 
	// -- canvas_name->get_image(solib, char *name)
	// -- canvas_name->remove_image(solib, char *name)
	// -- canvas_name->enabled_image(solib, char *name)

		// -- image.name = "";
		// -- image.background("");
		// -- image.x = 
		// -- image.y = 
		// -- image.width = 
		// -- image.height = 
		// -- image.enabled(false) // la retire de la liste chainé mais la save a coté la remet quand true
	//sprite
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debut_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:24:30 by jorobin           #+#    #+#             */
/*   Updated: 2016/12/20 15:28:18 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cet algorithme va determiner a partir des tetriminos choisis le plus petit
//carre que ceux-ci peuvent former a partir des differents assemblages
//possibles dans leur ordre d'apparition (les tetriminos ne s'emboitent pas
//forcement, le carre peut donc presenter des trous)
//--------------------------------------------------------------------------
//
//Le tetriminos place sera le plus en haut et a gauche possible.
//Il faut donc:
//- Une fonction qui teste si les tetriminos sont tous valides 
//- une fonction de placement du tetriminos au "carre" et qui passera au tetriminos suivant
//jusqu'a ce qu'il n'y ai plus de tetriminos (fin du fichier ouvert)
//- ma bite
// kekosaure

/*
UPDATE
ouvrir le fichier
Lire le fichier
stocker dans une chaine
couper la chaine par pieces
checker chaque pieces

Si valide
Placer le tetrimino
checker si le placement est le plus opti
repeter autant de fois qu'il y a de piece

afficher grille
FIN
*/

#include "libft.h"

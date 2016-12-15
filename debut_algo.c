/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debut_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorobin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:24:30 by jorobin           #+#    #+#             */
/*   Updated: 2016/12/15 18:13:34 by jorobin          ###   ########.fr       */
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
//- une fonction qui check la position initiale du tetriminos qu'on testera dans
//la fonction test de la meilleure position 
//- une fonction qui change la position du tetriminos
//- une fonction qui trouve la meilleure position du tetriminos (moins d'espace etc)
//- une fonction de placement du tetriminos au "carre" et qui passera au tetriminos suivant
//jusqu'a ce qu'il n'y ai plus de tetriminos (fin du fichier ouvert)
//- ma bite
#include "libft.h"

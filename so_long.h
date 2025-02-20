/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:00:10 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/20 13:00:10 by bobytrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include <stdio.h>									//! printf just for testing 
# include <unistd.h>								// Write
# include <stdlib.h>								// Mallocs
# include <X11/X.h>
# include <X11/keysym.h>

//	------------------
//	::  parameters  ::
//	------------------
# define SIZE 32
# define HEIGHT 32
# define WIDTH 32

//	--------------
//	::  Assets  ::
//	--------------

//	------------
//	::  keys  ::
//	------------
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

//	------------------
//	::  Validators  ::
//	------------------
int	xs_check(int ac, char **av);


//	-------------
//	::  Tools  ::
//	-------------

//	------------
//	::  Free  ::
//	------------



#endif
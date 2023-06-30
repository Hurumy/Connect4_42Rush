/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect4.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:17:36 by komatsud          #+#    #+#             */
/*   Updated: 2023/06/30 21:48:25 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONNECT4_H
# define FT_CONNECT4_H 
# include <stdlib.h>
# include <time.h>
# include <limits.h>
# include "libft.h"

//ft_init.c
int		ft_init(int argc, int argv);

//ft_error.c
void	ft_error_invalidargs(void);
void	ft_error_with_free(void);


#endif
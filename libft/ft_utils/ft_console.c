/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:05:41 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/18 13:59:49 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void    ft_console_log(char *str) 
{
    int newFile;
    
    newFile = open("./projet.log", O_RDWR | O_CREAT | O_APPEND);
    ft_putstr_fd(str, newFile);
}

void    ft_console_log_num(int num) 
{
    int newFile;
    
    newFile = open("./projet.log", O_RDWR | O_CREAT | O_APPEND);
    ft_putnbr_fd(num, newFile);

}

void    ft_console_log_clear(void)
{
    int newFile;
    
    newFile = open("./projet.log", O_RDWR | O_CREAT | O_TRUNC);
    ft_putstr_fd("", newFile);
}
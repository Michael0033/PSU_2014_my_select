/*
** my_putstr.c for my_putstr.c in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Fri Jan  9 11:31:33 2015 michael besnainou
** Last update Sat Jan 10 19:49:05 2015 michael besnainou
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  while (*str)
    write(1, str++, 1);
}

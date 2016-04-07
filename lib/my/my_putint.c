/*
** my_putint.c for my_putint.c in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Fri Jan  9 11:33:13 2015 michael besnainou
** Last update Fri Jan  9 13:12:04 2015 michael besnainou
*/

#include <unistd.h>

int	my_putint(int i)
{
  write(1, &i, 1);
  return (0);
}

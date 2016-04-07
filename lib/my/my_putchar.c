/*
** my_putchar.c for my_putchar.c in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Fri Jan  9 11:32:32 2015 michael besnainou
** Last update Fri Jan  9 11:32:58 2015 michael besnainou
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

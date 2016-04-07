/*
** gere_key.c for gere_key.c in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Sun Jan 11 15:17:43 2015 michael besnainou
** Last update Sun Jan 11 17:58:48 2015 michael besnainou
*/

#include		<termios.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<term.h>
#include		"include/my_select.h"

int			init_key(t_slt *slt)
{
  slt->key[0] = 0;
  slt->key[1] = 0;
  slt->key[2] = 0;
  if (read(0, slt->key, 3) == -1)
    return (2);
  return (0);
}

int			detect_keys(int argc, char **argv, t_slt *slt)
{
  int			tab_int[argc];

  slt->underline =  (init_tab(argc, tab_int));
  while (1)
    {
      tputs(tgetstr("cl", NULL), 0, my_putint);
      aff_params(argc, argv, slt, tab_int);
      init_key(slt);
      if (slt->key[0] == 27 && slt->key[1] == 0 && slt->key[2] == 0)
        return (0);
      else if (slt->key[0] == 27 && slt->key[1] == 91 && slt->key[2] == 65)
        slt->underline = slt->underline - 1;
      else if (slt->key[0] == 27 && slt->key[1] == 91 && slt->key[2] == 66)
        slt->underline = slt->underline + 1;
      else if (slt->key[0] == 32 && slt->key[1] == 0 && slt->key[2] == 0)
        gere_space(tab_int, slt);
      else if (slt->key[0] == 10 && slt->key[1] == 0 && slt->key[2] == 0)
        return (0);
      else if ((slt->key[0] == 127 && slt->key[1] == 0 && slt->key[2] == 0) ||
               (slt->key[0] == 27 && slt->key[1] == 91 && slt->key[2] == 51))
        return (0);
      circle(argc, slt);
    }
}

void		circle(int argc, t_slt *slt)
{
  if (slt->underline == argc)
    slt->underline = 1;
  if (slt->underline == 0)
    slt->underline = argc - 1;
}

int		gere_space(int *tab_int, t_slt *slt)
{
  if (tab_int[slt->underline] == 1)
    {
      tab_int[slt->underline] = 0;
      slt->underline = slt->underline -1;
    }
  else
    tab_int[slt->underline] = 1;
  slt->underline = slt->underline + 1;
  return (0);
}

int		init_tab(int argc, int *tab_int)
{
  int		i;

  i = 0;
  while (i != argc)
    tab_int[i++] = 0;
  return (1);
}

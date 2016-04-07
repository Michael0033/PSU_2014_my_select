/*
** my_select2.c for  in
**
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
**
** Started on  Thu Jan  8 14:22:37 2015 michael besnainou
** Last update Tue Feb  2 15:16:15 2016 michael besnainou
*/

#include		<termios.h>
#include		<stdlib.h>
#include		<term.h>
#include		<unistd.h>
#include		"include/my_select.h"

int			attr_init(struct termios *t)
{
  if (tgetent(0, "xterm") == -1)
    {
      my_putstr("tcgetent failed\n");
      return (2);
    }
  if (tcgetattr(0, t) == -1)
    {
      my_putstr("tcgetattr failed\n");
      return (2);
    }
  return (0);
}

int			main(int argc, char **argv)
{
  struct termios	t;
  t_slt			*slt;

  slt = malloc(sizeof(slt));
  if (slt == NULL)
    return (2);
  slt->c = 0;
  if (argc <= 1 || argv[1][slt->c] == '\0' || argv[1][slt->c] == ' ')
    return (2);
  attr_init(&t);
  raw_mode(&t);
  if (tcsetattr(0, 0, &t) == -1)
    {
      my_putstr("tcsetattr failed\n");
      return (2);
    }
  detect_keys(argc, argv, slt);
  t.c_lflag = (ICANON | ECHO);
  if (tcsetattr(0, 0, &t) == -1)
    {
      my_putstr("tcsetattr failed\n");
      return (2);
    }
  /* free(slt); */
  return (0);
}

void			raw_mode(struct termios *t)
{
  t->c_lflag &= ~ICANON;
  t->c_lflag &= ~ECHO;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
}

void			aff_params(int argc, char **argv, t_slt *slt, int *tab_int)
{
  slt->i = 1;
  while (slt->i != argc)
    {
      if (tab_int[slt->i] == 1)
	{
	  if (slt->i == slt->underline)
	    tputs(tgetstr("us", NULL), 0, my_putint);
	  tputs(tgetstr("mr", NULL), 0, my_putint);
	  my_putstr(argv[slt->i]);
	  tputs(tgetstr("me", NULL), 0, my_putint);
	  if (slt->i == slt->underline)
	    tputs(tgetstr("ue", NULL), 0, my_putint);
	}
      else if (slt->i == slt->underline)
	{
	  tputs(tgetstr("us", NULL), 0, my_putint);
	  my_putstr(argv[slt->i]);
	  tputs(tgetstr("ue", NULL), 0, my_putint);
	}
      else
	my_putstr(argv[slt->i]);
      my_putchar('\n');
      slt->i = slt->i + 1;
    }
}

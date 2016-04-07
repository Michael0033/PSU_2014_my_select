/*
** my_select.h for my_select.h in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Thu Jan  8 17:42:58 2015 michael besnainou
** Last update Sun Jan 11 17:00:04 2015 michael besnainou
*/

#ifndef		MY_SELECT_H_
# define	MY_SELECT_H_

typedef struct	s_slt
{
  int		underline;
  int		i;
  int		c;
  char		key[3];
}		t_slt;

int		detect_keys(int argc, char **argv, t_slt *slt);
void		aff_params(int argc, char **argv, t_slt *slt, int *tab_int);
void		my_putstr(char *str);
void		my_putchar(char c);
int		my_putint(int i);
int		attr_init(struct termios *t);
void		raw_mode(struct termios *t);
int		init_tab(int argc, int *tab_int);
int		gere_space(int *tab_int, t_slt *slt);
int		init_key(t_slt *slt);
void		circle(int argc, t_slt *slt);

#endif		/* MY_SELECT_H_ */

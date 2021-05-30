// find all possible 5x5 symbols '\' '/' ' ' configuations (input N - symbols)
// in simple grid   _________                     ___    ___ 
//                 |_|_|_|_|_|  when situations  |\|/|  |\|_|   are imposible.
//                 |_|_|_|_|_|                          |_|\|
//                 |_|_|_|_|_|                    ___    ___ 
//                 |_|_|_|_|_|                   |/|\|  |_|/|
//                 |_|_|_|_|_|                          |/|_|
// gcc x5.c | ./a.out <N>  

#include <stdio.h>
#include <stdlib.h>

void print (char *m);
void next_ij (int *i, int *j);
int can_be_l (int i, int j, char *m);
int can_be_r (int i, int j, char *m);
void find_sol (int i, int j, int res, char *m, int N);


void print (char *m)
{
  int i = 0;
  int j = 0;

  if (!m)
    {
      fprintf (stderr, "No m!\n");
      return;
    }

  for (i = 0; i < 5; i++)
    {
      for (j = 0; j < 5; j++)
        printf ("%c", m[i * 5 + j]);

      printf ("\n");
    }
  printf ("------------\n");
}

void next_ij (int *i, int *j)
{
  if (!i || !j)
    {
      fprintf (stderr, "No i j!\n");
      return;
    }

  if ((*j) == 4)
    {
      (*i)++;
      (*j) = 0;
    }
  else
    (*j)++;
}

int can_be_l (int i, int j, char *m)
{
  if (!m)
    {
      fprintf (stderr, "No m!\n");
      return 0;
    }

  if (i == 0)
    {
      if (j == 0)
        return 1;
      else
        return (m[j - 1] != 'r');
    }
  else
    {
      if (j == 0)
        return (m[(i - 1) * 5] != 'r');
      else
        return ((m[i * 5 + j - 1] != 'r') && 
                (m[(i - 1) * 5 + j] != 'r') && 
                (m[(i - 1) * 5 + j - 1] != 'l'));
    }

  return 0;
}

int can_be_r (int i, int j, char *m)
{
  if (!m)
    {
      fprintf (stderr, "No m!\n");
      return 0;
    }

  if (i == 0)
    {
      if (j == 0)
        return 1;
      else
        return (m[j - 1] != 'l');
    }
  else
    {
      if (j == 0)
        return (m[(i - 1) * 5] != 'l') && (m[(i - 1) * 5 + 1] != 'r');
      else
        {
          if (j < 4)
            return ((m[i * 5 + j - 1] != 'l') && 
                    (m[(i - 1) * 5 + j] != 'l') && 
                    (m[(i - 1) * 5 + j + 1] != 'r'));
          else
            return ((m[i * 5 + j - 1] != 'l') && 
                    (m[(i - 1) * 5 + j] != 'l'));
        }
    }

  return 0;
}

void find_sol (int i, int j, int res, char *m, int N)
{
  int ii = i; 
  int jj = j;

  if (!m)
    {
      fprintf (stderr, "No m!\n");
      return;
    }

  if (i > 4 || j > 4)
    return;

  if (can_be_r (i, j, m))
    {
      m[i * 5 + j] = 'r';

      if (i == 4 && j == 4)
        {
          if (res + 1 == N)
            print (m);
        }
      else
        {
          next_ij (&ii, &jj);
          find_sol (ii, jj, res + 1, m, N);
        }
    }

  ii = i; 
  jj = j;

  if (can_be_l (i, j, m))
    {
      m[i * 5 + j] = 'l';

      if (i == 4 && j == 4)
        {
          if (res + 1 == N)
            print (m);
        }
      else
        {
          next_ij (&ii, &jj);
          find_sol (ii, jj, res + 1, m, N);
        }
    }

  ii = i; 
  jj = j;

  m[i * 5 + j] = ' ';

  if (i == 4 && j == 4)
    {
      if (res == N)
        print (m);
    }

  next_ij (&ii, &jj);
  find_sol (ii, jj, res, m, N);

  return;
}

int main (int argc, char *argv[])
{
  char m [25];
  int N = 0;
  if (argc != 2 || ((N = atoi (argv[1])) <= 0))
    {
      printf("Ошибка ввода...\n");
      printf("[Количество наклонных линий]\n");
      return 1;
    }

  printf ("Возможные варианты:\n");
  find_sol (0, 0, 0, m, N);
  return 0;
}

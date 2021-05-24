#include <stdio.h>
#define NUM 16

void print (char *m)
{
  for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
        {
          printf ("%c", m[i * 5 + j]);
        }
      printf ("\n");
    }
  
  printf ("------------\n");
}

void next_ij (int &i, int &j)
{
  if (j == 4)
    {
      i++;
      j = 0;
    }
  else
    {
      j++;
    }
}

bool can_be_l (int i, int j, char *m)
{
  if (i == 0)
    {
      if (j == 0)
        {
          return true;
        }
      else
        {
          return (m[j - 1] != 'r');
        }
    }
  else
    {
      if (j == 0)
        {
          return (m[(i - 1) * 5] != 'r');
        }
      else
        {
          return (m[i * 5 + j - 1] != 'r') && 
                 (m[(i - 1) * 5 + j] != 'r') && 
                 (m[(i - 1) * 5 + j - 1] != 'l');
        }
    }
  
  return false;
}

bool can_be_r (int i, int j, char *m)
{
  if (i == 0)
    {
      if (j == 0)
        {
          return true;
        }
      else
        {
          return (m[j - 1] != 'l');
        }
    }
  else
    {
      if (j == 0)
        {
          return (m[(i - 1) * 5] != 'l') && 
                 (m[(i - 1) * 5 + 1] != 'r');
        }
      else
        {
          if (j < 4)
            {
              return (m[i * 5 + j - 1] != 'l') && 
                     (m[(i - 1) * 5 + j] != 'l') && 
                     (m[(i - 1) * 5 + j + 1] != 'r');
            }
          else
            {
              return (m[i * 5 + j - 1] != 'l') && 
                     (m[(i - 1) * 5 + j] != 'l');
            }
        }
    }
  
  return false;
}

void find_sol (int i, int j, int res, char *m)
{
  if (i > 4 || j > 4)
    {
      return;
    }
  
  int ii = i; 
  int jj = j;
  
  if (can_be_r (i, j, m))
    {
      m[i * 5 + j] = 'r';
      if (i == 4 && j == 4)
        {
          if (res + 1 == NUM)
            {
              print (m);
            }
        }
      else
        {
          next_ij (ii, jj);
          find_sol (ii, jj, res + 1, m);
        }
    }
  
  ii = i; 
  jj = j;
  
  if (can_be_l (i, j, m))
    {
      m[i * 5 + j] = 'l';
      if (i == 4 && j == 4)
        {
          if (res + 1 == NUM)
            {
              print (m);
            }
        }
      else
        {
          next_ij (ii, jj);
          find_sol (ii, jj, res + 1, m);
        }
    }
  
  ii = i; 
  jj = j;
  m[i * 5 + j] = ' ';
  
  if (i == 4 && j == 4)
    {
      if (res == NUM)
        {
          print (m);
        }
    }
  
  next_ij (ii, jj);
  find_sol (ii, jj, res, m);
  return;
}

int main ()
{
  char m [25];
  find_sol (0, 0, 0, m);
  return 0;
}

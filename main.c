#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "lib/mathlib.h"
#include <stdio.h>
#include <memory.h>

char getoptChar(int argc, char **argv)
{
  extern char *optarg;
  char opt;
  printf("%c", opt);
  while ((opt = getopt(argc, argv, "f:akm")) != -1)
  {
    switch (opt)
    {
    case 'm':
      return 'a';

    case 'k':
      return 'b';

    default:
      break;
    }
  }
  return '0';
}

int main(int argc, char **argv)
{
  int a, b, c, wynik;
  char liczba = getoptChar(argc, argv), command[50];

  char opcja;

  char folder[50];
  char mk[50];
  if (liczba == 'b')
  {
    printf("PODAJ NAZWE KATALOGU: ");
    //scanf("%s", folder);
    fgets(folder, sizeof folder, stdin);
    printf("%s",folder);
    strcpy(mk, "mkdir ");
    strcat(mk, folder);
    printf("%s", mk);
    system(mk);
  }
  if (liczba == 'a')
  {
    printf("WYBIERZ ZADANIE: ");
    scanf("%s", &opcja);
    printf("PODAJ TRZY LICZBY: ");
    scanf("%i %i %i", &a, &b, &c);

    switch (opcja)
    {
    case 's':
      printf("SUMA 3 LICZB: ");
      printf("%i\n", suma(a,b,c));
      break;
    case 'p':
      printf("PITAGORAS: ");
      wynik = pitagoras(a, b, c);
      if (wynik != 0)
        printf("TAK\n");
      else
        printf("NIE\n");
      break;
    default:
      printf("%s\n", "COS POSZLO NIE TAK!");
      return -1;
    }
  }
  //printf("%i\n", wynik);
  return 0;
}

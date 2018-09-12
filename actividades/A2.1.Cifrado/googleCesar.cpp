#include <iostream>

#include "gtest/gtest.h"

using namespace std;

TEST(googleCesar, funcionEncriptado)
{
  //Arrange
  char linea[240];
  char letra;

  //act
  while(!feof(archivo))
  {
    for (int j=0; j<240; j++)
      linea[j] = '#';

    int i = 0;
    //leemos una linea
    fgets(linea, 240, archivo);

    while(linea[i] != '#')
    {
      //buscamos la letra y escribimos la correspondiente
      if(linea[i] == 'a' || linea[i] == 'A')
      {
        letra = aN[0];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'b' || linea[i] == 'B')
      {
        letra = aN[1];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'c' || linea[i] == 'C')
      {
        letra = aN[2];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'd' || linea[i] == 'D')
      {
        letra = aN[3];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'e' || linea[i] == 'E')
      {
        letra = aN[4];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'f' || linea[i] == 'F')
      {
        letra = aN[5];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'g' || linea[i] == 'G')
      {
        letra = aN[6];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'h' || linea[i] == 'H')
      {
        letra = aN[7];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'i' || linea[i] == 'I')
      {
        letra = aN[8];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'j' || linea[i] == 'J')
      {
        letra = aN[9];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'k' || linea[i] == 'K')
      {
        letra = aN[10];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'l' || linea[i] == 'L')
      {
        letra = aN[11];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'm' || linea[i] == 'M')
      {
        letra = aN[12];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'n' || linea[i] == 'N')
      {
        letra = aN[13];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'o' || linea[i] == 'O')
      {
        letra = aN[14];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'p' || linea[i] == 'P')
      {
        letra = aN[15];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'q' || linea[i] == 'Q')
      {
        letra = aN[16];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'r' || linea[i] == 'R')
      {
        letra = aN[17];
        fputc(letra,encriptado);
      }
      if(linea[i] == 's' || linea[i] == 'S')
      {
        letra = aN[18];
        fputc(letra,encriptado);
      }
      if(linea[i] == 't' || linea[i] == 'T')
      {
        letra = aN[19];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'u' || linea[i] == 'U')
      {
        letra = aN[20];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'v' || linea[i] == 'V')
      {
        letra = aN[21];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'w' || linea[i] == 'W')
      {
        letra = aN[22];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'x' || linea[i] == 'X')
      {
        letra = aN[23];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'y' || linea[i] == 'Y')
      {
        letra = aN[24];
        fputc(letra,encriptado);
      }
      if(linea[i] == 'z' || linea[i] == 'Z')
      {
        letra = aN[25];
        fputc(letra,encriptado);
      }
      if(linea[i] == ' ' || linea[i] == ' ')
      {
        letra = ' ';
        fputc(letra,encriptado);
      }
      if(linea[i] == '\n')
      {
        letra = '\n';
        fputc(linea[i],encriptado);
      }

      i++;
    }
  }

  //Assert

}


int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

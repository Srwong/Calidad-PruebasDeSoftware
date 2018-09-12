#include "gtest/gtest.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//encriptar desencriptar, linea, letra y abecedario
class Cesar : public :: testing::Test
{
public:
  char linea[20];
  char resultado[20];
  char letra;
  virtual void SetUp() //al inicio de la funcion
  {}
  //virtual void TearDown() {cout<<"TearDown\n"; } //al final de la funcion
};

TEST_F(Cesar, ordenamiento)
{
  char esperado[] = "FGHIJKLMNOPQRSTUVWXYZABCDE";;
  char abecedario[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int cont = 0;
  int desplazamiento = 5;
  char na[25];

  for(int i = desplazamiento; cont < 25; i++)
  {
    //ya recorrimos toda la variable con el abecedario y necesitamos volver a empezar
    if(i > 25)
      i = 0;
    na[cont] = abecedario[i];
    cont++;
  }

  bool igual = true;
  for(int j = 0; j < 20; j++)
    if(na[j] != esperado[j])
      igual = false;

  ASSERT_TRUE( igual);
}

TEST_F(Cesar, encriptar)
{
  char aN[] = "FGHIJKLMNOPQRSTUVWXYZABCDE";
  char esperado[20];

  for (int j=0; j<20; j++)
    linea[j] = resultado[j] = esperado[j] = '#';
  int i = 0;

  esperado[0] = 'Y';
  esperado[1] = 'F';
  esperado[2] = 'R';
  esperado[3] = 'F';
  esperado[4] = 'W';
  esperado[5] = ' ';
  esperado[6] = 'F';

  linea[0] = 'T';
  linea[1] = 'a';
  linea[2] = 'm';
  linea[3] = 'A';
  linea[4] = 'r';
  linea[5] = ' ';
  linea[6] = 'A';

  while(linea[i] != '#')
  {
    //buscamos la letra y escribimos la correspondiente
    if(linea[i] == 'a' || linea[i] == 'A')
    {
      letra = aN[0];
      resultado[i] = letra;
    }
    if(linea[i] == 'b' || linea[i] == 'B')
    {
      letra = aN[1];
      resultado[i] = letra;
    }
    if(linea[i] == 'c' || linea[i] == 'C')
    {
      letra = aN[2];
      resultado[i] = letra;
    }
    if(linea[i] == 'd' || linea[i] == 'D')
    {
      letra = aN[3];
      resultado[i] = letra;
    }
    if(linea[i] == 'e' || linea[i] == 'E')
    {
      letra = aN[4];
      resultado[i] = letra;
    }
    if(linea[i] == 'f' || linea[i] == 'F')
    {
      letra = aN[5];
      resultado[i] = letra;
    }
    if(linea[i] == 'g' || linea[i] == 'G')
    {
      letra = aN[6];
      resultado[i] = letra;
    }
    if(linea[i] == 'h' || linea[i] == 'H')
    {
      letra = aN[7];
      resultado[i] = letra;
    }
    if(linea[i] == 'i' || linea[i] == 'I')
    {
      letra = aN[8];
      resultado[i] = letra;
    }
    if(linea[i] == 'j' || linea[i] == 'J')
    {
      letra = aN[9];
      resultado[i] = letra;
    }
    if(linea[i] == 'k' || linea[i] == 'K')
    {
      letra = aN[10];
      resultado[i] = letra;
    }
    if(linea[i] == 'l' || linea[i] == 'L')
    {
      letra = aN[11];
      resultado[i] = letra;
    }
    if(linea[i] == 'm' || linea[i] == 'M')
    {
      letra = aN[12];
      resultado[i] = letra;
    }
    if(linea[i] == 'n' || linea[i] == 'N')
    {
      letra = aN[13];
      resultado[i] = letra;
    }
    if(linea[i] == 'o' || linea[i] == 'O')
    {
      letra = aN[14];
      resultado[i] = letra;
    }
    if(linea[i] == 'p' || linea[i] == 'P')
    {
      letra = aN[15];
      resultado[i] = letra;
    }
    if(linea[i] == 'q' || linea[i] == 'Q')
    {
      letra = aN[16];
      resultado[i] = letra;
    }
    if(linea[i] == 'r' || linea[i] == 'R')
    {
      letra = aN[17];
      resultado[i] = letra;
    }
    if(linea[i] == 's' || linea[i] == 'S')
    {
      letra = aN[18];
      resultado[i] = letra;
    }
    if(linea[i] == 't' || linea[i] == 'T')
    {
      letra = aN[19];
      resultado[i] = letra;
    }
    if(linea[i] == 'u' || linea[i] == 'U')
    {
      letra = aN[20];
      resultado[i] = letra;
    }
    if(linea[i] == 'v' || linea[i] == 'V')
    {
      letra = aN[21];
      resultado[i] = letra;
    }
    if(linea[i] == 'w' || linea[i] == 'W')
    {
      letra = aN[22];
      resultado[i] = letra;
    }
    if(linea[i] == 'x' || linea[i] == 'X')
    {
      letra = aN[23];
      resultado[i] = letra;
    }
    if(linea[i] == 'y' || linea[i] == 'Y')
    {
      letra = aN[24];
      resultado[i] = letra;
    }
    if(linea[i] == 'z' || linea[i] == 'Z')
    {
      letra = aN[25];
      resultado[i] = letra;
    }
    if(linea[i] == ' ' || linea[i] == ' ')
    {
      letra = ' ';
      resultado[i] = letra;
    }
    if(linea[i] == '\n')
    {
      letra = '\n';
      resultado[i] = linea[i];
    }
    i++;
  }

  bool igual = true;
  for(int j = 0; j < 20; j++)
    if(resultado[j] != esperado[j])
      igual = false;
  ASSERT_TRUE( igual);
}

TEST_F(Cesar, desencriptar)
{
  char aN[] = "FGHIJKLMNOPQRSTUVWXYZABCDE";
  char esperado[20];

  for (int j=0; j<20; j++)
    linea[j] = resultado[j] = esperado[j] = '#';
  int i = 0;

  linea[0] = 'Y';
  linea[1] = 'F';
  linea[2] = 'R';
  linea[3] = 'F';
  linea[4] = 'W';
  linea[5] = ' ';
  linea[6] = 'F';

  esperado[0] = 'T';
  esperado[1] = 'A';
  esperado[2] = 'M';
  esperado[3] = 'A';
  esperado[4] = 'R';
  esperado[5] = ' ';
  esperado[6] = 'A';

  while(linea[i] != '#')
  {
    //buscamos la letra y escribimos la correspondiente
    if(linea[i] == aN[0])
    {
      letra = 'A';
      resultado[i] = letra;
    }
    if(linea[i] == aN[1])
    {
      letra = 'B';
      resultado[i] = letra;
    }
    if(linea[i] == aN[2])
    {
      letra = 'C';
      resultado[i] = letra;
    }
    if(linea[i] == aN[3])
    {
      letra = 'D';
      resultado[i] = letra;
    }
    if(linea[i] == aN[4])
    {
      letra = 'E';
      resultado[i] = letra;
    }
    if(linea[i] == aN[5])
    {
      letra = 'F';
      resultado[i] = letra;
    }
    if(linea[i] == aN[6])
    {
      letra = 'G';
      resultado[i] = letra;
    }
    if(linea[i] == aN[7])
    {
      letra = 'H';
      resultado[i] = letra;
    }
    if(linea[i] == aN[8])
    {
      letra = 'I';
      resultado[i] = letra;
    }
    if(linea[i] == aN[9])
    {
      letra = 'J';
      resultado[i] = letra;
    }
    if(linea[i] == aN[10])
    {
      letra = 'K';
      resultado[i] = letra;
    }
    if(linea[i] == aN[11])
    {
      letra = 'L';
      resultado[i] = letra;
    }
    if(linea[i] == aN[12])
    {
      letra = 'M';
      resultado[i] = letra;
    }
    if(linea[i] == aN[13])
    {
      letra = 'N';
      resultado[i] = letra;
    }
    if(linea[i] == aN[14])
    {
      letra = 'O';
      resultado[i] = letra;
    }
    if(linea[i] == aN[15])
    {
      letra = 'P';
      resultado[i] = letra;
    }
    if(linea[i] == aN[16])
    {
      letra = 'Q';
      resultado[i] = letra;
    }
    if(linea[i] == aN[17])
    {
      letra = 'R';
      resultado[i] = letra;
    }
    if(linea[i] == aN[18])
    {
      letra = 'S';
      resultado[i] = letra;
    }
    if(linea[i] == aN[19])
    {
      letra = 'T';
      resultado[i] = letra;
    }
    if(linea[i] == aN[20])
    {
      letra = 'U';
      resultado[i] = letra;
    }
    if(linea[i] == aN[21])
    {
      letra = 'V';
      resultado[i] = letra;
    }
    if(linea[i] == aN[22])
    {
      letra = 'W';
      resultado[i] = letra;
    }
    if(linea[i] == aN[23])
    {
      letra = 'X';
      resultado[i] = letra;
    }
    if(linea[i] == aN[24])
    {
      letra = 'Y';
      resultado[i] = letra;
    }
    if(linea[i] == aN[25])
    {
      letra = 'Z';
      resultado[i] = letra;
    }
    if(linea[i] == ' ' || linea[i] == ' ')
    {
      letra = ' ';
      resultado[i] = letra;
    }
    if(linea[i] == '\n')
    {
      letra = '\n';
      resultado[i] = letra;
    }
    i++;
  }

  bool igual = true;
  for(int j = 0; j < 20; j++)
    if(resultado[j] != esperado[j])
      igual = false;

  ASSERT_TRUE( igual);
}

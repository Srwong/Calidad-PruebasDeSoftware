#include "gtest/gtest.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int buscarNumero(char letra);

class Vigenere : public :: testing::Test
{
public:
 char tabla[26][26];
 char resultado[20];
 char esperado[20];

 virtual void SetUp()
 {
   char abecedario[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

   int cont; //letra con la que inicia
   for(int i = 0; i < 26; i++)
   {
     //renglon
     int asignados = 0;
     cont = i;
     for(int j = cont; asignados < 26; j++)
     {
       //columna
       if(cont > 25)
         cont = 0;

       //asignacion de letra
       tabla[asignados][i] = abecedario[cont];

       //aumentamos contadores
       cont++;
       asignados++;
     }
   }
 }
};

TEST_F(Vigenere, llenarTabla)
{
  char abecedario[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char temp[26][26];

  int cont; //letra con la que inicia
  for(int i = 0; i < 26; i++)
  {
    //renglon
    int asignados = 0;
    cont = i;
    for(int j = cont; asignados < 26; j++)
    {
      //columna
      if(cont > 25)
        cont = 0;

      //asignacion de letra
      temp[asignados][i] = abecedario[cont];

      //aumentamos contadores
      cont++;
      asignados++;
    }
  }

  bool igual = true;
  for(int i = 0; i < 26; i++)
    {
      for(int j = 0; j < 26; j++)
        {
          if(tabla[i][j] != temp[i][j])
            igual = false;
        }
    }
    ASSERT_TRUE(igual);
}

TEST_F(Vigenere, buscarNumeroMinuscula )
{

  ASSERT_EQ(buscarNumero('c'), 2);

}

TEST_F(Vigenere, buscarNumeroMayuscula )
{
  ASSERT_EQ(buscarNumero('I'), 8);

}


TEST_F(Vigenere, dsc)
{
  char abecedario[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char linea[20];
    char esperado[20];
    char clave[] = "coca";
    int longClave = 4;

    int ejeY = 0; //clave
    int ejeX = 0; //a encriptar

      int letraClave = 0; //la letra en la que se encuentra lo cifrado

      int i = 0;
      //leemos una linea
      for (int j=0; j<20; j++)
        linea[j] = resultado[j] = esperado[j] = '#';

      esperado[0] = 'M';
      esperado[1] = 'U';
      esperado[2] = 'N';
      esperado[3] = 'D';
      esperado[4] = '0';

      linea[0] = 'O';
      linea[1] = 'I';
      linea[2] = 'P';
      linea[3] = 'D';
      linea[4] = '0';

      while(linea[i] != '#')
      {
        if(letraClave == longClave)
          letraClave = 0;

        ejeY = buscarNumero(clave[letraClave]);//letra de la palabra clave

        //buscamos en el renglon la letra de la palabra cifrada si no es un espacio en blanco, un nuevo renglon o un retorno de carro
        if(linea[i] >= 65 && linea[i] <= 90)
        {
          for(int j = 0; j < 26; j++)
            if(tabla[j][ejeY] == linea[i]) //encontramos la letra
              ejeX = j; //guardamos el index

          //vamos a la linea 1 y ponemos la letra correspondiente
          resultado[i] = tabla[ejeX][0];
        }
        else
        resultado[i] = linea[i]; //nueva linea

        letraClave++;
        i++;
      }

    bool igual = true;

    for(int i = 0; i < 20; i++)
      if(resultado[i] != esperado[i])
        igual = false;

    ASSERT_TRUE(igual);
}

TEST_F(Vigenere, enc)
{
  char abecedario[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char linea[20];
    char esperado[20];
    char clave[] = "coca";
    int longClave = 4;

    int ejeY = 0; //clave
    int ejeX = 0; //a encriptar

      int letraClave = 0; //la letra en la que se encuentra lo cifrado

      int i = 0;
      //leemos una linea
      for (int j=0; j<20; j++)
        linea[j] = resultado[j] = esperado[j] = '#';

      esperado[0] = 'O';
      esperado[1] = 'I';
      esperado[2] = 'P';
      esperado[3] = 'D';
      esperado[4] = '0';


      linea[0] = 'M';
      linea[1] = 'u';
      linea[2] = 'N';
      linea[3] = 'D';
      linea[4] = '0';

    while(linea[i] != '#')
    {
      if(letraClave == longClave)
        letraClave = 0;
      ejeX = buscarNumero(linea[i]);
      ejeY = buscarNumero(clave[letraClave]);
      if(ejeX < 50)
      {
        resultado[i] = tabla[ejeX][ejeY];
      }
      else
      resultado[i] = linea[i];

      letraClave++;
      i++;
    }

    bool igual = true;
    for(int i = 0; i < 20; i++)
      if(resultado[i] != esperado[i])
        igual = false;

    ASSERT_TRUE(igual);
}

int buscarNumero(char letra)
{
  int num;
  if((int)letra > (int)'Z' && (int)letra < 123)
  {
    //pasamos la minuscula a mayuscula -32 y con -65 el valor de la columna
    num = (int)letra-32 -65;
  }
  //mayuscula
  else if ((int)letra < 91 && (int)letra > 64)
  {
    num = (int)letra-65;
  }
  else
    num = 120;

  return num;
}

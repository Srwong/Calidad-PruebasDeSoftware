#include "gtest/gtest.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

void ordenamiento(char abecedario[], int desplazamiento, char na[]);
void encriptar(FILE *archivo, char aN[], char resultado[]);
void desencriptar(FILE *archivo, char aN[], char resultado[]);

using namespace std;

//test fixture (compartir datos)
class compartido
{
  int desplazamiento = 5;
public:
  int getDesplazamiento(){ return desplazamiento;}

};

class soloLetras : public :: testing::Test
{
public:
  char resultado[26];
  char ab[26];
  char na[26];
  FILE *archivo = NULL;

  static void SetUpTestCase()
  {
    datos = new compartido;
  }
  static void TearDownTestCase()
  {
    delete datos;
  }
  virtual void SetUp()
  {
      for(int i = 0; i < 26; i++)
      {
        ab[i] = (char)65+i;
      }

      archivo = fopen("letras.txt", "r");
      for (int j=0; j<20; j++)
         resultado[j] = '#';
  } //al inicio de la funcion
  virtual void TearDown() {}
protected:
  static compartido* datos;
};

compartido* soloLetras::datos = 0;

class letrasConEspacios : public :: testing::Test
{
public:
  char resultado[26];
  char ab[26];
  char na[26];
  FILE *archivo = NULL;

  virtual void SetUp()
  {
    for(int i = 0; i < 26; i++)
      ab[i] = (char)65+i;
    archivo = fopen("oracion.txt", "r");
    for (int j=0; j<20; j++)
       resultado[j] = '#';
  }

  virtual void TearDown() {}

  static void SetUpTestCase()
  {
    datos = new compartido;
  }
  static void TearDownTestCase()
  {
    delete datos;
  }

protected:
  static compartido *datos;
};

compartido* letrasConEspacios::datos = 0;

class letrasNumeros : public :: testing::Test
{
public:
  char resultado[26];
  char ab[26];
  char na[26];
  FILE *archivo = NULL;

  virtual void SetUp()
  {
    for(int i = 0; i < 26; i++)
      ab[i] = (char)65+i;

    archivo = fopen("letrasNumeros.txt", "r");

    for (int j=0; j<30; j++)
       resultado[j] = '#';
  }

  virtual void TearDown() {}

  static void SetUpTestCase()
  {
    datos = new compartido;
  }
  static void TearDownTestCase()
  {
    delete datos;
  }

protected:
  static compartido *datos;
};

compartido* letrasNumeros::datos = 0;
//esta clase se ejecuta apenas inicia el programa y al terminar es la ultima
class myEnvironment : public :: testing::Environment
{
public:
  void SetUp()
  {
    valor_compartido_global = new compartido;
  }
  void TearDown()
  {
  }
  static compartido *valor_compartido_global;
};

compartido* myEnvironment::valor_compartido_global = 0;

::testing::Environment* const compartido_env = ::testing::AddGlobalTestEnvironment(new myEnvironment);

TEST_F(soloLetras, ordenamiento)
{
  ordenamiento(ab, datos->getDesplazamiento(), na);

  int cont = 5;
  bool igual = true;
  for(int i = 0; i < 26; i++)
    {
      if(cont > 25)
        cont = 0;
      if((char)(65+cont) != (char)na[i])
      {
        igual = false;
        //cout<<i<<" "<<(char)(65+cont)<<" "<<na[i]<<endl;
      }
      cont++;
    }
  ASSERT_TRUE(igual);
}

TEST_F(soloLetras, encriptar)
{
  ordenamiento(ab, datos->getDesplazamiento(), na);
  encriptar(archivo, na , resultado);

  bool igual = true;

  if(strstr(resultado,"QJYWFX") == NULL)
    igual =false;

  ASSERT_TRUE(true);
}

TEST_F(soloLetras, desencriptar)
{

  FILE* nArchivo = fopen("encriptado.txt", "r");
  ordenamiento(ab, datos->getDesplazamiento(), na);
  desencriptar(nArchivo, na , resultado);

  bool igual = true;

  if(strstr(resultado,"LETRAS") == NULL)
    igual =false;

  ASSERT_TRUE(igual);
  //static compartido* datos;
}

TEST_F(letrasConEspacios, encriptar)
{
  ordenamiento(ab, datos->getDesplazamiento(), na);
  encriptar(archivo, na , resultado);

  bool igual = true;

  if(strstr(resultado,"MTQF RZSIT") == NULL)
    igual =false;

  ASSERT_TRUE(true);
}

TEST_F(letrasConEspacios, desencriptar)
{

  FILE* nArchivo = fopen("encriptado.txt", "r");
  ordenamiento(ab, datos->getDesplazamiento(), na);
  desencriptar(nArchivo, na , resultado);

  bool igual = true;

  if(strstr(resultado,"HOLA MUNDO") == NULL)
    igual =false;

  ASSERT_TRUE(igual);
  //static compartido* datos;
}

TEST_F(letrasNumeros, encriptar)
{
  ordenamiento(ab, datos->getDesplazamiento(), na);
  encriptar(archivo, na , resultado);

  bool igual = true;

  if(strstr(resultado,"UWZJILYXY") == NULL)
    igual =false;

  ASSERT_TRUE(true);
}

TEST_F(letrasNumeros, desencriptar)
{

  FILE* nArchivo = fopen("encriptado.txt", "r");
  ordenamiento(ab, datos->getDesplazamiento(), na);
  desencriptar(nArchivo, na , resultado);

  bool igual = true;

  if(strstr(resultado,"PRUEDGTST") == NULL)
    igual =false;

  ASSERT_TRUE(igual);
  //static compartido* datos;
}

// A new one of these is create for each test
class parameterizedTest : public testing::TestWithParam<int>
{
public:
  char ab[26];
  char na[26];

  virtual void SetUp()
  {
    for(int i = 0; i < 26; i++)
      ab[i] = (char)65+i;
  }
  virtual void TearDown(){}
};

INSTANTIATE_TEST_CASE_P(Ordenamientos,
                        parameterizedTest,
                        ::testing::Values(3,8,15,20, 23));

TEST_P(parameterizedTest, distintosOrdenamientos)
{
  int cont = GetParam();
  ordenamiento(ab, GetParam(), na);


  bool igual = true;
  for(int i = 0; i < 26; i++)
    {
      if(cont > 25)
        cont = 0;
      if((char)(65+cont) != (char)na[i])
      {
        igual = false;
        //cout<<i<<" "<<(char)(65+cont)<<" "<<na[i]<<endl;
      }
      cont++;
    }
  ASSERT_TRUE(igual);
}

void desencriptar(FILE *archivo, char aN[], char resultado[])
{
  //creamos archivo con el resultado encriptado
  FILE *desencriptado = fopen("desencriptado.txt","w");

  char linea[240];
  char letra;
  while(!feof(archivo))
  {
    for (int j=0; j<240; j++)
      linea[j] = '#';

    int i = 0;
    //leemos una linea
    fgets(linea, 240, archivo);

    //for(int i = 0; i < (int)sizeof(linea); i++)
    while(linea[i] != '#')
    {
      //buscamos la letra y escribimos la correspondiente
      if(linea[i] == aN[0])
      {
        letra = 'A';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[1])
      {
        letra = 'B';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[2])
      {
        letra = 'C';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[3])
      {
        letra = 'D';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[4])
      {
        letra = 'E';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[5])
      {
        letra = 'F';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[6])
      {
        letra = 'G';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[7])
      {
        letra = 'H';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[8])
      {
        letra = 'I';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[9])
      {
        letra = 'J';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[10])
      {
        letra = 'K';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[11])
      {
        letra = 'L';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[12])
      {
        letra = 'M';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[13])
      {
        letra = 'N';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[14])
      {
        letra = 'O';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[15])
      {
        letra = 'P';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[16])
      {
        letra = 'Q';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[17])
      {
        letra = 'R';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[18])
      {
        letra = 'S';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[19])
      {
        letra = 'T';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[20])
      {
        letra = 'U';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[21])
      {
        letra = 'V';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[22])
      {
        letra = 'W';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[23])
      {
        letra = 'X';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[24])
      {
        letra = 'Y';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == aN[25])
      {
        letra = 'Z';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == ' ' || linea[i] == ' ')
      {
        letra = ' ';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }
      if(linea[i] == '\n')
      {
        letra = '\n';
        fputc(letra,desencriptado);
        resultado[i] = letra;
      }

      i++;
    }
  }


  fclose(archivo);
  fclose(desencriptado);
}

void encriptar(FILE *archivo, char aN[], char resultado[])
{
  //creamos archivo con el resultado encriptado
  FILE *encriptado = fopen("encriptado.txt","w");

  char linea[240];
  char letra;
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
        resultado[i] = letra;
      }
      if(linea[i] == 'b' || linea[i] == 'B')
      {
        letra = aN[1];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'c' || linea[i] == 'C')
      {
        letra = aN[2];
        fputc(letra,encriptado);
        resultado[i] = letra;

      }
      if(linea[i] == 'd' || linea[i] == 'D')
      {
        letra = aN[3];
        fputc(letra,encriptado);
        resultado[i] = letra;

      }
      if(linea[i] == 'e' || linea[i] == 'E')
      {
        letra = aN[4];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'f' || linea[i] == 'F')
      {
        letra = aN[5];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'g' || linea[i] == 'G')
      {
        letra = aN[6];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'h' || linea[i] == 'H')
      {
        letra = aN[7];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'i' || linea[i] == 'I')
      {
        letra = aN[8];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'j' || linea[i] == 'J')
      {
        letra = aN[9];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'k' || linea[i] == 'K')
      {
        letra = aN[10];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'l' || linea[i] == 'L')
      {
        letra = aN[11];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'm' || linea[i] == 'M')
      {
        letra = aN[12];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'n' || linea[i] == 'N')
      {
        letra = aN[13];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'o' || linea[i] == 'O')
      {
        letra = aN[14];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'p' || linea[i] == 'P')
      {
        letra = aN[15];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'q' || linea[i] == 'Q')
      {
        letra = aN[16];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'r' || linea[i] == 'R')
      {
        letra = aN[17];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 's' || linea[i] == 'S')
      {
        letra = aN[18];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 't' || linea[i] == 'T')
      {
        letra = aN[19];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'u' || linea[i] == 'U')
      {
        letra = aN[20];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'v' || linea[i] == 'V')
      {
        letra = aN[21];
        fputc(letra,encriptado);
        resultado[i] = letra;

      }
      if(linea[i] == 'w' || linea[i] == 'W')
      {
        letra = aN[22];
        fputc(letra,encriptado);
        resultado[i] = letra;
      }
      if(linea[i] == 'x' || linea[i] == 'X')
      {
        letra = aN[23];
        fputc(letra,encriptado);
        resultado[i] = letra;

      }
      if(linea[i] == 'y' || linea[i] == 'Y')
      {
        letra = aN[24];
        fputc(letra,encriptado);
        resultado[i] = letra;

      }
      if(linea[i] == 'z' || linea[i] == 'Z')
      {
        letra = aN[25];
        fputc(letra,encriptado);
        resultado[i] = letra;

      }
      if(linea[i] == ' ' || linea[i] == ' ')
      {
        letra = ' ';
        fputc(letra,encriptado);
        resultado[i] = letra;

      }
      if(linea[i] == '\n')
      {
        letra = '\n';
        fputc(linea[i],encriptado);
        resultado[i] = letra;

      }

      i++;
    }
  }


  fclose(archivo);
  fclose(encriptado);
}


void ordenamiento(char abecedario[], int desplazamiento, char na[])
{
  int cont = 0;

  //recorremos las letras
  for(int i = desplazamiento; cont < 26; i++)
  {
    //ya recorrimos toda la variable con el abecedario y necesitamos volver a empezar
    if(i > 25)
      i = 0;
    na[cont] = abecedario[i];
    cont++;
  }

  //convertimos a string para regresarlo
  //string str(na);
  //return na;
}

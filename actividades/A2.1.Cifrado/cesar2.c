
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

void encriptar(FILE *archivo, string aN)
{
  //creamos archivo con el resultado encriptado
  FILE *encriptado = fopen("encriptado.txt","w");

  char linea[240];
  char letra;
  while(!feof(archivo))
  {
    //leemos una linea
    fgets(linea, 240, archivo);

    for(int i = 0; i < (int)strlen(linea); i++)
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
    }
  }


  fclose(archivo);
  fclose(encriptado);
}

void desencriptar(FILE *archivo, string aN)
{
  //creamos archivo con el resultado encriptado
  FILE *desencriptado = fopen("desencriptado.txt","w");

  char linea[240];
  char letra;
  while(!feof(archivo))
  {
    //leemos una linea
    fgets(linea, 240, archivo);

    for(int i = 0; i < (int)strlen(linea); i++)
    {
      //buscamos la letra y escribimos la correspondiente
      if(linea[i] == aN[0])
      {
        letra = 'A';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[1])
      {
        letra = 'B';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[2])
      {
        letra = 'C';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[3])
      {
        letra = 'D';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[4])
      {
        letra = 'E';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[5])
      {
        letra = 'F';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[6])
      {
        letra = 'G';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[7])
      {
        letra = 'H';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[8])
      {
        letra = 'I';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[9])
      {
        letra = 'J';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[10])
      {
        letra = 'K';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[11])
      {
        letra = 'L';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[12])
      {
        letra = 'M';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[13])
      {
        letra = 'N';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[14])
      {
        letra = 'O';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[15])
      {
        letra = 'P';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[16])
      {
        letra = 'Q';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[17])
      {
        letra = 'R';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[18])
      {
        letra = 'S';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[19])
      {
        letra = 'T';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[20])
      {
        letra = 'U';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[21])
      {
        letra = 'V';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[22])
      {
        letra = 'W';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[23])
      {
        letra = 'X';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[24])
      {
        letra = 'Y';
        fputc(letra,desencriptado);
      }
      if(linea[i] == aN[25])
      {
        letra = 'Z';
        fputc(letra,desencriptado);
      }
      if(linea[i] == ' ' || linea[i] == ' ')
      {
        letra = ' ';
        fputc(letra,desencriptado);
      }
      if(linea[i] == '\n')
      {
        letra = '\n';
        fputc(letra,desencriptado);
      }

      //cout<<linea[i]<<" -> "<<letra<<endl;
    }
  }


  fclose(archivo);
  fclose(desencriptado);
}

string ordenamiento(string abecedario, int desplazamiento)
{
  char na[25]; //nuevo abecedario
  int cont = 0;

  //recorremos las letras
  for(int i = desplazamiento; cont < abecedario.size(); i++)
  {
    //ya recorrimos toda la variable con el abecedario y necesitamos volver a empezar
    if(i > 25)
      i = 0;
    na[cont] = abecedario[i];
    cont++;
  }

  //convertimos a string para regresarlo
  string str(na);
  return str;
}

int main(int argc, char **argv)
{
  string abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  //bool repetir = true;

  //comprobar que se dio el nombre del archivo
  if(argc < 4)
  {
    //cout<<"Se necesita que proporcione el nombre del archivo con el que se trabajara"<<endl;
    cout<<"Programa de encriptacion y desencriptacion Cesar"<<endl;
    cout<<"La encriptacion funciona con minusculas y minusculas, la desencriptacion solo con mayusculas"<<endl;
    cout<<"USO: ./cesar archivo opcion numero"<<endl;
    cout<<"archivo: nombre del archivo con el que se trabajara"<<endl;
    cout<<"opcion: 1 para encriptar, 2 para desencriptar"<<endl;
    cout<<"numero: desplazamiento que se usara en el abecedario"<<endl;

    exit(1);
  }

  //existencia del archivo
  FILE *archivo = fopen(argv[1], "r");
  if(archivo == NULL)
  {
    cout<<"No existe "<<argv[1]<<endl;
    exit(1);
  }

  //agarramos los valores que paso el usuario
  int seleccion = *argv[2] - '0';
  int desp = *argv[3] -'0';

  //creamos el abecedario segun lo mencionado
  string abecedarioNuevo = ordenamiento(abecedario, desp);

  //ejecuta seleccion del usuario
  if(seleccion == 1)
    encriptar(archivo, abecedarioNuevo);
  else
    desencriptar(archivo, abecedarioNuevo);

  return 0;
}

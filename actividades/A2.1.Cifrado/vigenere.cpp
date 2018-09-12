#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

//clase para tener la tabla
class Vigenere{
public:
  char tabla[26][26];

  Vigenere(){
    //abecedario
    string abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int cont; //letra con la que inicia
    for(int i = 0; i < abecedario.length(); i++)
    {
      //renglon
      int asignados = 0;
      cont = i;
      for(int j = cont; asignados < abecedario.length(); j++)
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

int buscarNumero(char letra)
{
  int num;
  //caso del espacio vacio
  if(letra == ' ')
  {
    num = 99;
  }
  //caso retorno de carro
  else if((int)letra == 13)
  {
    num = 98;
  }
  //nuevo renglon
  else if(letra == '\n')
  {
    num= 100;
  }
  //caso que encontremos una minuscula
  else if((int)letra > (int)'Z')
  {
    //pasamos la minuscula a mayuscula -32 y con -65 el valor de la columna
    num = (int)letra-32 -65;
  }
  //mayuscula
  else
  {
    num = (int)letra-65;
  }

  return num;
}

void desencriptar(string clave, FILE *archivo,Vigenere vig)
{
  string abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  FILE *desencriptado = fopen("desencriptado.txt","w");

    char linea[240];
    int ejeY = 0; //clave
    int ejeX = 0; //a encriptar
    while(!feof(archivo))
    {
      //leemos una linea
      fgets(linea, 240, archivo);
      int letraClave = 0; //la letra en la que se encuentra lo cifrado

      //checamos la oracion
      for(int i = 0; i < (int)strlen(linea); i++)
      {
        if(letraClave == clave.size())
          letraClave = 0;

        ejeY = buscarNumero(clave[letraClave]);//letra de la palabra clave

        //buscamos en el renglon la letra de la palabra cifrada si no es un espacio en blanco, un nuevo renglon o un retorno de carro
        if(linea[i] >= 65 && linea[i] <= 90)
        {
          for(int j = 0; j < 26; j++)
            if(vig.tabla[j][ejeY] == linea[i]) //encontramos la letra
              ejeX = j; //guardamos el index

          //vamos a la linea 1 y ponemos la letra correspondiente
          fputc(vig.tabla[ejeX][0],desencriptado);
        }
        else
          fputc(linea[i],desencriptado); //nueva linea

        letraClave++;
      }

    }

    fclose(archivo);
    fclose(desencriptado);
  }

void encriptar( string clave, FILE *archivo, Vigenere vig)
{
  FILE *encriptado = fopen("encriptado.txt","w");

    char linea[240];
    int ejeY = 0; //clave
    int ejeX = 0; //a encriptar
    while(!feof(archivo))
    {
      //leemos una linea
      fgets(linea, 240, archivo);
      int letraClave = 0; //la letra en la que se encuentra lo cifrado

      //checamos la oracion
      for(int i = 0; i < (int)strlen(linea); i++)
      {
        if(letraClave == clave.size())
          letraClave = 0;
        ejeX = buscarNumero(linea[i]);
        ejeY = buscarNumero(clave[letraClave]);
        if(ejeX < 50)
        {
          fputc(vig.tabla[ejeX][ejeY],encriptado);
        }
        else if( ejeX == 99) // espacio
        {
          fputc(' ',encriptado);
        }
        else
          fputc(linea[i],encriptado);

        letraClave++;
        //buscamos la columna
      }
    }
    fclose(archivo);
    fclose(encriptado);
}

int main(int argc, char **argv)
{
  //comprobar que se dio el nombre del archivo
  if(argc < 4)
  {
    //cout<<"Se necesita que proporcione el nombre del archivo con el que se trabajara"<<endl;
    cout<<"Programa de encriptacion y desencriptacion Vigenere"<<endl;
    cout<<"La encriptacion funciona con minusculas y minusculas, la desencriptacion solo con mayusculas"<<endl;
    cout<<"USO: ./vig archivo opcion clave"<<endl;
    cout<<"archivo: nombre del archivo con el que se trabajara"<<endl;
    cout<<"opcion: 1 para encriptar, 2 para desencriptar"<<endl;
    cout<<"clave: palabra clave usara para la desencriptacion o encriptacion"<<endl;

    exit(1);
  }

  //existencia del archivo
  FILE *archivo = fopen(argv[1], "r");
  if(archivo == NULL)
  {
    cout<<"No existe "<<argv[1]<<endl;
    exit(1);
  }

  //obtenemos los argumentos que nos proporciona el usuario
  int opcion = *argv[2] - '0';
  string clave (argv[3]);
  Vigenere vig;

  if (opcion == 1)
    encriptar(clave, archivo, vig);
  else
    desencriptar(clave, archivo, vig);

  return 0;
}

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class AsciiArt
{
    string comp;
    string decomp;
    vector <string> art;
public:

    AsciiArt(){}

    void fill(FILE * archivo)
    {
        string comp = "";
        char linea[240];
        int j = 0;

        char caracter = '1'; //caracter actual

        while(!feof(archivo))
        {
            //leemos una linea
            fgets(linea, 240, archivo);
            //checamos la oracion
            for(int i = 0; i < (int)strlen(linea); i++)
            {
                //cout<<"caracter: "<<linea[i]<<endl;
                if((int)linea[i] == 10) //si es cambio de linea
                {
                    art.push_back(">");
                }
                else //pasamos el caracter
                {
                    stringstream ss;
                    ss << linea[i]; //metemos el caracter
                    string temp;
                    ss >> temp; //metemos a string temporal
                    art.push_back(temp); //aniadimos al 
                }
            }
            j++;
        }

/*
        //print the vector
        for(int i = 0; i < art.size(); i++)
        {
            cout<<art[i];
        }
        cout<<endl;*/
    }   

    void compress()
    {
        int i  = 0;
        int j = 0;

        int band[2] = {10, 10};
        int cont = 0;
        string caracter = "";

        caracter = art[0]; //primer caracter
        cont = 1;
        
        for(int i = 1; i < art.size(); i++)
        {
            if(caracter == art[i]) //mismo caracter
            {
                cont++;
            }
            else if ((int)caracter[0] == 0) //no se debe hacer nada
            {
                caracter = art[i];
            }
            else
            {
                comp = comp + to_string(cont); //pasamos el numero de veces que aparecio el caracter
                cont = 1; //reiniciamos el contador a 1
                comp = comp + caracter; //pasamos el caracter que teniamos
                caracter = art[i]; //pasamos al nuevo caracter
            }

            if(i == art.size()-1)
            {
                comp = comp + to_string(cont); //pasamos el numero de veces que aparecio el caracter
                cont = 1; //reiniciamos el contador a 1
                comp = comp + caracter; //pasamos el caracter que teniamos
                caracter = art[i]; //pasamos al nuevo caracter
            }
        }

        cout<<"compressed: "<<endl<<comp<<endl;
    }

    void decompress()
    {
        string caracter;
        string num = "";

        for(int i = 0; i < comp.length(); i++)
        {
            caracter = comp[i]; //caracter que vamos a trabajar este ciclos

            if((int)caracter[0] > 47 && (int)caracter[0] < 58) //es un numero
            {
                num = num + caracter[0];
            }
            else //encontramos un signo
            {
                int temp = stoi(num); //veces que se repetira la insercion del signo

                for(int j = 0; j < temp; j++ ) //insercion del signo
                {
                    if(caracter[0] == '>') //cambio de linea
                    {
                        decomp = decomp + "\n";
                    }
                    else    //cualquier signo
                    {
                        decomp = decomp + caracter[0];
                    }
                }
                num = "";
            }
        }
        cout<<"decompressed: "<<endl<<decomp<<endl;
    }
};


int main(int argc, char **argv)
{
    /*
        El archivo con el que trabaja el programa no puede contener numeros ni el simbolo de mayor ">"
    */
    FILE *archivo = fopen(argv[1], "r");
    if(archivo == NULL)
    {
        cout<<"No existe "<<argv[1]<<endl;
        return 0;
    }

    AsciiArt art1;
    art1.fill(archivo);
    fclose(archivo);
    art1.compress();
    art1.decompress();

    return 0;
}
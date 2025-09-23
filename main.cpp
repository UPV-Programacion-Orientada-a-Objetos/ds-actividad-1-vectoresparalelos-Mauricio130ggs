#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;        //Esta linea permite no tener que usar std:: antes de cada cin, cout, etc.

vector<string> nombres;
vector<string> paises;
vector<string> disciplinas;
vector<string> generos;
vector<int> medallas;

void leerArchivo(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    string linea;

    while (getline(archivo, linea)){
        stringstream ss(linea);
        string nombre, pais, disciplina, genero;
        int medalla;

        getline(ss, nombre, ',');
        getline(ss, pais, ',');
        getline(ss, disciplina, ',');
        getline(ss, genero, ',');
        ss >> medalla;

        nombres.push_back(nombre);
        paises.push_back(pais);
        disciplinas.push_back(disciplina);
        generos.push_back(genero);
        medallas.push_back(medalla);

    }
}

void registrarAtleta(){
    string nombre, pais, diciplina,genero;
    int medalla;

    cout << "Ingrese el nombre del atleta: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el pais del atleta: ";
    getline(cin, pais);

    cout << "Ingrese la diciplina del atleta: ";
    getline(cin, diciplina);

    cout << "Ingrese el genero del atleta (M/F): ";
    getline(cin, genero);

    cout << "Ingrese el numero de medallas ganadas: ";
    cin >> medalla;

    nombres.push_back(nombre);
    paises.push_back(pais);
    disciplinas.push_back(diciplina);
    generos.push_back(genero);
    medallas.push_back(medalla);
}

void buscarAtleta(const string& nombre){
    bool encontrado = false;
    for (size_t i= 0; i < nombres.size(); ++i){
        if (nombres[i]== nombre){
            cout<<"Atleta encontrado:\n";
            cout<<"Nombre: "<<nombres[i]<<"\n";
            cout<<"Pais: "<<paises[i]<<"\n";
            cout<<"Diciplina: "<<disciplinas[i]<<"\n";
            cout<<"Genero: "<<generos[i]<<"\n";
            cout<<"Medallas: "<<medallas[i]<<"\n";
            encontrado = true;
            break;
        }
    }


}





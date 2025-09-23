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
    if (!encontrado){
        cout<<"Atleta no encontrado.\n";
    }
}

void calcularMedallasPorPais(const string& pais){
    int totalMedallas = 0;
    for(size_t i= 0; i < paises.size(); ++i){
        if (paises[i]== pais){
            totalMedallas += medallas[i];
        }
    }
    cout<<"Total de medallas para "<<pais<<": "<<totalMedallas<<"\n";
}
 void encontrarAtletaConMasMedallas(){
    int maxMedallas = -1;
    string atleta;
    for(size_t i=0; i< medallas.size(); ++i){
        if (medallas[i]> maxMedallas){
            maxMedallas = medallas[i];
            atleta = nombres[i];
        }
    }
    cout<<"Atleta con mas medallas: "<<atleta<<" con "<<maxMedallas<<" medallas.\n";
 }

 string obtenerRutaArchivo() {
     string archivo;
     cout << "Ingrese la ruta del archivo (Enter para usar data/data1.csv): ";
     getline(cin, archivo);

     if(archivo.empty()) {
         archivo = "data/data1.csv";
     }
     return archivo;
 }
 int main() {
    string archivo = obtenerRutaArchivo();
    leerArchivo(archivo);
    int opcion;
    do{
        cout<< "Menu:\n";
        cout<< "1. Registrar nuevo atleta\n";
        cout<< "2. Buscar atleta por nombre\n";
        cout<< "3. Calcular total de medallas por pais\n";
        cout<< "4. Encontrar atleta con mas medallas\n";
        cout<< "5. Salir\n";
        cout<< "Seleccione una opcion: ";
        cin>> opcion;
        switch (opcion){
            case 1:
            registrarAtleta();
            break;
            case 2: {
                string nombre;
                cout<<"Ingrese el nombre del atleta a buscar: ";
                cin.ignore();
                getline(cin, nombre);
                buscarAtleta(nombre);
                break;
            }
            case 3: {
                string pais;
                cout<<"Ingrese el pais: ";
                cin.ignore();
                getline(cin, pais);
                calcularMedallasPorPais(pais);
                break;
            }
            case 4:
            encontrarAtletaConMasMedallas();
            break;
            case 5:
            cout<<"Saliendo del programa.\n";
            break;
            default:
            cout<<"Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
    return 0;
}
               



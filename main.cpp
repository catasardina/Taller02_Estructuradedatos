#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "SparseMatrix.h"
using namespace std;

void generarMatriz(SparseMatrix& m, int cantidad) {
    srand(time(NULL));
    for (int i = 0; i < cantidad; i++) {
        int x = rand() % 100;
        int y = rand() % 100;
        int value = (rand() % 9) + 1;
        m.add(value, x, y);
    }
}

template<typename Func>
double medirTiempo(Func f, int repeticiones = 10) {
    double total = 0;
    for (int i = 0; i < repeticiones; i++) {
        clock_t start = clock();
        f();
        clock_t end = clock();
        total += double(end - start) / CLOCKS_PER_SEC;
    }
    return total / repeticiones;
}

int main() {
    int sizes[] = {50, 250, 500, 1000, 5000};
    
    // Abrir archivo CSV para escribir resultados
    ofstream csvFile("data/resultados_rendimiento.csv");
    csvFile << "Tamaño,Insercion,Busqueda,Multiplicacion\n";
    
    cout << "Pruebas de rendimiento" << endl;
    
    for(int t : sizes) {
        cout << "==== Tamaño: " << t << " Elementos =====" << endl;
        SparseMatrix X, Z;
        generarMatriz(X, t);
        generarMatriz(Z, t);

        
        double tiempoAdd = medirTiempo([&]() {
            SparseMatrix temp;
            generarMatriz(temp, t);
        });
        
        double tiempoGet = medirTiempo([&]() {
            for(int i = 0; i < t; i++) {
                X.get(rand() % 100, rand() % 100);
            }
        });
        
        double tiempoMul = medirTiempo([&]() {
            SparseMatrix* P = X.multiply(&Z);
            delete P;
        });
        
        cout << "Inserción promedio: " << tiempoAdd << " s" << endl;
        cout << "Búsqueda promedio:  " << tiempoGet << " s" << endl;
        cout << "Multiplicación promedio: " << tiempoMul << " s" << endl;
        cout << endl;
        
        csvFile << t << "," << tiempoAdd << "," << tiempoGet << "," << tiempoMul << "\n";
    }
    
    csvFile.close();
    cout << "Termino de las pruebas. Datos guardados en resultados_rendimiento.csv" << endl;
    return 0;
}
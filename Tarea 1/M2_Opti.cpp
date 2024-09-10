#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
vector<vector<int>> transponerMatriz(const vector<vector<int>>& B) {
    int filas = B.size();
    int columnas = B[0].size();
    vector<vector<int>> B_T(columnas, vector<int>(filas));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            B_T[j][i] = B[i][j];
        }
    }

    return B_T;
}

vector<vector<int>> multiplicarMatricesOpt(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();
    vector<vector<int>> B_T = transponerMatriz(B);
    vector<vector<int>> C(n, vector<int>(p, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B_T[j][k];
            }
        }
    }

    return C;
}

vector<vector<int>> leerMatrizDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<vector<int>> matriz;
    string linea;
    
    while (getline(archivo, linea)) {
        vector<int> fila;
        stringstream ss(linea);
        string valor;
        
        while (getline(ss, valor, ',')) {
            fila.push_back(stoi(valor));
        }
        
        matriz.push_back(fila);
    }
    
    return matriz;
}

int main() {
    vector<vector<int>> A = leerMatrizDesdeArchivo("matriz_A.txt");
    vector<vector<int>> B = leerMatrizDesdeArchivo("matriz_B.txt");
    auto start = high_resolution_clock::now();
    vector<vector<int>> C = multiplicarMatricesOpt(A, B);
    auto stop = high_resolution_clock::now();  
    auto duration = duration_cast<microseconds>(stop - start);
    for (const auto& fila : C) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
    cout << "Tiempo de ejecución: "
         << duration.count() << " microsegundos" << endl;

    return 0;
}

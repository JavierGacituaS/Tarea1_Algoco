#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();
    vector<vector<int>> C(n, vector<int>(p, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

vector<vector<int>> leerMatrizDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<vector<int>> matriz;
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            vector<int> fila;
            string numero;
            while (getline(ss, numero, ',')) {
                fila.push_back(stoi(numero));
            }

            matriz.push_back(fila);
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }

    return matriz;
}

int main() {
    vector<vector<int>> matriz_A = leerMatrizDesdeArchivo("matriz_A.txt");
    vector<vector<int>> matriz_B = leerMatrizDesdeArchivo("matriz_B.txt");
    auto start = high_resolution_clock::now();
    vector<vector<int>> matriz_C = multiplicarMatrices(matriz_A, matriz_B);
    auto stop = high_resolution_clock::now();  
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Matriz resultante C:" << endl;
    for (const auto& fila : matriz_C) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
    cout << "Tiempo de ejecución: "
         << duration.count() << " microsegundos" << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

vector<int> leerListaDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<int> lista;
    string linea, numero;

    if (archivo.is_open()) {
        getline(archivo, linea);
        stringstream ss(linea);

        while (getline(ss, numero, ',')) {
            lista.push_back(stoi(numero));
        }

        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }

    return lista;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


    int main() {
    vector<int> lista = leerListaDesdeArchivo("lista_desordenada.txt");
    auto start = high_resolution_clock::now();
    selectionSort(lista);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    for (int num : lista) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Tiempo de ejecución: "
         << duration.count() << " microsegundos" << endl;
    return 0;
}


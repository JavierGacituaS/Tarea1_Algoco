#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

int main() {
    vector<int> lista = leerListaDesdeArchivo("lista_desordenada.txt");
    auto start = high_resolution_clock::now();
    quickSort(lista, 0, lista.size() - 1);
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

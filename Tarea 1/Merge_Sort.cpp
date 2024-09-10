#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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
    mergeSort(lista, 0, lista.size() - 1);
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

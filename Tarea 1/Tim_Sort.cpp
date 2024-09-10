#include <bits/stdc++.h> 
using namespace std; 
using namespace std::chrono;
const int RUN = 32; 

void insertionSort(int arr[], int left, int right) { 
    for (int i = left + 1; i <= right; i++) { 
        int temp = arr[i]; 
        int j = i - 1; 
        while (j >= left && arr[j] > temp) { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = temp; 
    } 
} 

void merge(int arr[], int l, int m, int r) { 
    int len1 = m - l + 1, len2 = r - m; 
    int left[len1], right[len2]; 
    for (int i = 0; i < len1; i++) 
        left[i] = arr[l + i]; 
    for (int i = 0; i < len2; i++) 
        right[i] = arr[m + 1 + i]; 

    int i = 0, j = 0, k = l; 

    while (i < len1 && j < len2) { 
        if (left[i] <= right[j]) { 
            arr[k] = left[i]; 
            i++; 
        } 
        else { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < len1) { 
        arr[k] = left[i]; 
        k++; 
        i++; 
    } 

    while (j < len2) { 
        arr[k] = right[j]; 
        k++; 
        j++; 
    } 
} 

void timSort(int arr[], int n) { 
    for (int i = 0; i < n; i += RUN) 
        insertionSort(arr, i, min((i + RUN - 1), (n - 1))); 

    for (int size = RUN; size < n; size = 2 * size) { 
        for (int left = 0; left < n; left += 2 * size) { 
            int mid = left + size - 1; 
            int right = min((left + 2 * size - 1), (n - 1)); 

            if (mid < right) 
                merge(arr, left, mid, right); 
        } 
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
    int n = lista.size();
    int arr[n];
    copy(lista.begin(), lista.end(), arr);

    timSort(arr, n);
	auto stop = high_resolution_clock::now();  
    auto duration = duration_cast<microseconds>(stop - start);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    	cout << "Tiempo de ejecución: "
         << duration.count() << " microsegundos" << endl;

    return 0;
}

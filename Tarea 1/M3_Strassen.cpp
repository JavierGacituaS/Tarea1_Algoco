//Algoritmo original: https://www.geeksforgeeks.org/strassens-matrix-multiplication-algorithm-implementation/, con ligeros cambios para lectura de entrada.

#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
using namespace std::chrono;
inline lld** MatrixMultiply(lld** a, lld** b, int n, int l, int m)
{
    lld** c = new lld*[n];
    for (int i = 0; i < n; i++)
        c[i] = new lld[m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = 0;
            for (int k = 0; k < l; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

inline lld** Strassen(lld** a, lld** b, int n, int l, int m)
{
    if (n == 1 || l == 1 || m == 1)
        return MatrixMultiply(a, b, n, l, m);

    int adjN = (n >> 1) + (n & 1);
    int adjL = (l >> 1) + (l & 1);
    int adjM = (m >> 1) + (m & 1);

    lld** c = new lld*[adjN + adjN];
    for (int i = 0; i < adjN + adjN; i++)
        c[i] = new lld[adjM + adjM]{0};

    lld**** As = new lld***[2];
    for (int x = 0; x < 2; x++) {
        As[x] = new lld**[2];
        for (int y = 0; y < 2; y++) {
            As[x][y] = new lld*[adjN];
            for (int i = 0; i < adjN; i++) {
                As[x][y][i] = new lld[adjL];
                for (int j = 0; j < adjL; j++) {
                    int I = i + (x & 1) * adjN;
                    int J = j + (y & 1) * adjL;
                    As[x][y][i][j] = (I < n && J < l) ? a[I][J] : 0;
                }
            }
        }
    }

    lld**** Bs = new lld***[2];
    for (int x = 0; x < 2; x++) {
        Bs[x] = new lld**[2];
        for (int y = 0; y < 2; y++) {
            Bs[x][y] = new lld*[adjL];
            for (int i = 0; i < adjL; i++) {
                Bs[x][y][i] = new lld[adjM];
                for (int j = 0; j < adjM; j++) {
                    int I = i + (x & 1) * adjL;
                    int J = j + (y & 1) * adjM;
                    Bs[x][y][i][j] = (I < l && J < m) ? b[I][J] : 0;
                }
            }
        }
    }

    lld*** s = new lld**[10];
    for (int i = 0; i < 10; i++) {
        switch (i) {
        case 0:
            s[i] = new lld*[adjL];
            for (int j = 0; j < adjL; j++) {
                s[i][j] = new lld[adjM];
                for (int k = 0; k < adjM; k++) {
                    s[i][j][k] = Bs[0][1][j][k] - Bs[1][1][j][k];
                }
            }
            break;
        case 1:
            s[i] = new lld*[adjN];
            for (int j = 0; j < adjN; j++) {
                s[i][j] = new lld[adjL];
                for (int k = 0; k < adjL; k++) {
                    s[i][j][k] = As[0][0][j][k] + As[0][1][j][k];
                }
            }
            break;
        case 2:
            s[i] = new lld*[adjN];
            for (int j = 0; j < adjN; j++) {
                s[i][j] = new lld[adjL];
                for (int k = 0; k < adjL; k++) {
                    s[i][j][k] = As[1][0][j][k] + As[1][1][j][k];
                }
            }
            break;
        case 3:
            s[i] = new lld*[adjL];
            for (int j = 0; j < adjL; j++) {
                s[i][j] = new lld[adjM];
                for (int k = 0; k < adjM; k++) {
                    s[i][j][k] = Bs[1][0][j][k] - Bs[0][0][j][k];
                }
            }
            break;
        case 4:
            s[i] = new lld*[adjN];
            for (int j = 0; j < adjN; j++) {
                s[i][j] = new lld[adjL];
                for (int k = 0; k < adjL; k++) {
                    s[i][j][k] = As[0][0][j][k] + As[1][1][j][k];
                }
            }
            break;
        case 5:
            s[i] = new lld*[adjL];
            for (int j = 0; j < adjL; j++) {
                s[i][j] = new lld[adjM];
                for (int k = 0; k < adjM; k++) {
                    s[i][j][k] = Bs[0][0][j][k] + Bs[1][1][j][k];
                }
            }
            break;
        case 6:
            s[i] = new lld*[adjN];
            for (int j = 0; j < adjN; j++) {
                s[i][j] = new lld[adjL];
                for (int k = 0; k < adjL; k++) {
                    s[i][j][k] = As[0][1][j][k] - As[1][1][j][k];
                }
            }
            break;
        case 7:
            s[i] = new lld*[adjL];
            for (int j = 0; j < adjL; j++) {
                s[i][j] = new lld[adjM];
                for (int k = 0; k < adjM; k++) {
                    s[i][j][k] = Bs[1][0][j][k] + Bs[1][1][j][k];
                }
            }
            break;
        case 8:
            s[i] = new lld*[adjN];
            for (int j = 0; j < adjN; j++) {
                s[i][j] = new lld[adjL];
                for (int k = 0; k < adjL; k++) {
                    s[i][j][k] = As[0][0][j][k] - As[1][0][j][k];
                }
            }
            break;
        case 9:
            s[i] = new lld*[adjL];
            for (int j = 0; j < adjL; j++) {
                s[i][j] = new lld[adjM];
                for (int k = 0; k < adjM; k++) {
                    s[i][j][k] = Bs[0][0][j][k] + Bs[0][1][j][k];
                }
            }
            break;
        }
    }

    lld*** p = new lld**[7];
    p[0] = Strassen(As[0][0], s[0], adjN, adjL, adjM);
    p[1] = Strassen(s[1], Bs[1][1], adjN, adjL, adjM);
    p[2] = Strassen(s[2], Bs[0][0], adjN, adjL, adjM);
    p[3] = Strassen(As[1][1], s[3], adjN, adjL, adjM);
    p[4] = Strassen(s[4], s[5], adjN, adjL, adjM);
    p[5] = Strassen(s[6], s[7], adjN, adjL, adjM);
    p[6] = Strassen(s[8], s[9], adjN, adjL, adjM);

    for (int i = 0; i < adjN; i++) {
        for (int j = 0; j < adjM; j++) {
            c[i][j] = p[4][i][j] + p[3][i][j] - p[1][i][j] + p[5][i][j];
            if (j + adjM < m)
                c[i][j + adjM] = p[0][i][j] + p[1][i][j];
            if (i + adjN < n)
                c[i + adjN][j] = p[2][i][j] + p[3][i][j];
            if (i + adjN < n && j + adjM < m)
                c[i + adjN][j + adjM] = p[4][i][j] + p[0][i][j] - p[2][i][j] - p[6][i][j];
        }
    }

    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            for (int i = 0; i < adjN; i++) {
                delete[] As[x][y][i];
            }
            delete[] As[x][y];
        }
        delete[] As[x];
    }
    delete[] As;

    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            for (int i = 0; i < adjL; i++) {
                delete[] Bs[x][y][i];
            }
            delete[] Bs[x][y];
        }
        delete[] Bs[x];
    }
    delete[] Bs;

    for (int i = 0; i < 10; i++) {
        switch (i) {
        case 0:
        case 3:
        case 5:
        case 7:
        case 9:
            for (int j = 0; j < adjL; j++) {
                delete[] s[i][j];
            }
            break;
        case 1:
        case 2:
        case 4:
        case 6:
        case 8:
            for (int j = 0; j < adjN; j++) {
                delete[] s[i][j];
            }
            break;
        }
        delete[] s[i];
    }
    delete[] s;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < (n >> 1); j++) {
            delete[] p[i][j];
        }
        delete[] p[i];
    }
    delete[] p;

    return c;
}

vector<vector<lld>> leerMatrizDesdeArchivo(const string& nombreArchivo, int& filas, int& columnas) {
    ifstream archivo(nombreArchivo);
    vector<vector<lld>> matriz;
    string linea;
    
    while (getline(archivo, linea)) {
        vector<lld> fila;
        stringstream ss(linea);
        string valor;
        
        while (getline(ss, valor, ',')) {
            fila.push_back(stoi(valor));
        }
        
        matriz.push_back(fila);
    }

    filas = matriz.size();
    columnas = (matriz.empty() ? 0 : matriz[0].size());

    return matriz;
}

lld** convertirVectorAMatriz(const vector<vector<lld>>& vec, int& filas, int& columnas) {
    lld** matriz = new lld*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new lld[columnas];
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = vec[i][j];
        }
    }
    return matriz;
}

void liberarMatriz(lld** matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

int main() {
    int filasA, columnasA, filasB, columnasB;
    
    vector<vector<lld>> A = leerMatrizDesdeArchivo("matriz_A.txt", filasA, columnasA);
    vector<vector<lld>> B = leerMatrizDesdeArchivo("matriz_B.txt", filasB, columnasB);

    if (columnasA != filasB) {
        cerr << "Las matrices no se pueden multiplicar: el número de columnas de A debe ser igual al número de filas de B." << endl;
        return 1;
    }

    int maxSize = max({filasA, columnasA, filasB, columnasB});
    int n = pow(2, ceil(log2(maxSize))); // Tamaño necesario para el algoritmo de Strassen
    vector<vector<lld>> paddedA(n, vector<lld>(n, 0));
    vector<vector<lld>> paddedB(n, vector<lld>(n, 0));

    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasA; j++) {
            paddedA[i][j] = A[i][j];
        }
    }

    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < columnasB; j++) {
            paddedB[i][j] = B[i][j];
        }
    }

    int adjN = paddedA.size();
    int adjL = paddedB.size();
    int adjM = paddedB[0].size();

    lld** matA = convertirVectorAMatriz(paddedA, adjN, adjL);
    lld** matB = convertirVectorAMatriz(paddedB, adjL, adjM);
    auto start = high_resolution_clock::now();
    lld** matC = Strassen(matA, matB, adjN, adjL, adjM);
    auto stop = high_resolution_clock::now();  
    auto duration = duration_cast<microseconds>(stop - start);
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            printf("%lld ", matC[i][j]);
        }
        printf("\n");
    }
    cout << "Tiempo de ejecución: "
         << duration.count() << " microsegundos" << endl;
    liberarMatriz(matA, adjN);
    liberarMatriz(matB, adjL);
    liberarMatriz(matC, adjN);

    return 0;
}

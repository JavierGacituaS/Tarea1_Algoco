import random

def generar_matriz(filas, columnas):
    return [[random.randint(0, 100) for _ in range(columnas)] for _ in range(filas)]

def guardar_matriz_en_txt(nombre_archivo, matriz):
    with open(nombre_archivo, 'w') as file:
        for fila in matriz:
            file.write(', '.join(map(str, fila)) + '\n')

filas_A = 8
columnas_A = 8 #Número de filas para B igualmente
columnas_B = 8

matriz_A = generar_matriz(filas_A, columnas_A)
matriz_B = generar_matriz(columnas_A, columnas_B)

guardar_matriz_en_txt("matriz_A.txt", matriz_A)
guardar_matriz_en_txt("matriz_B.txt", matriz_B)


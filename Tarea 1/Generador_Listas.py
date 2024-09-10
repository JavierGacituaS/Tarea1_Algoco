import random

def generar_lista_desordenada(tamaño):
    return [random.randint(0, tamaño * 10) for _ in range(tamaño)]

def generar_lista_ascendente(tamaño):
    return list(range(tamaño))

def generar_lista_descendente(tamaño):
    return list(range(tamaño, 0, -1))

def generar_lista_casi_ordenada(tamaño, alteraciones=10):
    lista = list(range(tamaño))
    for _ in range(alteraciones):
        i = random.randint(0, tamaño - 1)
        j = random.randint(0, tamaño - 1)
        lista[i], lista[j] = lista[j], lista[i]
    return lista

def guardar_lista_en_txt(nombre_archivo, lista):
    with open(nombre_archivo, 'w') as file:
        file.write(', '.join(map(str, lista)))

tamaño_lista = 10
lista_desordenada = generar_lista_desordenada(tamaño_lista)
lista_ascendente = generar_lista_ascendente(tamaño_lista)
lista_descendente = generar_lista_descendente(tamaño_lista)
lista_casi_ordenada = generar_lista_casi_ordenada(tamaño_lista)

guardar_lista_en_txt("lista_desordenada.txt", lista_desordenada)
guardar_lista_en_txt("lista_ascendente.txt", lista_ascendente)
guardar_lista_en_txt("lista_descendente.txt", lista_descendente)
guardar_lista_en_txt("lista_casi_ordenada.txt", lista_casi_ordenada)

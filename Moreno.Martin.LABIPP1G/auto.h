#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "marca.h"
#include "color.h"

#define ASC 1
#define DESC 0

typedef struct
{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
}eAuto;

#endif // AUTO_H_INCLUDED
int inicializarAuto(eAuto autos[], int tam);
int obtenerDescripcionColor(eColor colores[], int tam, int id, char descricpion);
int obtenerDescripcionMarca(eMarca marcas[], int tam, int id, char descricpion);
void mostrarAuto(eAuto unAuto, eMarca marcas[], eColor colores[], int tamM, int tamC);
void mostrarAutos(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
int modificarAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
int altaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, int id);
int bajaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
int buscarAuto(eAuto autos[], int tam, int patente);
int ordenarAutosXMarcaPatente(eAuto autos[], int tam, int criterioM, int criterioP);

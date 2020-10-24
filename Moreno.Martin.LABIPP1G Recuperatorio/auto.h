#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "color.h"
#include "marca.h"


#define ASC 1
#define DESC 0

typedef struct
{
    int id;
    char patente[8];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
}eAuto;

#endif // AUTO_H_INCLUDED

int inicializarAuto(eAuto autos[], int tam);
int obtenerDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[]);
void mostrarAuto(eAuto unAuto, eMarca marcas[], eColor colores[], int tamM, int tamC);
int mostrarAutos(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
int modificarAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
int altaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, int id);
int bajaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
int buscarAuto(eAuto autos[], int tam, char patente[]);
int ordenarAutosXMarcaPatente(eAuto autos[], int tam, int criterioM, int criterioP);
int validarPatente(eAuto autos[], int tam, char patente[]);
int obtenerPatenteAuto(eAuto autos[], int tam, int id, char patente[]);
int hardcodearAutos(eAuto autos[], int tam, int cantidad);
int mostrarColorSeleccionado(eColor colores[], int tamC, eAuto autos[], int tamA, eMarca marcas[],int tamM);
int mostrarMarcaSeleccionada(eColor colores[], int tamC, eAuto autos[], int tamA, eMarca marcas[], int tamM);
/*int listaDeAutosXMarca(eAuto autos[], int tam, eMarca marcas[], int tamM);*/

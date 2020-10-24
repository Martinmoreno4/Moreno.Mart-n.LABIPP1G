#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"

typedef struct
{
    int id;
    char patenteAuto;
    char idServicio;
    int isEmpty;
    eFecha fecha;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int inicializarTrabajo(eTrabajo trabajos[], int tam);
void mostrarTrabajo(eTrabajo trabajo, eAuto autos[], int tamA, eServicio servicios[], int tamS);
int mostrarTrabajos(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS);
int buscarLibreTrabajo(eTrabajo trabajos[], int tam);
int altaTrabajo(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, int id);

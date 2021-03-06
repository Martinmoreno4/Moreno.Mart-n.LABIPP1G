#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "color.h"
#include "marca.h"
#include "auto.h"

void mostrarColor(eColor color)
{
    printf("  %d    %s\n", color.id, color.descripcion);
}

int mostrarColores(eColor colores[], int tamC)
{
    int error = 1;
    if( colores != NULL && tamC >0)
    {
        printf("      Listado de Colores      \n");
        printf("------------------------------\n");
        printf("   id        Descripcion\n");
        for(int i =0; i < tamC; i++)
        {
            mostrarColor(colores[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int validarIdColor(eColor colores[], int tamC, int id)
{
    int esValido = 0;

    if( colores != NULL && tamC >0 && id >= 1000)
    {
        for(int i=0; i<tamC; i++)
        {
            if(colores[i].id == id)
            {
                esValido = 1;
                break;
            }
        }

    }

    return esValido;
}

int obtenerDescripcionColor(eColor colores[], int tam, int id, char descripcion[])
{
    int error = 1;
    if(colores !=NULL && tam > 0 && id >= 1000 && descripcion!=NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(colores[i].id == id)
            {

                strcpy(descripcion, colores[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}

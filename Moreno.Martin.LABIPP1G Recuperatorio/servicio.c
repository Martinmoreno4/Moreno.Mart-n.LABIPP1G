#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicio.h"

void mostrarServicio(eServicio servicio)
{
    printf("  %d    %s    $ %d\n", servicio.id, servicio.descripcion, servicio.precio);
}

int mostrarServicios(eServicio servicios[], int tamS)
{
    int error = 1;
    if( servicios != NULL && tamS >0)
    {
        printf("     Listado de Servicios     \n");
        printf("------------------------------\n");
        printf("   id        Descripcion:     precio\n");
        for(int i =0; i < tamS; i++)
        {
            mostrarServicio(servicios[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int obtenerDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion)
{
    int error = 1;
    if(servicios !=NULL && tam > 0 && id >= 1000 && descripcion!=NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(servicios[i].id == id)
            {
                strcpy(descripcion, servicios[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}

int validarIdServicio(eServicio servicios[], int tam, int id)
{
    int esValido = 0;

    if( servicios != NULL && tam >0 && id >= 1000)
    {
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id == id)
            {
                esValido = 1;
                break;
            }
        }

    }

    return esValido;
}

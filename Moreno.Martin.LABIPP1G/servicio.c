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

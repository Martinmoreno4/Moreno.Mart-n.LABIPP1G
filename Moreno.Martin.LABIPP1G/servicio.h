#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

void mostrarServicio(eServicio servicio);
int mostrarServicios(eServicio servicios[], int tamS);
#endif // SERVICIO_H_INCLUDED



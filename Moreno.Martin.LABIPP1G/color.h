#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eColor;

void mostrarColor(eColor color);
int mostrarColores(eColor colores[], int tamC);
int validarIdColor(eColor colores[], int tamC, int id);

#endif // COLOR_H_INCLUDED



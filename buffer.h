#ifndef __BUFFER_H
#define __BUFFER_H

struct Buffer
{
    int    len;
    int    max;
    char    * data;
};

/* Crea un buffer vac�o */
struct Buffer * creaBuffer (char* buf);

/* Inicia un buffer vac�o */
void iniciaBuffer(struct Buffer* b, char* buf);

/* Elimina un buffer */
void liberaBuffer(struct Buffer * b);

/* A�ade un car�cter al final */
struct Buffer * anyadeChar(struct Buffer * b, char c);

/* A�ade una cadena al final */
struct Buffer * anyadeCadena(struct Buffer * b, char * c);

/* Elimina el �ltimo car�cter del final */
struct Buffer * eliminaUltimo(struct Buffer * b);

#endif

/* $Id: buffer.h 1399 2007-12-20 09:45:07Z pedroe $ */

#ifndef __TOKBUF_H
#define __TOKBUF_H

#include "buffer.h"

/* Tokens reconocidos */
enum TokType_
{
    EOL,            /* Fin de l�nea */
    ARG,            /* Argumento */
    AMPERSAND,      /* & */
    SEMICOLON,      /* ; */
    PIPE,           /* | */
    BACKQUOTE,      /* ` */
    QUOTE,          /* ' */
    MENOR,          /* < */
    MAYOR,          /* > */
    MAYORMAYOR,     /* >> */
    DOSMAYOR,       /* 2> */
    DOSMAYORMAYOR,  /* 2>> */
    AND,            /* && */
    OR,             /* || */
    ARROBA,         /* @ */
    PORCIENTO,      /* % */
    SPACE           /* " ", \t, etc. */
};
/* Tipo token */
typedef enum TokType_ TokType;

/* Estructura para almacenar un token junto con su contenido (si procede) */
struct Token
{
    TokType     type;         /* Tipo del token (ver arriba) */
    char        *data;        /* Texto del token */
};

/* Estructura que guarda un conjunto de tokens. Este conjunto representa
 * a la l�nea de comandos una vez que se ha hecho el parsing.
 */
struct TokBuf
{
    int        length;
    struct Token    * tokens;
};


/**
 * userin
 *
 * Retorna el Buffer resultado de leer la cadena entrada por el teclado
 * Esta funci�n llama a las funciones de userfn.h depeniendo de los
 * caracteres le�dos.
 *
 * @return El Buffer construido
 */
struct Buffer * userin();

/**
 * trataToken
 *
 * A�ade un token nuevo a curTokBuf. curTokBuf guarda el TokBuf actual
 * siendo reconocido a partir de la entrada del usuario. Si hay una
 * cadena temporal en tmpArg, la a�ade antes como un token de tipo ARG.
 *
 * @param type Tipo del token
 * @param string Cadena del token
 */
void trataToken(TokType type, char *string);


/**
 * trataChar
 *
 * A�ade un car�cter al argumento temporal tmpArg.
 *
 * @param c El car�cter.
 */
void trataChar(char c);


/**
 * gettok
 *
 * Retorna un TokBuf construido a partir de la cadena dada como par�metro
 *
 * @param str La cadena
 *
 * @return El TokBuf* con la lista de tokens.
 */
struct TokBuf * gettok(char *str);

/**
 * liberaTokBuf
 *
 * Libera la memoria asociada a un TokBuf
 *
 * @param t El TokBuf.
 */
void liberaTokBuf(struct TokBuf * t);

/**
 * modoInterpretado
 *
 * Establece el modo (interpretado o no) en el descriptor de fichero "fd"
 *
 * @param fd El descriptor de fichero
 * @param on 1=on, 0=off
 */
void modoInterpretado(int fd, int on);

#endif

/* $Id: gettok.h 1399 2007-12-20 09:45:07Z pedroe $ */

#include<string.h>
#ifndef MEDICO_H
#define MEDICO_H

typedef struct medico {
    int id;
    char *nome;
    char *especialidade;
    struct medico *esq;
    struct medico *dir;
} Medico;



#endif
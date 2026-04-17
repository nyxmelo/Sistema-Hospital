typedef struct paciente {
    int id;
    struct paciente *prox;
    struct paciente *ant;
} Paciente;
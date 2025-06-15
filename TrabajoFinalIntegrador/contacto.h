#ifndef CONTACTO_H
#define CONTACTO_H

struct Contacto {
    char nombre[50];
    char telefono[15];
    char email[50];
    struct Contacto* siguiente;
};

struct Contacto* crearContacto(char nombre[], char telefono[], char email[]);
void insertarOrdenado(struct Contacto** cabeza, char nombre[], char telefono[], char email[]);
void mostrarContactos(struct Contacto* cabeza);
void buscarContacto(struct Contacto* cabeza, char nombre[]);
void eliminarContacto(struct Contacto** cabeza, char nombre[]);
void cambiarContacto (struct Contacto* cabeza, char nombre[]);
void liberarAgenda(struct Contacto* cabeza);
void guardarAgenda(struct Contacto* cabeza);
void cargarAgenda(struct Contacto** cabeza);




#endif

# TFI_AgendaContactos 

Este proyecto tiene como finalidad implementar una agenda de contactos simple utilizando el lenguaje C.
Esta diseñada para ejecutarse por consola y permite gestionar una lista de contactos con funciones de agregar, eliminar, buscar, modificar, ordenar y guardar en un fichero.

---

## Integrantes

- **Grossetti, Ignacio Arturo**: Developer. (Alias: lojack0101)
- **Hotchkyss, Gersom Tomás**: Developer.

## Características

- **Agregar contactos**: Nombre, teléfono y correo electrónico.
- **Buscar contacto**: Por nombre.
- **Eliminar contacto**: Debe existir mínimamente un contacto.
- **Modificar contacto**: Se modifica el teléfono y/o email.
- **Guardar/leer automáticamente**: La agenda queda en un fichero ('agenda.txt').
- **Ordenamiento alfabético**: Automático al agregar nuevos contactos.

## Estructura del Proyecto

- **'main.c'**: Código fuente principal.
- **'contacto.h'**:Encabezado con la definición de la estructura Contacto y las declaraciones de funciones.
- **'contacto.c'**: Archivo con la implementación de todas las funciones relacionadas con la gestión de contactos.
- **'agenda.txt'**: Fichero de almacenamiento de contactos.

## Cómo ejecutar

1. **Compilar:**

'gcc main.c contacto.c -o agenda'

'./agenda'


  

#ifndef COLORES_H
#define COLORES_H

#include <stdio.h>
#include <stdarg.h>

/* 
 * Códigos ANSI para formatear texto en la terminal.
 * Estos códigos funcionan en terminales que soportan ANSI (Linux, macOS, Windows 10+ con ANSI habilitado).
 */
#define RESET       "\033[0m"
#define NEGRO       "\033[30m"
#define ROJO        "\033[31m"
#define VERDE       "\033[32m"
#define AMARILLO    "\033[33m"
#define AZUL        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define BLANCO      "\033[37m"

/* Estilos de texto */
#define NEGRITA     "\033[1m"
#define SUBRAYADO   "\033[4m"

/* Colores específicos para el juego */
#define COLOR_VIDA      AZUL      // La vida se mostrará en azul
#define COLOR_DANO      ROJO      // El daño se mostrará en rojo
#define COLOR_MENU      AMARILLO  // Los menús en amarillo
#define COLOR_EXITO     VERDE     // Mensajes de éxito en verde
#define COLOR_ERROR     ROJO      // Mensajes de error en rojo
#define COLOR_ATACAR    MAGENTA   // Acciones de ataque en magenta

/*
 * Función auxiliar para imprimir texto con un color específico.
 * Ejemplo de uso:
 *     imprimir_con_color(COLOR_VIDA, "Vida: %d\n", vida);
 */
static inline void imprimir_con_color(const char *color, const char *formato, ...) {
    va_list args;
    va_start(args, formato);
    printf("%s", color);
    vprintf(formato, args);
    printf("%s", RESET);
    va_end(args);
}

#endif // COLORES_H
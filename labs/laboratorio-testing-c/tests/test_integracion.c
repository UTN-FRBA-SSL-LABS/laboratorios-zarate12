#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_compra_con_descuento(void){
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan",200,3};
    Producto l = {"Leche",350,2};
    carrito_agregar(&c, p);
    carrito_agregar(&c, l);
    int total_con_descuento = carrito_descuento(carrito_total(&c),10);
    ASSERT_IGUAL(1300,carrito_total(&c));
    ASSERT_IGUAL(1170,total_con_descuento);
}
/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_agregar_hasta_llenar(void){
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan",200,1};
    Producto l = {"Leche",350,1};
    Producto m = {"Morron",240,1};
    Producto f = {"Fideos",400,1};
    carrito_agregar(&c,p);
    carrito_agregar(&c,l);
    carrito_agregar(&c,m);
    carrito_agregar(&c,f);
    ASSERT_IGUAL(4,carrito_contar(&c));
    int intento_agregar = carrito_agregar(&c,p);
    ASSERT_IGUAL(0,intento_agregar);
    ASSERT_IGUAL(4,carrito_contar(&c));
}
/* TODO: escribir test_agregar_hasta_llenar() */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}

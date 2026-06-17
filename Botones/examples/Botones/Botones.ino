/*
 * Proyecto: Ejemplo de aplicación del controlador de Hardware Modular
 * Empresa: Ortmed S.A. de C.V.
 * Autor: Milton Elias Pech Uc (Ing. Floppa)
 * Descripción: Sketch de ejemplo para manejar eventos de botones con debounce.
 */

/*
    INSTRUCCIONES:

    Implementa un controlador para detectar eventos en botones que se conecten a los pines del microcontrolador.
    El controlador debe pedir los pines GPIO a los cuales se van a conectar botones, así como la acción que 
    se ejecutará cuando el botón se pulsa y/o cuando el botón se libera (no necesariamente ambas).
    Por ejemplo, si se conecta un push button en el GPIO 2 del microcontrolador, el sistema debe efectuar
    alguna acción arbitraria que se le especifique, como imprimir el mensaje "Haz presionado el botón en el pin 2".
    Asimismo, el controlador debe poder realizar alguna acción cuando el botón deje de presionarse, como imprimir
    el mensaje "Haz soltado el botón en el pin 2".

    Tip 1: para este ejercicio tendrás que implementar la lógica para sensar cuándo los botones cambian de estado (presionado/liberado).
    Emplea cualquier estructura(s) de datos que consideres te puede(n) facilitar tanto el guardado como la detección de cambios. Si lo haces,
    no te olvides de incluir los encabezados correspondientes usando "#include ..." al principio del archivo.
    Tip 2: este ejercicio requerirá un uso fuerte de funciones anónimas en C++ (lambdas). Puedes consultar
    ejemplos en internet o solicitarle ejemplos de su uso a la IA de tu preferencia. Concretamente, te recomiendo consultar
    documentación y ejemplos de "std::function".

    SALVO PARA CONSULTAR EJEMPLOS SOBRE FUNCIONES ANÓNIMAS Y ESTRUCTURAS DE DATOS, NO USAR IA PARA EL RESTO DE ESTE EJERCICIO.
*/

#include "Botones.hpp"

#define Tiempo_Espera 100

std::vector<int> Pines{16, 17, 22, 23};

/* Instancia aquí tu controlador */

Controlador Ctrl;

void setup() {
    Serial.begin(115200);
    Serial.println();

    // Registro de acciones //

    Ctrl.RegistrarAccion(Pines[0], EventoBoton::Pulsar, [](){ Serial.println("Hola"); });
    Ctrl.RegistrarAccion(Pines[0], EventoBoton::Soltar, [](){ Serial.println("Adiós"); });

    Ctrl.RegistrarAccion(Pines[1], EventoBoton::Pulsar, [](){ Serial.println("Qué onda"); });
    Ctrl.RegistrarAccion(Pines[1], EventoBoton::Soltar, [](){ Serial.println("Ahí nos vemos"); });

    Ctrl.RegistrarAccion(Pines[2], EventoBoton::Pulsar, [](){ Serial.println("Buenos días"); });
    Ctrl.RegistrarAccion(Pines[2], EventoBoton::Soltar, [](){ Serial.println("Buenas noches"); });

    Ctrl.RegistrarAccion(Pines[3], EventoBoton::Pulsar, [](){ Serial.println("A quien corresponda"); });
    Ctrl.RegistrarAccion(Pines[3], EventoBoton::Soltar, [](){ Serial.println("Me despido"); });

    /* Inicializa aquí tu controlador, si se requiere. */

    Ctrl.InicializarCtrl();
}

void loop() {

    /* Pon a trabajar al controlador aquí para que haga el sensado. */

    Ctrl.ActualizarCtrl(Tiempo_Espera);
}
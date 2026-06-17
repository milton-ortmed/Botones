Esta librería se utiliza para manejar botones pulsadores con ESP32.
La librería utiliza internamente el debounce.
La librería considera que los botones tienen resistencias de pull-up, es decir, el botón entrega una lectura
de 1 en reposo y una lectura de 0 cuando se presiona.
Sin embargo, se puede utilizar la librería para botones con resistencias de pull-down, intercambiando los
eventos de pulsar y soltar.

Se incluye un sketch de ejemplo para comprobar el manejo de 4 botones, los cuales se utilizan para imprimir
diferentes mensajes en el monitor serial.
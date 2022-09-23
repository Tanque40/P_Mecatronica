void setup(){
    DDRB = DDRB | B10000000; // Data Direction Register B: Inputs 0-6, Output 7
}

void loop() {
    asm (
        "inicio: \n\t"          // Etiqueta de referencia en el codigo
        "sbi 0x05,0x07 \n\t"    // Asigna el bit de la ubicación 0x07 en el registro 0x05
        "call tiempo \n\t"      // Llama a una función tiempo
        "cbi 0x05,0x07 \n\t"    // Limpia el bit de la ubicación 0x07 en el registro 0x05
        "call tiempo \n\t"      // Llama a una función tiempo
        "jmp main \n\t"         // Nos mueve a la etiqueta de main
        "tiempo: \n\t"          // Etiqueta tiempo
        "LDI r22, 45 \n\t"      // Carga la constante 45 en el registro 22
        "LOOP_3: \n\t"          // Etiqueta LOOP_3
        "LDI r21, 255 \n\t"     // Asigna la constante 255 al registro 21
        "LOOP_2: \n\t"          // Etiqueta LOOP_2
        "LDI r20, 255 \n\t"     // Asigna el valor 255 al registro 20
        "LOOP_1: \n\t"          // Etiqueta LOOP_1
        "DEC r20 \n\t"          // Reduce en 1 el valor del registro 20
        "BRNE LOOP_1 \n\t"      // Hace LOOP_1 si el valor obtenido aún no es cero
        "DEC r21 \n\t"          // Reduce en uno el valor del registro 21
        "BRNE LOOP_2 \n\t"      // Repite LOOP_2 hasta que de un valor de cero
        "DEC r22 \n\t"          // Reduce en uno el valor del registro 22
        "BRNE LOOP_3 \n\t"      // Repite el LOOP_3 hasta que el valor sea cero
        "ret \n\t"              // Fin del programa
);
}
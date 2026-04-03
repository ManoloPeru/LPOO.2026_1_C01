#include "pch.h"
#include <iostream>  // Para entrada/salida estándar (opcional, pero útil para depuración)
using namespace System;

// --- Prototipos de Funciones (Implementación completa) ---

/**
 * Función 1: Registrar corrientes de los 10 motores
 * Propósito: Capturar las lecturas de amperaje de los 10 motores
 * @param motores: Arreglo de 10 floats que almacenará las corrientes
 */
void registrarCorrientes(array<float>^ motores) {
    Console::WriteLine("\n=== REGISTRO DE CORRIENTES DE LOS 10 EJES ===");

    // Estructura iterativa FOR para recorrer los 10 motores
    for (int i = 0; i < motores->Length; i++) {
        float corriente;
        bool entradaValida = false;

        // Bucle de validación para evitar valores negativos
        do {
            Console::Write("Ingrese corriente para Motor {0}: ", i + 1);
            corriente = float::Parse(Console::ReadLine());

            // Validación: No permitir valores negativos (físicamente imposible)
            if (corriente < 0) {
                Console::WriteLine("ERROR: La corriente no puede ser negativa. Intente nuevamente.");
            }
            else {
                entradaValida = true;
            }
        } while (!entradaValida);

        // Asignar el valor validado al arreglo
        motores[i] = corriente;
    }

    Console::WriteLine("Registro completado exitosamente.");
}

/**
 * Función 2: Mostrar estado de todos los motores
 * Propósito: Reporte de telemetría actual del brazo robótico
 * @param motores: Arreglo con las corrientes de los 10 motores
 */
void mostrarEstadoMotores(array<float>^ motores) {
    Console::WriteLine("\n=== ESTADO ACTUAL DE LOS EJES ===");

    // Estructura iterativa FOR para recorrer y mostrar cada motor
    for (int i = 0; i < motores->Length; i++) {
        // Formato: Motor X: Y.Y A
        Console::WriteLine("Motor {0}: {1} A", i + 1, motores[i]);
    }
}

/**
 * Función 3: Calcular consumo promedio del brazo
 * Propósito: Análisis de carga general del sistema
 * @param motores: Arreglo con las corrientes
 * @return: Promedio aritmético de todas las corrientes
 */
float calcularConsumoPromedio(array<float>^ motores) {
    float suma = 0.0f;

    // Estructura iterativa FOR para sumar todos los valores
    for (int i = 0; i < motores->Length; i++) {
        suma += motores[i];
    }

    // Calcular promedio (división entre 10 elementos)
    float promedio = suma / motores->Length;
    return promedio;
}

/**
 * Función 4: Obtener esfuerzo máximo
 * Propósito: Identificar el motor con mayor carga de trabajo
 * @param motores: Arreglo con las corrientes
 * @return: Valor máximo de corriente en el arreglo
 */
float obtenerEsfuerzoMaximo(array<float>^ motores) {
    // Inicializar con el primer elemento (si el arreglo tiene al menos 1 elemento)
    float maximo = motores[0];

    // Recorrer el arreglo para encontrar el valor máximo
    for (int i = 1; i < motores->Length; i++) {
        if (motores[i] > maximo) {
            maximo = motores[i];
        }
    }

    return maximo;
}

/**
 * Función 5: Obtener esfuerzo mínimo (EXTRA - Requerido por el enunciado)
 * Propósito: Identificar motores sin carga o desconectados
 * @param motores: Arreglo con las corrientes
 * @return: Valor mínimo de corriente en el arreglo
 */
float obtenerEsfuerzoMinimo(array<float>^ motores) {
    // Inicializar con el primer elemento
    float minimo = motores[0];

    // Recorrer el arreglo para encontrar el valor mínimo
    for (int i = 1; i < motores->Length; i++) {
        if (motores[i] < minimo) {
            minimo = motores[i];
        }
    }

    return minimo;
}

/**
 * Función 6: Verificar sobrecargas críticas
 * Propósito: Seguridad industrial - Detectar corrientes >= 4.5A
 * @param motores: Arreglo con las corrientes
 */
void verificarSobrecargas(array<float>^ motores) {
    float umbral = 4.5f;
    bool haySobrecarga = false;

    Console::WriteLine("\n=== VERIFICANDO SEGURIDAD DEL BRAZO ===");

    // Estructura iterativa FOR para evaluar cada motor
    for (int i = 0; i < motores->Length; i++) {
        // Si la corriente supera o iguala el umbral crítico
        if (motores[i] >= umbral) {
            // Mostrar alerta con el motor específico y su corriente
            Console::WriteLine("[ALERTA] Motor {0} supera el umbral crítico con {1} A.", i + 1, motores[i]);
            haySobrecarga = true;
        }
    }

    // Si no se encontraron sobrecargas, informar que todo está en orden
    if (!haySobrecarga) {
        Console::WriteLine("SISTEMA OK: No se detectaron sobrecargas en ningún motor.");
    }
}

/**
 * Función 7: Recalibrar motor específico
 * Propósito: Mantenimiento y ajuste tras liberar obstrucción
 * @param motores: Arreglo con las corrientes
 * @param idMotor: ID del motor a recalibrar (1-10)
 * @param nuevaCorriente: Nuevo valor de corriente para el motor
 */
void recalibrarMotor(array<float>^ motores, int idMotor, float nuevaCorriente) {
    // Validación 1: Rango del ID del motor (1-10)
    if (idMotor < 1 || idMotor > 10) {
        Console::WriteLine("ERROR: ID de motor inválido. Debe estar entre 1 y 10.");
        return;
    }

    // Validación 2: La nueva corriente no puede ser negativa
    if (nuevaCorriente < 0) {
        Console::WriteLine("ERROR: La corriente no puede ser negativa.");
        return;
    }

    // Actualizar el motor (convertir ID a índice: ID-1)
    int indice = idMotor - 1;
    motores[indice] = nuevaCorriente;

    Console::WriteLine("Sistema: Motor {0} actualizado correctamente a {1} A.", idMotor, nuevaCorriente);
}

// --- Función Principal ---
int main(array<System::String^>^ args) {
    // Declaración del arreglo de 10 servomotores (todos inicializados en 0.0 por defecto)
    array<float>^ motores = gcnew array<float>(10);

    String^ opcion;
    bool primeraVez = true;

    // Bucle principal del menú (do-while para mostrar al menos una vez)
    do {
        // Limpiar consola para mejor experiencia (opcional)
        // Console::Clear();

        // Mostrar menú principal
        Console::WriteLine("\n========================================");
        Console::WriteLine(" SISTEMA DE CONTROL DE TORQUE v1.0");
        Console::WriteLine("========================================");
        Console::WriteLine("1. Registrar corrientes iniciales");
        Console::WriteLine("2. Mostrar estado de la red (10 ejes)");
        Console::WriteLine("3. Calcular consumo promedio total");
        Console::WriteLine("4. Identificar esfuerzos extremos (Max y Min)");
        Console::WriteLine("5. Verificar sobrecargas críticas (>4.5A)");
        Console::WriteLine("6. Recalibrar motor específico");
        Console::WriteLine("Q. Finalizar sistema");
        Console::Write("\nSeleccione una opcion: ");

        opcion = Console::ReadLine()->ToUpper();

        // Estructura selectiva if-else para manejar las opciones
        if (opcion == "1") {
            registrarCorrientes(motores);
            primeraVez = false;
        }
        else if (opcion == "2") {
            // Verificar si ya se registraron datos
            if (primeraVez && motores[0] == 0.0f) {
                Console::WriteLine("\nADVERTENCIA: Aún no se han registrado corrientes. Use la opción 1 primero.");
            }
            else {
                mostrarEstadoMotores(motores);
            }
        }
        else if (opcion == "3") {
            if (primeraVez && motores[0] == 0.0f) {
                Console::WriteLine("\nADVERTENCIA: Aún no se han registrado corrientes. Use la opción 1 primero.");
            }
            else {
                float promedio = calcularConsumoPromedio(motores);
                Console::WriteLine("\n=== CONSUMO PROMEDIO DEL BRAZO ===");
                Console::WriteLine("El consumo promedio es: {0} A", promedio);
            }
        }
        else if (opcion == "4") {
            if (primeraVez && motores[0] == 0.0f) {
                Console::WriteLine("\nADVERTENCIA: Aún no se han registrado corrientes. Use la opción 1 primero.");
            }
            else {
                float maximo = obtenerEsfuerzoMaximo(motores);
                float minimo = obtenerEsfuerzoMinimo(motores);
                Console::WriteLine("\n=== ESFUERZOS EXTREMOS DETECTADOS ===");
                Console::WriteLine("Esfuerzo máximo detectado: {0} A", maximo);
                Console::WriteLine("Esfuerzo mínimo detectado: {0} A", minimo);
            }
        }
        else if (opcion == "5") {
            if (primeraVez && motores[0] == 0.0f) {
                Console::WriteLine("\nADVERTENCIA: Aún no se han registrado corrientes. Use la opción 1 primero.");
            }
            else {
                verificarSobrecargas(motores);
            }
        }
        else if (opcion == "6") {
            if (primeraVez && motores[0] == 0.0f) {
                Console::WriteLine("\nADVERTENCIA: Aún no se han registrado corrientes. Use la opción 1 primero.");
            }
            else {
                try {
                    Console::Write("\nIngrese ID del motor (1-10): ");
                    int id = Int32::Parse(Console::ReadLine());

                    Console::Write("Ingrese nueva lectura de corriente: ");
                    float nuevaCorriente = float::Parse(Console::ReadLine());

                    recalibrarMotor(motores, id, nuevaCorriente);
                }
                catch (FormatException^) {
                    Console::WriteLine("ERROR: Formato de número inválido. Ingrese valores numéricos.");
                }
            }
        }
        else if (opcion != "Q") {
            Console::WriteLine("\nOPCIÓN INVÁLIDA. Por favor, seleccione una opción del 1 al 6 o 'Q' para salir.");
        }

        // Pausa para que el usuario vea el resultado antes de volver al menú
        if (opcion != "Q") {
            Console::WriteLine("\nPresione cualquier tecla para continuar...");
            Console::ReadKey();
        }

    } while (opcion != "Q");

    Console::WriteLine("\nSistema cerrado correctamente.");
    Console::WriteLine("¡Gracias por usar el Sistema de Control de Torque!");

    return 0;
}
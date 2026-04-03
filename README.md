# 🤖 Sistema de Control de Torque - Brazo Robótico Industrial

[![C++/CLI](https://img.shields.io/badge/C%2B%2B-CLI-blue.svg)](https://docs.microsoft.com/en-us/cpp/dotnet/dotnet-programming-with-cpp-cli-visual-cpp)
[![Visual Studio 2022](https://img.shields.io/badge/Visual%20Studio-2022-purple.svg)](https://visualstudio.microsoft.com/)
[![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Descripción del Proyecto

Sistema de monitoreo y control para un **brazo robótico industrial de 10 ejes (servomotores)** desarrollado en C++/CLI. El software permite gestionar en tiempo real el consumo de corriente de cada motor, detectar sobrecargas peligrosas y realizar mantenimiento preventivo.

### 🎯 Contexto Industrial

En entornos de automatización industrial, es crítico monitorear el consumo de corriente (en Amperios) de cada servomotor. Un consumo anormal indica:
- **Valores bajos**: Motor sin carga o posible desconexión
- **Valores elevados**: Carga excesiva u obstrucción mecánica (>4.5A)

El sistema implementa un umbral de seguridad de **4.5 Amperios** para prevenir daños en los bobinados de los motores.

## ✨ Funcionalidades Principales

| # | Función | Descripción |
|---|---------|-------------|
| 1 | `registrarCorrientes()` | Captura las lecturas de corriente de los 10 motores con validación de datos |
| 2 | `mostrarEstadoMotores()` | Despliega el consumo actual de todos los ejes del brazo |
| 3 | `calcularConsumoPromedio()` | Calcula la carga media del sistema completo |
| 4 | `obtenerEsfuerzosExtremos()` | Identifica el motor con mayor y menor carga de trabajo |
| 5 | `verificarSobrecargas()` | Evalúa y alerta sobre motores que superen el umbral de 4.5A |
| 6 | `recalibrarMotor()` | Permite actualizar la lectura de un motor específico (mantenimiento) |

## 🛠️ Requisitos Técnicos Implementados

### Estructuras de Datos
- ✅ Arreglo unidimensional de **10 floats** (obligatorio para gestión de memoria estática)
- ✅ Paso de parámetros por referencia (`array<float>^`) en C++/CLI

### Estructuras de Control
- ✅ Bucles iterativos (`for`, `while`, `do-while`) para procesamiento de arreglos
- ✅ Estructuras selectivas (`if-else`) para el menú interactivo
- ✅ Manejo de excepciones para entradas inválidas

### Validaciones Críticas
- 🔒 **No se permiten valores negativos** de corriente (físicamente imposibles)
- 🔒 **Validación de rango** al recalibrar motor (ID 1-10)
- 🔒 **Manejo de formato** para entradas no numéricas

## 📊 Caso de Prueba

### Entrada de Datos

Corrientes registradas:
- Motor 1: 1.5 A 
- Motor 2: 2.2 A 
- Motor 3: 3.0 A 
- Motor 4: 4.8 A 
- Motor 5: 2.5 A
- Motor 6: 3.8 A
- Motor 7: 1.2 A
- Motor 8: 5.5 A
- Motor 9: 1.9 A
- Motor 10: 3.2 A

### Salida Esperada
=== ESTADO ACTUAL DE LOS EJES ===
- Motor 1: 1.5 A 
- Motor 2: 2.2 A 
- Motor 3: 3.0 A 
- Motor 4: 4.8 A 
- Motor 5: 2.5 A 
- Motor 6: 3.8 A
- Motor 7: 1.2 A
- Motor 8: 5.5 A
- Motor 9: 1.9 A
- Motor 10: 3.2 A

=== CONSUMO PROMEDIO DEL BRAZO ===
- El consumo promedio es: 2.96 A

=== ESFUERZOS EXTREMOS DETECTADOS ===
- Esfuerzo máximo detectado: 5.5 A
 Esfuerzo mínimo detectado: 1.2 A

=== VERIFICANDO SEGURIDAD ===
- [ALERTA] Motor 4 supera el umbral crítico con 4.8 A.
- [ALERTA] Motor 8 supera el umbral crítico con 5.5 A.

=== RECALIBRACIÓN ===
- Sistema: Motor 4 actualizado correctamente a 2.8 A.

## 💻 Menú del Sistema
========================================
### SISTEMA DE CONTROL DE TORQUE v1.0
========================================
1. **Registrar corrientes iniciales**
2. **Mostrar estado de la red (10 ejes)**
3. **Calcular consumo promedio total**
4. **Identificar esfuerzos extremos (Max y Min)**
5. **Verificar sobrecargas críticas (>4.5A)**
6. **Recalibrar motor específico**
Q. **Finalizar sistema**


## 🚀 Instalación y Ejecución

### Prerrequisitos
- **Visual Studio 2022** (Community Edition es suficiente)
- **Componente de desarrollo en C++/CLI** (instalado con el workload "Desarrollo de escritorio con C++")

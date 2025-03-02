https://github.com/Dalvelac/Grupo-de-Rubik/

# 🧩 Simulador de Cubo de Rubik

Este proyecto es un **simulador del Cubo de Rubik 3x3**, desarrollado en **C++**, que permite realizar movimientos y visualizar el estado actual del cubo en consola.

## 📌 Características
- Simulación completa del **Cubo de Rubik 3x3**.
- Permite ejecutar secuencias de movimientos como `R U R' U'` y ver su efecto.
- Soporte para **todos los movimientos básicos** (`U, D, F, B, R, L` y sus variaciones `'` y `2`).
- Representación interna del estado del cubo con aristas y esquinas.
- Implementado en **C++** con una arquitectura modular.

## 🚀 Instalación y Compilación

### 1️⃣ Clonar el repositorio:

git clone https://github.com/Dalvelac/Grupo-de-Rubik
cd Grupo-de-Rubik

### 2️⃣ Compilar con CMake:

Si usas CLion simplemente abre el proyecto y ejecuta Build.
Si usas terminal, compila con:

mkdir -p build
cd build
cmake ..
make

### 3️⃣ Ejecutar el programa

### 📖 Uso

Al ejecutar el programa, puedes ingresar una secuencia de movimientos para mezclar el cubo:
```
Ingrese secuencia de movimientos (ej: R U R' U'):
```
Ejemplo:
```
R U R' U' F2 D2 L'
```
Luego, se imprimirá el estado del cubo en consola.

# 📂 Estructura del Proyecto
```
Proyecto/
 ├── include/              # Archivos de cabecera (.h)
 │    ├── EstadoCubo.h
 │    ├── Move.h
 │    ├── RubikCube.h
 ├── src/                  # Implementaciones (.cpp)
 │    ├── EstadoCubo.cpp
 │    ├── Move.cpp
 │    ├── RubikCube.cpp
 ├── main.cpp              # Punto de entrada del programa
 ├── CMakeLists.txt        # Configuración de CMake
 ├── README.md             # Documentación
```

### ✨ Posibles Mejoras

    Implementar un solucionador automático para resolver el cubo desde cualquier estado.
    Agregar una interfaz gráfica en OpenGL o SDL para una mejor visualización.
    Soporte para otras variantes de cubos como 2x2 o 4x4.

### 🤝 Contribuciones

Si deseas contribuir, haz un fork del repositorio y abre un Pull Request con tus mejoras. 🚀

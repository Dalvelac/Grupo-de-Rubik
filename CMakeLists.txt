cmake_minimum_required(VERSION 3.10)
project(GrupoDeRubik)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir la carpeta de encabezados
include_directories(include)

# Lista de archivos fuente
set(SOURCES
        src/CuboRubik.cpp
        src/EstadoCubo.cpp
        src/Movimientos.cpp
        main.cpp
)

# Generar el ejecutable
add_executable(GrupoDeRubik ${SOURCES})

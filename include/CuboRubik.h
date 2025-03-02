#ifndef RUBIKCUBE_H
#define RUBIKCUBE_H

#include <string>
#include <unordered_map>
#include "EstadoCubo.h"
#include "Movimientos.h"

/**
 * @brief Clase principal que representa un Cubo de Rubik.
 *
 * Contiene:
 * - Un EstadoCubo con la disposición actual (aristas y esquinas).
 * - Un mapa de movimientos (strings como "R", "U", "F", etc.) a sus respectivas transformaciones (Move).
 *
 * Ofrece métodos para:
 * - Inicializar el estado.
 * - Ejecutar movimientos individuales o secuencias de movimientos.
 * - Imprimir el estado resultante.
 */
class RubikCube {
public:
    /**
     * @brief Constructor que inicializa el cubo en estado resuelto (identidad).
     */
    RubikCube();

    /**
     * @brief Aplica un movimiento al estado actual del cubo.
     * @param m Movimiento (permutación + ajustes de orientación).
     */
    void aplicarMovimiento(const Move& m);

    /**
     * @brief Ejecuta una secuencia de movimientos dada en un string (p.ej. "R U R' U'").
     * @param secuencia Cadena con los movimientos separados por espacios.
     */
    void ejecutarMovimientos(const std::string& secuencia);

    /**
     * @brief Imprime el estado actual del cubo (aristas y esquinas) por consola.
     */
    void imprimirEstado();

private:
    /**
     * @brief Inicializa el mapa de movimientos básicos (U, U', U2, R, R', etc.).
     */
    void initMoves();

public:
    EstadoCubo state;  ///< Estado actual del cubo.
    std::unordered_map<std::string, Move> moves;  ///< Mapa de movimientos por nombre.
};

#endif // RUBIKCUBE_H

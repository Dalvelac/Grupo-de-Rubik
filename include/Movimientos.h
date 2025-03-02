#ifndef MOVE_H
#define MOVE_H

#include <array>

/**
 * Estructura que define la transformación que genera un movimiento en el cubo.
 *
 * Contiene:
 * - Permutación de las 12 aristas (edgePerm).
 * - Ajuste de orientación de las 12 aristas (edgeOriAdjust).
 * - Permutación de las 8 esquinas (cornerPerm).
 * - Ajuste de orientación de las 8 esquinas (cornerOriAdjust).
 *
 * Cada giro (ej: U, U', R, R', F, etc.) se modela como un objeto de tipo Move.
 */
struct Move {
    std::array<int, 12> edgePerm{};
    std::array<int, 12> edgeOriAdjust{};
    std::array<int, 8>  cornerPerm{};
    std::array<int, 8>  cornerOriAdjust{};
};

#endif // MOVE_H

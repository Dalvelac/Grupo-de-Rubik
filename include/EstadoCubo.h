#ifndef ESTADOCUBO_H
#define ESTADOCUBO_H

#include <array>

/**
 * Estructura que representa el estado completo del cubo.
 *
 * Contiene la información de las 12 aristas (edges) y las 8 esquinas (corners),
 * así como su orientación correspondiente.
 *
 * - Aristas: índices 0 a 11
 *   0: UF, 1: UR, 2: UB, 3: UL, 4: FR, 5: BR,
 *   6: BL, 7: FL, 8: DF, 9: DR, 10: DB, 11: DL
 *
 * - Esquinas: índices 0 a 7
 *   0: UFR, 1: URB, 2: UBL, 3: ULF,
 *   4: DFR, 5: DRB, 6: DBL, 7: DLF
 *
 * La orientación de las aristas se guarda en edgeOri (valores 0 o 1),
 * mientras que la orientación de las esquinas se guarda en cornerOri (valores 0, 1 o 2).
 */
struct EstadoCubo {
    // Aristas
    std::array<int, 12> edges{};
    std::array<int, 12> edgeOri{};

    // Esquinas
    std::array<int, 8> corners{};
    std::array<int, 8> cornerOri{};
};

#endif // ESTADOCUBO_H

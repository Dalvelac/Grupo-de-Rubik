#include <iostream>
#include "include/CuboRubik.h"

/**
 * @brief Punto de entrada del programa.
 *
 * Solicita al usuario una secuencia de movimientos (por ejemplo: "R U R' U'")
 * y muestra el estado final del cubo tras aplicar dichos movimientos.
 */
int main() {
    RubikCube rubik;

    std::string input;
    std::cout << "Ingrese secuencia de movimientos (ej: R U R' U'):" << std::endl;
    std::getline(std::cin, input);

    rubik.ejecutarMovimientos(input);

    std::cout << "\nEstado final del cubo:\n";
    rubik.imprimirEstado();

    return 0;
}

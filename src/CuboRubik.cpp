#include "../include/CuboRubik.h"

#include <iostream>
#include <sstream>  // Para std::istringstream

// using namespace std; // Opcional; en proyectos grandes se desaconseja, pero a veces se usa.

RubikCube::RubikCube() {
    // Estado identidad: cada pieza en su posición con orientación 0
    for (int i = 0; i < 12; i++) {
        state.edges[i] = i;
        state.edgeOri[i] = 0;
    }
    for (int i = 0; i < 8; i++) {
        state.corners[i] = i;
        state.cornerOri[i] = 0;
    }

    // Se definen todos los movimientos y se guardan en el map "moves"
    initMoves();
}

void RubikCube::initMoves() {
    // --------------------
    // Movimiento U
    {
        Move U;
        U.edgePerm       = {3, 0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11};
        U.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        U.cornerPerm     = {3, 0, 1, 2, 4, 5, 6, 7};
        U.cornerOriAdjust= {0, 0, 0, 0, 0, 0, 0, 0};
        moves["U"] = U;
    }
    {
        Move Uprime;
        Uprime.edgePerm       = {1, 2, 3, 0, 4, 5, 6, 7, 8, 9, 10, 11};
        Uprime.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        Uprime.cornerPerm     = {1, 2, 3, 0, 4, 5, 6, 7};
        Uprime.cornerOriAdjust= {0, 0, 0, 0, 0, 0, 0, 0};
        moves["U'"] = Uprime;
    }
    {
        Move U2;
        U2.edgePerm       = {2, 3, 0, 1, 4, 5, 6, 7, 8, 9, 10, 11};
        U2.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        U2.cornerPerm     = {2, 3, 0, 1, 4, 5, 6, 7};
        U2.cornerOriAdjust= {0, 0, 0, 0, 0, 0, 0, 0};
        moves["U2"] = U2;
    }

    // --------------------
    // Movimiento D
    {
        Move D;
        D.edgePerm       = {0, 1, 2, 3, 4, 5, 6, 7, 11, 8, 9, 10};
        D.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        D.cornerPerm     = {0, 1, 2, 3, 7, 4, 5, 6};
        D.cornerOriAdjust= {0, 0, 0, 0, 0, 0, 0, 0};
        moves["D"] = D;
    }
    {
        Move Dprime;
        Dprime.edgePerm       = {0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 8};
        Dprime.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        Dprime.cornerPerm     = {0, 1, 2, 3, 5, 6, 7, 4};
        Dprime.cornerOriAdjust= {0, 0, 0, 0, 0, 0, 0, 0};
        moves["D'"] = Dprime;
    }
    {
        Move D2;
        D2.edgePerm       = {0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 8, 9};
        D2.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        D2.cornerPerm     = {0, 1, 2, 3, 6, 7, 4, 5};
        D2.cornerOriAdjust= {0, 0, 0, 0, 0, 0, 0, 0};
        moves["D2"] = D2;
    }

    // --------------------
    // Movimiento F
    {
        Move F;
        F.edgePerm       = {7, 1, 2, 3, 0, 5, 6, 8, 4, 9, 10, 11};
        F.edgeOriAdjust  = {1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0};
        F.cornerPerm     = {3, 1, 2, 7, 0, 5, 6, 4};
        F.cornerOriAdjust= {1, 0, 0, 2, 2, 0, 0, 1};
        moves["F"] = F;
    }
    {
        Move Fprime;
        Fprime.edgePerm       = {4, 1, 2, 3, 8, 5, 6, 0, 7, 9, 10, 11};
        Fprime.edgeOriAdjust  = {1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0};
        Fprime.cornerPerm     = {4, 1, 2, 0, 7, 5, 6, 3};
        Fprime.cornerOriAdjust= {2, 0, 0, 1, 1, 0, 0, 2};
        moves["F'"] = Fprime;
    }
    {
        Move F2;
        F2.edgePerm       = {8, 1, 2, 3, 7, 5, 6, 4, 0, 9, 10, 11};
        F2.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        F2.cornerPerm     = {7, 1, 2, 4, 3, 5, 6, 0};
        F2.cornerOriAdjust= {0, 0, 0, 0, 0, 0, 0, 0};
        moves["F2"] = F2;
    }

    // --------------------
    // Movimiento B
    {
        Move B;
        B.edgePerm       = {0, 1, 6, 3, 4, 2, 10, 7, 8, 9, 5, 11};
        B.edgeOriAdjust  = {0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0};
        B.cornerPerm     = {0, 2, 6, 3, 4, 1, 5, 7};
        B.cornerOriAdjust= {0, 2, 1, 0, 0, 1, 2, 0};
        moves["B"] = B;
    }
    {
        Move Bprime;
        Bprime.edgePerm       = {0, 1, 5, 3, 4, 10, 2, 7, 8, 9, 6, 11};
        Bprime.edgeOriAdjust  = {0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0};
        Bprime.cornerPerm     = {0, 5, 1, 3, 4, 6, 2, 7};
        Bprime.cornerOriAdjust= {0, 1, 2, 0, 0, 2, 1, 0};
        moves["B'"] = Bprime;
    }
    {
        Move B2;
        B2.edgePerm       = {0, 1, 10, 3, 4, 6, 5, 7, 8, 9, 2, 11};
        B2.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        B2.cornerPerm     = {0, 6, 5, 3, 4, 2, 1, 7};
        B2.cornerOriAdjust= {0, 0, 0, 0, 0, 0, 0, 0};
        moves["B2"] = B2;
    }

    // --------------------
    // Movimiento R
    {
        Move R;
        R.edgePerm       = {0, 4, 2, 3, 9, 1, 6, 7, 8, 5, 10, 11};
        R.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        R.cornerPerm     = {4, 0, 2, 3, 5, 1, 6, 7};
        R.cornerOriAdjust= {2, 1, 0, 0, 1, 2, 0, 0};
        moves["R"] = R;
    }
    {
        Move Rprime;
        Rprime.edgePerm       = {0, 5, 2, 3, 1, 9, 6, 7, 8, 4, 10, 11};
        Rprime.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        Rprime.cornerPerm     = {1, 5, 2, 3, 0, 4, 6, 7};
        Rprime.cornerOriAdjust= {1, 2, 0, 0, 2, 1, 0, 0};
        moves["R'"] = Rprime;
    }
    {
        Move R2;
        R2.edgePerm       = {0, 9, 2, 3, 5, 4, 6, 7, 8, 1, 10, 11};
        R2.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        R2.cornerPerm     = {5, 4, 2, 3, 1, 0, 6, 7};
        R2.cornerOriAdjust= {0, 0, 0, 0, 0, 0, 0, 0};
        moves["R2"] = R2;
    }

    // --------------------
    // Movimiento L
    {
        Move L;
        L.edgePerm       = {0, 1, 2, 7, 4, 5, 3, 11, 8, 9, 10, 6};
        L.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        L.cornerPerm     = {0, 1, 6, 2, 4, 5, 7, 3};
        L.cornerOriAdjust= {0, 0, 2, 1, 0, 0, 1, 2};
        moves["L"] = L;
    }
    {
        Move Lprime;
        Lprime.edgePerm       = {0, 1, 2, 6, 4, 5, 11, 3, 8, 9, 10, 7};
        Lprime.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        Lprime.cornerPerm     = {0, 1, 3, 7, 4, 5, 2, 6};
        Lprime.cornerOriAdjust= {0, 0, 1, 2, 0, 0, 2, 1};
        moves["L'"] = Lprime;
    }
    {
        Move L2;
        L2.edgePerm       = {0, 1, 2, 11, 4, 5, 7, 6, 8, 9, 10, 3};
        L2.edgeOriAdjust  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        L2.cornerPerm     = {0, 1, 7, 6, 4, 5, 3, 2};
        L2.cornerOriAdjust= {0, 0, 0, 0, 0, 0, 0, 0};
        moves["L2"] = L2;
    }
}

void RubikCube::aplicarMovimiento(const Move& m) {
    EstadoCubo nuevo;
    // Actualiza las aristas
    for (int i = 0; i < 12; i++) {
        nuevo.edges[i]    = state.edges[m.edgePerm[i]];
        nuevo.edgeOri[i]  = (state.edgeOri[m.edgePerm[i]] + m.edgeOriAdjust[i]) % 2;
    }
    // Actualiza las esquinas
    for (int i = 0; i < 8; i++) {
        nuevo.corners[i]   = state.corners[m.cornerPerm[i]];
        nuevo.cornerOri[i] = (state.cornerOri[m.cornerPerm[i]] + m.cornerOriAdjust[i]) % 3;
    }
    state = nuevo;
}

void RubikCube::ejecutarMovimientos(const std::string& secuencia) {
    std::istringstream iss(secuencia);
    std::string token;
    while (iss >> token) {
        if (moves.find(token) != moves.end()) {
            aplicarMovimiento(moves[token]);
        } else {
            std::cout << "Movimiento desconocido: " << token << std::endl;
        }
    }
}

void RubikCube::imprimirEstado() {
    std::cout << "Estado de las aristas:\n";
    for (int i = 0; i < 12; i++) {
        std::cout << "Posicion " << i << " -> Pieza " << state.edges[i]
                  << " (Ori: " << state.edgeOri[i] << ")\n";
    }

    std::cout << "\nEstado de las esquinas:\n";
    for (int i = 0; i < 8; i++) {
        std::cout << "Posicion " << i << " -> Pieza " << state.corners[i]
                  << " (Ori: " << state.cornerOri[i] << ")\n";
    }
}

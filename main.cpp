#include <iostream>
#include <fstream>
#include "Matrice.h"
#include "Matrice_Implementare.cpp"

int main() {

    // M3 = matrice 3x3
    // M4 = matrice 4x4
    Matrice<float> M3;
    Matrice<int> M4_A, M4_B;
    std::ifstream f("..//date.in");

    f >> M3;
    f >> M4_A >> M4_B;

    std::cout << "Matricele sunt:\nM3:\n" << M3 << "\nM4_A:\n" << M4_A << "\nM4_B\n" << M4_B;

    std::cout << "Operatii cu M4:\n";
    std::cout << "Suma (M4_A + M4_B) :\n" << M4_A + M4_B << '\n';
    std::cout << "Diferenta (M4_A - M4_B):\n" << M4_A - M4_B << '\n';
    std::cout << "Inmultire (M4_A * M4_B):\n" << M4_A * M4_B << '\n';
    std::cout << "Inmultire cu scalar (M4_A * 2):\n" << M4_A * 2 << '\n';
    std::cout << "Determinanti:\n";
    std::cout << "det(M4_A): " << M4_A.determinant() << '\n';
    std::cout << "det(M4_B): " << M4_B.determinant() << '\n';
    std::cout << "det(M3): " << M3.determinant() << '\n';
    std::cout << "\nInversabile? \n";
    std::cout << "inv(M3) = " << (M3.inversabila() ? "DA" : "NU");
    std::cout << "\ninv(M4_A) = " << (M4_A.inversabila() ? "DA" : "NU");
    std::cout << "\ninv(M4_B) = " << (M4_B.inversabila() ? "DA" : "NU");
    std::cout << "\n\nSelectare element linie coloana (M3[0][2]) = " << M3[0][2];
    std::cout << "\nNr linii M3 = " << M3.getLinii();
    std::cout << "\nNr coloane M4_A = " << M4_A.getColoane();

    return 0;
}
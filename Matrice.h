#ifndef MATRICEWITHTEMPLATES_MATRICE_H
#define MATRICEWITHTEMPLATES_MATRICE_H

#include <iostream>

template<class T>
class Matrice {
private:
    int nrLinii;
    int nrColoane;
    T **matrice;

public:

    Matrice();

    ~Matrice();

    Matrice(int n, int m);

    Matrice(const Matrice<T> &m);

    template<class U>
    friend std::istream &operator>>(std::istream &is, Matrice<U> &m);

    template<class U>
    friend std::ostream &operator<<(std::ostream &os, const Matrice<U> &m);

    Matrice<T> operator=(const Matrice<T> &m);

    Matrice<T> &operator+(Matrice<T> &m);

    Matrice<T> &operator-(Matrice<T> &m);

    Matrice<T> &operator*(Matrice<T> &m);

    Matrice<T> &operator*(int scalar);

    T *operator[](int);

    double determinant();

    void copiere(Matrice<T> &m);

    void rangInferior(int linie, int coloana);

    bool inversabila();

    int getLinii();

    int getColoane();
};

#endif //MATRICEWITHTEMPLATES_MATRICE_H

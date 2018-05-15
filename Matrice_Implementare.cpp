#include "Matrice.h"

template<class T>
Matrice<T>::Matrice() {
    // Inititalizam matricea cu 0 elemente
    nrLinii = 0;
    nrColoane = 0;
    matrice = NULL;
}

template<class T>
Matrice<T>::~Matrice() {
    // Dealocam memoria
    for (int i = 0; i < nrLinii; i++)
        delete[] matrice[i];
    delete[] matrice;
}

template<class T>
Matrice<T>::Matrice(int const n, int const m) {
    // Alocam memorie pentru o matrice cu n linii si m coloane
    nrLinii = n;
    nrColoane = m;

    matrice = new T *[nrLinii];
    for (int i = 0; i < nrLinii; i++)
        matrice[i] = new T[nrColoane + 1];

    for (int i = 0; i < nrLinii; i++) {
        for (int j = 0; j < nrColoane; j++) {
            matrice[i][j] = 0;
        }
    }
}

template<class T>
Matrice<T>::Matrice(const Matrice<T> &m) {
    // Copiem continutul matricii 'm' in this
    nrLinii = m.nrLinii;
    nrColoane = m.nrColoane;

    matrice = new int *[nrLinii];
    for (int i = 0; i < nrLinii; i++)
        matrice[i] = new int[nrColoane + 1];

    for (int i = 0; i < nrLinii; i++) {
        for (int j = 0; j < nrColoane; j++) {
            matrice[i][j] = m.matrice[i][j];
        }
    }
}

template<class T>
std::istream &operator>>(std::istream &is, Matrice<T> &m) {
    // Citim o matrice sub forma
    // nrLinii nrColoane
    // a00 a01 a02 ... a(0, nrColoane)
    // a10 a11 a12 ... a(1, nrColoane)
    // ..............................
    // a(nrLinii,0) ... a(nrLinii,nrColoane)
    is >> m.nrLinii;
    is >> m.nrColoane;

    m.matrice = new T *[m.nrLinii];
    for (int i = 0; i < m.nrLinii; i++)
        m.matrice[i] = new T[m.nrColoane + 1];

    for (int i = 0; i < m.nrLinii; i++) {
        for (int j = 0; j < m.nrColoane; j++) {
            is >> m.matrice[i][j];
        }
    }
    return is;
}

template<class T>
std::ostream &operator<<(std::ostream &output, const Matrice<T> &m) {
    // Scriem o matrice sub forma
    // a00 a01 a02 ... a(0, nrColoane)
    // a10 a11 a12 ... a(1, nrColoane)
    // ..............................
    // a(nrLinii,0) ... a(nrLinii,nrColoane)
    for (int i = 0; i < m.nrLinii; i++) {
        for (int j = 0; j < m.nrColoane; j++) {
            output << m.matrice[i][j] << " ";
        }
        output << std::endl;
    }
    return output;
}

template<class T>
Matrice<T> Matrice<T>::operator=(const Matrice<T> &m) {
    // Copiem continutul matricii 'm' in this
    nrLinii = m.nrLinii;
    nrColoane = m.nrColoane;

    matrice = new T *[nrLinii];
    for (int i = 0; i < nrLinii; i++)
        matrice[i] = new T[nrColoane + 1];

    for (int i = 0; i < nrLinii; i++) {
        for (int j = 0; j < nrColoane; j++) {
            matrice[i][j] = m.matrice[i][j];
        }
    }
}

template<class T>
Matrice<T> &Matrice<T>::operator+(Matrice<T> &m) {
    // Adunarea a doua matrici de dimensiuni egale
    Matrice<T> *temp = new Matrice<T>(nrLinii, nrColoane);
    if (nrLinii == m.nrLinii && nrColoane == m.nrColoane) {
        for (int i = 0; i < nrLinii; i++) {
            for (int j = 0; j < nrColoane; j++) {
                temp->matrice[i][j] = matrice[i][j] + m.matrice[i][j];
            }
        }
    }
    return *temp;
}

template<class T>
Matrice<T> &Matrice<T>::operator-(Matrice<T> &m) {
    // Scaderea a doua matrici de dimensiuni egale
    Matrice *temp = new Matrice<T>(nrLinii, nrColoane);
    if (nrLinii == m.nrLinii && nrColoane == m.nrColoane) {
        for (int i = 0; i < nrLinii; i++) {
            for (int j = 0; j < nrColoane; j++) {
                temp->matrice[i][j] = matrice[i][j] - m.matrice[i][j];
            }
        }
    }
    return *temp;
}

template<class T>
Matrice<T> &Matrice<T>::operator*(Matrice<T> &m) {
    // Inmultirea a doua matrici ca la matematica
    Matrice<T> *temp = new Matrice<T>(nrLinii, m.nrColoane);
    if (nrColoane == m.nrLinii) {
        for (int i = 0; i < nrLinii; i++)
            for (int j = 0; j < m.nrColoane; j++) {
                temp->matrice[i][j] = 0;
                for (int k = 0; k < nrColoane; k++) {
                    temp->matrice[i][j] += matrice[i][k] * m.matrice[k][j];
                }
            }
    }
    return *temp;
}

template<class T>
Matrice<T> &Matrice<T>::operator*(int scalar) {
    // Inmultirea unei matrici cu scalar
    Matrice<T> *temp = new Matrice<T>(nrLinii, nrColoane);
    for (int i = 0; i < nrLinii; i++) {
        for (int j = 0; j < nrColoane; j++) {
            temp->matrice[i][j] = matrice[i][j] * scalar;
        }
    }
    return *temp;
}

template<class T>
T *Matrice<T>::operator[](int linie) {
    // Utilizat pentru a putea selecta un element prin M[i][j]
    return matrice[linie];
}

template<class T>
void Matrice<T>::copiere(Matrice<T> &m) {
    // Functie helper utilizata cand nu putem utiliza operatorul egal in anumite functii din clasa
    nrLinii = m.nrLinii;
    nrColoane = m.nrColoane;

    matrice = new T *[nrLinii];
    for (int i = 0; i < nrLinii; i++)
        matrice[i] = new T[nrColoane + 1];

    for (int i = 0; i < nrLinii; i++) {
        for (int j = 0; j < nrColoane; j++) {
            matrice[i][j] = m.matrice[i][j];
        }
    }
}

template<class T>
void Matrice<T>::rangInferior(int linie, int coloana) {
    // Cream o noua matrice fara linia 'linie' si coloana 'coloana'
    Matrice<T> *temp = new Matrice<T>(nrLinii - 1, nrColoane -1);
    int k = 0, m = 0;
    for (int i = 0; i < nrLinii; i++) {
        k = 0;
        if (i == linie) continue;
        for (int j = 0; j < nrColoane; j++) {
            if (j == coloana) continue;
            temp->matrice[m][k] = matrice[i][j];
            k++;
        }
        m++;
    }
    this->copiere(*temp);
}

template<class T>
double Matrice<T>::determinant() {
    // Calculam determinantul unei matrici ca la matematica
    // Daca este 2x2 atunci este simplu
    // Daca este mai mare atunci dezvoltam fiecare element de pe prima linie
    if (nrLinii == nrColoane) {
        double det = 0;
        if (nrLinii == 2) {
            det = matrice[0][0] * matrice[1][1] - matrice[0][1] * matrice[1][0];
            return det;
        }

        for (int j = 0; j < nrColoane; j++) {
            Matrice<T> temp(nrLinii, nrColoane);
            temp.copiere(*this);
            temp.rangInferior(0, j);
            int p;
            if (j % 2 == 0) p = 1;
            else p = -1;
            det += p * matrice[0][j] * temp.determinant();
        }
        return det;
    }
}

template<class T>
bool Matrice<T>::inversabila() {
    // Daca determinantul diferit de 0 atunci este inversabila
    return (determinant() != 0) ? true : false;
}

template<class T>
int Matrice<T>::getLinii() {
    return nrLinii;
}

template<class T>
int Matrice<T>::getColoane() {
    return nrColoane;
}
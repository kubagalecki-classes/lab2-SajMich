#include <iostream>

class Wektor
{
public:
    // konstruktor parametryczny
    Wektor(int n) : dlugosc(n), pojemnosc(n)
    {
        w = new double[dlugosc];
        for (int i = 0; i < dlugosc; i++) {
            w[i] = 0;
        }
        std::cout << "konstruktor parametryczny"
                  << "\n";
    }

    // konstruktor kopiujacy
    Wektor(const Wektor& W) : dlugosc(W.dlugosc), pojemnosc(W.pojemnosc)
    {
        w = new double[dlugosc];
        w = W.w;
        std::cout << "Konstruktor kopiujacy"
                  << "\n";
    }

    // konstruktor przenoszacy
    Wektor(Wektor&& W) : w(nullptr), dlugosc(0), pojemnosc(0)
    {
        w           = W.w;
        dlugosc     = W.dlugosc;
        pojemnosc   = W.pojemnosc;
        W.w         = nullptr;
        W.dlugosc   = 0;
        W.pojemnosc = 0;
        std::cout << "Konstruktotr przenoszacy"
                  << "\n";
    }

    // destruktor
    ~Wektor()
    {
        delete[] w;
        std::cout << "destruktor"
                  << "\n";
    }

    int get() { return dlugosc; };

    void print()
    {
        std::cout << "Wektor: "
                  << "\n";
        for (int i = 0; i < dlugosc; i++) {
            std::cout << w[i] << "\n";
        }
    }

    // zmiana dlugosci
    void zmienDlugosc(int m)
    {
        if (m <= pojemnosc) {
            dlugosc = m;
            for (int i = m; i < pojemnosc; i++) {
                w[i] = 0;
            }
        }

        else {
            double* tmp = new double[m];
            for (int i = 0; i < dlugosc; i++) {
                tmp[i] = w[i];
            }
            for (int i = dlugosc; i < m; i++) {
                tmp[i] = 0;
            }
            delete[] w;
            w         = tmp;
            dlugosc   = m;
            pojemnosc = m;
        }
    }

    // przeciazanie operatorow
    double& operator[](int);
    Wektor& operator=(const Wektor&);
    Wektor& operator=(Wektor&&);

private:
    int     dlugosc;
    int     pojemnosc;
    double* w;
};

// przeciazanie operatora []
double& Wektor::operator[](int index)
{
    if (index >= dlugosc) {
        zmienDlugosc(index);
    }
    return w[index];
}
// kopiujacy operator przypisania =
Wektor& Wektor::operator=(const Wektor& W)
{
    if (this != &W) {
        delete w;
        dlugosc   = W.dlugosc;
        pojemnosc = W.pojemnosc;
        w         = new double[dlugosc];
        for (int i = 0; i < W.dlugosc; i++) {
            w[i] = W.w[i];
        }
    }
    return *this;
}

// przenoszacy opertor przypisania
Wektor& Wektor::operator=(Wektor&& W)
{
    w         = std::move(W.w);
    dlugosc   = std::move(W.dlugosc);
    pojemnosc = std::move(W.pojemnosc);
    return *this;
}

int main()
{
    Wektor v1{2};
    v1[0] = 10;
    v1[1] = 6;
    v1.print();
    std::cout << "liczba elementow: " << v1.get() << "\n";
}

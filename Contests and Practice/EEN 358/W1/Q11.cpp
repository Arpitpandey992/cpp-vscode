#include <iostream>
using namespace std;
struct complex {
    double real;
    double img;
    complex(double r, double i) {
        real = r;
        img = i;
    }
};
complex* add_cmplx(complex* c1, complex* c2) {
    double r = c1->real + c2->real;
    double i = c1->img + c2->img;
    return new complex(r, i);
}
complex* mult_cmplx(complex* c1, complex* c2) {
    double r = (c1->real * c2->real) - (c1->img * c2->img);
    double i = c1->real * c2->img + c1->img * c2->real;
    return new complex(r, i);
}
complex* div_cmplx(complex* c1, complex* c2) {
    double r = ((c1->real * c2->real) + (c1->img * c2->img)) / (c2->real * c2->real + c2->img * c2->img);
    double i = (-(c1->real * c2->img) + (c1->img * c2->real)) / (c2->real * c2->real + c2->img * c2->img);
    return new complex(r, i);
}
complex* Negate(complex* c) {
    return new complex(c->real, c->img * (-1));
}
void print(complex* c) {
    cout << c->real;
    if (c->img == 0) return;
    if (c->img > 0)
        cout << "+";
    cout << c->img << "i" << endl;
}
int main() {
    complex* c1 = new complex(4.2, -3.1);
    complex* c2 = new complex(-3.098, 11.2);
    cout << "c1 = ";
    print(c1);
    cout << "c2 = ";
    print(c2);
    complex* c = add_cmplx(c1, c2);
    cout << "c1+c2 = ";
    print(c);

    c = mult_cmplx(c1, c2);
    cout << "c1*c2 = ";
    print(c);

    c = div_cmplx(c1, c2);
    cout << "c1/c2 = ";
    print(c);

    c = Negate(c1);
    cout << "Conjugate of c1 = ";
    print(c);

    c = Negate(c2);
    cout << "Conjugate of c2 = ";
    print(c);
}

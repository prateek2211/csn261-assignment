#include <iostream>
#include <vector>
using namespace std;
class Polynomial
{
private:
    int degree;
    vector<int> coef;

public:
    Polynomial(int degree) : degree(degree)
    {
        coef.resize(degree + 1, 0);
    }
    void setCoefficient(vector<int> arr)
    {
        coef = arr;
    };
    void printPolynomial()
    {
        for (int i = coef.size() - 1; i > 0; i--)
            if (coef[i] != 0)
                std::cout << coef[i] << "x^" << i << " +";
        if (coef[0] != 0)
            std::cout << coef[0] << "\n";
    }
    Polynomial multiply(Polynomial &p)
    {
        int newDeg = p.degree + degree;
        Polynomial pol(newDeg);
        for (int i = 0; i <= newDeg; i++)
            for (int j = 0; j <= degree && j <= i; j++)
                pol.coef[i] += coef[j] * p.coef[i - j];
        return pol;
    };
    Polynomial add(Polynomial &p)
    {
        int newDeg = p.degree > degree ? p.degree : degree;
        Polynomial pol(newDeg);
        for (int i = 0; i <= pol.degree; i++)
        {
            int a;
            int b;
            a = coef[i];
            b = p.coef[i];
            if (i > p.degree)
                b = 0;
            else if (i > degree)
                a = 0;

            pol.coef[i] = a + b;
        }
        return pol;
    }
};
int main(int argc, char const *argv[])
{
    int d1, d2;
    cout << "No. of terms in the expression: ";
    cin >> d1;
    vector<int> c1(d1);
    Polynomial p1(d1 - 1);
    cout << "Coefficient Power\n";
    for (int i = d1 - 1; i >= 0; i--)
    {
        cout << i << "\t";
        cin >> c1[i];
        cout << endl;
    }
    p1.setCoefficient(c1);
    cout << "No. of terms in the expression: ";
    cin >> d2;
    vector<int> c2(d2);
    Polynomial p2(d2 - 1);
    cout << "Coefficient Power\n";
    for (int i = d2 - 1; i >= 0; i--)
    {
        cout << i << "\t";
        cin >> c2[i];
        cout << endl;
    }
    p2.setCoefficient(c2);
    cout << "Enter 1 to add or 2 for multiply\n";
    int o = 1;
    while (o == 1 || o == 2)
    {
        cin >> o;
        if (o == 1)
        {
            p1.multiply(p2).printPolynomial();
        }
        if (o == 2)
        {
            p1.add(p2).printPolynomial();
        }
    }
    return 0;
}
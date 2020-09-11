#include "rational.h"

using ::std::cout;
using std::endl;

int main ()
{
    Rational r2(2, 11), r3(1, -3), r5(18, 6);
    Rational res1 = 3 + r2 * r3;
    Rational res2 = (3 + r2) * r3;
    Rational res3 = 3 + r3 * (r2 + 2) / (r5 - r3);

    cout << 3 << " + " << r2 << " * " <<  r3 << " = " << res1 << endl;
    cout << "(" << 3 << " + " << r2 << ")" << " * " <<  r3 << " = " << res2 << endl;
    cout << 3 << " + " << r3 << " * " << "(" << r2 << " + " << 2 << ")" << "/"
    << "(" << r5 << " - " << r3 << ")" << " = " << res3 << endl;

//    3 + 2/11 * (-1/3) = 97/33
//    (3 + 2/11) * (-1/3) = (-35/33)
//    3 + (-1/3) * (2/11 + 2)/(18/6 - (-1/3)) = 153/55

}

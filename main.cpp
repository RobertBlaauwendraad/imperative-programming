#include <iostream>

using namespace std;


/********************************************************************
    Assignment part 2: Inclusion
********************************************************************/
void inclusion(double epsilon, double v) {
    double an = 0;
    double bn = (v > 1) ? v : 1;
    double xn = (an + bn) / 2;
    int n = 0;
    
    //Check if a0 or b0 are already the square root of v
    if(an * an == v) {
        cout << "Inclusion square root of " << v << " is " << an << '\t' 
            << n << '\t' << an << '\t' << xn << '\t' << bn << endl;
        return;
    } else if(bn * bn == v) {
        cout << "Inclusion square root of " << v << " is " << bn << '\t'
             << n << '\t' << an << '\t' << xn << '\t' << bn << endl;
        return;
    }
    
    //This while loop runs as long as the Halting Criterion is not met
    while(abs((xn * xn) - v) >= epsilon){ 
        if((xn*xn) < v){
            an = xn;
        } else {
            bn = xn;
        }        
        xn = (an + bn) / 2;
        n++;
    }
    cout << "Inclusion square root of " << v << " is " << xn << " for epsilon "
        << epsilon << '\t'  << n << '\t' << an << '\t' << xn << '\t' << bn << endl;
    return;
}

/********************************************************************
    Assignment part 3: Newton-Raphson
********************************************************************/
void newtonraphson(double epsilon, double v) {
    //implement this function
    double xn = (v > 1) ? v : 1;
    int n = 0;

    while(abs((xn * xn) - v) >= epsilon){
        double fx = xn * xn - v;
        double fpx = 2 * xn;
        xn = xn - (fx/fpx);
        n++;
    }
    cout << "Newton-Raphson square root of " << v << " is " << xn << " for epsilon " 
        << epsilon << '\t' << n << '\t' << xn << endl;
}

int main() {
    inclusion(0.1, 20);
    newtonraphson(0.1, 20);

    return 0;
}

/********************************************************************
    Desktop test part 1
v = 0
a0 = 0
b0 = max(0,1) = 1
a0 * a0 = v, a0 is the result

---------

v = 1
a0 = 0
b0 = 1
b0 * b0 = v, b0 is the result

---------

v = 0.5
a0 = 0
b0 = 1
x0 = (0+1)/2 = 0.5
|0.5 * 0.5 - 0.5| = 0.25

a1 = 0.5
b1 = 1
x1 = 0.75
|0.75 * 0.75 - 0.5| = 0.0625
0.0625 <= 0.1 so 0.75 is the result

---------

v = 16
a0 = 0
b0 = max(1,16) = 16
x0 = 8
|8 * 8 - 16| = 48

a1 = 0
b1 = 8
x1 = 4
|4 * 4 - 16| = 0
0 <= 0.1 so 4 is the result

---------

v = 20
a0 = 0
b0 = max(1,20) = 20
x0 = (0+20)/2 = 10
|10 * 10 - 20| = 80

a1 = 0
b1 = 10
x1 = 5
|25-20| = 5

a2 = 0
b2 = 5
x2 = 2.5
|6.25-20|=13.75

.
.
.
.

a8 = 4.453125
b8 = 4.53125
x8 = 4.4921875
|4.4921875*4.4921875-20|=0.17974...

a9 = 4.453125
b9 = 4.4921875
x8 = 4.47265175
|4.47265175*4.47265175-20|=0.0004... <= 0.1
So result is 4.47265175

********************************************************************/

/********************************************************************
 * Desktop test part 4
 * ---------
 * 
 * v = 0
 * Inclusion square root of 0 is 0 0       0       0.5     1
 * Newton-Raphson square root of 0 is 0.25 for epsilon 0.1 2       0.25
 * 
 * v = 1
 * Inclusion square root of 1 is 1 0       0       0.5     1
 * Newton-Raphson square root of 1 is 1 for epsilon 0.1    0       1
 * 
 * v = 0.5
 * Inclusion square root of 0.5 is 0.75 for epsilon 0.1    1       0.5     0.75    1
 * Newton-Raphson square root of 0.5 is 0.75 for epsilon 0.1       1       0.75
 * 
 * v = 16
 * Inclusion square root of 16 is 4 for epsilon 0.1        1       0       4       8
 * Newton-Raphson square root of 16 is 4.00226 for epsilon 0.1     4       4.00226
 * 
 * v = 20
 * Inclusion square root of 20 is 4.47266 for epsilon 0.1  9       4.45312 4.47266 4.49219
 * Newton-Raphson square root of 20 is 4.47831 for epsilon 0.1     4       4.47831
********************************************************************/

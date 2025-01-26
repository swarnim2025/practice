#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define ld  long double 

ld f_x(ld x) {
    ld res = 2.0*(x * x * x) - 2.5*x -5.0;
    // ld res=-x*x+25;
    return res;
}


ld d_x(ld x) {
    ld res =6*x*x-2.5;
    // ld res=-x*x+25;
    return res;
}



 

int main(){

ld x0=1.0;
ld x1=2.0;
ld epsilon=0.0001;
ld  x2=x1-(f_x(x1)/d_x(x1));


ld curr_epsilon=fabs(x2-x1)/x2;


    cout << setprecision(15) << fixed;

    // Print the table header
    cout << setw(10) << "Iter"
         << setw(20) << "x0"
         << setw(20) << "x1"
         << setw(20) << "x2"
         << setw(20) << "Epsilon"
         << setw(20) << "f(x2)" << endl;

int maxiter=100;
int curr_it=0;
while(curr_epsilon>epsilon && curr_it<maxiter){
cout << setw(10) << curr_it
         << setw(20) << x0
         << setw(20) << x1
         << setw(20) << x2
         << setw(20) << curr_epsilon
         << setw(20) << f_x(x2 )<< endl;


x0=x1;
x1=x2;
x2=x1-(f_x(x1)/d_x(x1));
curr_epsilon=fabs(x2-x1)/x2;
curr_it++;

}
cout << setw(10) << curr_it
         << setw(20) << x0
         << setw(20) << x1
         << setw(20) << x2
         << setw(20) << curr_epsilon
         << setw(20) << f_x(x2 )<< endl;






}

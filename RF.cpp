#include <bits/stdc++.h>
#include <iostream>
#include <iomanip> // For table formatting
#include <cmath>   // For fabs()
using namespace std;
# define debug(x)  cout<<#x<<" = "<<x<<endl;
#define ld long double
#define ll long long

// Function to evaluate f(x)
ld f_x(ld x) {
    ld res = 2.0*(x * x * x) - 2.5*x -5.0;
    // ld res=-x*x+25;
    return res;
}

int main() {
    ld l = 1.0, r = 2.0;
    ld epsilon = 0.0001; // Convergence tolerance
    ld mid = l - 100;    // Initial mid value
    ld curr_epsilon = 500.0; // Initial epsilon
    ld prev;            // Store previous mid value
    ll iterations = 100; // Maximum allowed iterations
    ll curr_it = 0;      // Iteration counter

    // Set precision for floating-point numbers
    cout << setprecision(15) << fixed;

    // Print the table header
    cout << setw(10) << "Iter"
         << setw(20) << "Left"
         << setw(20) << "Right"
         << setw(20) << "Midpoint"
         << setw(20) << "Epsilon"
         << setw(20) << "f(Midpoint)" << endl;

    // Check if root lies within the interval
    if (f_x(l) != 0.0 && f_x(r) != 0.0) {
        while (l < r && curr_epsilon > epsilon && curr_it <= iterations) {
            prev = mid;
            mid = (fabs(f_x(r))*l + r*fabs(f_x(l)))/(fabs(f_x(l))+fabs(f_x(r)));
            // debug(mid);
            curr_epsilon = fabs((mid - prev) / mid);

            // Print the current iteration data
            cout << setw(10) << curr_it+1
                 << setw(20) << l
                 << setw(20) << r
                 << setw(20) << mid;


if(curr_it==0)
               cout  << setw(22) << "..........";
               else cout<<setw(22)<<curr_epsilon;
               cout  << setw(25) << f_x(mid) << endl;

            // Check if we found the root
            if (f_x(mid) == 0.0) {
               
                break;
            }

            // Update bounds based on f(mid)
            if (f_x(mid) * f_x(r) < 0 ) {
                l = mid;
          
            }
             else {
                r = mid;
            }

            // Increment iteration counter
            curr_it++;
        }
    }

    return 0;
}

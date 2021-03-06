#include <iostream>
#include <cstdlib>
using namespace std;

template <class T=double> class Solver {
   int size;
   T *x, *y; 
public:
   Solver(double h) {
      size = 1 / h +1;
      x = new T[size];
      y = new T[size];
      x[0] = 0; y[0] = 1;
      for(int i=1; i<size; i++) {
	 x[i] = i * h;
	 y[i] = y[i-1] + (x[i]-x[i-1]) * \
	    (x[i-1] * x[i-1] - 2 * y[i-1]);
      };
   }
   ~Solver(){
         delete [] x;
	 delete [] y;
   }
   void show() {
      for(int i=0; i<size; i++) cout << "y("\
	 << x[i] << ") = " << y[i] << "\n";
   }
};

template <class T=double> class Solver_coeff {
   int size;
   T *x, *y; 
public:
   Solver_coeff(double h, double a, double b, double c) {
      size = 1 / h + 1;
      x = new T[size];
      y = new T[size];
      x[0] = 0; y[0] = 1;
      for(int i=1; i<size; i++) {
	 x[i] = i * h;
	 y[i] = y[i-1] + (x[i]-x[i-1]) * \
	    (a* x[i-1] * x[i-1] + b * y[i-1] +c);
      };
   }
   ~Solver_coeff(){
         delete [] x;
	 delete [] y;
   }
   void show() {
      for(int i=0; i<size; i++) cout << "y("\
	 << x[i] << ") = " << y[i] << "\n";
   }
};



int main() {
   double step, a, b, c;
   cin >> step >> a >> b >> c;
   Solver<> sol1(step);
   sol1.show();
   Solver_coeff<> sol2(step, a, b, c);
   sol2.show();
   return 0;
};

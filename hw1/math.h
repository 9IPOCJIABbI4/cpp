#include <iostream>
using namespace std;

const int n = 3;

class matrix;

class vec {
   double a[n];
public:
   vec() { 
      int i;
      for(i=0; i<n; i++) a[i] = 0;
   }

   vec operator+(vec v2);
   vec operator-(vec v2);

   double operator*(vec v2); //Скалярное умножение

   friend vec operator*(matrix mat, vec v);

   friend ostream &operator<<(ostream &stream, vec v);
   friend istream &operator>>(istream &stream, vec &v);
};

class matrix {
   double m[n][n];
public:
   matrix() {
      int i, j;
      for(i=0; i<n; i++) {
	 for(j=0; j<n; j++) m[i][j] = 0;
      }
   }

   matrix operator+(matrix mat2);
   matrix operator-(matrix mat2);

   matrix operator*(matrix mat2);

   friend vec operator*(matrix mat, vec v);

   friend ostream &operator<<(ostream &stream, matrix mat);
   friend istream &operator>>(istream &stream, matrix &mat);
}; 

class comp_num {
   double re, im;
public:
   comp_num() {
      re = im = 0;
   }

   comp_num operator+(comp_num cn2);
   comp_num operator-(comp_num cn2);

   comp_num operator*(comp_num cn2);
   comp_num operator/(comp_num cn2);

   friend ostream &operator<<(ostream &stream, comp_num cn);
   friend istream &operator>>(istream &stream, comp_num &cn);
};

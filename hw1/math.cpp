#include "math.h"
#include <iostream>

using namespace std;

vec vec::operator+(vec v2)
{
   vec temp;
   int i;

   for(i=0; i<n; i++) {
      temp.a[i] = a[i] + v2.a[i];
   };

   return temp;
}

vec vec::operator-(vec v2)
{
   vec temp;
   int i;

   for(i=0; i<n; i++) {
      temp.a[i] = a[i] - v2.a[i];
   };

   return temp;
}

double vec::operator*(vec v2)
{
   double temp;
   int i;

   temp = 0;

   for(i=0; i<n; i++) {
      temp += a[i] * v2.a[i];
   };

   return temp;
}

matrix matrix::operator+(matrix mat2)
{
   matrix temp;
   int i,j;

   for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
         temp.m[i][j] = m[i][j] + mat2.m[i][j];
      };
   };

   return temp;
}

matrix matrix::operator-(matrix mat2)
{
   matrix temp;
   int i,j;

   for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
         temp.m[i][j] = m[i][j] - mat2.m[i][j];
      };
   };

   return temp;
}

matrix matrix::operator*(matrix mat2)
{
   matrix temp;
   int i,j,k;

   for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
	 temp.m[i][j] = 0;
	 for(k=0; k<n; k++) {
            temp.m[i][j] += m[i][k] * mat2.m[k][j];
	 };
      };
   };

   return temp;
}

vec operator*(matrix mat, vec v)
{
   vec temp;
   int i,j;

   for(i=0; i<n; i++) {
      temp.a[i] = 0;
      for(j=0; j<n; j++) {
         temp.a[i] += mat.m[i][j] * v.a[j];
      };
   };

   return temp;
};

comp_num comp_num::operator+(comp_num cn2) 
{
   comp_num temp;

   temp.re = re + cn2.re;
   temp.im = im + cn2.im;

   return temp;
}

comp_num comp_num::operator-(comp_num cn2) 
{
   comp_num temp;

   temp.re = re - cn2.re;
   temp.im = im - cn2.im;

   return temp;
}

comp_num comp_num::operator*(comp_num cn2) 
{
   comp_num temp;

   temp.re = re * cn2.re - im * cn2.im;
   temp.im = re * cn2.im + im * cn2.re;

   return temp;
}

comp_num comp_num::operator/(comp_num cn2) 
{
   comp_num temp;

   temp.re = (re * cn2.re + im * cn2.im) / \
	     (cn2.re * cn2.re + cn2.im * cn2.im);
   temp.im = (im * cn2.re - re * cn2.im) / \
	     (cn2.re * cn2.re + cn2.im * cn2.im);
   return temp;
}

ostream &operator<<(ostream &stream, vec v)
{
   int i;

   for (i=0; i<n-1; i++) stream << v.a[i] << ", ";
   stream << v.a[n-1] << "\n";

   return stream; 
}

istream &operator>>(istream &stream, vec &v)
{
   int i;

   cout << "?????????????? ???????????????? ??????????????: ";
   for (i=0; i<n; i++) {
      stream >> v.a[i];
   }; 
   return stream;
}

ostream &operator<<(ostream &stream, matrix mat)
{
   int i, j;

   for (i=0; i<n; i++) {
      for (j=0; j<n-1; j++) stream << mat.m[i][j] << ", ";
      stream << mat.m[i][n-1] << "\n";
   }

   return stream; 
}

istream &operator>>(istream &stream, matrix &mat)
{
   int i, j;

   for (i=0; i<n; i++) {
      cout << "?????????????? " << i+1 << "-?? ???????????? ??????????????: ";
      for (j=0; j<n; j++) {
	 stream >> mat.m[i][j];
      };
   };

   return stream; 
}

ostream &operator<<(ostream &stream, comp_num cn)
{
   stream << cn.re << " + " << cn.im << "i" << "\n";
   return stream; 
}

istream &operator>>(istream &stream, comp_num &cn)
{
  cout << "?????????????? ???????????????????????????? ?????????? ???????????????????????? ??????????: ";
  stream >> cn.re;
  cout << "?????????????? ???????????? ?????????? ???????????????????????? ??????????: ";
  stream >> cn.im;
  return stream;
}


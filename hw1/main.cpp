#include <iostream>
#include "math.h"

using namespace std;

int main()
{
   vec v1, v2;
   matrix mat1, mat2;
   comp_num cn1, cn2;

   cin >> v1 >> v2;
   cout << v1 * v2 << "\n" << v1 + v2;

   cin >> mat1 >> mat2;
   cout << mat1 * mat2 << mat1 + mat2 << mat1 * v1;

   cin >> cn1 >> cn2;
   cout << cn1 * cn2 << cn1 + cn2 << cn1 / cn2;

   return 0;
}

#include <iostream>

using namespace std;

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
 
double* setValues( int i )
{
	double * x = &vals[i];
  return x;
}
int main ()
{
 
   cout << "Value before change" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
 
   double *y;
   y = setValues(1);
   *y = 20.23;
   y = setValues(3);
  *y = 70.8;
 
   cout << "Value after change" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
   return 0;
}
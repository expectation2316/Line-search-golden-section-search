#include<iostream> 
#include<cmath> 
#include<fstream> 
#include<windows.h> 
using namespace std; 
double f(double x);  
double GoldenSection( double a, double x1, double x2, double b); 
int main() 
{   
	double a=-10,b=10; 
	double x1 = 0.312 * (b-a), x2=0.618 * (b-a);  
	double x = GoldenSection(a,x1,x2,b);  
	double y = f(x);   
	cout<<"x="<<x<<endl;  
	cout<<"min="<<y<<endl;  
	return 0;
}  
double f(double x) 
{  
	return (x*x-1)*(x*x-1) + (x-1)*(x-1) + 3; 
}  
double GoldenSection( double a, double x1, double x2, double b) 
{   
	double y1 = f(x1), y2 = f(x2);  
	if( fabs(b -a) < 0.000001)   
		return (y1 < y2) ? x1 : x2;  
	if( y1 < y2 )   
		return GoldenSection( a, a+0.312*(x2 - a), a+0.618*(x2 - a), x2);  
	if( y1 > y2 )   
		return GoldenSection( x1, x1 + 0.312*(b - x1), x1 + 0.618*(b - x1),b);  
	if( y1 == y2 )   
		return GoldenSection( x1,x1+0.312*(x2-x1), x1+0.618*(x2-x1), x2); 
}
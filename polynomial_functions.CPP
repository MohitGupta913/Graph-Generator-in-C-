#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <iostream.h>
double f(double x, double*a, int deg){
   float sum = 0;
   for(int i=0; i<=deg; i++){
	    sum+=a[i] * pow(x, (deg-i));
    }
   return sum;
}
void main(){
    int deg; double a[100];
    cout<<"Enter degree of polynomial"<<endl;
    cin>>deg;
    for(int i=0; i<=deg; i++){
	cout<<"Enter coefficient of x^"<<deg-i<<endl;
	cin>>a[i];
}
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	cout<<"Graph ofexpression : "<<endl;
	for(int k=0; k<deg; k++){
	      cout<<a[k]<<"x^"<<deg-k<<"  +  ";
	}
	cout<<a[deg];
    double mx = getmaxx();
	double my = getmaxy();
	line(mx/2, 0, mx/2, my );
	line(0, my/2, mx, my/2);
	for(double j=-mx/2; j<mx/2; j+=0.01){
	      double x =0.1*j;
	  double y = 10*f(x, a, deg);
	      putpixel(mx/2 + j, my/2 - y, GREEN);
	}

	getch();
	closegraph();
}

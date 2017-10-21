#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <iostream.h>
#define pi 3.14159265
class Graph
{       int deg; double a[100]; //poly
	float z[20],t,c[20],p[20],b[20],cx[20],X,Y;//log and exp
	char fun[10];     //trig
	int F[100];
	double ct[100], af[100], ph[100], po[100];

	public:
	void polynomial_function();
	friend double f(double x,Graph *A);
	friend double Lsum(double x,Graph *A);
	void Log();
	friend double Esum(double x,Graph *A);
	void Exp();
	void trigo_fun();
	friend void check_fun(int i, Graph *A);
	friend int get_val(int i, Graph *A,int j);
};

double f(double x,Graph *A)
{
   float sum = 0;
   for(int i=0; i<=A->deg; i++){
	    sum+=A->a[i] * pow(x, (A->deg-i));
    }
   return sum;
}

void Graph::polynomial_function()
{
	 cout<<"Enter degree of polynomial"<<endl;
	 cin>>deg;

    for(int i=0; i<=deg; i++){
		 cout<<"Enter coefficient of x^"<<deg-i<<endl;
		 cin>>a[i];
     }

	int gd = DETECT, gm;

	initgraph(&gd, &gm, "c:\\tc\\bgi");
		cout<<"Graph ofexpression : "<<endl;
		if(a[0]<0){
		   cout<<"-";
		}
	for(int k=0; k<deg; k++){
	      if(a[k]!=0){
		    cout<<abs(a[k])<<"x^"<<deg-k;
		    if(a[k+1]<0){
			cout<<"-";
		    }
		    else{
			cout<<"+";
		    }
     }
	}
	      if(a[deg]!=0){
		cout<<abs(a[deg]);
	}
	    double mx = getmaxx();
		double my = getmaxy();

		line(mx/2, 0, mx/2, my );
		line(0, my/2, mx, my/2);

	for(double j=-mx/2; j<mx/2; j+=0.01){
	      double x =0.1*j;
	      double y = 10*f(x,this);
	      putpixel(mx/2 + j, my/2 - y, GREEN);
	}

	getch();
	closegraph();
}

void check_fun(int i, Graph *A)
{
    if(!strcmp(A->fun, "sin")){
	A->F[i]=1;
    }
    else if(!strcmp(A->fun, "cos")){
	A->F[i]=2;
    }
    else if(!strcmp(A->fun, "tan")){
	A->F[i]=3;
    }
    else if(!strcmp(A->fun, "cosec")){
	A->F[i]=4;
    }
    else if(!strcmp(A->fun, "sec")){
	A->F[i]=5;
    }
    else if(!strcmp(A->fun, "cot")){
	A->F[i]=6;
    }
    else{
	A->F[i]=-1;
    }
}
int get_val(int i, Graph *A,int j)
{
    int y;
    switch(A->F[j]){
    case 1:
	y = int((A->ct[j])*(pow(sin((((A->af[j])*i)+(A->ph[j]/2))*pi/90),A->po[j])*25 ) );
	break;
    case 2:
	y = int(A->ct[j]*(pow(cos((A->af[j]*i+A->ph[j]/2)*pi/90),A->po[j])*25));
	break;
    case 3:
	y = int(A->ct[j]*(pow(tan((A->af[j]*i+A->ph[j]/2)*pi/90),A->po[j])*25));
	break;
    case 4:
	y = int(A->ct[j]*25/(pow(sin((A->af[j]*i+A->ph[j]/2)*pi/90),A->po[j])));
	break;
    case 5:
	y = int(A->ct[j]*25/(pow(cos((A->af[j]*i+A->ph[j]/2)*pi/90),A->po[j])));
	break;
    case 6:
	y = int(A->ct[j]*25/(pow(tan((A->af[j]*i+A->ph[j]/2)*pi/90),A->po[j])));
	break;
    }
    return y;
}
void Graph::trigo_fun()
{
	int i,s,j=0;
	int gd = DETECT;
	int gm;
	cout<<"Number of terms you will enter: ";
	cin>>s;
	for(i=0;i<s;i++)
	{
	    cout<<"Enter function "<<i+1<<": ";
	    cin>>fun;
	    int I=0;

	    while(fun[I]!='\0')
	    {
		char c;
		if(isalpha(fun[I]))
		{
		    c = fun[I];
		    fun[I] = tolower(c);
		}
		I++;
	    }
	    check_fun(i,this);
	    if(F[i]==-1){
		cout<<"Invalid input! Aborting->->->\n";
		break;
	    }
	    else{
		cout<<"Enter coefficient of function "<<i+1<<": ";
		cin>>ct[i];
		cout<<"Enter angular frequency of function "<<i+1<<": ";
		cin>>af[i];
		cout<<"Enter phase of function "<<i+1<<" in degrees: ";
		cin>>ph[i];
		cout<<"Enter power of function "<<i+1<<": ";
		cin>>po[i];
		cout<<endl;
	    }
	}

	char p[]="C:\\TC\\BGI";
	initgraph(&gd, &gm, p);
	int mx = getmaxx();
	int my = getmaxy();
	line(0,my/2, mx, my/2);
	line(mx/2, 0, mx/2, my);
	line(mx/2, 0, mx/2-5, 5);
	line(mx/2, 0, mx/2+5, 5);
	line(mx, my/2, mx-5, my/2-5);
	line(mx, my/2, mx-5, my/2+5);
	for(float v=-360;v<=360;v+=0.01){
	    int x = int((mx/2)+v);
	    int y = 0;
	    for(j=0;j<s;j++)
	    {
		y = y+get_val(v,this,j);
	    }
	    putpixel(x, int(my/2-y), GREEN);
	}
	getch();
	closegraph();
}

double Lsum(double x,Graph *A)
{
	float sum = 0;
	for(int i=0; i<A->t; i++)
	{       if((x+A->z[i])>0)
		sum+=A->c[i]*pow((log(A->cx[i]*x+A->z[i])/log(A->b[i])),A->p[i]);
	}
	if(sum!=0)
		return sum;
	else
		return 1000000;
}

void Graph::Log()
{
	cout<<"Enter the number of terms in the expression : ";
	cin>>t;
	for(int u=0; u<t; u++)
	{
		cout<<"Enter the value of coefficient of "<<u+1<<" term";
		cin>>c[u];
		cout<<"Enter the value of phase of "<<u+1<<" term";
		cin>>z[u];
		cout<<"Enter the value of power of "<<u+1<<" term";
		cin>>p[u];
		cout<<"Enter the value of coefficient of x of"<<u+1<<" term";
		cin>>cx[u];
		cout<<"Enter the base (should be greater than 0) of "<<u+1<<" term";
		cin>>b[u];
	}
	cout<<"Enter the scale of the graph :- \n1.)For X axis";
	cin>>X;
	cout<<"2.)For Y axis : ";
	cin>>Y;
	cout<<"Graph ofexpression : "<<endl;
	for(int k=0; k<t; k++)
	{
		cout<<c[k]<<"*(log base"<<b[k]<<"("<<cx[k]<<"x+"<<z[k]<<"))^"<<p[k]<<"  +  ";
	}
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	double mx = getmaxx();
	double my = getmaxy();
	line(0,my/2, mx, my/2);
	line(mx/2, 0, mx/2, my);
	line(mx/2, 0, mx/2-5, 5);
	line(mx/2, 0, mx/2+5, 5);
	line(mx, my/2, mx-5, my/2-5);
	line(mx, my/2, mx-5, my/2+5);

	for(double x=-(mx/2); x<mx/2; x+=0.01)
	{
		double y =Lsum(x,this);
		putpixel((mx/2 +X*x),(my/2 - Y*y), RED);
	}
	getch();
	closegraph();
}

double Esum(double x,Graph *A)
{
	float sum = 0;
	for(int i=0; i<A->t; i++)
		sum+=A->c[i]*pow(A->b[i],pow(A->cx[i]*x,A->p[i])+A->z[i]);
	return sum;
}

void Graph::Exp()
{
	cout<<"Enter the number of terms in the expression : ";
	cin>>t;
	for(int u=0; u<t; u++)
	{
		cout<<"Enter the value of the variable of "<<u+1<<" term";
		cin>>b[u];
		cout<<"Enter the value of coefficient of "<<u+1<<" term";
		cin>>c[u];
		cout<<"Enter the value of phase of power of variable of "<<u+1<<" term";
		cin>>z[u];
		cout<<"Enter the value of cofficient of x of "<<u+1<<" term";
		cin>>cx[u];
		cout<<"Enter the value of power of x of "<<u+1<<" term";
		cin>>p[u];
	}
	cout<<"Enter the scale of the graph :- \n1.)For X axis";
	cin>>X;
	cout<<"2.)For Y axis : ";
	cin>>Y;
	cout<<"Graph ofexpression : "<<endl;
	for(int k=0; k<t; k++)
	{
		cout<<c[k]<<"*"<<b[k]<<"^("<<cx[k]<<"x^"<<p[k]<<"+"<<z[k]<<")"<<"  +  ";
	}

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	double mx = getmaxx();
	double my = getmaxy();
	line(0,my/2, mx, my/2);
	line(mx/2, 0, mx/2, my);
	line(mx/2, 0, mx/2-5, 5);
	line(mx/2, 0, mx/2+5, 5);
	line(mx, my/2, mx-5, my/2-5);
	line(mx, my/2, mx-5, my/2+5);

	for(double x=-(mx/2); x<mx/2; x+=0.01)
	{
		double y =Esum(x,this);
		putpixel((mx/2 +X*x),(my/2 - Y*y), RED);
	}
	getch();
	closegraph();
}

void main()
{
	clrscr();
	int op;
	Graph A;
	char choice;
	do
	{
		cout<<"What function do you want to choose\n1.)Logarithmic\n2.)Exponential\n3.)Algebaraic\n4.)Trigonomertric\n5.)Exit";
		cin>>op;
		switch(op)
		{	case 1: A.Log();
				break;
			case 2: A.Exp();
				break;
			case 3: A.polynomial_function();
				break;
			case 4: A.trigo_fun();
				break;
			case 5: exit(0);
			default: cout<<"Wrong Choice!!!";
		}
		cout<<"Do you want to continue (Y/N) ?";
		cin>>choice;
	}while(choice=='y'||choice=='Y');
}
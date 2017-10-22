#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <iostream.h>
#define pi 3.14159265
class DrawGraph{
	public:
	    virtual void drawgraph()=0;
};

class polynomial : public DrawGraph{
         int deg; double a[100]; 
    public:
         void drawgraph();
	     friend double draw(double x,polynomial* p);	
	       
};


class trigo : public DrawGraph{
         char fun[10];     //trig
	     int F[100];
	     double ct[100], af[100], ph[100], po[100];
	public:
	     void drawgraph();
	     friend void check_fun(int i, trigo* t);
	     friend int draw(int i, trigo* t,int j);	
};


class lo : public DrawGraph{
	     float z[20],t,c[20],p[20],b[20],cx[20],X,Y;
	public:
		 friend double draw(double x, lo* l);
	     void drawgraph();	
};

class ex : public DrawGraph{
	     float z[20],t,c[20],p[20],b[20],cx[20],X,Y;
	public:
	     friend double draw(double x, ex* e);
	     void drawgraph();     
};


double draw(double x,polynomial* p)
{
   float sum = 0;
   for(int i=0; i<=p->deg; i++){
	    sum+=p->a[i] * pow(x, (p->deg-i));
    }
   return sum;
}

void polynomial :: drawgraph()
{
	 cout<<"Enter degree of polynomial"<<endl;
	 cin>>deg;

    for(int i=0; i<=deg; i++){
		 cout<<"Enter coefficient of x^"<<deg-i<<endl;
		 cin>>a[i];
     }

	int gd = DETECT, gm;

	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
		cout<<"Graph of expression : "<<endl;
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

		outtextxy(mx/2+5,my/2+5, "O");
		outtextxy(mx-10, my/2+5, "X");
		outtextxy(mx/2+5, 10, "Y");
		outtextxy(mx/2+5, my-10, "Y'");
		outtextxy(5, my/2 + 5, "X'");
		line(mx/2, 0, mx/2, my );
		line(0, my/2, mx, my/2);

	for(double j=-mx/2; j<mx/2; j+=0.01){
	      double x =0.1*j;
	      double y = 10*draw(x,this);
	      putpixel(mx/2 + j, my/2 - y, GREEN);
	}

	getch();
	closegraph();
}

void check_fun(int i, trigo* t)
{
    if(!strcmp(t->fun, "sin")){
	t->F[i]=1;
    }
    else if(!strcmp(t->fun, "cos")){
	t->F[i]=2;
    }
    else if(!strcmp(t->fun, "tan")){
	t->F[i]=3;
    }
    else if(!strcmp(t->fun, "cosec")){
	t->F[i]=4;
    }
    else if(!strcmp(t->fun, "sec")){
	t->F[i]=5;
    }
    else if(!strcmp(t->fun, "cot")){
	t->F[i]=6;
    }
    else{
	t->F[i]=-1;
    }
}
int draw(int i, trigo* t,int j)
{
    int y;
    switch(t->F[j]){
    case 1:
	y = int((t->ct[j])*(pow(sin((((t->af[j])*i)+(t->ph[j]/2))*pi/90),t->po[j])*25 ) );
	break;
    case 2:
	y = int(t->ct[j]*(pow(cos((t->af[j]*i+t->ph[j]/2)*pi/90),t->po[j])*25));
	break;
    case 3:
	y = int(t->ct[j]*(pow(tan((t->af[j]*i+t->ph[j]/2)*pi/90),t->po[j])*25));
	break;
    case 4:
	y = int(t->ct[j]*25/(pow(sin((t->af[j]*i+t->ph[j]/2)*pi/90),t->po[j])));
	break;
    case 5:
	y = int(t->ct[j]*25/(pow(cos((t->af[j]*i+t->ph[j]/2)*pi/90),t->po[j])));
	break;
    case 6:
	y = int(t->ct[j]*25/(pow(tan((t->af[j]*i+t->ph[j]/2)*pi/90),t->po[j])));
	break;
    }
    return y;
}
void trigo :: drawgraph()
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

	char p[]="C:\\turboc3\\BGI";
	initgraph(&gd, &gm, p);
	int mx = getmaxx();
	int my = getmaxy();
	outtextxy(mx/2+5,my/2+5, "O");
	outtextxy(mx-10, my/2+5, "X");
	outtextxy(mx/2+5, 10, "Y");
	outtextxy(mx/2+5, my-10, "Y'");
	outtextxy(5, my/2 + 5, "X'");
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
		y = y+draw(v,this,j);
	    }
	    putpixel(x, int(my/2-y), GREEN);
	}
	getch();
	closegraph();
}

double draw(double x, lo* l)
{
	float sum = 0;
	for(int i=0; i<l->t; i++)
	{       if((l->cx[i]*x+l->z[i])>0 && l->b[i]>0 )
                sum+=l->c[i]*pow((log(l->cx[i]*x+l->z[i])/log(l->b[i])),l->p[i]);
	}
	if(sum!=0)
		return sum;
	else
		return 1000000;
}

void lo :: drawgraph()
{
	cout<<"Enter the number of terms in the expression : ";
	cin>>t;
	cout<<"Enter the following terms according to the expression : ";
	cout<<"C*(log base b (vx+z))^p\n";
	for(int u=0; u<t; u++)
	{
		cout<<"Enter the value of coefficient of "<<u+1<<" term (C) ";
		cin>>c[u];
		cout<<"Enter the value of phase of "<<u+1<<" term (z) ";
		cin>>z[u];
		cout<<"Enter the value of power of "<<u+1<<" term (p) ";
		cin>>p[u];
		cout<<"Enter the value of coefficient of x of "<<u+1<<" term (v) ";
		cin>>cx[u];
		cout<<"Enter the base (should be greater than 0) of "<<u+1<<" term (b) ";
		cin>>b[u];
	}
	cout<<"Enter the scale of the graph :- \n1.)For X axis :  ";
	cin>>X;
	cout<<"2.)For Y axis :   ";
	cin>>Y;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\BGI");
	cout<<"Graph ofexpression : "<<endl;
	for(int k=0; k<t; k++)
	{       if(k>=1)
			cout<<" + ";
		cout<<c[k]<<"*(log base"<<b[k]<<" ("<<cx[k]<<"x+"<<z[k]<<"))^"<<p[k];
	}
	double mx = getmaxx();
	double my = getmaxy();
	outtextxy(mx/2+5,my/2+5, "O");
	outtextxy(mx-10, my/2+5, "X");
	outtextxy(mx/2+5, 10, "Y");
	outtextxy(mx/2+5, my-10, "Y'");
	outtextxy(5, my/2 + 5, "X'");
	line(0,my/2, mx, my/2);
	line(mx/2, 0, mx/2, my);
	line(mx/2, 0, mx/2-5, 5);
	line(mx/2, 0, mx/2+5, 5);
	line(mx, my/2, mx-5, my/2-5);
	line(mx, my/2, mx-5, my/2+5);

	for(double x=-(mx/2); x<mx/2; x+=0.001)
	{
		double y =draw(x,this);
		putpixel((mx/2 +X*x),(my/2 - Y*y), RED);
	}
	getch();
	closegraph();
}

double  draw(double x, ex* e)
{
	float sum = 0;
	for(int i=0; i<e->t; i++)
		sum+=e->c[i]*pow(e->b[i],pow(e->cx[i]*x,e->p[i])+e->z[i]);
	return sum;
}

void ex :: drawgraph()
{
	cout<<"Enter the number of terms in the expression :   ";
	cin>>t;
	cout<<"Enter the following terms according to the expression : ";
	cout<<"C*A^((zx^p)+s)\n";
	for(int u=0; u<t; u++)
	{
		cout<<"Enter the value of the variable of "<<u+1<<" term (A) ";
		cin>>b[u];
		cout<<"Enter the value of coefficient of "<<u+1<<" term (C) ";
		cin>>c[u];
		cout<<"Enter the value of phase of power of variable of "<<u+1<<" term (s) ";
		cin>>z[u];
		cout<<"Enter the value of cofficient of x of "<<u+1<<" term (z) ";
		cin>>cx[u];
		cout<<"Enter the value of power of x of "<<u+1<<" term (p) ";
		cin>>p[u];
	}
	cout<<"Enter the scale of the graph :- \n1.)For X axis :   ";
	cin>>X;
	cout<<"2.)For Y axis :   ";
	cin>>Y;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\BGI");
	cout<<"Graph of expression : "<<endl;
	for(int k=0; k<t; k++)
	{       if(k>=1)
			cout<<"  +  ";
		cout<<c[k]<<"*"<<b[k]<<"^("<<cx[k]<<"x^"<<p[k]<<"+"<<z[k]<<")";
	}
	double mx = getmaxx();
	double my = getmaxy();
	outtextxy(mx/2+5,my/2+5, "O");
	outtextxy(mx-10, my/2+5, "X");
	outtextxy(mx/2+5, 10, "Y");
	outtextxy(mx/2+5, my-10, "Y'");
	outtextxy(5, my/2 + 5, "X'");
	line(0,my/2, mx, my/2);
	line(mx/2, 0, mx/2, my);
	line(mx/2, 0, mx/2-5, 5);
	line(mx/2, 0, mx/2+5, 5);
	line(mx, my/2, mx-5, my/2-5);
	line(mx, my/2, mx-5, my/2+5);

	for(double x=-(mx/2); x<mx/2; x+=0.0001)
	{
		double y =draw(x,this);
		putpixel((mx/2 +X*x),(my/2 - Y*y), RED);
	}
	getch();
	closegraph();
}

void main()
{
	clrscr();
	int op;
	polynomial p; trigo t; lo l; ex e;
	char choice;
	do
	{
		cout<<"\n\n           -----------------------------------------------------------\n                              GRAPH GENERATOR IN C++\n           -----------------------------------------------------------\n"<<endl;
		cout<<"--------------------------------------\n";
		cout<<"Which function's graph you want to see\n1.)Logarithmic\n2.)Exponential\n3.)Polynomial\n4.)Trigonomertric\n5.)Exit";
		cout<<"\n--------------------------------------"<<endl;
		cout<<"\n";
		cin>>op;
		cout<<"\n";
		switch(op)
		{	case 1: l.drawgraph();
				break;
			case 2: e.drawgraph();
				break;
			case 3: p.drawgraph();
				break;
			case 4: t.drawgraph();
				break;
			case 5: exit(0);
			default: cout<<"Wrong Choice!!!\n";
		}
		cout<<"Do you want to continue (Y/N) ?\n";
		cin>>choice;
	}while(choice=='y'||choice=='Y');
}

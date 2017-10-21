#include<graphics.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
using namespace std;
#define pi 3.14159265
void check_fun(char* fun, int F[], int i){
    if(!strcmp(fun, "sin")){
        F[i]=1;
    }
    else if(!strcmp(fun, "cos")){
        F[i]=2;
    }
    else if(!strcmp(fun, "tan")){
        F[i]=3;
    }
    else if(!strcmp(fun, "cosec")){
        F[i]=4;
    }
    else if(!strcmp(fun, "sec")){
        F[i]=5;
    }
    else if(!strcmp(fun, "cot")){
        F[i]=6;
    }
    else{
        F[i]=-1;
    }
}
int get_val(int F, double c, double af, double ph, double po, int i){
    int y;
    switch(F){
    case 1:
        y = int(c*(pow(sin((af*i+ph/2)*pi/90),po)*25));
        break;
    case 2:
        y = int(c*(pow(cos((af*i+ph/2)*pi/90),po)*25));
        break;
    case 3:
        y = int(c*(pow(tan((af*i+ph/2)*pi/90),po)*25));
        break;
    case 4:
        y = int(c*25/(pow(sin((af*i+ph/2)*pi/90),po)));
        break;
    case 5:
        y = int(c*25/(pow(cos((af*i+ph/2)*pi/90),po)));
        break;
    case 6:
        y = int(c*25/(pow(tan((af*i+ph/2)*pi/90),po)));
        break;
    }
    return y;
}
void trigo_fun(){
        char fun[10];
        int i,s,j=0;
        int gd = DETECT;
        int gm;
        cout<<"Number of terms you will enter: ";
        cin>>s;
        int F[s];
        double c[s], af[s], ph[s], po[s];
        for(i=0;i<s;i++){
            try{
            cout<<"Enter function "<<i+1<<": ";
            cin>>fun;
            int I=0;

            while(fun[I]!='\0'){
                char c;
                if(isalpha(fun[I])){
                    c = fun[I];
                    fun[I] = tolower(c);
                }
                I++;
            }
            check_fun(fun, F, i);
            if(F[i]==-1){
                throw F[i];
            }
            else{
                cout<<"Enter coefficient of function "<<i+1<<": ";
                cin>>c[i];
                cout<<"Enter angular frequency of function "<<i+1<<": ";
                cin>>af[i];
                cout<<"Enter phase of function "<<i+1<<" in degrees: ";
                cin>>ph[i];
                cout<<"Enter power of function "<<i+1<<": ";
                cin>>po[i];
                cout<<endl;
            }
            }
            catch(int a){
                cout<<"Invalid input! Aborting...\n";
                break;
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

        for(float v=-360;v<=360;v=v+0.01){
            int x = int((mx/2)+v);
            //int y=int(my/2);
            int y = 0;
            for(j=0;j<s;j++){
                y = y+get_val(F[j], c[j], af[j], ph[j], po[j], v);
            }
            //putpixel(x, y, WHITE);
            putpixel(x, int(my/2-y), WHITE);
        }
        getch();
        closegraph();
}
int main(){
    int Ch;
    do{
        cout<<"Menu:\n1. Trigonometric Function     2. Exit\nEnter your choice: ";
        cin>>Ch;
        switch(Ch){
        case 1:
            trigo_fun();
            break;
        case 2:
            break;
        default: cout<<"Wrong Input!\n";
        }
    }while(Ch!=2);
}

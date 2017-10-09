#include<graphics.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
    char fun[10],ch;
    double i, c, af, ph, po;
    double pi = 3.14159265;
    int I=0;
    int gd = DETECT;
    int gm;
    char p[]="C:\\TC\\BGI";
    do{
        cout<<"Enter a trigonometric function: ";
        cin>>fun;
        cout<<"Enter coefficient: ";
        cin>>c;
        cout<<"Enter angular frequency: ";
        cin>>af;
        cout<<"Enter phase in degrees: ";
        cin>>ph;
        cout<<"Enter power: ";
        cin>>po;
        while(fun[I]!='\0'){
            char c;
            if(isalpha(fun[I])){
                c = fun[I];
                fun[I] = tolower(c);
            }
            I++;
        }
        initgraph(&gd, &gm, p);
        int mx = getmaxx();
        int my = getmaxy();
        line(0,my/2, mx, my/2);
        line(mx/2, 0, mx/2, my);
        line(mx/2, 0, mx/2-5, 5);
        line(mx/2, 0, mx/2+5, 5);
        line(mx, my/2, mx-5, my/2-5);
        line(mx, my/2, mx-5, my/2+5);

        if(!strcmp(fun, "sin(x)")){
            for(i=-360;i<=360;i++){
                int x = int((mx/2)+i);
                int y = int(my/2-c*(sin((af*i+ph/2)*pi/90)*25));
                putpixel(x, y, WHITE);
                delay(1);
            }
        }
        else if(!strcmp(fun, "cos(x)")){
            for(i=-360;i<=360;i++){
                int x = int((mx/2)+i);
                int y = int(my/2-c*(cos((af*i+ph/2)*pi/90)*25));
                putpixel(x, y, WHITE);
                delay(1);
            }
        }
        else if(!strcmp(fun, "tan(x)")){
            for(i=-270;i<=270;i+=0.01){
                int x = int((mx/2)+i);
                int y = int(my/2-c*(tan((af*i+ph/2)*pi/90)*25));
                putpixel(x, y, WHITE);
            }
        }
        else if(!strcmp(fun, "cosec(x)")){
            for(i=-270;i<=270;i+=0.01){
                int x = int((mx/2)+i);
                int y = int(my/2-c*25/(sin((af*i+ph/2)*pi/90)));
                putpixel(x, y, WHITE);
            }
        }
        else if(!strcmp(fun, "sec(x)")){
            for(i=-270;i<=270;i+=0.01){
                int x = int((mx/2)+i);
                int y = int(my/2-c*25/(cos((af*i+ph/2)*pi/90)));
                putpixel(x, y, WHITE);
            }
        }
        else if(!strcmp(fun, "cot(x)")){
            for(i=-270;i<=270;i+=0.01){
                int x = int((mx/2)+i);
                int y = int(my/2-c*25/(tan((af*i+ph/2)*pi/90)));
                putpixel(x, y, WHITE);
            }
        }
        else{
            cleardevice();
            outtextxy(10, 10, "Oops! Invalid Input.");
        }
        getch();
        closegraph();
        cout<<"Do you want to continue?...";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
}

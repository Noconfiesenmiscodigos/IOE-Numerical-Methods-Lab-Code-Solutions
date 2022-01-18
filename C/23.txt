/* Modified Euler's Method */
#include<stdio.h>
#include<math.h>
#include<conio.h>
void main( )
{
    float x,y,x1=0.0,y1=0.0,h,ms=0.0,flag=0,y2=0.0,t=0.0;
    int i,j;
    printf("\n Enter the value of x ");
    scanf("%f",&x);
    printf("Enter the value of y ");
    scanf("%f",&y);
    printf("enter the height ");
    scanf("%f",&h);
    i=7;
    printf("\nx");
    //gotoxy(10,i);
    printf("\t x+y=y1");
    //gotoxy(28,i);
    printf ("\t mean slope");
    //gotoxy(45,i);
    printf("\t old y+.1(mean slope)=new y");
    while(x1<x)
    {
        i++;
        do
        {
            i++;
            if(flag==0)
            {
                y1=x1+y;
                //gotoxy(2,i);
                printf("\n%.1f",x1);
                //gotoxy(10,i);
                printf("\t\t%.5f",y1);
                //gotoxy(28,i);
                printf("\t\t%.5f",ms);
                ms=y1;
                y2=y+h*ms;
                //gotoxy(45,i);
                printf("\t\t%.5f",y2);
                x1=x1+h;
                flag=1;
            }
            else
            {
                ms=(y1+(x1+y2))/2.0;
                t=y+h*ms;
                if(y2==t)
                {
                    y2=y+h*ms;
                    break;
                }
                //gotoxy(2,i);
                printf("\n%.1f",x1);
                //gotoxy(10,i);
                printf("\t\t%.1f+%.5f",
                       x1,y2);
                y2=y+h*ms;
                //gotoxy(28,i);
                printf("\t\t%.5f",ms);
                //gotoxy(45,i);
                printf("\t\t%.5f",y2);
            }
        }
        while(1);
        y=y2;
        printf("\n\n");
        flag=0;
    }
}

/*

 Enter the value of x .3
Enter the value of y .1
enter the height .1

x        x+y=y1  mean slope      old y+.1(mean slope)=new y
0.0             0.10000         0.00000         0.11000
0.1             0.1+0.11000             0.15500         0.11550
0.1             0.1+0.11550             0.15775         0.11578
0.1             0.1+0.11578             0.15789         0.11579
0.1             0.1+0.11579             0.15789         0.11579
0.1             0.1+0.11579             0.15789         0.11579


0.1             0.21579         0.15789         0.13737
0.2             0.2+0.13737             0.27658         0.14345
0.2             0.2+0.14345             0.27962         0.14375
0.2             0.2+0.14375             0.27977         0.14377
0.2             0.2+0.14377             0.27978         0.14377
0.2             0.2+0.14377             0.27978         0.14377


0.2             0.34377         0.27978         0.17814
0.3             0.3+0.17814             0.41096         0.18486
0.3             0.3+0.18486             0.41432         0.18520
0.3             0.3+0.18520             0.41448         0.18522
0.3             0.3+0.18522             0.41449         0.18522
0.3             0.3+0.18522             0.41449         0.18522
*/

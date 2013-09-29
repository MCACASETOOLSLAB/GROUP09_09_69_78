#include"graphics.h"
#include<conio.h>
#include<iostream>
using namespace std;

int main()
{
     int i=0,j=0;
     int left, top,right ,bottom;

     initwindow(800,700,"Producer Consumer Problem");
     outtextxy(100,50,"Process Synchronization Using Producer Consumer Problem");

     // First Chair Drawing
     left=100, top =100,right =190, bottom =200; 
     rectangle(left,top,right,bottom);
     //Second Chair Drawing
     left=210, top =100,right =300, bottom =200; 
     rectangle(left,top,right,bottom);
     // Third Chair Drawing
     left=320, top =100,right =410, bottom =200; 
     rectangle(left,top,right,bottom);
     //Fourth Chair Drawing
     left=430, top =100,right =510, bottom =200; 
     rectangle(left,top,right,bottom);
     left=530,top=100,right=610,bottom=200;
     rectangle(left,top,right,bottom);
     // Message to the box
     outtextxy(120,135,"Empty");
     outtextxy(230,135,"Empty");
     outtextxy(340,135,"Empty");
     outtextxy(450,135,"Empty");
     outtextxy(550,135,"Empty");
     
     
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"5");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"0");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"0");
 
     
     // Item-1 moves
     for(i=800,j=400; i >= 50; i--)
     {
         delay(2);
         outtextxy(i,j,"Producer Produced Item-1");
     }

     outtextxy(120,135,"          ");
     outtextxy(120,135,"Item-l");
     //delay(1000);
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"4");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"1");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"0");
     delay(2000);
    
     // Item-2 moves
     for(i=800,j=400; i >= 50; i--)
     {
         delay(2);
         outtextxy(i,j,"Producer Produced Item-2");
     }
     outtextxy(230,135,"          ");
     outtextxy(230,135,"Item-2");
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"3");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"2");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"0");
     delay(2000);
     
     //consuming Item-1
     for(i=50,j=400; i <= 800; i++)
     {
        delay(2);
        outtextxy(i,j,"Consumer is consuming Item-1");
     }
     outtextxy(120,135,"          ");
     outtextxy(120,135,"Empty");
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"4");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"2");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"1");
     delay(2000);

     /********************************************/

     //Item-3 moves
     for(i=800,j=400; i >= 50; i--)
     {
         delay(2);
         outtextxy(i,j,"Producer Produced Item-3");
     }

     outtextxy(120,135,"          ");
     outtextxy(120,135,"Item-3");
     //delay(1000);
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"3");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"3");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"1");
     delay(2000);
     
     
     //Item-4 move
     for(i=800,j=400; i >= 50; i--)
     {
         delay(2);
         outtextxy(i,j,"Producer Produced Item-4");
     }

     outtextxy(340,135,"          ");
     outtextxy(340,135,"Item-4");
     //delay(1000);
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"2");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"4");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"1");
     delay(2000);
     
     
     
     //Item-5 move
     for(i=800,j=400; i >= 50; i--)
     {
         delay(2);
         outtextxy(i,j,"Producer Produced Item-5");
     }

     outtextxy(450,135,"          ");
     outtextxy(450,135,"Item-5");
     //delay(1000);
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"1");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"5");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"1");
     delay(2000);
     
     
     //Item-6 move
     for(i=800,j=400; i >= 50; i--)
     {
         delay(2);
         outtextxy(i,j,"Producer Produced Item-6");
     }

     outtextxy(550,135,"          ");
     outtextxy(550,135,"Item-6");
     //delay(1000);
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"0");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"6");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"1");
     delay(2000);
     
     //Item-7 move
     for(i=800,j=400; i >= 50; i--)
     {
         delay(2);
         outtextxy(i,j,"Producer Produced Item-7");
     }
     outtextxy(50,400,"No Space Available.");
     delay(2000);
     outtextxy(50,400,"                     '\n                   '");
    
    //consuming Item-3
     for(i=50,j=400; i <= 800; i++)
     {
        delay(2);
        outtextxy(i,j,"Consumer is consuming Item-3");
     }
     outtextxy(120,135,"          ");
     outtextxy(120,135,"Empty");
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"1");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"6");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"2");
     delay(2000);
     
     //consuming Item-2
     for(i=50,j=400; i <= 800; i++)
     {
        delay(2);
        outtextxy(i,j,"Consumer is consuming Item-2");
     }
     outtextxy(230,135,"          ");
     outtextxy(230,135,"Empty");
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"2");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"6");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"3");
     delay(2000);
     
     //consuming Item-4
     for(i=50,j=400; i <= 800; i++)
     {
        delay(2);
        outtextxy(i,j,"Consumer is consuming Item-4");
     }
     outtextxy(340,135,"          ");
     outtextxy(340,135,"Empty");
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"3");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"6");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"4");
     delay(2000);
     
     //consuming Item-5
     for(i=50,j=400; i <= 800; i++)
     {
        delay(2);
        outtextxy(i,j,"Consumer is consuming Item-5");
     }
     outtextxy(450,135,"          ");
     outtextxy(450,135,"Empty");
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"4");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"6");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"5");
     delay(2000);
     
     
     //consuming Item-6
     for(i=50,j=400; i <= 800; i++)
     {
        delay(2);
        outtextxy(i,j,"Consumer is consuming Item-4");
     }
     outtextxy(550,135,"          ");
     outtextxy(550,135,"Empty");
     outtextxy(100,480,"Available Buffer");
     outtextxy(100,500,"5");
     outtextxy(100,550,"Item Produced");
     outtextxy(100,570,"6");
     outtextxy(100,620,"Item Consumed");
     outtextxy(100,640,"6");
     delay(2000);
 
 
      /*************************/
 
      cleardevice();
      outtextxy(300,400,"Thank You For Watching");
      delay(5000);
      closegraph();
}

#include<stdio.h>
#include<time.h>
#include<graphics.h>
 
int main()
{
      int gd = DETECT, gm;
      initgraph (&gd, &gm, ""); 
while(1)
{   
time_t now;
struct tm *now_tm;
int hour,minu,sec;
now = time(NULL);
now_tm = localtime(&now);
hour = now_tm->tm_hour;
//printf("%dhrs",hour);
minu = now_tm->tm_min;
//printf(":%dmin",minu);
sec = now_tm->tm_sec;
//printf(":%dsec",sec);

// here check for hours and decide for pm or am after which convert to 12 hr system
if(hour<=12)
	{
	//for A
	line(530,320,530,310);
	line(530,310,550,310);
	line(550,310,550,320);
	line(530,320,550,320);
	line(530,320,530,330);
	line(550,320,550,330);

	//M in not 7 segment
	line(560,310,560,330);
	line(560,310,570,330);
	line(570,330,580,310);
	line(580,310,580,330);
	}
else
	{
	//for P
	line(530,320,530,310);
	line(530,310,550,310);
	line(550,310,550,320);
	line(530,320,550,320);
	line(530,320,530,330);



	//M in not 7 segment
	line(560,310,560,330);
	line(560,310,570,330);
	line(570,330,580,310);
	line(580,310,580,330);
	}








hour=hour%12;

int h1 = hour/10;
int h2 = hour%10;
int m1 = minu/10;
int m2 = minu%10;
int s1 = sec/10;
int s2 = sec%10;
display(h1,h2,m1,m2,s1,s2);
delay(1000);
cleardevice();

}
  
}

void display(int h1, int h2, int m1, int m2,int s1, int s2)
{ 
      //Hours
      digit(h1,100,250,100,330,140,250,140,330,100,290,140,290);
      
      digit(h2,160,250,160,330,200,250,200,330,160,290,200,290);
      
      
      //space for colon
      putpixel(220,290,WHITE);
      putpixel(220,330,WHITE);
      
      
      //Minutes
      digit(m1,240,250,240,330,280,250,280,330,240,290,280,290);
      
      
      
      digit(m2,320,250,320,330,360,250,360,330,320,290,360,290);
      
      putpixel(380+20,290,WHITE);
      putpixel(380+20,330,WHITE);
      
      //Second
      digit(s1,400+20,250,400+20,330,440+20,250,440+20,330,400+20,290,440+20,290);
       
      digit(s2,460+20,250,460+20,330,500+20,250,500+20,330,460+20,290,500+20,290);
     
      
}

void digit(int value , int left_up_x,int left_up_y, int left_down_x,int left_down_y,int right_up_x,int right_up_y, int right_down_x,int right_down_y,int left_mid_x,int left_mid_y,int right_mid_x,int right_mid_y)
{
if(value==1)
	{
	 line(right_up_x,right_up_y,right_mid_x,right_mid_y);
	 line(right_down_x,right_down_y,right_mid_x,right_mid_y);
	}
if(value==2)
	{
	line(right_up_x,right_up_y,left_up_x,left_up_y);
	line(right_up_x,right_up_y,right_mid_x,right_mid_y);
	line(right_mid_x,right_mid_y,left_mid_x,right_mid_y);
	line(left_mid_x,left_mid_y,left_down_x,left_down_y);
	line(left_down_x,left_down_y,right_down_x,right_down_y);
	}
if(value==3)
	{
	line(right_up_x,right_up_y,left_up_x,left_up_y);
	line(right_up_x,right_up_y,right_mid_x,right_mid_y);
	line(right_mid_x,right_mid_y,left_mid_x,left_mid_y);
	line(right_mid_x,right_mid_y,right_down_x,right_down_y);
	line(left_down_x,left_down_y,right_down_x,right_down_y);

	}
if(value==4)
	{
	line(left_up_x,left_up_y,left_mid_x,left_mid_y);
	line(right_mid_x,right_mid_y,left_mid_x,left_mid_y);
	line(right_up_x,right_up_y,right_mid_x,right_mid_y);
	line(right_down_x,right_down_y,right_mid_x,right_mid_y);
	}
if(value==5)
	{
	line(right_up_x,right_up_y,left_up_x,left_up_y);
	line(left_up_x,left_up_y,left_mid_x,left_mid_y);
	line(right_mid_x,right_mid_y,left_mid_x,left_mid_y);
	line(right_down_x,right_down_y,right_mid_x,right_mid_y);
	line(left_down_x,left_down_y,right_down_x,right_down_y);
	}
if(value==6)
	{
	line(right_up_x,right_up_y,left_up_x,left_up_y);
	line(left_up_x,left_up_y,left_mid_x,left_mid_y);
	line(right_mid_x,right_mid_y,left_mid_x,left_mid_y);
	line(right_down_x,right_down_y,right_mid_x,right_mid_y);
	line(left_down_x,left_down_y,right_down_x,right_down_y);
	line(left_down_x,left_down_y,left_mid_x,left_mid_y);
	}
if(value==7)
	{
	line(right_up_x,right_up_y,left_up_x,left_up_y);
	line(right_up_x,right_up_y,right_mid_x,right_mid_y);
	line(right_down_x,right_down_y,right_mid_x,right_mid_y);
	}
if(value==8)
	{
	line(right_up_x,right_up_y,left_up_x,left_up_y);
	line(left_up_x,left_up_y,left_mid_x,left_mid_y);
	line(right_mid_x,right_mid_y,left_mid_x,left_mid_y);
	line(right_down_x,right_down_y,right_mid_x,right_mid_y);
	line(left_down_x,left_down_y,right_down_x,right_down_y);
	line(left_down_x,left_down_y,left_mid_x,left_mid_y);
	line(right_mid_x,right_mid_y,right_up_x,right_up_y);
	}
if(value==9)
	{
	line(right_up_x,right_up_y,left_up_x,left_up_y);
	line(left_up_x,left_up_y,left_mid_x,left_mid_y);
	line(right_mid_x,right_mid_y,left_mid_x,right_mid_y);
	line(right_down_x,right_down_y,right_mid_x,right_mid_y);
	line(left_down_x,left_down_y,right_down_x,right_down_y);
	line(right_mid_x,right_mid_y,right_up_x,right_up_y);
	}

if(value==0)
	{
	line(right_up_x,right_up_y,left_up_x,left_up_y);
	line(left_up_x,left_up_y,left_mid_x,left_mid_y);
	line(right_down_x,right_down_y,right_mid_x,right_mid_y);
	line(left_down_x,left_down_y,right_down_x,right_down_y);
	line(left_down_x,left_down_y,left_mid_x,left_mid_y);
	line(right_mid_x,right_mid_y,right_up_x,right_up_y);
	}

}

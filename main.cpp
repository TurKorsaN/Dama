#include <graphics.h>

char sinir[12][12]={{1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,1,0,0,0,0,0,0,0,0,1,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,1,0,0,0,0,0,0,0,0,1,1},
                    {1,1,0,0,0,0,0,0,0,0,1,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,1,0,0,0,0,0,0,0,0,1,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1}};
int tasx[4][9],tasy[4][8],w=2,z=2,w1,z1,sayac1=0,sayac2=0;
int damax[4][8],damay[4][8],u,v,sayfano=0;

void giris();
void girisciz(int *a,int *b,int *c,int *d,int *e,int *f,int *g,int *h,int *i,int *j);
void son1();
void son2();
void damahareket1(int *a,int *b,int *c,int *d,int *e,int *f);
void damahareket2(int *a,int *b,int *c,int *d,int *e,int *f);
void oyuncu1(int *a,int *b,int *c,int *d,int *e,int *f);
void oyuncu2(int *a,int *b,int *c,int *d,int *e,int *f);
void hareket1(int *a,int *b,int *c,int *d,int *e,int *f);
void hareket2(int *a,int *b,int *c,int *d,int *e,int *f);
void taslar();
void tahta();
void ciz(int *a,int *b,int *c,int *d,int *e,int *f);
void taslarbaslangic();

int main(void)
{
   initwindow(1050,800);
   giris();
   closegraph();
   int a=10,b=90,c=10,d=90,e=50,f=50,*p1,*p2,*p3,*p4,*p5,*p6,i,j;
   initwindow(1050,800);
   p1=&a;
   p2=&b;
   p3=&c;
   p4=&d;
   p5=&e;
   p6=&f;
   for(i=0;i<8;i++);
   for(j=0;j<8;j++);
   {
     damax[i][j]=-20;
     damay[i][j]=-20;
   }
   taslarbaslangic();
   ciz(p1,p2,p3,p4,p5,p6);
   while(1)
   {
           oyuncu1(p1,p2,p3,p4,p5,p6);
           if(sayac2==16)
           {
              son1();
              break;
           }
           oyuncu2(p1,p2,p3,p4,p5,p6);
           if(sayac1==16)
           {
              son2();
              break;
           }
   }
  getch();
  closegraph();
  return 0;
}

void ciz(int *a,int *b,int *c,int *d,int *e,int *f)
{
    cleardevice();
    tahta();
    taslar();
    setcolor(4);
    setfillstyle(1,0);
    circle(*e,*f,40);
    rectangle(*a,*c,*b,*d);
    setcolor(12);
    outtextxy(880,20,"Alper Sevindik");
    outtextxy(895,50,"Dama 1.0");
    outtextxy(880,250,"Ýyi Eðlenceler");
    outtextxy(900,680,"Tuþlar");
    outtextxy(882,700,"Yön Tuþlarý");
    outtextxy(840,720,"Enter (Taþ seçer ve koyar)");
    outtextxy(810,740,"Backspace (Seçilen taþý geri býrakýr)");
    outtextxy(820,760,"ESC (Sýra diðer oyuncuya geçer)");
}

void tahta()
{
    int x=-100,y=0,x2=0,y2=100,i,j;
    for(j=0;j<4;j++)
    {
        for(i=0;i<5;i++)
        {
            setfillstyle(1,11);
            bar(x+(i*200),y,x2+(i*200),y2);
        }
        x=-100; x2=0;
        y+=200; y2+=200;
    }
    x=0,y=-100,x2=100,y2=0;
    for(j=0;j<4;j++)
    {
        for(i=0;i<5;i++)
        {
            setfillstyle(1,11);
            bar(x,y+(i*200),x2,y2+(i*200));
        }
        y=-100; y2=0;
        x+=200; x2+=200;
    }
    x=0,y=0,x2=100,y2=100;
    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
        {
            setfillstyle(1,9);
            bar(x+(i*200),y,x2+(i*200),y2);
        }
        x=0; x2=100;
        y+=200; y2+=200;
    }
    x=100,y=100,x2=200,y2=200;
    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
        {
            setfillstyle(1,9);
            bar(x,y+(i*200),x2,y2+(i*200));
        }
        y=100; y2=200;
        x+=200; x2+=200;
    }
}

void taslarbaslangic()
{
     int t,i,j;
     t=750;
     for(i=0;i<2;i++)
     {
         tasx[i][-1]=-50;
         t-=100;
         for(j=0;j<9;j++)
         {
              tasx[i][j]=tasx[i][j-1]+100;
              tasy[i][j]=t;
              setcolor(0);
              setfillstyle(1,0);
              fillellipse(tasx[i][j],tasy[i][j],30,30);
         }
     }
     t=350;
     for(i=2;i<4;i++)
     {
         tasx[i][-1]=-50;
         t-=100;
         for(j=0;j<9;j++)
         {
              tasx[i][j]=tasx[i][j-1]+100;
              tasy[i][j]=t;
              setcolor(0);
              setfillstyle(1,15);
              fillellipse(tasx[i][j],tasy[i][j],30,30);
         }
     }
}

void taslar()
{   
     int i,j;
     for(i=0;i<2;i++)
     {
         for(j=0;j<8;j++)
         {
              if(tasx[i][j]>0)
              {
              setcolor(0);
              setfillstyle(1,0);
              fillellipse(tasx[i][j],tasy[i][j],30,30);
              }
              if(damax[i][j]>0)
              {
              setcolor(0);
              setfillstyle(11,15);
              fillellipse(damax[i][j],damay[i][j],30,30);
              }
         }
     }
     for(i=2;i<4;i++)
     {
         for(j=0;j<8;j++)
         {
              if(tasx[i][j]>0)
              {
              setcolor(0);
              setfillstyle(1,15);
              fillellipse(tasx[i][j],tasy[i][j],30,30);
              }
              if(damax[i][j]>0)
              {
              setcolor(0);
              setfillstyle(9,15);
              fillellipse(damax[i][j],damay[i][j],30,30);
              }
         }
     }
}     

void hareket1(int *a,int *b,int *c,int *d,int *e,int *f)
{
     int x,y,i,j,q=0,k,l,p=0; char tus;
     while(1)
     {
        setactivepage(1-sayfano);
        ++sayfano%=2;
        outtextxy(820,100,"Oynama Sýrasý: 1. Oyuncu (Siyah)");
        setactivepage(1-sayfano);
        ++sayfano%=2;
        x=(*a+*b)/2;
        y=(*c+*d)/2;
        for(i=0;i<2;i++)
        for(j=0;j<8;j++){
        if(x==tasx[i][j]&&y==tasy[i][j])
        {
           do
           {  
              if (kbhit()) cleardevice();
              setactivepage(1-sayfano);
              ++sayfano%=2;
              setcolor(12);
              circle(u,v,30);
              circle(u,v,29);
              outtextxy(820,100,"Oynama Sýrasý: 1. Oyuncu (Siyah)");
              setactivepage(1-sayfano);
              ++sayfano%=2;
              tus=getch();
              for(k=2;k<4;k++)
              for(l=0;l<8;l++)
              {
                 if((x==tasx[k][l]&&y-100==tasy[k][l]||x==damax[k][l]&&y-100==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*a+*b)/2)-tasx[i][j]==0&&((*c+*d)/2)-tasy[i][j]==-200)
                 {
                    if(x==tasx[k][l]&&y-100==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(x==damax[k][l]&&y-100==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    tasx[i][j]=(*a+*b)/2;
                    tasy[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    sinir[w1][z1]=0;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sinir[w+1][z]=0;
                    sayac2++;
                    for(k=2;k<4;k++)
                    for(l=0;l<8;l++)
                    if(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-100==tasy[k][l]||((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-100==damay[k][l])&&sinir[w-2][z]==0)||((((*a+*b)/2)-100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)-100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z-2]==0)||((((*a+*b)/2)+100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)+100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z+2]==0))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       hareket1(a,b,c,d,e,f);
                    }
                    break;
                 }
                 if((x-100==tasx[k][l]&&y==tasy[k][l]||x-100==damax[k][l]&&y==damay[k][l])&&tus==13&&sinir[w][z]==0&&tasx[i][j]-((*a+*b)/2)==200&&((*c+*d)/2)-tasy[i][j]==0)
                 {
                    if(x-100==tasx[k][l]&&y==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(x-100==damax[k][l]&&y==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    tasx[i][j]=(*a+*b)/2;
                    tasy[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    sinir[w1][z1]=0;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sinir[w][z+1]=0;
                    sayac2++;
                    for(k=2;k<4;k++)
                    for(l=0;l<8;l++)
                    if(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-100==tasy[k][l]||((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-100==damay[k][l])&&sinir[w-2][z]==0)||((((*a+*b)/2)-100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)-100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z-2]==0)||((((*a+*b)/2)+100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)+100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z+2]==0))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       hareket1(a,b,c,d,e,f);
                    }
                    break;
                 }
                 if((x+100==tasx[k][l]&&y==tasy[k][l]||x+100==damax[k][l]&&y==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*a+*b)/2)-tasx[i][j]==200&&((*c+*d)/2)-tasy[i][j]==0)
                 {
                    if(x+100==tasx[k][l]&&y==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(x+100==damax[k][l]&&y==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    tasx[i][j]=(*a+*b)/2;
                    tasy[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    sinir[w1][z1]=0;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sinir[w][z-1]=0;
                    sayac2++;
                    for(k=2;k<4;k++)
                    for(l=0;l<8;l++)
                    if(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-100==tasy[k][l]||((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-100==damay[k][l])&&sinir[w-2][z]==0)||((((*a+*b)/2)-100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)-100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z-2]==0)||((((*a+*b)/2)+100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)+100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z+2]==0))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       hareket1(a,b,c,d,e,f);
                    }
                    break;
                 }
              }
              for(k=2;k<4;k++)
              for(l=0;l<8;l++)
              {
                 if((x+100==tasx[k][l]&&y==tasy[k][l]||x+100==damax[k][l]&&y==damay[k][l])&&sinir[w1][z1+2]==0)
                 p=1;
                 if((x-100==tasx[k][l]&&y==tasy[k][l]||x-100==damax[k][l]&&y==damay[k][l])&&sinir[w1][z1-2]==0)
                 p=1;
                 if((x==tasx[k][l]&&y-100==tasy[k][l]||x==damax[k][l]&&y-100==damay[k][l])&&sinir[w1-2][z1]==0)
                 p=1;
              }
              if (tus==13&&sinir[w][z]==0&&(((((*a+*b)/2)-tasx[i][j]==-100||((*a+*b)/2)-tasx[i][j]==100)&&tasy[i][j]==((*c+*d)/2))||(tasy[i][j]-((*c+*d)/2)==100&&((*a+*b)/2)==tasx[i][j]))&&p==0)
              {
                 tasx[i][j]=(*a+*b)/2;
                 tasy[i][j]=(*c+*d)/2;
                 sinir[w][z]=1;
                 sinir[w1][z1]=0;
                 ciz(a,b,c,d,e,f);
                 q=1;
              }
              if(tasy[i][j]==50)
              {
                 damax[i][j]=tasx[i][j];
                 damay[i][j]=tasy[i][j];
                 tasy[i][j]=tasx[i][j]=-20;
              }
              if (tus==8) {oyuncu1(a,b,c,d,e,f); q=1;}
              if (tus==75&&*a>100){*a-=100; *b-=100; *e-=100; z--;}
              if (tus==77&&*b<700){*b+=100; *a+=100; *e+=100; z++;}
              if (tus==72&&*c>100){*c-=100; *d-=100; *f-=100; w--;}
              if (tus==80&&*d<700){*d+=100; *c+=100; *f+=100; w++;}
              ciz(a,b,c,d,e,f);
              setvisualpage(sayfano);
              setactivepage(1-sayfano);
              ++sayfano%=2;
              ciz(a,b,c,d,e,f);
           } while(q==0);
        }
        if(x==damax[i][j]&&y==damay[i][j])
        {
           damahareket1(a,b,c,d,e,f);
           q=1;
           break;
        }
        if (q==1) break;
        }
        if (q==1) break;
        if (kbhit()) cleardevice();
        setactivepage(1-sayfano);
        ++sayfano%=2;
        outtextxy(820,100,"Oynama Sýrasý: 1. Oyuncu (Siyah)");
        setactivepage(1-sayfano);
        ++sayfano%=2;
        tus=getch();
        if (tus==75&&*a>100){*a-=100; *b-=100; *e-=100; z--;}
        if (tus==77&&*b<700){*b+=100; *a+=100; *e+=100; z++;}
        if (tus==72&&*c>100){*c-=100; *d-=100; *f-=100; w--;}
        if (tus==80&&*d<700){*d+=100; *c+=100; *f+=100; w++;}
        ciz(a,b,c,d,e,f);
        setvisualpage(sayfano);
        setactivepage(1-sayfano);
        ++sayfano%=2;
        ciz(a,b,c,d,e,f);
     }
}

void hareket2(int *a,int *b,int *c,int *d,int *e,int *f)
{
     int x,y,i,j,q=0,k,l,g,h,p=0; char tus;
     while(1)
     {
        setactivepage(1-sayfano);
        ++sayfano%=2;
        outtextxy(820,100,"Oynama Sýrasý: 2. Oyuncu (Beyaz)");
        setactivepage(1-sayfano);
        ++sayfano%=2;
        x=(*a+*b)/2;
        y=(*c+*d)/2;
        for(i=2;i<4;i++)
        for(j=0;j<8;j++){
        if(x==tasx[i][j]&&y==tasy[i][j])
        {
         do
          {  
              if (kbhit()) cleardevice();
              setactivepage(1-sayfano);
              ++sayfano%=2;
              outtextxy(820,100,"Oynama Sýrasý: 2. Oyuncu (Beyaz)");
              setcolor(12);
              circle(u,v,30);
              circle(u,v,29);
              setactivepage(1-sayfano);
              ++sayfano%=2;
              tus=getch();
              for(k=0;k<2;k++)
              for(l=0;l<8;l++)
              {
                 if((x==tasx[k][l]&&y+100==tasy[k][l]||x==damax[k][l]&&y+100==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*a+*b)/2)-tasx[i][j]==0&&((*c+*d)/2)-tasy[i][j]==200)
                 {
                    if(x==tasx[k][l]&&y+100==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(x==damax[k][l]&&y+100==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    tasx[i][j]=(*a+*b)/2;
                    tasy[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    sinir[w1][z1]=0;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sinir[w-1][z]=0;
                    sayac1++;
                    for(k=0;k<2;k++)
                    for(l=0;l<8;l++)
                    if(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+100==tasy[k][l]||((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+100==damay[k][l])&&sinir[w+2][z]==0)||((((*a+*b)/2)-100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)-100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z-2]==0)||((((*a+*b)/2)+100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)+100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z+2]==0))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       hareket2(a,b,c,d,e,f);
                    }
                    break;
                 }
                 if((x-100==tasx[k][l]&&y==tasy[k][l]||x-100==damax[k][l]&&y==damay[k][l])&&tus==13&&sinir[w][z]==0&&tasx[i][j]-((*a+*b)/2)==200&&((*c+*d)/2)-tasy[i][j]==0)
                 {
                    if(x-100==tasx[k][l]&&y==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(x-100==damax[k][l]&&y==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    tasx[i][j]=(*a+*b)/2;
                    tasy[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    sinir[w1][z1]=0;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sinir[w][z+1]=0;
                    sayac1++;
                    for(k=0;k<2;k++)
                    for(l=0;l<8;l++)
                    if(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+100==tasy[k][l]||((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+100==damay[k][l])&&sinir[w+2][z]==0)||((((*a+*b)/2)-100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)-100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z-2]==0)||((((*a+*b)/2)+100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)+100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z+2]==0))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       hareket2(a,b,c,d,e,f);
                    }
                    break;
                 }
                 if((x+100==tasx[k][l]&&y==tasy[k][l]||x+100==damax[k][l]&&y==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*a+*b)/2)-tasx[i][j]==200&&((*c+*d)/2)-tasy[i][j]==0)
                 {
                    if(x+100==tasx[k][l]&&y==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(x+100==damax[k][l]&&y==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    tasx[i][j]=(*a+*b)/2;
                    tasy[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    sinir[w1][z1]=0;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sinir[w][z-1]=0;
                    sayac1++;
                    for(k=0;k<2;k++)
                    for(l=0;l<8;l++)
                    if(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+100==tasy[k][l]||((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+100==damay[k][l])&&sinir[w+2][z]==0)||((((*a+*b)/2)-100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)-100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z-2]==0)||((((*a+*b)/2)+100==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)+100==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&sinir[w][z+2]==0))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       hareket2(a,b,c,d,e,f);
                    }
                    break;
                 }
              }
               for(k=0;k<2;k++)
               for(l=0;l<8;l++)
               {
                  if((x+100==tasx[k][l]&&y==tasy[k][l]||x+100==damax[k][l]&&y==damay[k][l])&&sinir[w1][z1+2]==0)
                  p=1;
                  if((x-100==tasx[k][l]&&y==tasy[k][l]||x-100==damax[k][l]&&y==damay[k][l])&&sinir[w1][z1-2]==0)
                  p=1;
                  if((x==tasx[k][l]&&y+100==tasy[k][l]||x==damax[k][l]&&y+100==damay[k][l])&&sinir[w1+2][z1]==0)
                  p=1;
               }
              if (tus==13&&sinir[w][z]==0&&(((((*a+*b)/2)-tasx[i][j]==-100||((*a+*b)/2)-tasx[i][j]==100)&&((*c+*d)/2)-tasy[i][j]==0)||(((*c+*d)/2)-tasy[i][j]==100&&((*a+*b)/2)-tasx[i][j]==0))&&p==0)
              {
                 tasx[i][j]=(*a+*b)/2;
                 tasy[i][j]=(*c+*d)/2;
                 sinir[w][z]=1;
                 sinir[w1][z1]=0;
                 ciz(a,b,c,d,e,f);
                 q=1;
              }
              if(tasy[i][j]==750)
              {
                  damax[i][j]=tasx[i][j];
                  damay[i][j]=tasy[i][j];
                  tasy[i][j]=tasx[i][j]=-20;
              }
              if (tus==8) {oyuncu2(a,b,c,d,e,f); q=1;}
              if (tus==75&&*a>100){*a-=100; *b-=100; *e-=100; z--;}
              if (tus==77&&*b<700){*b+=100; *a+=100; *e+=100; z++;}
              if (tus==72&&*c>100){*c-=100; *d-=100; *f-=100; w--;}
              if (tus==80&&*d<700){*d+=100; *c+=100; *f+=100; w++;}
              ciz(a,b,c,d,e,f);
              setvisualpage(sayfano);
              setactivepage(1-sayfano);
              ++sayfano%=2; 
              ciz(a,b,c,d,e,f);
          } while (q==0);
        }
        if(x==damax[i][j]&&y==damay[i][j])
        {
           damahareket2(a,b,c,d,e,f);
           q=1;
           break;
        }
        if (q==1) break;
        }
        if (q==1) break;
        if (kbhit()) cleardevice();
        setactivepage(1-sayfano);
        ++sayfano%=2;
        outtextxy(820,100,"Oynama Sýrasý: 2. Oyuncu (Beyaz)");
        setactivepage(1-sayfano);
        ++sayfano%=2;
        tus=getch();
        if (tus==75&&*a>100){*a-=100; *b-=100; *e-=100; z--;}
        if (tus==77&&*b<700){*b+=100; *a+=100; *e+=100; z++;}
        if (tus==72&&*c>100){*c-=100; *d-=100; *f-=100; w--;}
        if (tus==80&&*d<700){*d+=100; *c+=100; *f+=100; w++;}
        ciz(a,b,c,d,e,f);
        setvisualpage(sayfano);
        setactivepage(1-sayfano);
        ++sayfano%=2;
        ciz(a,b,c,d,e,f);
     }
}

void oyuncu1(int *a,int *b,int *c,int *d,int *e,int *f)
{
   int i,j,q=0,p=0,k,l,x[4][8],y[4][8],dx[4][8],dy[4][8],g,m,n,o; char tus;
   for(i=0;i<2;i++)
   for(j=0;j<8;j++)
   x[i][j]=y[i][j]=dx[i][j]=dy[i][j]=-20;
   do
   {
      setactivepage(1-sayfano);
      ++sayfano%=2;
      outtextxy(820,100,"Oynama Sýrasý: 1. Oyuncu (Siyah)");
      setactivepage(1-sayfano);
      ++sayfano%=2;
      if (kbhit()) cleardevice();
      tus=getch();
      if (tus==13)
      {
         w1=w;
         z1=z;
         for(i=0;i<2;i++)
         for(j=0;j<8;j++)
         for(k=2;k<4;k++)
         for(l=0;l<8;l++)
         {
            if((tasx[i][j]+100==tasx[k][l]&&tasy[i][j]==tasy[k][l]||tasx[i][j]+100==damax[k][l]&&tasy[i][j]==damay[k][l])&&sinir[((tasy[i][j]-50)/100)+2][((tasx[i][j]-50)/100)+4]==0)
            {
               x[i][j]=tasx[i][j];
               y[i][j]=tasy[i][j];
               p=1;
            }
            if((tasx[i][j]-100==tasx[k][l]&&tasy[i][j]==tasy[k][l]||tasx[i][j]-100==damax[k][l]&&tasy[i][j]==damay[k][l])&&sinir[((tasy[i][j]-50)/100)+2][((tasx[i][j]-50)/100)]==0)
            {
               x[i][j]=tasx[i][j];
               y[i][j]=tasy[i][j];
               p=1;
            }
            if((tasx[i][j]==tasx[k][l]&&tasy[i][j]-100==tasy[k][l]||tasx[i][j]==damax[k][l]&&tasy[i][j]-100==damay[k][l])&&sinir[((tasy[i][j]-50)/100)][((tasx[i][j]-50)/100)+2]==0)
            {
               x[i][j]=tasx[i][j];
               y[i][j]=tasy[i][j];
               p=1;
            }
         }
         for(m=100,g=2;700>m;m+=100,g++)
         for(i=0;i<2;i++)
         for(j=0;j<8;j++)
         for(k=2;k<4;k++)
         for(l=0;l<8;l++)
         for(n=0;n<2;n++)
         for(o=0;o<8;o++)
         if((((damax[i][j]==tasx[k][l]&&damay[i][j]+m==tasy[k][l])||(damax[i][j]==damax[k][l]&&damay[i][j]+m==damay[k][l]))&&sinir[((damay[i][j]-50)/100)+g+2][((damax[i][j]-50)/100)+2]==0&&(sinir[((damay[i][j]-50)/100)+g][((damax[i][j]-50)/100)+2]==0||(damax[i][j]==damax[n][o]&&damay[i][j]+m-100==damay[n][o]))||(((damax[i][j]==tasx[k][l]&&damay[i][j]-m==tasy[k][l])||(damax[i][j]==damax[k][l]&&damay[i][j]-m==damay[k][l]))&&sinir[((damax[i][j]-50)/100)-g+2][((damay[i][j]-50)/100)+2]==0&&(sinir[((damay[i][j]-50)/100)-g+4][((damax[i][j]-50)/100)+2]==0||(damax[i][j]==damax[n][o]&&damay[i][j]-m+100==damay[n][o])))||(((damax[i][j]-m==tasx[k][l]&&damay[i][j]==tasy[k][l])||(damax[i][j]-m==damax[k][l]&&damay[i][j]==damay[k][l]))&&sinir[((damay[i][j]-50)/100)+2][((damax[i][j]-50)/100)-g+2]==0&&(sinir[((damay[i][j]-50)/100)+2][((damax[i][j]-50)/100)-g+4]==0||(damax[i][j]-m+100==damax[n][o]&&damay[i][j]==damay[n][o])))||(((damax[i][j]+m==tasx[k][l]&&damay[i][j]==tasy[k][l])||(damax[i][j]+m==damax[k][l]&&damay[i][j]==damay[k][l]))&&sinir[((damay[i][j]-50)/100)+2][((damax[i][j]-50)/100)+g+2]==0&&(sinir[((damay[i][j]-50)/100)+2][((damax[i][j]-50)/100)+g]==0||(damax[i][j]+m-100==damax[n][o]&&damay[i][j]==damay[n][o])))))
         {
            dx[i][j]=damax[i][j];
            dy[i][j]=damay[i][j];
            p=1;
         }
         if(p==1)
         setactivepage(1-sayfano);
         ++sayfano%=2;
         outtextxy(820,500,"Yemek Zorunludur.");
         setactivepage(1-sayfano);
         ++sayfano%=2;
         for(i=0;i<2;i++){
         for(j=0;j<8;j++){
         if(((((*a+*b)/2)==x[i][j]&&((*c+*d)/2)==y[i][j])||(((*a+*b)/2)==dx[i][j]&&((*c+*d)/2)==dy[i][j]))&&p==1)
         {
            u=*e;
            v=*f;
            setcolor(12);
            circle(u,v,30);
            circle(u,v,29);
            hareket1(a,b,c,d,e,f);
            q=1;
            break;
         }
         else if(((((*a+*b)/2)==tasx[i][j]&&((*c+*d)/2)==tasy[i][j])||(((*a+*b)/2)==damax[i][j]&&((*c+*d)/2)==damay[i][j]))&&p==0)
         {
            u=*e;
            v=*f;
            setcolor(12);
            circle(u,v,30);
            circle(u,v,29);
            hareket1(a,b,c,d,e,f);
            q=1;
            break;
         }}
         if(q==1) break;}
         if(q==0) oyuncu1(a,b,c,d,e,f);
         break;
      }
      if (tus==75&&*a>100){*a-=100; *b-=100; *e-=100; z--;}
      if (tus==77&&*b<700){*b+=100; *a+=100; *e+=100; z++;}
      if (tus==72&&*c>100){*c-=100; *d-=100; *f-=100; w--;}
      if (tus==80&&*d<700){*d+=100; *c+=100; *f+=100; w++;}
      ciz(a,b,c,d,e,f);
      setvisualpage(sayfano);
      setactivepage(1-sayfano);
      ++sayfano%=2;
      ciz(a,b,c,d,e,f);
   } while (tus!=27);
}

void oyuncu2(int *a,int *b,int *c,int *d,int *e,int *f)
{
   int i,j,q=0,p=0,k,l,x[4][8],y[4][8],dx[4][8],dy[4][8],m,n,o,g; char tus;
   for(i=2;i<4;i++)
   for(j=0;j<8;j++)
   x[i][j]=y[i][j]=dx[i][j]=dy[i][j]=-20;
   do
   {
      setactivepage(1-sayfano);
      ++sayfano%=2;
      outtextxy(820,100,"Oynama Sýrasý: 2. Oyuncu (Beyaz)");
      setactivepage(1-sayfano);
      ++sayfano%=2;
      if (kbhit()) cleardevice();
      tus=getch();
      if (tus==13)
      {
         w1=w;
         z1=z;
         for(i=2;i<4;i++)
         for(j=0;j<8;j++)
         for(k=0;k<2;k++)
         for(l=0;l<8;l++)
         {
            if((tasx[i][j]+100==tasx[k][l]&&tasy[i][j]==tasy[k][l]||tasx[i][j]+100==damax[k][l]&&tasy[i][j]==damay[k][l])&&sinir[((tasy[i][j]-50)/100)+2][((tasx[i][j]-50)/100)+4]==0)
            {
               x[i][j]=tasx[i][j];
               y[i][j]=tasy[i][j];
               p=1;
            }
            if((tasx[i][j]-100==tasx[k][l]&&tasy[i][j]==tasy[k][l]||tasx[i][j]-100==damax[k][l]&&tasy[i][j]==damay[k][l])&&sinir[((tasy[i][j]-50)/100)+2][((tasx[i][j]-50)/100)]==0)
            {
               x[i][j]=tasx[i][j];
               y[i][j]=tasy[i][j];
               p=1;
            }
            if((tasx[i][j]==tasx[k][l]&&tasy[i][j]+100==tasy[k][l]||tasx[i][j]==damax[k][l]&&tasy[i][j]+100==damay[k][l])&&sinir[((tasy[i][j]-50)/100)+4][((tasx[i][j]-50)/100)+2]==0)
            {
               x[i][j]=tasx[i][j];
               y[i][j]=tasy[i][j];
               p=1;
            }
         }
         for(m=100,g=2;700>m;m+=100,g++)
         for(i=2;i<4;i++)
         for(j=0;j<8;j++)
         for(k=0;k<2;k++)
         for(l=0;l<8;l++)
         for(n=2;n<4;n++)
         for(o=0;o<8;o++)
         if((((damax[i][j]==tasx[k][l]&&damay[i][j]+m==tasy[k][l])||(damax[i][j]==damax[k][l]&&damay[i][j]+m==damay[k][l]))&&sinir[((damay[i][j]-50)/100)+g+2][((damax[i][j]-50)/100)+2]==0&&(sinir[((damay[i][j]-50)/100)+g][((damax[i][j]-50)/100)+2]==0||(damax[i][j]==damax[n][o]&&damay[i][j]+m-100==damay[n][o]))||(((damax[i][j]==tasx[k][l]&&damay[i][j]-m==tasy[k][l])||(damax[i][j]==damax[k][l]&&damay[i][j]-m==damay[k][l]))&&sinir[((damax[i][j]-50)/100)-g+2][((damay[i][j]-50)/100)+2]==0&&(sinir[((damay[i][j]-50)/100)-g+4][((damax[i][j]-50)/100)+2]==0||(damax[i][j]==damax[n][o]&&damay[i][j]-m+100==damay[n][o])))||(((damax[i][j]-m==tasx[k][l]&&damay[i][j]==tasy[k][l])||(damax[i][j]-m==damax[k][l]&&damay[i][j]==damay[k][l]))&&sinir[((damay[i][j]-50)/100)+2][((damax[i][j]-50)/100)-g+2]==0&&(sinir[((damay[i][j]-50)/100)+2][((damax[i][j]-50)/100)-g+4]==0||(damax[i][j]-m+100==damax[n][o]&&damay[i][j]==damay[n][o])))||(((damax[i][j]+m==tasx[k][l]&&damay[i][j]==tasy[k][l])||(damax[i][j]+m==damax[k][l]&&damay[i][j]==damay[k][l]))&&sinir[((damay[i][j]-50)/100)+2][((damax[i][j]-50)/100)+g+2]==0&&(sinir[((damay[i][j]-50)/100)+2][((damax[i][j]-50)/100)+g]==0||(damax[i][j]+m-100==damax[n][o]&&damay[i][j]==damay[n][o])))))
         {
            dx[i][j]=damax[i][j];
            dy[i][j]=damay[i][j];
            p=1;
         }
         if(p==1)
         setactivepage(1-sayfano);
         ++sayfano%=2;
         outtextxy(820,500,"Yemek Zorunludur.");
         setactivepage(1-sayfano);
         ++sayfano%=2;
         for(i=2;i<4;i++){
         for(j=0;j<8;j++){
         if(((((*a+*b)/2)==x[i][j]&&((*c+*d)/2)==y[i][j])||(((*a+*b)/2)==dx[i][j]&&((*c+*d)/2)==dy[i][j]))&&p==1)
         {
            u=*e;
            v=*f;
            setcolor(12);
            circle(u,v,30);
            circle(u,v,29);
            hareket2(a,b,c,d,e,f);
            q=1;
            break;
         }
         else if(((((*a+*b)/2)==tasx[i][j]&&((*c+*d)/2)==tasy[i][j])||(((*a+*b)/2)==damax[i][j]&&((*c+*d)/2)==damay[i][j]))&&p==0)
         {
            u=*e;
            v=*f;
            setcolor(12);
            circle(u,v,30);
            circle(u,v,29);
            hareket2(a,b,c,d,e,f);
            q=1;
            break;
         }}
         if(q==1) break;}
         if(q==0) oyuncu2(a,b,c,d,e,f);
         break;
      }
      if (tus==75&&*a>100){*a-=100; *b-=100; *e-=100; z--;}
      if (tus==77&&*b<700){*b+=100; *a+=100; *e+=100; z++;}
      if (tus==72&&*c>100){*c-=100; *d-=100; *f-=100; w--;}
      if (tus==80&&*d<700){*d+=100; *c+=100; *f+=100; w++;}
      ciz(a,b,c,d,e,f);
      setvisualpage(sayfano);
      setactivepage(1-sayfano);
      ++sayfano%=2;
      ciz(a,b,c,d,e,f);
   } while (tus!=27);
}

void damahareket1(int *a,int *b,int *c,int *d,int *e,int *f)
{
     int x,y,i,j,q=0,k,l,m,n,o,say=0,w2,z2,h,g,p=0; char tus;
     while(1)
     {
        setactivepage(1-sayfano);
        ++sayfano%=2;
        outtextxy(820,100,"Oynama Sýrasý: 1. Oyuncu (Siyah)");
        setactivepage(1-sayfano);
        ++sayfano%=2;
        x=(*a+*b)/2;
        y=(*c+*d)/2;
        w2=w1;
        z2=z1;
        for(i=0;i<2;i++)
        for(j=0;j<8;j++)
        if(x==damax[i][j]&&y==damay[i][j])
        {
           do
           {  
              if (kbhit()) cleardevice();
              setactivepage(1-sayfano);
              ++sayfano%=2;
              outtextxy(820,100,"Oynama Sýrasý: 1. Oyuncu (Siyah)");
              setcolor(12);
              circle(u,v,30);
              circle(u,v,29);
              setactivepage(1-sayfano);
              ++sayfano%=2;
              tus=getch();
              w2=w1;
              z2=z1;
              for(k=2;k<4;k++)
              for(l=0;l<8;l++)
              {
                 for(m=100;100*(w1-w)>m;m+=100)
                 if((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l]||((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*a+*b)/2)-damax[i][j]==0)
                 {
                    for(;w2>w+1;w2--)
                    if(sinir[w2-1][z]==1)
                    say++;
                    w2=w1;
                    if(say>1)
                    {
                       oyuncu1(a,b,c,d,e,f);
                       q=1;
                       break;
                    }
                    if(((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    damax[i][j]=(*a+*b)/2;
                    damay[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    for(;w2>w;w2--)
                    sinir[w2][z1]=0;
                    w2=w1;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sayac2++;
                    for(m=100,g=2;700>m;m+=100,g++)
                    for(k=2;k<4;k++)
                    for(l=0;l<8;l++)
                    for(n=0;n<2;n++)
                    for(o=0;o<8;o++)
                    if((((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l]))&&sinir[w+g][z]==0&&(sinir[w+g-2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)+m-100==damay[n][o]))||(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l]))&&sinir[w-g][z]==0&&(sinir[w-g+2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)-m+100==damay[n][o])))||(((((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z-g]==0&&(sinir[w][z-g+2]==0||(((*a+*b)/2)-m+100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))||(((((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z+g]==0&&(sinir[w][z+g-2]==0||(((*a+*b)/2)+m-100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       damahareket1(a,b,c,d,e,f);
                       break;
                    }
                    break;
                 }
                 for(m=100;100*(w-w1)>m;m+=100)
                 if((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l]||((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*a+*b)/2)-damax[i][j]==0)
                 {
                    for(;w-1>w2;w2++)
                    if(sinir[w2+1][z]==1)
                    say++;
                    w2=w1;
                    if(say>1)
                    {
                       oyuncu1(a,b,c,d,e,f);
                       q=1;
                       break;
                    }
                    if(((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    damax[i][j]=(*a+*b)/2;
                    damay[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    for(;w>w2;w2++)
                    sinir[w2][z1]=0;
                    w2=w1;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sayac2++;
                    for(k=0;k<2;k++)
                    for(l=0;l<8;l++)
                    if((sinir[w-1][z]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l])||(sinir[w+1][z]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l])||(sinir[w][z+1]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l])||(sinir[w][z-1]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l]))
                    p=1;
                    for(m=100,g=2;700>m;m+=100,g++)
                    for(k=2;k<4;k++)
                    for(l=0;l<8;l++)
                    for(n=0;n<2;n++)
                    for(o=0;o<8;o++)
                    if((((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l]))&&sinir[w+g][z]==0&&(sinir[w+g-2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)+m-100==damay[n][o]))||(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l]))&&sinir[w-g][z]==0&&(sinir[w-g+2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)-m+100==damay[n][o])))||(((((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z-g]==0&&(sinir[w][z-g+2]==0||(((*a+*b)/2)-m+100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))||(((((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z+g]==0&&(sinir[w][z+g-2]==0||(((*a+*b)/2)+m-100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       damahareket1(a,b,c,d,e,f);
                       break;
                    }
                    break;
                 }
                 for(m=100;100*(z-z1)>m;m+=100)
                 if((((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*c+*d)/2)-damay[i][j]==0)
                 {
                    for(;z-1>z2;z2++)
                    if(sinir[w][z2+1]==1)
                    say++;
                    z2=z1;
                    if(say>1)
                    {
                       oyuncu1(a,b,c,d,e,f);
                       q=1;
                       break;
                    }
                    if(((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    damax[i][j]=(*a+*b)/2;
                    damay[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    for(;z>z2;z2++)
                    sinir[w1][z2]=0;
                    z2=z1;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sayac2++;
                    for(k=0;k<2;k++)
                    for(l=0;l<8;l++)
                    if((sinir[w-1][z]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l])||(sinir[w+1][z]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l])||(sinir[w][z+1]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l])||(sinir[w][z-1]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l]))
                    p=1;
                    for(m=100,g=2;700>m;m+=100,g++)
                    for(k=2;k<4;k++)
                    for(l=0;l<8;l++)
                    for(n=0;n<2;n++)
                    for(o=0;o<8;o++)
                    if((((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l]))&&sinir[w+g][z]==0&&(sinir[w+g-2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)+m-100==damay[n][o]))||(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l]))&&sinir[w-g][z]==0&&(sinir[w-g+2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)-m+100==damay[n][o])))||(((((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z-g]==0&&(sinir[w][z-g+2]==0||(((*a+*b)/2)-m+100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))||(((((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z+g]==0&&(sinir[w][z+g-2]==0||(((*a+*b)/2)+m-100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       damahareket1(a,b,c,d,e,f);
                       break;
                    }
                    break;
                 }
                 for(m=100;100*(z1-z)>m;m+=100)
                 if((((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*c+*d)/2)-damay[i][j]==0)
                 {
                    for(;z2>z+1;z2--)
                    if(sinir[w][z2-1]==1)
                    say++;
                    z2=z1;
                    if(say>1)
                    {
                       oyuncu1(a,b,c,d,e,f);
                       q=1;
                       break;
                    }
                    if(((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    damax[i][j]=(*a+*b)/2;
                    damay[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    for(;z2>z;z2--)
                    sinir[w1][z2]=0;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sayac2++;
                    for(k=0;k<2;k++)
                    for(l=0;l<8;l++)
                    if((sinir[w-1][z]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l])||(sinir[w+1][z]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l])||(sinir[w][z+1]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l])||(sinir[w][z-1]==1&&((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)==damay[k][l]))
                    p=1;
                    for(m=100,g=2;700>m;m+=100,g++)
                    for(k=2;k<4;k++)
                    for(l=0;l<8;l++)
                    for(n=0;n<2;n++)
                    for(o=0;o<8;o++)
                    if((((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l]))&&sinir[w+g][z]==0&&(sinir[w+g-2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)+m-100==damay[n][o]))||(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l]))&&sinir[w-g][z]==0&&(sinir[w-g+2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)-m+100==damay[n][o])))||(((((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z-g]==0&&(sinir[w][z-g+2]==0||(((*a+*b)/2)-m+100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))||(((((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z+g]==0&&(sinir[w][z+g-2]==0||(((*a+*b)/2)+m-100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       damahareket1(a,b,c,d,e,f);
                       break;
                    }
                    break;
                 }
                 if (q==1) break;
              }
              cleardevice();
              ciz(a,b,c,d,e,f);
              setvisualpage(sayfano);
              setactivepage(1-sayfano);
              ++sayfano%=2;
              ciz(a,b,c,d,e,f);
              if (q==1) break;
                 for(m=100,h=1;800>m;m+=100,h++){
                 for(n=2;n<4;n++){
                 for(o=0;o<8;o++)
                 if((x==tasx[n][o]&&y-m==tasy[n][o]||x==damax[n][o]&&y-m==damay[n][o])&&sinir[w-h-1][z]==0&&sinir[w-h+1][z]==0)
                 {
                 p=1;
                 break;
                 }
                 if((x==tasx[n][o]&&y-m==tasy[n][o]||x==damax[n][o]&&y-m==damay[n][o])&&sinir[w-h-1][z]==0&&sinir[w-h+1][z]==0)
                 break;}
                 if((x==tasx[n][o]&&y-m==tasy[n][o]||x==damax[n][o]&&y-m==damay[n][o])&&sinir[w-h-1][z]==0&&sinir[w-h+1][z]==0)
                 break;}
                 for(m=100,h=1;800>m;m+=100,h++){
                 for(n=2;n<4;n++){
                 for(o=0;o<8;o++)
                 if((x==tasx[n][o]&&y+m==tasy[n][o]||x==damax[n][o]&&y+m==damay[n][o])&&sinir[w+h+1][z]==0&&sinir[w+h-1][z]==0)
                 {
                 p=1;
                 break;
                 }
                 if((x==tasx[n][o]&&y+m==tasy[n][o]||x==damax[n][o]&&y+m==damay[n][o])&&sinir[w+h+1][z]==0&&sinir[w+h-1][z]==0)
                 break;}
                 if((x==tasx[n][o]&&y+m==tasy[n][o]||x==damax[n][o]&&y+m==damay[n][o])&&sinir[w+h+1][z]==0&&sinir[w+h-1][z]==0)
                 break;}
                 for(m=100,h=1;800>m;m+=100,h++){
                 for(n=2;n<4;n++){
                 for(o=0;o<8;o++)
                 if((x-m==tasx[n][o]&&y==tasy[n][o]||x-m==damax[n][o]&&y==damay[n][o])&&sinir[w][z-h-1]==0&&sinir[w][z-h+1]==0)
                 {
                 p=1;
                 break;
                 }
                 if((x-m==tasx[n][o]&&y==tasy[n][o]||x-m==damax[n][o]&&y==damay[n][o])&&sinir[w][z-h-1]==0&&sinir[w][z-h+1]==0)
                 break;}
                 if((x-m==tasx[n][o]&&y==tasy[n][o]||x-m==damax[n][o]&&y==damay[n][o])&&sinir[w][z-h-1]==0&&sinir[w][z-h+1]==0)
                 break;}
                 for(m=100,h=1;800>m;m+=100,h++){
                 for(n=2;n<4;n++){
                 for(o=0;o<8;o++)
                 if((x+m==tasx[n][o]&&y==tasy[n][o]||x+m==damax[n][o]&&y==damay[n][o])&&sinir[w][z+h+1]==0&&sinir[w][z+h-1]==0)
                 {
                 p=1;
                 break;
                 }
                 if((x+m==tasx[n][o]&&y==tasy[n][o]||x+m==damax[n][o]&&y==damay[n][o])&&sinir[w][z+h+1]==0&&sinir[w][z+h-1]==0)
                 break;}
                 if((x+m==tasx[n][o]&&y==tasy[n][o]||x+m==damax[n][o]&&y==damay[n][o])&&sinir[w][z+h+1]==0&&sinir[w][z+h-1]==0)
                 break;}
              if (tus==13&&sinir[w][z]==0&&((damay[i][j]-((*c+*d)/2)==0)||(((*a+*b)/2)-damax[i][j]==0))&&p==0)
              {
                 damax[i][j]=(*a+*b)/2;
                 damay[i][j]=(*c+*d)/2;
                 sinir[w][z]=1;
                 sinir[w1][z1]=0;
                 ciz(a,b,c,d,e,f);
                 setvisualpage(sayfano);
                 setactivepage(1-sayfano);
                 ++sayfano%=2;
                 ciz(a,b,c,d,e,f);
                 q=1;
                 break;
              }
              if (tus==75&&*a>100){*a-=100; *b-=100; *e-=100; z--;}
              if (tus==77&&*b<700){*b+=100; *a+=100; *e+=100; z++;}
              if (tus==72&&*c>100){*c-=100; *d-=100; *f-=100; w--;}
              if (tus==80&&*d<700){*d+=100; *c+=100; *f+=100; w++;}
              ciz(a,b,c,d,e,f);
              setvisualpage(sayfano);
              setactivepage(1-sayfano);
              ++sayfano%=2;
              ciz(a,b,c,d,e,f);
           } while(q==0);
        }
        if (q==1) break;
        if (kbhit()) cleardevice();
        setactivepage(1-sayfano);
        ++sayfano%=2;
        outtextxy(820,100,"Oynama Sýrasý: 1. Oyuncu (Siyah)");
        setactivepage(1-sayfano);
        ++sayfano%=2;
        tus=getch();
        if (tus==75&&*a>100){*a-=100; *b-=100; *e-=100; z--;}
        if (tus==77&&*b<700){*b+=100; *a+=100; *e+=100; z++;}
        if (tus==72&&*c>100){*c-=100; *d-=100; *f-=100; w--;}
        if (tus==80&&*d<700){*d+=100; *c+=100; *f+=100; w++;}
        ciz(a,b,c,d,e,f);
        setvisualpage(sayfano);
        setactivepage(1-sayfano);
        ++sayfano%=2;
        ciz(a,b,c,d,e,f);
     }
}

void damahareket2(int *a,int *b,int *c,int *d,int *e,int *f)
{
     int x,y,i,j,q=0,k,l,m,n,o,say=0,w2,z2,h,g,p=0; char tus;
     while(1)
     {
        setactivepage(1-sayfano);
        ++sayfano%=2;
        outtextxy(820,100,"Oynama Sýrasý: 2. Oyuncu (Beyaz)");
        setactivepage(1-sayfano);
        ++sayfano%=2;
        x=(*a+*b)/2;
        y=(*c+*d)/2;
        w2=w1;
        z2=z1;
        for(i=2;i<4;i++)
        for(j=0;j<8;j++)
        if(x==damax[i][j]&&y==damay[i][j])
        {
           do
           {  
              if (kbhit()) cleardevice();
              setactivepage(1-sayfano);
              ++sayfano%=2;
              outtextxy(820,100,"Oynama Sýrasý: 2. Oyuncu (Beyaz)");
              setcolor(12);
              circle(u,v,30);
              circle(u,v,29);
              setactivepage(1-sayfano);
              ++sayfano%=2;
              tus=getch();
              for(k=0;k<2;k++)
              for(l=0;l<8;l++)
              {
                 for(m=0;100*(w-w1)>m;m+=100)
                 if((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l]||((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*a+*b)/2)-damax[i][j]==0)
                 {
                    for(;w-1>w2;w2++)
                    if(sinir[w2+1][z]==1)
                    say++;
                    w2=w1;
                    if(say>1)
                    {
                       oyuncu2(a,b,c,d,e,f);
                       q=1;
                       break;
                    }
                    if(((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    damax[i][j]=(*a+*b)/2;
                    damay[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    for(;w>w2;w2++)
                    sinir[w2][z1]=0;
                    w2=w1;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sayac1++;
                    for(m=100,g=2;700>m;m+=100,g++)
                    for(k=0;k<2;k++)
                    for(l=0;l<8;l++)
                    for(n=2;n<4;n++)
                    for(o=0;o<8;o++)
                    if((((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l]))&&sinir[w+g][z]==0&&(sinir[w+g-2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)+m-100==damay[n][o]))||(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l]))&&sinir[w-g][z]==0&&(sinir[w-g+2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)-m+100==damay[n][o])))||(((((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z-g]==0&&(sinir[w][z-g+2]==0||(((*a+*b)/2)-m+100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))||(((((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z+g]==0&&(sinir[w][z+g-2]==0||(((*a+*b)/2)+m-100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       damahareket2(a,b,c,d,e,f);
                    }
                    break;
                 }
                 for(m=0;100*(w1-w)>m;m+=100)
                 if((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l]||((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*a+*b)/2)-damax[i][j]==0)
                 {
                    for(;w2>w+1;w2--)
                    if(sinir[w2-1][z]==1)
                    say++;
                    w2=w1;
                    if(say>1)
                    {
                       oyuncu2(a,b,c,d,e,f);
                       q=1;
                       break;
                    }
                    if(((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    damax[i][j]=(*a+*b)/2;
                    damay[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    for(;w2>w;w2--)
                    sinir[w2][z1]=0;
                    w2=w1;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sayac1++;
                    for(m=100,g=2;700>m;m+=100,g++)
                    for(k=0;k<2;k++)
                    for(l=0;l<8;l++)
                    for(n=2;n<4;n++)
                    for(o=0;o<8;o++)
                    if((((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l]))&&sinir[w+g][z]==0&&(sinir[w+g-2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)+m-100==damay[n][o]))||(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l]))&&sinir[w-g][z]==0&&(sinir[w-g+2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)-m+100==damay[n][o])))||(((((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z-g]==0&&(sinir[w][z-g+2]==0||(((*a+*b)/2)-m+100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))||(((((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z+g]==0&&(sinir[w][z+g-2]==0||(((*a+*b)/2)+m-100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       damahareket2(a,b,c,d,e,f);
                    }
                    break;
                 }
                 for(m=0;100*(z-z1)>m;m+=100)
                 if((((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*c+*d)/2)-damay[i][j]==0)
                 {
                    for(;z-1>z2;z2++)
                    if(sinir[w][z2+1]==1)
                    say++;
                    z2=z1;
                    if(say>1)
                    {
                       oyuncu2(a,b,c,d,e,f);
                       q=1;
                       break;
                    }
                    if(((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    damax[i][j]=(*a+*b)/2;
                    damay[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    for(;z>z2;z2++)
                    sinir[w1][z2]=0;
                    z2=z1;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sayac1++;
                    for(m=100,g=2;700>m;m+=100,g++)
                    for(k=0;k<2;k++)
                    for(l=0;l<8;l++)
                    for(n=2;n<4;n++)
                    for(o=0;o<8;o++)
                    if((((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l]))&&sinir[w+g][z]==0&&(sinir[w+g-2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)+m-100==damay[n][o]))||(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l]))&&sinir[w-g][z]==0&&(sinir[w-g+2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)-m+100==damay[n][o])))||(((((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z-g]==0&&(sinir[w][z-g+2]==0||(((*a+*b)/2)-m+100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))||(((((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z+g]==0&&(sinir[w][z+g-2]==0||(((*a+*b)/2)+m-100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       damahareket2(a,b,c,d,e,f);
                    }
                    break;
                 }
                 for(m=0;100*(z1-z)>m;m+=100)
                 if((((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l]||((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l])&&tus==13&&sinir[w][z]==0&&((*c+*d)/2)-damay[i][j]==0)
                 {
                    for(;z2>z+1;z2--)
                    if(sinir[w][z2-1]==1)
                    say++;
                    z2=z1;
                    if(say>1)
                    {
                       oyuncu2(a,b,c,d,e,f);
                       q=1;
                       break;
                    }
                    if(((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])
                    {
                       tasx[k][l]=-20;
                       tasy[k][l]=-20;
                    }
                    if(((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l])
                    {
                       damax[k][l]=-20;
                       damay[k][l]=-20;
                    }
                    damax[i][j]=(*a+*b)/2;
                    damay[i][j]=(*c+*d)/2;
                    sinir[w][z]=1;
                    for(;z2>z;z2--)
                    sinir[w1][z2]=0;
                    z2=z1;
                    ciz(a,b,c,d,e,f);
                    q=1;
                    sayac1++;
                    for(m=100,g=2;700>m;m+=100,g++)
                    for(k=0;k<2;k++)
                    for(n=2;n<4;n++)
                    for(o=0;o<8;o++)
                    if((((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)+m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)+m==damay[k][l]))&&sinir[w+g][z]==0&&(sinir[w+g-2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)+m-100==damay[n][o]))||(((((*a+*b)/2)==tasx[k][l]&&((*c+*d)/2)-m==tasy[k][l])||(((*a+*b)/2)==damax[k][l]&&((*c+*d)/2)-m==damay[k][l]))&&sinir[w-g][z]==0&&(sinir[w-g+2][z]==0||(((*a+*b)/2)==damax[n][o]&&((*c+*d)/2)-m+100==damay[n][o])))||(((((*a+*b)/2)-m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)-m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z-g]==0&&(sinir[w][z-g+2]==0||(((*a+*b)/2)-m+100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))||(((((*a+*b)/2)+m==tasx[k][l]&&((*c+*d)/2)==tasy[k][l])||(((*a+*b)/2)+m==damax[k][l]&&((*c+*d)/2)==damay[k][l]))&&sinir[w][z+g]==0&&(sinir[w][z+g-2]==0||(((*a+*b)/2)+m-100==damax[n][o]&&((*c+*d)/2)==damay[n][o])))))
                    {
                       cleardevice();
                       ciz(a,b,c,d,e,f);
                       setvisualpage(sayfano);
                       setactivepage(1-sayfano);
                       ++sayfano%=2;
                       ciz(a,b,c,d,e,f);
                       u=*e;
                       v=*f;
                       setcolor(12);
                       circle(u,v,30);
                       circle(u,v,29);
                       w1=w;
                       z1=z;
                       damahareket2(a,b,c,d,e,f);
                    }
                    break;
                 }
                 if(q==1) break;
              }
              cleardevice();
              ciz(a,b,c,d,e,f);
              setvisualpage(sayfano);
              setactivepage(1-sayfano);
              ++sayfano%=2;
              ciz(a,b,c,d,e,f);
              if (q==1) break;
                 for(m=100,h=1;800>m;m+=100,h++){
                 for(n=0;n<2;n++){
                 for(o=0;o<8;o++)
                 if((x==tasx[n][o]&&y-m==tasy[n][o]||x==damax[n][o]&&y-m==damay[n][o])&&sinir[w-h-1][z]==0&&sinir[w-h+1][z]==0)
                 {
                 p=1;
                 break;
                 }
                 if(x==tasx[n][o]&&y-m==tasy[n][o]||x==damax[n][o]&&y-m==damay[n][o])
                 break;}
                 if(x==tasx[n][o]&&y-m==tasy[n][o]||x==damax[n][o]&&y-m==damay[n][o])
                 break;}
                 for(m=100,h=1;800>m;m+=100,h++){
                 for(n=0;n<2;n++){
                 for(o=0;o<8;o++)
                 if((x==tasx[n][o]&&y+m==tasy[n][o]||x==damax[n][o]&&y+m==damay[n][o])&&sinir[w+h+1][z]==0&&sinir[w+h-1][z]==0)
                 {
                 p=1;
                 break;
                 }
                 if(x==tasx[n][o]&&y+m==tasy[n][o]||x==damax[n][o]&&y+m==damay[n][o])
                 break;}
                 if(x==tasx[n][o]&&y+m==tasy[n][o]||x==damax[n][o]&&y+m==damay[n][o])
                 break;}
                 for(m=100,h=1;800>m;m+=100,h++){
                 for(n=0;n<2;n++){
                 for(o=0;o<8;o++)
                 if((x-m==tasx[n][o]&&y==tasy[n][o]||x-m==damax[n][o]&&y==damay[n][o])&&sinir[w][z-h-1]==0&&sinir[w][z-h+1]==0)
                 {
                 p=1;
                 break;
                 }
                 if(x-m==tasx[n][o]&&y==tasy[n][o]||x-m==damax[n][o]&&y==damay[n][o])
                 break;}
                 if(x-m==tasx[n][o]&&y==tasy[n][o]||x-m==damax[n][o]&&y==damay[n][o])
                 break;}
                 for(m=100,h=1;800>m;m+=100,h++){
                 for(n=0;n<2;n++){
                 for(o=0;o<8;o++)
                 if((x+m==tasx[n][o]&&y==tasy[n][o]||x+m==damax[n][o]&&y==damay[n][o])&&sinir[w][z+h+1]==0&&sinir[w][z+h-1]==0)
                 {
                 p=1;
                 break;
                 }
                 if(x+m==tasx[n][o]&&y==tasy[n][o]||x+m==damax[n][o]&&y==damay[n][o])
                 break;}
                 if(x+m==tasx[n][o]&&y==tasy[n][o]||x+m==damax[n][o]&&y==damay[n][o])
                 break;}
              if (tus==13&&sinir[w][z]==0&&((damay[i][j]-((*c+*d)/2)==0)||(((*a+*b)/2)-damax[i][j]==0))&&p==0)
              {
                 damax[i][j]=(*a+*b)/2;
                 damay[i][j]=(*c+*d)/2;
                 sinir[w][z]=1;
                 sinir[w1][z1]=0;
                 ciz(a,b,c,d,e,f);
                 setvisualpage(sayfano);
                 setactivepage(1-sayfano);
                 ++sayfano%=2;
                 ciz(a,b,c,d,e,f);
                 q=1;
                 break;
              }
              if (tus==75&&*a>100){*a-=100; *b-=100; *e-=100; z--;}
              if (tus==77&&*b<700){*b+=100; *a+=100; *e+=100; z++;}
              if (tus==72&&*c>100){*c-=100; *d-=100; *f-=100; w--;}
              if (tus==80&&*d<700){*d+=100; *c+=100; *f+=100; w++;}
              ciz(a,b,c,d,e,f);
              setvisualpage(sayfano);
              setactivepage(1-sayfano);
              ++sayfano%=2;
              ciz(a,b,c,d,e,f);
           } while(q==0);
        }
        if (q==1) break;
        if (kbhit()) cleardevice();
        setactivepage(1-sayfano);
        ++sayfano%=2;
        outtextxy(820,100,"Oynama Sýrasý: 2. Oyuncu (Beyaz)");
        setactivepage(1-sayfano);
        ++sayfano%=2;
        tus=getch();
        if (tus==75&&*a>100){*a-=100; *b-=100; *e-=100; z--;}
        if (tus==77&&*b<700){*b+=100; *a+=100; *e+=100; z++;}
        if (tus==72&&*c>100){*c-=100; *d-=100; *f-=100; w--;}
        if (tus==80&&*d<700){*d+=100; *c+=100; *f+=100; w++;}
        ciz(a,b,c,d,e,f);
        setvisualpage(sayfano);
        setactivepage(1-sayfano);
        ++sayfano%=2;
        ciz(a,b,c,d,e,f);
     }
}

void son1()
{
      setactivepage(1-sayfano);
      ++sayfano%=2;
      setfillstyle(1,3);
      bar(400,350,650,450);
      setcolor(9);
      outtextxy(480,390,"TEBRÝKLER");
      outtextxy(430,410,"Kazanan: 1. Oyuncu (Siyah)");
}

void son2()
{
      setactivepage(1-sayfano);
      ++sayfano%=2;
      setfillstyle(1,4);
      bar(400,350,650,450);
      setcolor(9);
      outtextxy(480,390,"TEBRÝKLER");
      outtextxy(430,410,"Kazanan: 2. Oyuncu (Beyaz)");
}

void girisciz(int *a,int *b,int *c,int *d,int *e,int *f,int *g,int *h,int *i,int *j)
{
   if(*a>50)
   circle(525,400,*a);
   if(*b>50)
   circle(525,400,*b);
   if(*c>50)
   circle(525,400,*c);
   if(*d>50)
   circle(525,400,*d);
   if(*e>50)
   circle(525,400,*e);
   if(*f>50)
   circle(525,400,*f);
   if(*g>50)
   circle(525,400,*g);
   if(*h>50)
   circle(525,400,*h);
   if(*i>50)
   circle(525,400,*i);
   if(*j>50)
   circle(525,400,*j);
}

void giris() 
{
int sayfano=1,a=50,b=-50,c=-150,d=-250,e=-350,f=-450,g=-550,h=-650,i=-750,j=-850;
do
{
cleardevice();
settextstyle(0,0,15);
outtextxy(480,387,"DAMA");
girisciz(&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
setvisualpage(sayfano);
delay(10);
setactivepage(1-sayfano);
++sayfano%=2;
if(a==1050)
   a=50;
if(b==1050)
   b=50;
if(c==1050)
   c=50;
if(d==1050)
   d=50;
if(e==1050)
   e=50;
if(f==1050)
   f=50;
if(g==1050)
   g=50;
if(h==1050)
   h=50;
if(i==1050)
   i=50;
if(j==1050)
   j=50;
   a++;
   b++;
   c++;
   d++;
   e++;
   f++;
   g++;
   h++;
   i++;
   j++;
} while(!kbhit());
}

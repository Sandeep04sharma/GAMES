#include<windows.h>
#include<time.h>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void Display(char [8][8]);
COORD coord={0,0}; // this is global variable
                                   //center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y)
{
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Display(char Board[8][8])
{
 system("CLS");
 int i;
 cout<<"\t\t\t"<<"       LET'S HAVE A FUN WITH CHECKERS GAME !!!!!!"<<"\n\n";

 for(i=0;i<8;i++)
 {
  cout<<"  \t  +---+---+---+---+---+---+---+---+"<<endl;
  //textcolor("BLUE");
  cout<<"\t"<<i+1<<" | "<<Board[i][0]<<" | "<<Board[i][1]<<" | "<<Board[i][2]<<" | "<<Board[i][3]<<" | "<<Board[i][4]<<" | "<<Board[i][5]<<" | "<<Board[i][6]<<" | "<<Board[i][7]<<" |"<<endl;
 }
 cout<<"  \t  +---+---+---+---+---+---+---+---+"<<endl;
 cout<<"  \t    A   B   C   D   E   F   G   H  \n\n"<<endl;
}

void ccolor(){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, clr);
SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
//the above code displays colorful background. if you want colorful then you can remove the above comment but not the code, only comment//
}


int main()
{ char *wlcm[5]={"WELCOME","     TO","       THE","     CHECKERS"," GAME !!!"};
for(int i=0;i<5;i++)
{
 cout<<"\n\n"<<"\t\t\t"<<wlcm[i]<<"  ";
 Sleep(500);
}
Sleep(1000);
system("CLS");
Intro:
srand(time(0));
system("CLS");
int i,j,X,Y,dir,Pla,Opp,yolo=0,limit=0;
char Board[8][8],A,B,pos[2];
for(i=0;i<8;i++)
{
 for(j=0;j<8;j++)
 Board[i][j]=' ';
}
cout<<"\t\t\t"<<"       LET'S HAVE A FUN WITH CHECKERS GAME !!!!!!"<<"\n\n";
cout<<"   The Rules are as usual:"<<endl<<endl;
cout<<"   In the End, Player which will have his/her tokens left Wins the Game"<<"\n\n";
cout<<"   !    @    #    $    %    ^    &    *    (    )    /    -    +    = "<<endl<<endl;
Sleep(3000);
cout<<"   Enter Your Token Symbol: "; cin>>A;
cout<<"   Enter Opponent's Token Symbol: "; cin>>B;
if(A==B)
{
 cout<<endl<<"\t\t"<<"LOL !!! Both the Tokens are Same........";
 Sleep(1000);
 goto Intro;
}
char tICK = A;
char Tick = B;
system("cls");
//
char *Quote[5]={"AND","    THE","       GAME","       STARTS"," NOW ....."};
for(i=0;i<5;i++)
{
 cout<<"\n\n"<<"\t\t\t"<<Quote[i]<<"  ";
 Sleep(500);
}
Sleep(1000);
ccolor();

Board[0][0] = B; Board[0][2] = B; Board[0][4] = B; Board[0][6] = B;
Board[1][1] = B; Board[1][3] = B; Board[1][5] = B; Board[1][7] = B;
Board[2][0] = B; Board[2][2] = B; Board[2][4] = B; Board[2][6] = B;
Board[5][1] = A; Board[5][3] = A; Board[5][5] = A; Board[5][7] = A;
Board[6][0] = A; Board[6][2] = A; Board[6][4] = A; Board[6][6] = A;
Board[7][1] = A; Board[7][3] = A; Board[7][5] = A; Board[7][7] = A;
// Your Turn
start:
Display(Board);
cout<<"Your ("<<A<<") Turn........";
Sleep(1000);
cout<<endl<<"Enter Position:( Like A1, G6, C3 etc. ) ";
gets(pos);
cout<<endl;

if(pos[0]=='A')
X = 0;
else if(pos[0]=='B')
X = 1;
else if(pos[0]=='C')
X = 2;
else if(pos[0]=='D')
X = 3;
else if(pos[0]=='E')
X = 4;
else if(pos[0]=='F')
X = 5;
else if(pos[0]=='G')
X = 6;
else if(pos[0]=='H')
X = 7;
else
{
 cout<<"Enter Again...";
 Sleep(500);
 goto start;
}
if(pos[1]=='1')
Y = 0;
else if(pos[1]=='2')
Y = 1;
else if(pos[1]=='3')
Y = 2;
else if(pos[1]=='4')
Y = 3;
else if(pos[1]=='5')
Y = 4;
else if(pos[1]=='6')
Y = 5;
else if(pos[1]=='7')
Y = 6;
else if(pos[1]=='8')
Y = 7;
else
{
 cout<<"Enter Again...";
 Sleep(500);
 goto start;
}

if(Board[Y][X]!=A)
{
 cout<<"Enter Again...";
 Sleep(500);
 goto start;
}
cout<<"Which Direction? "<<endl;
cout<<"1 (Upper-Left Diagonal) , 2 (Upper-Right Diagonal) "<<endl;
cout<<"3 (Lower-Left Diagonal) , 4 (Lower-Right Diagonal) "; cin>>dir;
A = tICK;
B = Tick;
// UL Diagonal//////////////////////1 1 1 1 11   111  1111  1  11 1  111  1 1 11 11 1 1 1  111111111111111111111111111111111111111111111111111
if(dir==1)
{
  if(X==0 || Y==0)
  {
   cout<<"Token can't move....";
   Sleep(500);
   goto start;
  }
  if(Board[Y-1][X-1]==A)
 {
   cout<<"Token can't move....";
   Sleep(500);
   goto start;
 }
 if(Board[Y-1][X-1]==' ')
 {
  Board[Y][X]=' ';
  Board[--Y][--X]=A;
  goto done1;
 }
 if(Board[Y-1][X-1]==B)
 {
  if(X<=1)
  {
   cout<<"Token can't move....";
   Sleep(500);
   goto start;
  }
  if(Board[Y-2][X-2]!=' ')
  {
   cout<<"Token can't move....";
   Sleep(500);
   goto start;
  }
  else
  {
   Board[Y][X]=' ';
   Board[Y-1][X-1]=' ';
   Y-=2; X-=2;
   Board[Y][X]=A;
   goto done1;
  }
 }
}
// UR Diagonal         2   2 2  2 2 2 2  2 2 2 2        2 2   2 222222222222 2222222222222
if(dir==2)
{
 if(X==7 || Y==0)
 {
  cout<<"Token can't move....";
  Sleep(500);
  goto start;
 }
 if(Board[Y-1][X+1]==A)
 {
  cout<<"Token can't move....";
  Sleep(500);
  goto start;
 }
 if(Board[Y-1][X+1]==' ')
 {
  Board[Y][X]=' ';
  Board[--Y][++X]=A;
  goto done1;
 }
 if(Board[Y-1][X+1]==B)
 {
  if(X>=6)
  {
   cout<<"Token can't move....";
   Sleep(500);
   goto start;
  }
  if(Board[Y-2][X+2]!=' ')
  {
   cout<<"Token can't move....";
   Sleep(500);
   goto start;
  }
  else
  {
   Board[Y][X]=' ';
   Board[Y-1][X+1]=' ';
   Y-=2; X+=2;
   Board[Y][X]=A;
   goto done1;
  }
 }
}
// DL Diagonal///////3/3/3/3/3/3/3/3/3/3/3/3/3/3/3/333333333333333///////////////333333333333333333333333333333
if(dir==3)
{
 if(X==0 || Y==7)
 {
  cout<<"Token can't move....";
  Sleep(500);
  goto start;
 }
 if(Board[Y+1][X-1]==A)
 {
  cout<<"Token can't move....";
  Sleep(500);
  goto start;
 }
 if(Board[Y+1][X-1]==' ')
 {
  Board[Y][X]=' ';
  Board[++Y][--X]=A;
  goto done1;
 }
 if(Board[Y+1][X-1]==B)
 {
  if(X<=1)
  {
   cout<<"Token can't move....";
   Sleep(500);
   goto start;
  }
  if(Board[Y+2][X-2]!=' ')
  {
   cout<<"Token can't move....";
   Sleep(500);
   goto start;
  }
  else
  {
   Board[Y][X]=' ';
   Board[Y+1][X-1]=' ';
   Y+=2; X-=2;
   Board[Y][X]=A;
   goto done1;
  }
 }
}
// DR Diagonal
if(dir==4)
{
 if(X==7 || Y==7)
 {
  cout<<"Token can't move....";
  Sleep(500);
  goto start;
 }
 if(Board[Y+1][X+1]==A)
 {
  cout<<"Token can't move....";
  Sleep(500);
  goto start;
 }
 if(Board[Y+1][X+1]==' ')
 {
  Board[Y][X]=' ';
  Board[++Y][++X]=A;
  goto done1;
 }
 if(Board[Y+1][X+1]==B)
 {
  if(X>=6)
  {
   cout<<"Token can't move....";
   Sleep(500);
   goto start;
  }
  if(Board[Y+2][X+2]!=' ')
  {
   cout<<"Token can't move....";
   Sleep(500);
   goto start;
  }
  else
  {
   Board[Y][X]=' ';
   Board[Y+1][X+1]=' ';
   Y+=2; X+=2;
   Board[Y][X]=A;
   goto done1;
  }
 }
}
done1:                                // Token /// /// ///// ////// ////

/////////// / / / / / / / / / / / / /  F O R  B B B B B B B B B B B B B BB B B B B  B B B B B B B B B B B B B B


Display(Board);
Sleep(500);
Pla=0; Opp=0;
A = tICK;
B = Tick;
for(i=0;i<8;i++)
{
 for(j=0;j<8;j++)
 {
  if(Board[i][j]==A)
  Pla++;
 }
}
for(i=0;i<8;i++)
{
 for(j=0;j<8;j++)
 {
  if(Board[i][j]==B)
  Opp++;
 }
}
if(Pla==0 || Opp==0)
goto end;
// Opponent's Turn
cout<<endl<<"Opponent's ("<<B<<") Turn........";
Sleep(1000);
Again:            //  TOKEN ///////// ///////////// /// TOKEN ////////// TOKEN ////////
if(limit==15)
{
 cout<<endl<<"Opponent got confused :-P";
 limit=0;
 Sleep(1000);
 goto start;
}
if(yolo==15)
{
 for(i=0;i<8;i++)
 {
  for(j=0;j<8;j++)
  {
   if(Board[i][j]==B);
   {
    Y = i;
    X = j;
   }
  }
 }
 yolo = 0;
 limit++;
}
else
{
 Y = rand()%8;
 X = rand()%8;
}
if(Board[Y][X]!=B)
goto Again;
dir = rand()%4 + 1;
if(Board[Y-1][X-1]==A && X>1 && Y>1)
dir = 1;
if(Board[Y-1][X+1]==A && X<6 && Y>1)
dir = 2;
if(Board[Y+1][X-1]==A && X>1 && Y<6)
dir = 3;
if(Board[Y+1][X+1]==A && X<6 && Y<6)
dir = 4;
A = tICK;
B = Tick;
// UL Diagonal  /  / / ////////////////// //1c1 1 111 1 11  1 11 1  1 11 1 ////// //////////
if(dir==1)
{
 if(X==0 || Y==0)
 { yolo++; goto Again; }
 if(Board[Y-1][X-1]==B)
 { yolo++; goto Again; }
 if(Board[Y-1][X-1]==' ')
 {
  Board[Y][X]=' ';
  Board[--Y][--X]=B;
  goto done2;
 }
 if(Board[Y-1][X-1]==A)
 {
  if(X>=1)
  { yolo++; goto Again; }
  if(Board[Y-2][X-2]!=' ')
  { yolo++; goto Again; }
  else
  {
   Board[Y][X]=' ';
   Board[Y-1][X-1]=' ';
   Y-=2; X-=2;
   Board[Y][X]=B;
   goto done2;
  }
 }
}
// UR Diagonal 2 /2 2/2 2 2/2 /2  /2/2 2 2/2 2 /2 2 /
if(dir==2)
{
 if(X==7 || Y==0)
 { yolo++; goto Again; }
 if(Board[Y-1][X+1]==B)
 { yolo++; goto Again; }
 if(Board[Y-1][X+1]==' ')
 {
  Board[Y][X]=' ';
  Board[--Y][++X]=B;
  goto done2;
 }
 if(Board[Y-1][X+1]==A)
 {
  if(X>=6)
  { yolo++; goto Again; }
  if(Board[Y-2][X+2]!=' ')
  { yolo++; goto Again; }
  else
  {
   Board[Y][X]=' ';
   Board[Y-1][X+1]=' ';
   Y-=2; X+=2;
   Board[Y][X]=B;
   goto done2;
  }
 }
}
// DL Diagonal  3 /3 / 3//33 3/3/3/ 333/3 3/3 3/ 3/3 3/  3 /3 33/3
if(dir==3)
{
 if(X==0 || Y==7)
 { yolo++; goto Again; }
 if(Board[Y+1][X-1]==B)
 { yolo++; goto Again; }
 if(Board[Y+1][X-1]==' ')
 {
  Board[Y][X]=' ';
  Board[++Y][--X]=B;
  goto done2;
 }
 if(Board[Y+1][X-1]==A)
 {
  if(X>=1)
  { yolo++; goto Again; }
  if(Board[Y+2][X-2]!=' ')
  { yolo++; goto Again; }
  else
  {
   Board[Y][X]=' ';
   Board[Y+1][X-1]=' ';
   Y+=2; X-=2;
   Board[Y][X]=B;
   goto done2;
  }
 }
}
// DR Diagonal / 4/4 4/4 4//4 /4/ 44/      /4/////////4    44444
if(dir==4)
{
 if(X==7 || Y==7)
 { yolo++; goto Again; }
 if(Board[Y+1][X+1]==B)
 { yolo++; goto Again; }
 if(Board[Y+1][X+1]==' ')
 {
  Board[Y][X]=' ';
  Board[++Y][++X]=B;
  goto done2;
 }
 if(Board[Y+1][X+1]==A)
 {
  if(X>=6)
  { yolo++; goto Again; }
  if(Board[Y+2][X+2]!=' ')
  { yolo++; goto Again; }
  else
  {
   Board[Y][X]=' ';
   Board[Y+1][X+1]=' ';
   Y+=2; X+=2;
   Board[Y][X]=B;
   goto done2;
  }
 }
}


done2:           /////// / TOKEN   /////


Display(Board);
Sleep(1000);
Pla=0; Opp=0;
A = tICK;
B = Tick;
for(i=0;i<8;i++)
{
 for(j=0;j<8;j++)
 {
  if(Board[i][j]==A)
  Pla++;
 }
}
for(i=0;i<8;i++)
{
 for(j=0;j<8;j++)
 {
  if(Board[i][j]==B)
  Opp++;
 }
}
if(Pla==0 || Opp==0)
goto end;
else
goto start;
end:      // / / / / // / T O K E N ////
system("CLS");
if(Pla>Opp)
{
 Sleep(2000);
 gotoxy(30,10);
 cout<<"YOU WON THE GAME !!!!!!";
}
if(Pla<Opp)
{
 Sleep(2000);
 gotoxy(30,10);
 cout<<"OPPONENT WON THE GAME !!!!!!";
}
if(Pla==Opp)
{
 Sleep(2000);
 gotoxy(30,10);
 cout<<"IT IS A DRAW !!!!!!";
}
getch();
}

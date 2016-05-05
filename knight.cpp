//The Knights Templar

#include <iostream>
#include<stdio.h>
#include<string.h>
//#include<oxymoron.h>

using namespace std;
int done=0,path[64][2];

int iseligible(int num)
{
	if (num>=0 && num<5)
	return 1;
	else return 0;
}

int generatechoices (int x, int y,int choices[][2])
{
	int count=-1;
	

	if (iseligible(x+1) && iseligible(y+2))
	{choices[++count][0]=x+1; choices[count][1]=y+2;} 

	if (iseligible(x-1) && iseligible(y+2))
	{choices[++count][0]=x-1; choices[count][1]=y+2;}

	if (iseligible(x+1) && iseligible(y-2))
	{choices[++count][0]=x+1; choices[count][1]=y-2;}

	if (iseligible(x-1) && iseligible(y-2))
	{choices[++count][0]=x-1; choices[count][1]=y-2;}

	if (iseligible(x+2) && iseligible(y+1))
	{choices[++count][0]=x+2; choices[count][1]=y+1;}

	if (iseligible(x+2) && iseligible(y-1))
	{choices[++count][0]=x+2; choices[count][1]=y-1;}

	if (iseligible(x-2) && iseligible(y+1))
	{choices[++count][0]=x-2; choices[count][1]=y+1;}

	if (iseligible(x-2) && iseligible(y-1))
	{choices[++count][0]=x-2; choices[count][1]=y-1;}

	return count;


}

void displaybeen(int been[][8])
{
	for (int i=0;i<8;++i)
		{cout<<"\n";
		for (int j=0;j<8;++j)
		cout<<been[i][j]<<" ";
		}

cout<<"\n\n\n\n";

return;
}

bool move(int x, int y, int been[][8],int knightplaced,int path[][2])
{
	int choices[8][2],xtemp,ytemp,count;

	//cout<<knightplaced<<'\n';
	//displaybeen(been);

	if (knightplaced==25)
	{done=1;return false;}

	if (!been[x][y])
	{been[x][y]=1; path[knightplaced][0]=x; path[knightplaced][1]=y;}
	else return false;
	knightplaced++;
	
	
	count=generatechoices(x,y,choices);

	for (int i=0;i<=count;++i)
		{if (done==1) return false;
		xtemp=choices[i][0]; ytemp=choices[i][1];
		//if(!been[xtemp][ytemp])
		move(xtemp,ytemp,been,knightplaced,path);
		//been[xtemp][ytemp]=0;
		//knightplaced--;
		}
		been[x][y]=0;
		

}

int main()
{
	int choices[8][2], x,y, been[8][8],count=0;
	x=0;
	y=0;

	for (int i=0;i<8;++i)
		for (int j=0;j<8;++j)
		been[i][j]=0;

	move(x,y,been,count,path);

	for (int i=0;i<25;++i)
	cout<<path[i][0]<<" "<<path[i][1]<<"\n";
	//count=generatechoices(x,y,choices);
	//cout<<count;
	//for (int i=0;i<=count;++i)
	//{ cout<<"\n";
	//	for (int j=0;j<2;++j)
	//	cout<<choices[i][j]<<" ";
	//}
	


return 0;
}

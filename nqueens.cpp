#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <oxymoron.h>
using namespace std;

int nqueens=4,done=0;

int iseligible(int num)
{
	if ((num>=0)&& (num<nqueens))
	return 1;

	else return 0;

}


void removeforbidden(int x, int y, int forbidden[][100], int count, int modified[][2])
{
	int xtemp,ytemp;
//	for (int i=0; iseligible(y+i); ++i)
//	forbidden[x][y+i]=0;

//	for (int i=0; iseligible(x+i) && iseligible(y+i); ++i)
//	forbidden[x+i][y+i]=0;

//	for (int i=0; iseligible(x-i) && iseligible(y+i); ++i)
//	forbidden[x-i][y+i]=0;

	for (int i=0;i<=count;++i)
	{	xtemp=modified[i][0];
		ytemp =modified[i][1];
		forbidden[xtemp][ytemp]=0;
	}

}



int generateforbidden(int x, int y, int forbidden[][100], int modified[][2])
{
//	for (int i=0; iseligible(x-i); ++i)
//	forbidden[x-i][y]=1;

	int count=-1;

	for (int i=0; iseligible(y+i); ++i)
	if (forbidden[x][y+i]==0)
	{forbidden[x][y+i]=1; modified[++count][0]=x; modified[count][1]=y+i;}

//	for (int i=0; iseligible(x+i); ++i)
//	forbidden[x+i][y]=1;

	for (int i=0; iseligible(x+i) && iseligible(y+i); ++i)
	if (forbidden[x+i][y+i]==0)
	{forbidden[x+i][y+i]=1; modified[++count][0]=x+i; modified[count][1]=y+i;}

	for (int i=0; iseligible(x-i) && iseligible(y+i); ++i)
	if(forbidden[x-i][y+i]==0)
	{forbidden[x-i][y+i]=1; modified[++count][0]=x-i; modified[count][1]=y+i;}

return count;
}

void displayforbidden(int forbidden[][100])
{
	for (int i=0; i<nqueens;++i)
		{cout<<'\n';
		for (int j=0;j<nqueens;++j)
		cout<<forbidden[j][i]<<" ";}

cout<<"\n\n\n";
}


bool placequeen(int x, int y, int queenplaced, int forbidden[][100], int path[][2])
{
	int xtemp,ytemp,index,count,modified[50][2];

	if (queenplaced==nqueens)
	{done=1; return false;}
			
	queenplaced++;

	if (forbidden[x][y]==0) 
	forbidden[x][y]==1;

	else return false;
	//cout<<done;

	if (queenplaced)		
	{count=generateforbidden(x,y,forbidden,modified);
	path[queenplaced-1][0]=x; path[queenplaced-1][1]=y;}

	//cout<<queenplaced<<'\n';
	//displayforbidden(forbidden);

	//index=queenplaced-1;
	for (int i=0;i<nqueens;++i)
		{
		xtemp=i; ytemp=queenplaced;
		placequeen(xtemp,ytemp,queenplaced,forbidden,path);
		if (done==1) return false;}
	removeforbidden(x,y,forbidden,count,modified);

}

int main()
{
	int forbidden[100][100],x,y,path[50][2];
	for (int x=0;x<100;++x)
		for (int y=0;y<100;++y)
			forbidden[x][y]=0;
	int queenplaced=-1;
	x=0;
	y=0;


	placequeen(x,y,queenplaced,forbidden,path);
	for (int i=0;i<nqueens;++i)
	cout<<path[i][0]<<" "<<path[i][1]<<'\n';
//	generateforbidden(1,1,forbidden);
//	displayforbidden(forbidden);
//	removeforbidden(1,1,forbidden);
//	displayforbidden(forbidden);	
//	for (i=0;i<n;++i)
//		for (int j=0;j<2;++j)
//			cout<<index[i][j]<<"\n";
	 
	return 0;
}

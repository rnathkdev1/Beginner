#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <oxymoron.h>

int sudoku[9][9];
int choices[9][9][10],options[9][9],rownum[9],columnnum[9],boxnum[9],rowfreq[9][10],columnfreq[9][10],boxfreq[9][10];
int done=0;

using namespace std;
void createsudoku()
{
	sudoku[0][0]=0; sudoku[0][1]=0; sudoku[0][2]=2; sudoku[0][3]=0; sudoku[0][4]=1; sudoku[0][5]=0; sudoku[0][6]=0; sudoku[0][7]=0; sudoku[0][8]=0;
	sudoku[1][0]=8; sudoku[1][1]=6; sudoku[1][2]=0; sudoku[1][3]=9; sudoku[1][4]=0; sudoku[1][5]=0; sudoku[1][6]=1; sudoku[1][7]=0; sudoku[1][8]=7;
	sudoku[2][0]=0; sudoku[2][1]=0; sudoku[2][2]=9; sudoku[2][3]=4; sudoku[2][4]=0; sudoku[2][5]=0; sudoku[2][6]=3; sudoku[2][7]=2; sudoku[2][8]=0;
	sudoku[3][0]=0; sudoku[3][1]=4; sudoku[3][2]=3; sudoku[3][3]=0; sudoku[3][4]=0; sudoku[3][5]=7; sudoku[3][6]=0; sudoku[3][7]=0; sudoku[3][8]=2;
	sudoku[4][0]=0; sudoku[4][1]=0; sudoku[4][2]=0; sudoku[4][3]=0; sudoku[4][4]=0; sudoku[4][5]=0; sudoku[4][6]=7; sudoku[4][7]=8; sudoku[4][8]=5;	
	sudoku[5][0]=2; sudoku[5][1]=0; sudoku[5][2]=8; sudoku[5][3]=1; sudoku[5][4]=5; sudoku[5][5]=0; sudoku[5][6]=0; sudoku[5][7]=0; sudoku[5][8]=0;
	sudoku[6][0]=0; sudoku[6][1]=0; sudoku[6][2]=6; sudoku[6][3]=0; sudoku[6][4]=0; sudoku[6][5]=0; sudoku[6][6]=0; sudoku[6][7]=7; sudoku[6][8]=0;
	sudoku[7][0]=0; sudoku[7][1]=0; sudoku[7][2]=0; sudoku[7][3]=0; sudoku[7][4]=8; sudoku[7][5]=0; sudoku[7][6]=0; sudoku[7][7]=9; sudoku[7][8]=0;
	sudoku[8][0]=9; sudoku[8][1]=1; sudoku[8][2]=0; sudoku[8][3]=2; sudoku[8][4]=0; sudoku[8][5]=3; sudoku[8][6]=0; sudoku[8][7]=0; sudoku[8][8]=0;
}

//---------------------------------------------------------------------------------------------------------
int box(int row, int column)
{
	int rowindex,columnindex,box;
	rowindex=(row/3)+1;

	columnindex=(column/3)+1;

	box=columnindex + ((rowindex-1)*3) - 1;
	return box;

}
	

//------------------------------------------------------------------------------------------------------	


void initialchoices()
{
	int tempbox;


	for(int i=0;i<9;++i)
	{	rownum[i]=0; columnnum[i]=0; 
		for (int j=0;j<9;++j)
		{	if (sudoku[i][j])
			{	
				choices[i][j][sudoku[i][j]]=sudoku[i][j];
				rowfreq[i][sudoku[i][j]]=1;
				rownum[i]++;
				tempbox=box(i,j);			
				boxfreq[tempbox][sudoku[i][j]]=1;
				++boxnum[tempbox];
			}
			if (sudoku[j][i])
			{	
				columnfreq[i][sudoku[j][i]]=1;				
				columnnum[i]++;
				
			}
		}
	}


	for (int row=0;row<9;++row)
		for (int column=0;column<9;++column)
		{	tempbox=box(row,column);		
			if (!sudoku[row][column])
				for (int testnum=1;testnum<10;++testnum)
					if (!rowfreq[row][testnum])
					if (!columnfreq[column][testnum])
					if (!boxfreq[tempbox][testnum])
					{	choices[row][column][testnum]=testnum;
						++options[row][column];
					}
		}


//xxxxxxxxxxxx----TESTING AREA----xxxxxxxxxxx

/*
	for (int i=0;i<9;++i)
	{	cout<<'\n';
		for (int j=0;j<9;++j)
		cout<<options[i][j]<<" ";
	}

	cout<<"\n\n\n\n";
	
	for (int i=0;i<9;++i)
	{	cout<<'\n';
		for (int j=0;j<9;++j)
		{	cout<<" ";
			for (int k=1;k<10;++k)
			cout<<choices[i][j][k];
		}
	}

	cout<<"\n\n\n\n";		

	for (int i=0;i<9;++i)
	{	cout<<'\n';
		for (int j=1;j<10;++j)
		cout<<rowfreq[i][j]<<" ";
	}

	cout<<"\n\n\n\n";
	
	for (int i=0;i<9;++i)
	{	cout<<'\n';
		for (int j=1;j<10;++j)
		cout<<columnfreq[i][j]<<" ";
	}

	cout<<"\n\n\n\n";

	for (int i=0;i<9;++i)
	{	cout<<'\n';
		for (int j=1;j<10;++j)
		cout<<boxfreq[i][j]<<" ";
	}

	cout<<"\n\n\n\n";
*/
}


//--------------------------------------------------------------------------------------------
void displaysudoku()
{
	for (int i=0;i<9;++i)
	{	cout<<'\n';	
		for (int j=0;j<9;++j)
		cout<<sudoku[i][j]<<" ";
	}
cout<<"\n\n\n";
}
//--------------------------------------------------------------------------------------------------
int boxcolumn(int boxno)
{
	int limit;
	limit = (boxno%3)*3;
	return limit; 
}
//--------------------------------------------------------------------------------------------------
int boxrow(int boxno)
{
	int limit;
	limit=boxno/3;
	return limit;
}
//----------------------------------------------------------------------------------------------------
void choiceupdate(int row, int column, int num,int reenterrow[9], int reentercolumn[9], int xreenterbox[9], int yreenterbox[9], int hash_details[3])
{
	int tempbox,rowlower,rowupper,columnlower,columnupper;
	int hash_rows=0;
	int hash_columns=0;
	int hash_box=0;
	rowfreq[row][num]=1;
	columnfreq[column][num]=1;
	boxfreq[box(row,column)][num]=1;

	//Note the #of rows (hash_rows) and their positions (reenterrow) in the row from which the number is being removed

	for (int iter=0;iter<9;++iter)
	{	if (choices[row][iter][num])
		{	choices[row][iter][num]=0; 
			options[row][iter]--; 
			reenterrow[hash_rows]=iter; 
			++hash_rows;
		}	
	
		if (choices[iter][column][num])
		{	choices[iter][column][num]=0;
			options[iter][column]--;
			reentercolumn[hash_columns]=iter;
			++hash_columns;
		}
	}

	//This part is the box update.

	tempbox=box(row,column);
//	cout<<"The box number is "<<tempbox<<'\n';
	rowlower=boxrow(tempbox); rowupper=rowlower+2;
	
	columnlower=boxcolumn(tempbox); columnupper=columnlower+2;
//	cout<<"Row "<<rowlower<<" column "<<columnlower<<'\n';

	for (int i=rowlower;i<=rowupper;++i)
		for (int j=columnlower;j<=columnupper;++j)
			if (choices[i][j][num])
			{	choices[i][j][num]=0;
				options[i][j]--;
				xreenterbox[hash_box]=i;
				yreenterbox[hash_box]=j;
				++hash_box;
			}


	hash_details[0]=hash_rows;
	hash_details[1]=hash_columns;
	hash_details[2]=hash_box;

/*	cout<<hash_rows<<" "<<hash_columns<<" "<<hash_box<<'\n';

	for(int i=0;i<hash_rows;++i)
	cout<<reenterrow[i]<<'\n';

	cout<<"\n\n\n\n";

	for (int i=0;i<hash_columns;++i)
	cout<<reentercolumn[i]<<'\n';
	
	cout<<"\n\n\n\n";

	for (int i=0;i<hash_box; ++i)
	cout<<xreenterbox[i]<<" "<<yreenterbox[i]<<'\n';
*/
}
//--------------------------------------------------------------------------------------------------
void recover(int row, int column, int num,int reenterrow[9], int reentercolumn[9], int xreenterbox[9], int yreenterbox[9], int hash_details[3])
{
	int hash_rows, hash_columns, hash_box, tempbox, col, ro, xtemp, ytemp;
	
	hash_rows=hash_details[0];
	hash_columns=hash_details[1];
	hash_box=hash_details[2];

//	cout<<"The rebels\n";
	
	for(int i=0;i<hash_rows;++i)
	{	col=reenterrow[i];
		choices[row][col][num]=num;
		rowfreq[row][num]=0;
		++options[row][col];
	}

//	cout<<"seeing things differently\n";

	for (int j=0;j<hash_columns;++j)
	{	ro=reentercolumn[j];
		choices[ro][column][num]=num;
		columnfreq[column][num]=0;
		++options[ro][column];
	}

	

	tempbox=box(row,column);
	for (int k=0;k<hash_box;++k)
	{	xtemp=xreenterbox[k]; ytemp=yreenterbox[k];
		choices[xtemp][ytemp][num]=num;
		boxfreq[tempbox][num]=0;
		++options[xtemp][ytemp];
	}

		
}
//--------------------------------------------------------------------------------------------------


int isvalidmove(int row, int column, int num)
{
	int boxnum;
	boxnum = box(row,column);
	
	if (choices[row][column][num]==0)
	return 0;
	
	//Add a condition that if it is a fixed number then return 0;
	else return 1;
}

//--------------------------------------------------------------------------------------------------
void displaychoices()
{
	for (int i=0;i<9;++i)
	{	cout<<'\n';
		for (int j=0;j<9;++j)
		{	cout<<" ";
			for (int k=1;k<10;++k)
			cout<<choices[i][j][k];
		}
	}

	cout<<"\n\n\n";
}
//--------------------------------------------------------------------------------------------------
void brainstorm(int moves, int row, int column, int num)
{
	int hash_rows=0, hash_columns=0, hash_box=0, reenterrow[9],reentercolumn[9];
	int xreenterbox[9],yreenterbox[9],hash_details[3];
	int variable_slotflag=0, secondflag=0,recoverflag=0,nextrow,nextcolumn,nextnum;
	
	if (done==1)
	return;

	++moves;
		
	row=int(moves-1)/9;
	column=(moves-1)%9;
	
	nextrow=int(moves)/9;
	nextcolumn=(moves)%9;
	
	if (moves==0)
	column=0;

//	cout<<"\nMove: "<<moves<<" row:"<<row<<" column:"<<column<<'\n';
//	cout<<"\nNumber:"<<num<<"\n\n";


if (moves)
{
	if (sudoku[row][column]==0)
	{	if(!isvalidmove(row,column,num))
		{	//cout<<"NOT VALID MOVE FOR row "<<row<<" column: "<<column<<" num: "<<num<<'\n';
			return;
		}
	}
//	cout<<"Round pegs in square holes\n";

	if (sudoku[row][column]==0)
	{variable_slotflag=1; sudoku[row][column]=num;}

//	if(variable_slotflag==1)
//	cout<<"\nIT IS A VARIABLE\n";

//	else cout<<"\nIT IS FIXED\n";
	
	if(moves==81)
	{displaysudoku(); done=1; return;}

	if (variable_slotflag==1)
	{choiceupdate (row,column,num,reenterrow,reentercolumn,xreenterbox,yreenterbox,hash_details);}
	
}


//	displaysudoku();
//	displaychoices();


//	cout<<"Here's to the crazy ones\n";
	
		 
	for (int k=1;  k<10 ;++k)
	{	if (choices[nextrow][nextcolumn][k]==0)
		continue;
		//cout<<"crazy enough to think with number: "<<k<<'\n';
		brainstorm(moves,row,column,choices[nextrow][nextcolumn][k]);
		
	}
	if (variable_slotflag==1)
	{	
		//cout<<"Recovering position "<<row<<" "<<column<<"\n";
		sudoku[row][column]=0;
		recover (row,column,num,reenterrow,reentercolumn,xreenterbox,yreenterbox,hash_details);
	}
}
//--------------------------------------------------------------------------------------------------

void brainstart()
{	
	int moves=-1,x=0,y=0,num=3;

	

	for (int i=0;i<9;++i)
	{	rownum[i]=0;columnnum[i]=0;boxnum[i]=0;
		for (int j=0;j<9;++j)
		{	sudoku[i][j]=0; options[i][j]=0; rowfreq[i][j+1]=0; columnfreq[i][j+1]=0; 
			boxfreq[i][j+1]=0;
			for (int k=0;k<9;++k)
			choices[i][j][k]=0;
		}
	}

	createsudoku();
	initialchoices();
	
	brainstorm(moves,x,y,num);

//--xxxxxxxxxx---TESTING ZONE----XXXXXX----
/*
	if(isvalidmove(0,1,3))
	cout<<"\nYES IT IS\n";

	int hash_rows, hash_columns, hash_box, reenterrow[9],reentercolumn[9],xreenterbox[9],yreenterbox[9],hash_details[3];

	displaychoices();
	choiceupdate (0,7,9,reenterrow,reentercolumn,xreenterbox,yreenterbox,hash_details);
//	recover (0,1,9,reenterrow,reentercolumn,xreenterbox,yreenterbox,hash_details);

	for (int i=0;i<9;++i)
	{	cout<<'\n';
		for (int j=0;j<9;++j)
		cout<<options[i][j]<<" ";
	}

	cout<<"\n\n\n\n";

	for (int i=0;i<9;++i)
	{	cout<<'\n';
		for (int j=0;j<9;++j)
		{	cout<<" ";
			for (int k=1;k<10;++k)
			cout<<choices[i][j][k];
		}
	}

	cout<<"\n\n\n\n";		

	for (int i=0;i<9;++i)
	{	cout<<'\n';
		for (int j=1;j<10;++j)
		cout<<rowfreq[i][j]<<" ";
	}

	cout<<"\n\n\n\n";
	
	for (int i=0;i<9;++i)
	{	cout<<'\n';
		for (int j=1;j<10;++j)
		cout<<columnfreq[i][j]<<" ";
	}

	cout<<"\n\n\n\n";

	for (int i=0;i<9;++i)
	{	cout<<'\n';
		for (int j=1;j<10;++j)
		cout<<boxfreq[i][j]<<" ";
	}

	cout<<"\n\n\n\n";
*/
}

//--------------------------------------------------------------------------------------------------


int main()
{
	int sudoku[9][9];
	
	brainstart();
//	displaysudoku(sudoku);
	return 0;
}


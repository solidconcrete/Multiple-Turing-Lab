#include <windows.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctype.h>
using namespace std;
int main()
{
    int pos[4], i = 0, length[4] = {0}, steps=0, j;
	string tape[4], name[4]={"1.txt", "2.txt", "3.txt", "4.txt"}, state[4]={"0", "0", "0", "0"}, ind[4], cst[4][100], nst[4][100] ;
	char a, d[4][100], csy[4][100], nsy[4][100];
	for(i=0; i<4; i++)
	{
		ifstream fin (name[i].c_str());
		fin >> pos[i] >> tape[i];
		cout<<pos[i]<<endl<<tape[i]<<endl;    
		pos[i]--; //read start position and tape
		string indicator (tape[i].length(), 32);  
		ind[i]=indicator;
		ind[i][pos[i]]=94;
		cout<<ind[i]<<endl;
		j=0;
	while (!fin.eof())
		{
			fin >> cst[i][j] >> csy[i][j] >> nsy[i][j] >> d[i][j] >> nst[i][j];
			cout << cst[i][j] << " " << csy[i][j] << " " << nsy[i][j]<< " " << d[i][j] << " " << nst[i][j]<<endl;
			j++;
		}
		length[i] = j;
	}
	for (int inf = 0; inf < 1; inf*=1)
	{	
		if(GetAsyncKeyState(VK_ESCAPE))
		break;
		usleep (8000);
		system("cls");
		for(i=0; i<4; i++)
		for(j=0; j<=length[i]; j++)
//		{	
			if ((cst[i][j] == state[i]) && (csy[i][j] == tape[i][pos[i]])) //search for the right command
			{
				
 				tape[i][pos[i]] = nsy[i][j];  //change the symbol
				state[i] = nst[i][j];       //change the state
				ind[i][pos[i]] = 32;             //change indicator state
				if (d[i][j] == 'R')
					pos[i]++;
				else
					pos[i]--;
				ind[i][pos[i]] = 94;
//				cout << endl << tape[i] << endl << ind[i];  //cout changed tape
				break;
			}			
//				
//		}
		for(int k=0; k<4; k++)
		cout<< endl<< tape[k] << endl<< ind[k]<<endl;
	}

	return 0;
}



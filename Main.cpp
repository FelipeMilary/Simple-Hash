#include <iostream>
using namespace std;

const char X_X = 'X';
const char O_O = 'O';
const long TAMANHHO = 3;
char aaVelha[3][3] = {0};
char cGanhador = 0;
long lCont = 0;

void imprimeMatriz()
{
	system("cls");
	
	cout << "       |     |     " << endl;
	cout << "    " << aaVelha[0][0] << "  |  " << aaVelha[0][1] << "  |  "<< aaVelha[0][2] << "  " << endl;
	cout << "       |     |     " << endl;
	cout << "  -----|-----|-----" << endl;
	cout << "       |     |     " << endl;
	cout << "    " << aaVelha[1][0] << "  |  " << aaVelha[1][1] << "  |  "<< aaVelha[1][2] << "  " << endl;
	cout << "       |     |     " << endl;
	cout << "  -----|-----|-----" << endl;
	cout << "       |     |     " << endl;
	cout << "    " << aaVelha[2][0] << "  |  " << aaVelha[2][1] << "  |  "<< aaVelha[2][2] << "  " << endl;
	cout << "       |     |     " << endl;
}


void fazJogada(long lLinha, long lColuna)
{
	if (lCont % 2 != 0)
	{
		if (aaVelha[lLinha - 1][lColuna - 1] != O_O && aaVelha[lLinha - 1][lColuna - 1] != X_X)
		{
			aaVelha[lLinha - 1][lColuna - 1] = O_O;
			++lCont;
		}
	}
	else
	{
		if (aaVelha[lLinha - 1][lColuna - 1] != O_O && aaVelha[lLinha - 1][lColuna - 1] != X_X)
		{
			aaVelha[lLinha - 1][lColuna - 1] = X_X;
			++lCont;
		}
	}
}

bool temGanhador()
{
	char cTemp1 = 0;
	char cTemp2 = 0;
	char cTemp3 = 0;
	
	//linha
	for (long idxLinha = 0; idxLinha < TAMANHHO; ++idxLinha)
	{
		cTemp1 = aaVelha[idxLinha][0];
		cTemp2 = aaVelha[idxLinha][1];
		cTemp3 = aaVelha[idxLinha][2];
		
		if (cTemp1 == cTemp2 && cTemp2 == cTemp3)
		{
			if (cTemp1 == O_O || cTemp1 == X_X)
			{
				cGanhador = cTemp1;
				return true;
			}
		}
	}
	//coluna
	for (long idxColuna = 0; idxColuna < TAMANHHO; ++idxColuna)
	{
		cTemp1 = aaVelha[0][idxColuna];
		cTemp2 = aaVelha[1][idxColuna];
		cTemp3 = aaVelha[2][idxColuna];
		
		if (cTemp1 == cTemp2 && cTemp2 == cTemp3)
		{
			if (cTemp1 == O_O || cTemp1 == X_X)
			{
				cGanhador = cTemp1;
				return true;
			}
		}
	}
	//diagonal
	
	cTemp1 = aaVelha[0][0];
	cTemp2 = aaVelha[1][1];
	cTemp3 = aaVelha[2][2];
	
	if (cTemp1 == cTemp2 && cTemp2 == cTemp3)
	{
		if (cTemp1 == O_O || cTemp1 == X_X)
			{
				cGanhador = cTemp1;
				return true;
			}
	}
	
	cTemp1 = aaVelha[0][2];
	cTemp3 = aaVelha[2][0];
	
	if (cTemp1 == cTemp2 && cTemp2 == cTemp3)
	{
		if (cTemp1 == O_O || cTemp1 == X_X)
			{
				cGanhador = cTemp1;
				return true;
			}
	}
	return false;
}

int main()
{
	long lLinha = 0;
	long lColuna = 0;
	
	bool bTerminou = false;
	
	while (bTerminou != true)
	{
		imprimeMatriz();
		
		cin >> lLinha >> lColuna;
		
		fazJogada(lLinha, lColuna);
		
		if (temGanhador())
		{
			imprimeMatriz();
			break;
		}
		if (lCont == 9)
		{
			imprimeMatriz();
			bTerminou = true;
			break;
		}
	}
	
	if (temGanhador())
		cout << "	" << cGanhador << " Ganhou" << endl;
	else
		cout << "	Empate" << endl;
	
	return 0;
}

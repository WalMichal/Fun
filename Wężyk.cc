#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

int i = 25;
int j = 65;
double czas = 150;

using namespace std;
enum liczba
{
	gora,
	prawo,
	lewo,
	dol,
	nic,
};
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void zamiana(char **cchar,int **tab, int x, int y, int szukana,int &ii,int&jj,int dlugosc,int nagroda)
{
	if (szukana == dlugosc +1)
	{
		if (nagroda)tab[ii][jj] = dlugosc;
		else
		tab[ii][jj] = 0;
		return;
	}
	if (tab[x + 1][y] == szukana)
	{
		tab[x + 1][y] = szukana+1;
		ii = x + 1;
		jj = y;
	}
	if (tab[x - 1][y] == szukana)
	{
		tab[x - 1][y] = szukana+1;
		ii = x - 1;
		jj = y;
	}

	if (tab[x][y + 1] == szukana)
	{
		tab[x][y + 1] = szukana+1;
		ii = x ;
		jj = y + 1;
	}

	if (tab[x][y - 1] == szukana)
	{
		tab[x][y - 1] = szukana+1;
		ii = x;
		jj = y - 1;
	}
	cchar[ii][jj] = '*';
	zamiana(cchar,tab, ii, jj, szukana + 1, ii, jj, dlugosc,nagroda);
}

template <typename typ>
void rysujcls(typ **tab)
{
	system("cls");
	for (int ii = 0; ii < i; ii++)
	{
		for (int jj = 0; jj < j; jj++)
		{
			cout << tab[ii][jj];
		}
		if(ii!=i-1)cout << endl;
	}
}
template <typename  typ>
typ** stworz()
{
	typ **plansza = new typ*[i];
	if (plansza == 0)
	{
		cout << "Brak pamięci"<<endl;
		exit(3);
	}
	for (int ii = 0; ii < i; ii++)
	{
		plansza[ii] = new typ[j];
		if (plansza[ii] == 0)
		{
			cout << "Brak pamięci przy linijce:" << ii << endl;
			exit(4);
		}
		for (int jj = 0; jj < j; jj++)
		{
			if (sizeof(typ) == sizeof(char))
			{
				if (ii == 0 || ii == i - 1 || jj == 0 || jj == j - 1)
					plansza[ii][jj] = '#';
				else
					plansza[ii][jj] = ' ';
			}
			else
				if (ii == 0 || ii == i - 1 || jj == 0 || jj == j - 1)
					plansza[ii][jj] = -1;
				else
					plansza[ii][jj] = 0;
		}
	}
	return plansza;
}
liczba kierunek()
{
	double stary;
	liczba lastvalue=nic;
	bool spr=0;
	int z224;
	stary = GetTickCount();
	while (GetTickCount() - stary < czas)
	{
		if (kbhit())
		{
			z224 = getch();
			if (z224 == 224)
			{
				if (kbhit())
				{
					z224 = getch();
					if (z224 == 72)
					{
						lastvalue = gora;
						spr = 1;
					}
					if (z224 == 80)
					{
						lastvalue = dol;
						spr = 1;
					}
					if (z224 == 75)
					{
						lastvalue = lewo;
						spr = 1;
					}
					if (z224 == 77)
					{
						lastvalue = prawo;
						spr = 1;
					}
				}
			}
		}
	}
	if (spr == 0)return nic;
	else return lastvalue;
}
void obslkierunku(liczba last, liczba *last1,int &x,int *y)
{
	if (last == nic)
	{
		last = *last1;
	}

	if (last == gora)
	{
		if (*last1 == dol)
		{
			x++;
		}
		else
		{
			*last1 = gora;
			x--;
		}
	}
	if (last == dol)
	{
		if (*last1 == gora)
		{
			x--;
		}
		else
		{
			*last1 = dol;
			x++;
		}
	}
	if (last == prawo)
	{
		if (*last1 == lewo)
		{
			*y=*y-1;
		}
		else
		{
			*last1 = prawo;
			*y = *y + 1;
		}
	}
	if (last == lewo)
	{
		if (*last1 == prawo)
		{
			*y = *y + 1;
		}
		else
		{
			*last1 = lewo;
			*y = *y - 1;
		}
	}

}

int main()
{
	system("chcp 1250");
	system("cls");
	srand(time(NULL));
	SetConsoleTitleA("Wprowadz dane:");

	int szybkosc;
	cout << "Podaj szybkość w przedziale <50;1000>" << endl;
	cin >> szybkosc;
	szybkosc=1050-szybkosc;
	while (cin.fail()||szybkosc>1000||szybkosc<50)
	{
		cin.clear(); cin.sync();
		cin.ignore(1000, '\n');
		cout << "Podaj poprawnie ??" << endl;
		cin >> szybkosc;
	}
	czas = szybkosc;

	cout << "Podaj szerokosc(zalecana:65, musi byc wieksza niz 3): " << endl;
	cin >> szybkosc;
	while (cin.fail()||szybkosc<=3)  // do poprawy
	{
		cin.clear(); cin.sync(); cin.ignore(1000, '\n');
		cout << "Podaj poprawnie ??" << endl;
		cin >> szybkosc;
	}
	j = szybkosc;

	cout << "Podaj szerokosc(zalecana:25, musi byc wieksza niz 3): " << endl;
	cin >> szybkosc;
	while (cin.fail()||szybkosc<=3) // do poprawy
	{
		cin.clear(); cin.sync(); cin.ignore(1000, '\n');
		cout << "Podaj poprawnie ??" << endl;
		cin >> szybkosc;
	}
	i = szybkosc;
	system("cls");
	SetConsoleTitleA("No to gramy:");
	int a=0, b=0;
	int aa, bb;
	int nagroda = -2;
	int nagrod=0;
	char **plansza = stworz<char>();
	int **plan = stworz<int>();
	int x = i / 2;
	int y = j / 2;
	/// Warunki Początkowe:
	plansza[x][y] = '*';
	plansza[x][y - 1] = '*';//początkowa długość wężyka ??
	plan[x][y] = 1;
	plan[x][y - 1] = 2;
	while (plan[a][b] != 0)
	{
		a = rand() % (i - 1) + 1;
		b = rand() % (j - 1) + 1;
	}
	plan[a][b] = -2;
	plansza[a][b] = 'x';
	liczba last = nic, last1 = prawo,last2;
	int dlugosc;
	dlugosc = 2;
	rysujcls<char>(plansza);
	while (1)
	{
		last = kierunek();
		obslkierunku(last, &last1, x, &y);  //x przez referencje

		if (plan[x][y] == -1|| plan[x][y] >1)
		{
			system("cls");
			cout << "Porazka" << endl;
			SetConsoleTitleA("Brawo :( !!!");
			return 2;
		}
		if (plan[x][y] == -2)
		{
			if (dlugosc == (i*j - 2 * (i + j) +3))
			{
				system("cls");
				cout << "Zwycięstwo-Dobrze ??" << endl;
				SetConsoleTitleA("Zwycięstwo.");
				return 777;
			}
			while (plan[a][b] != 0)
			{
				a = rand() % (i - 1) + 1;
				b = rand() % (j - 1) + 1;
			}
			plan[a][b] = -2;
			dlugosc++;
			nagrod = 1;
		}
		plan[x][y] = 1;
		zamiana(plansza,plan, x, y, 1, aa,bb,dlugosc,nagrod);
		nagrod = 0;
		/// Rysowanie z plan na plansza
		for (int ii = 0; ii < i - 1; ii++)
		{
			for (int jj = 0; jj < j - 1; jj++)
			{
				if (plan[ii][jj] == 0 && plansza[ii][jj]=='*')
				{
					gotoxy(jj + 1, ii + 1); cout << ' ';
					plansza[ii][jj] = ' ';
				}
				if (plan[ii][jj] > 0 && plansza[ii][jj]!='*')
				{
					gotoxy(jj+1, ii+1);cout << '*';
					plansza[ii][jj] = '*';
				}
				if (plan[ii][jj] == -2)
				{
					gotoxy(jj + 1, ii + 1); cout << 'x';
					plansza[ii][jj] = 'x';
				}
			}

		}
	}
	return 0;
}

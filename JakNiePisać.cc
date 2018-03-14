#include <iostream>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <string>
using namespace std;
typedef long double mojtyp;
const mojtyp SUMA=100000000;
const int TABLICA=3;
class A
{
    public:
    int *wsk;
    int liczba;
};
int main()
{
    A klasa;
    *(klasa.wsk)=10;  //wskaünik pokazuje na losowy adres
    //cout<<*(klasa.wsk)<<endl;  //ale mimo wszystko z tπ linijkπ zadzia≥a :)

    return 0;

}

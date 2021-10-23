#include <iostream>


#include <Windows.h>
#include <ios>
#include <limits>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <sstream>
#include <string>
#include <urlmon.h>
#include <tchar.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <tchar.h>
#include <Wininet.h>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <windows.h> 
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "urlmon.lib")


//made by ritz#9009
//  https://discord.gg/MqM4M9Tq4B


using namespace std;



void Clear()
{
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
    return;
}


int main()
{

    SetConsoleTitle(_T("login loader"));
    _mkdir("c:/4login"); //creates folder

    std::fstream myfile;
    std::string line;
    ofstream outFile;
    string username;
    string password;


    string option;
    std::cout << "[1] login\n";
    std::cout << "[2] regiester\n";
    cin >> option;

    if (option == "1")
    {
        ifstream file1("c:/4login/username.txt");
        ifstream file2("c:/4login/password.txt");
        string content1;
        string content2;
        while (file1 >> content1) {
            while (file2 >> content2) {
                Clear();
                std::cout << "username: ";
                cin >> username;
                std::cout << "password: ";
                cin >> password;


                if (content1 == username && content2 == password)
                {
                    std::cout << "Login Success!\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                if (content1 != username && content2 != password)
                {
                    std::cout << "Incorect Username And Password\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                if (content1 != username && content2 == password)
                {
                    std::cout << "Incorect Username\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                if (content1 == username && content2 != password)
                {
                    std::cout << "Incorect Password\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                else {
                    std::cout << "Incorect\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    if (option == "2")
    {
        std::cout << "username: ";
        cin >> username;
        std::cout << "password: ";
        cin >> password;

        outFile.open("c:/4login/username.txt");
        outFile << username << endl;
        outFile.close();

        outFile.open("c:/4login/password.txt");
        outFile << password << endl;
        outFile.close();
        Clear();
        main();
    }


}


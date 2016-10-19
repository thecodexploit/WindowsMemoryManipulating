#include <iostream>
#include <stdlib.h>
#include <Windows.h>

int main() {
    SetConsoleTitleA("ManipuleIt");
    int a,b = 0;
    while(1){
        std::cin >> b;
        a += b;
        system("cls");
        std::cout << &a << ": "<< a<< std::endl;
    }
}

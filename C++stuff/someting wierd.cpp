#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstring>

using namespace std;


void displaythis()
{	string x[4]={"How ","are ","you","?"};
    for (int i=0;i<4;i++)
    {
        cout << x[i];
        Sleep(100);
    }
getch();
}
void displaythis1()
{	string x[10]={"If ","you ","are ","getting ","this, ","please ","tell ","me ","your ","name...\n"};
    for (int i=0;i<10;i++)
    {
        cout << x[i];
        Sleep(100);
    }
getch();
}
int main()
{
	string name;
	string answer;
displaythis1();
cin>>name;
cout<<"Thank you, "<<name<<" for turning this program on! ";
displaythis();
cin>>answer;
cout<<"Well nevermind that, I have an important mission for you, it involves the entire world";

return 0;
}





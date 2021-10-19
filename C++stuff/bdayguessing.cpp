#include <iostream>
using namespace std;

int main ()
{int set1,set2,set3,set4,set5,bday;
int set6,set7,set8,set9,bmonth;

cout<<"I'm going to guess your birthday starting with the month.\n";
cout<<"If your birth month is in the set press 1, if it is not, then press 0\n";
cout<<"January, March, May, July, September, November\n";
cin>>set1;

cout<<"If your birth month is in the set press 1, if it is not, then press 0\n";
cout<<"February, March, June, July, October, November\n";
cin>>set2;

cout<<"If your birth month is in the set press 1, if it is not, then press 0\n";
cout<<"April, May, June, July, December\n";
cin>>set3;

cout<<"If your birth month is in the set press 1, if it is not, then press 0\n";
cout<<"August, September, October, November, December\n";
cin>>set4;

cout<<"Now im going to guess the day you were born using a set of numbers\n";
cout<<"If your birthday is in the set press 1, if it is not, then press 2\n";
cout<<"1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31\n";
cin>>set5;

cout<<"If your birthday is in the set press 1, if it is not, then press 0\n";
cout<<"2, 3, 6,7, 10, 11, 14, 15, 18, 19, 22, 23, 26, 27, 30, 31\n";
cin>>set6;

cout<<"If your birthday is in the set press 1, if it is not, then press 0\n";
cout<<"4, 5, 6, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30, 31\n";
cin>>set7;

cout<<"If your birthday is in the set press 1, if it is not, then press 0\n";
cout<<"8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31\n";
cin>>set8;

cout<<"If your birthday is in the set press 1, if it is not, then press 0\n";
cout<<"16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31\n";
cin>>set9;

bmonth=(set1*1)+(set2*2)+(set3*4)+(set4*8);
bday=(set5*1)+(set6*2)+(set7*4)+(set8*8)+(set9*16);

cout<<"After doing my calculations, I have figured out that your birth date is "<<bmonth<<"/"<<bday;
return 0;
}

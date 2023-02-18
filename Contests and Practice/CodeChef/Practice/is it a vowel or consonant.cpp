#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    char c;
    cin>>c;
    switch(c)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':cout<<"Vowel\n";
        break;
        default : cout<<"Consonant\n";

    }
}
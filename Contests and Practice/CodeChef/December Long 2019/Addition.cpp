#include <iostream>
#include <vector>
#include <string>
#include <map>
#include<algorithm>   
#include<cmath>
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ul unsigned long
#define fori for (i = 0; i < n; i++)
#define forj for (j = 0; j < n; j++)
#define test  ul t; cin >> t; while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
ul ct = 0;
string str(ul n)
{
    ul i;
    string a="00000000000000";
    for(i=0; n>0; i++)    
    {    
        a[13-i]=(char(n%2)+48);
       // cout << a[i];
        n= n/2;  
    }
    //cout << i;
    for (ul j = 0;j<(i/2);j++)
    {
        char temp=a[i-j-1];
        a[i - j - 1] = a[j];
        a[j] = temp;
    }
   // cout << a;
    return a;
}
ul bitw(string a)
{
    ul temp=0;
    for (ul i = 0; i <=(a.size()-1) ;i++)
    {
        ul t1 = long(a[i]-'0');
        //cout << t1 << endl;
        temp += (t1*pow(2, (a.size()-i-1)));
    }
    return temp;
}
void add(string a, string b)
{

    while (bitw(b)>0)
    {
        ul u = bitw(a) ^ bitw(b);
        ul v = bitw(a) & bitw(b);
        a = str(u);
        b = str(v * 2);
        cout << endl<<bitw(a)<<"  "<<bitw(b)<<endl;
        ct++;
    }
}

int main()
{
    test
    {
        ct = 0;
        string a, b;
        cin >> a;
        cin.ignore();
        cin >> b;
        add(a,b);
        cout << ct << endl;
    }
}
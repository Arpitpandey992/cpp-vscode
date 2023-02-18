#include<iostream>
using namespace std;
int intconv(char a)
{
	return a-'0';
}
void dm(int &y,int &m,int&leap,int&dmax)
{
	if(y%4==0&&y%100!=0)
		leap=1;
	else if(y%100==0&&y%400==0)
		leap=1;

	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	{
		dmax=31;
	}
	else if(m==4||m==6||m==9||m==11)
		dmax=30;
	else if(leap)
	{
		dmax=29;
	}
	else
	{
		dmax=28;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int y=0,m=0,d=0,i,dmax,leap=0,b=1,count=1;
		char dt[10];
		cin>>dt;

		y=1000*intconv(dt[0])+100*intconv(dt[1])+10*intconv(dt[2])+intconv(dt[3]);
		m=10*intconv(dt[5])+intconv(dt[6]);
		d=10*intconv(dt[8])+intconv(dt[9]);
		int rem=d%2;
		 i=2;
		while(b)
		{
			leap=0;
			dm(y,m,leap,dmax);
			if(d>=dmax)
			{
				if(m==12)
				{
					m=0;
					y++;
				}
				d=0;
				m++;
			}
			d++;
			if(i%2==0)
			{
				if(d%2==rem)
					b=0;
			}
			else
			{
				if(d%2!=rem)
					b=0;
			}
			if(i%2==1&&b==1)
				count++;
			i++;
		}
		
		
		cout<<count<<endl;
		//cout<<y<<" "<<m<<" "<<d<<' '<<dmax;
	}
}
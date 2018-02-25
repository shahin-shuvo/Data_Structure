#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
void namota(int a)
{
    for(int i = 1;i<=10;i++)
    {
        printf("%d *%d = %d\n",a,i,a*i);
    }

}
main()
{
    int a;
    cout<<"Enter your number"<<endl;
    for(int i = 1;i<=100;i++)
    namota(i);




}

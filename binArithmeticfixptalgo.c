#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<cstdio>
using namespace std;
class bin
{
    char a[32],b[32],c[32];/* a and b to store the number and c to the result*/
    int s1,s2,m;//m is 0 for addition and 1 for substraction
    char cary;int carry[32];
    public:
    bin()
    {
        /*initializing with null values*/
        cary='0';
        s1=0;s2=0;m=0;
        for(int i=0;i<32;i++)
        {
            a[i]='0';
            b[i]='0';
            c[i]='0';
        }
    }
    void getdata()
    {
        char m[32],n[32];
        cout<<"Enter first binary number in signed 2's complement\n";
        cin.sync();
        gets(m);
        cout<<"Enter second binary number in signed 2's complement\n";
        gets(n);
        s1=strlen(m);
        s2=strlen(n);
        for(int i=31,j=s1-1;j>=0;)
        {
            if(m[j]!='0'&&m[j]!='1')
            {
                system("cls");
                cout<<"\nNot a binary number";
                exit (1);
            }
            a[i]=m[j];
            i--;j--;
        }
        for(int i=31,j=s2-1;j>=0;)
        {
            if(n[j]!='0'&&n[j]!='1')
            {
                system("cls");
                cout<<"\nNot a binary number";
                exit (1);
            }
            b[i]=n[j];
            i--;j--;
        }
        system("cls");//edit as per compiler
    }
    void add();//to compute addition
    void sub();//to compute substraction
    void com();//to compute complement in case of substraction
    void display();//to display the result
};
void bin::sub()
{
    m=1;
    com();
    add();
}
void bin::com()
{
    int count=0;
    for(int i=31;i>=0;i--)
    {
        if(count>0)
        {
            if(b[i]=='1')
            {
                b[i]='0';
            }
            else
            {
                b[i]='1';
            }
        }
        if(b[i]=='1')
        {
            count++;
        }
    }
}
void bin::add()
{
    cout<<"\a";
    for(int i=31;i>=0;i--)
    {
        if(cary=='0'&&a[i]=='0'&&b[i]=='0')
        {
            cary='0';
            c[i]='0';
            carry[i]=cary-'0';
        }
        else if(cary=='0'&&a[i]=='0'&&b[i]=='1')
        {
            cary='0';
            c[i]='1';
             carry[i]=cary-'0';
        }
         else if(cary=='0'&&a[i]=='1'&&b[i]=='0')
        {
            cary='0';
            c[i]='1';
             carry[i]=cary-'0';
        }
        else if(cary=='0'&&a[i]=='1'&&b[i]=='1')
        {
            cary='1';
            c[i]='0';
            carry[i]=cary-'0';
        }
        else if(cary=='1'&&a[i]=='1'&&b[i]=='1')
        {
            cary='1';
            c[i]='1';
             carry[i]=cary-'0';
        }
        else if(cary=='1'&&a[i]=='0'&&b[i]=='0')
        {
            cary='0';
            c[i]='1';
             carry[i]=cary-'0';
        }
        else if(cary=='1'&&a[i]=='0'&&b[i]=='1')
        {
            cary='1';
            c[i]='0';
             carry[i]=cary-'0';
        }
        else if(cary=='1'&&a[i]=='1'&&b[i]=='0')
        {
            cary='1';
            c[i]='0';
             carry[i]=cary-'0';
        }
        else if(cary=='1'&&a[i]=='1'&&b[i]=='1')
        {
            cary='1';
            c[i]='1';
             carry[i]=cary-'0';
        }
    }
}

void bin::display()
{
    cout<<"\nFirst Binary Number is:\n";
    for(int i=32-s1;i<32;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    if(m==1)
    cout<<"\n2's complement of second number is:\n";
    else
    {
    cout<<"\nSecond Binary Number is:\n";
    }
    for(int i=(32-s2);i<32;i++)
    {
        cout<<b[i];
    }
    cout<<endl;
    if(carry[32-s1]^carry[32-s1+1]==1){//this will check for overflow of signed binary numbers
        cout<<"Result is: \n";
    for(int i=32-s1-1;i<32;i++)
    {
        cout<<c[i];
    }
        cout<<"\nOVERFLOW";
        if(carry[32-s1]==1)//to find the carry
            cout<<"\nCARRY\n";
            else
                cout<<"\nNO CARRY\n";
        }
    else{
    cout<<"Result is: \n";
    for(int i=32-s1;i<32;i++)
    {
        cout<<c[i];
    }
    cout<<"\nNO OVERFLOW"<<endl;
    if(carry[32-s1]==1)
            cout<<"\nCARRY\n";
            else
                cout<<"\nNO CARRY\n";
    }
}

int main()
{
    char y;y='y';
    bin b;
    int ch;

    while(y=='Y'||y=='y')
    {
        b.getdata();
    cout<<"\tMenu\n-------------------------------------------------------------------------------\n";
    cout<<"1. Addition\n2. Subtraction\n\t->";
    cin>>ch;
    switch(ch)
    {
        case 1:
        b.add();
        b.display();break;
        case 2:
        cout<<"Here is Substraction result\n";
        b.sub();
        b.display();break;
        default:
        cout<<"\nInvalid Choice";
    }
    cout<<"\nPress Y to continue\n->";
    cin>>y;
    }
    return 0;
}


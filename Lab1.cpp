#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    char str[200];
    int len;

    cout << "Enter a String : ";
    gets(str);

    len = strlen(str) - 1;
    if((str[0] == '/' && str[1] == '/') || ((str[0] == '/' && str[1] == '*') && (str[len-1] == '*' && str[len] == '/')))
        cout << "This is a Comment" << endl;
    else
        cout << "This is not a Comment" << endl;


    return 0;
}

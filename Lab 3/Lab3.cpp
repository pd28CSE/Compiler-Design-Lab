#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

bool isArithOperator(char ch);
bool isRelatOperator(char *str, int len);
bool isKeyword(char *str, int len);

int main()
{
    char str[100];
    int len, i;

    cout << "Enter Input : ";
    gets(str);
    len = strlen(str);

    if((len == 1) && isArithOperator(str[0]) == true)
        cout << "Arithmetic Operator" << endl;
    else if((len == 1 || len == 2) && isRelatOperator(str, len) == true)
        cout << "Relational Operator" << endl;
    else if(isKeyword(str, len) == true)
        cout << "Keyword" << endl;
    else
        cout << "Undefined" << endl;


    return 0;
}

bool isArithOperator(char ch)
{
    if(ch=='+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        return true;
    return false;
}

bool isRelatOperator(char *str, int len)
{
    if(len == 1){
        if(str[0] == '<' || str[0] == '>')
            return true;
        return false;
    }
    else if(len == 2){
        if((str[0] == '<' && str[1] == '=') || (str[0] == '>' && str[1] == '=') || (str[0] == '=' && str[1] == '=') || (str[0] == '!' && str[1] == '='))
            return true;
        return false;
    }
    return false;
}

bool isKeyword(char *str, int len)
{
    string keys[] = {"if", "else", "for", "while", "break", "continue", "int", "float", "double",
                    "return", "bool", "true", "false", "do", "char", "define"};
    int n, i, j;

    n = 16;
    for(i=0; i<n; i++){
        int sum = 0,k;
        k = keys[i].length();

        if(k == len){
            for(j=0; j<len; j++){
                if(str[j] == keys[i][j])
                    sum += 1;
                else
                    break;
            }
            if(sum == len)
                return true;
        }
    }

    return false;
}

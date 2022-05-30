#include<iostream>
#include<cstring>

using namespace std;

bool isValid(char *str, int n);

int main()
{
    char str[100];
    int len;



    cout << "Enter An Identifier: ";
    cin >> str;

    len = strlen(str);
    if(isValid(str, len) == true)
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;


    return 0;
}


bool isValid(char *str, int n)
{
    int i;
    bool check = false;

    if(str[0] >= 'a' && str[0]<='z' || str[0] >= 'A' && str[0]<='Z' || str[0] == '_'){
            check = true;
        for(i=1; i<n; i++){
            if(str[i] >= 'a' && str[i]<='z' || str[i] >= 'A' && str[i]<='Z' || str[i] == '_' || str[i] >= '0' && str[i] <= '9'){
                continue;
            }

            else
                return false;
        }
    }

    return check;
}

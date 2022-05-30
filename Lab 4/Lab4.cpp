#include<iostream>
#include<cstring>

using namespace std;

bool adFunc(string str, int len);
bool abFunc(string str, int len);
bool abcFunc(string str, int len);

int main()
{
    string str;
    int len;

    cout << "Enter a Text : ";
    cin >> str;

    len = str.length();

    if(adFunc(str, len) == true){
        cout << "The string is Recognized By : a+d*" << endl; // aad aa  a
    }
    else if(abFunc(str, len) == true){
        cout << "The string is Recognized By : abb*" << endl;
    }
    else if(abcFunc(str, len) == true){
        cout << "The string is Recognized By : a+bc" << endl;
    }
    else
        cout << "The string is not Recognized" << endl;


    return 0;
}

bool adFunc(string str, int len) // a+d*     aaadd   a   ad
{
    int i, j;
    bool check = false;

    if(str[0] == 'a' && len == 1)
        return true;
    for(i=0; i<len; i++){
        if(str[i] == 'a')
            check = true;
        else
            break;
    }
    for(j=i; j != 0 && j<len; j++){
        if(str[j] == 'd')
            check = true;
        else{
            check = false;
            break;
        }
    }

    return check;
}


bool abFunc(string str, int len) // abb*
{
    int i;
    bool check = false;


    if(len < 2)
        return false;
    else if(len >= 2 && str[0] == 'a' && str[1] == 'b'){
            check = true;
        for(i=2; i<len; i++){
            if(str[i] != 'b'){
                check = false;
                break;
            }
        }
        return check;
    }

    return false;
}


bool abcFunc(string str, int len) // a+bc
{
    int i;

    if(len == 3 && str[0] == 'a' && str[1] == 'b' && str[2] == 'c')
        return true;
    else if(str[0] == 'a' && len > 3 && str[len-2] == 'b' && str[len-1] == 'c'){
        for(i=1; i<len-2; i++){
            if(str[i] != 'a')
                return false;
        }
        return true;
    }

    return false;
}

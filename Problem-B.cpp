#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

void daonguoc(int &a)
{
    int temp = 0;
    
    while (a != 0)
    {
        temp += a % 10;
        temp *= 10;
        a /= 10;
    }
    temp /= 10;
    a = temp;
}

int stringToNum(char c)     // chuyen char sang so
{
    return c - '0';
}
 
char numToString(int n)     // chuyen so sang char
{
    return (char)(n+48);
}
void chuanHoa(string &a) // lam 2 xau co do dai bang nhau
{
    int lenTime = 6;

    int l1 = a.length();

    int n = abs(l1 - lenTime);
    
    if (l1 < lenTime)
        a.insert(0, n, '0');  // .insert(int pos, int n, int ch)
}

void nhaptime(string song[], int &n)
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> song[i];
}

void CHAR_INT(char &a)
{
    a -= 48;
}

void deleteChar(string &a, char b)
{
    int len = a.length();

    int count = 0;
    string temp = "";
    
    for (int i = 0; i < len; i++)
    {
        if ((int) a[i] != (int) b)
        {
            temp += a[i];
            count++;
        }
    }
    
    a = "";
    
    for (int i = 0; i < count; i++)
    {
        a += temp[i];
    }
}

int getChar(string a, int index)
{
    // "334455" => index = 2 => get int 4
    CHAR_INT(a[index]); // convert Char to Int

    return a[index];
}

string single(string a, int val1, int val2)
{
    string b = "";
    CHAR_INT(a[val1]);
    CHAR_INT(a[val2]);
    b += to_string(a[val1]) + to_string(a[val2]);
    return b;
}

int STRING_INT(string a)
{
    return stoi(a);
}

int STRING_INT_INDEX(string a, int index)
{
    CHAR_INT(a[index]);
    return a[index];
}

string CALC_SUM_TIME (string song[], int n)
{
    string hh = "";
    string mm = "";
    string ss = "";
    
    for (int i = 0; i < n; i++)
    {
        deleteChar(song[i], ':');
        chuanHoa(song[i]);
    }
    
    int sum = 0;
    
    string temp = "";
    
    // calc seconds
    for (int i = 0; i < n; i++)
    {
        temp += single(song[i], 4,5); // them vao chuoi
        
        sum += STRING_INT(temp);    // convert string to int
        
        temp = "";
    }
    
    bool isResume = true;
    int count = 0;
    
    while(isResume)
    {
        if (sum > 59)
        {
            sum -= 60;
            count++;
        } else {
            isResume = false;
        }//45 + 56 + 56 = 157 nho 2 = 37
    }
    
    ss += to_string(sum);    // convert int to string;
    sum = 0; // reset variable
    sum += count; // tang them count don vi

    // calc minutes
    for (int i = 0; i < n; i++)
    {
        temp += single(song[i], 2,3); // them vao chuoi
        sum += STRING_INT(temp);    // convert string to int
        temp = "";
    }

    isResume = true;
    count = 0;
    
    while(isResume)
    {
        if (sum > 59)
        {
            sum -= 60;
            count++;
        } else {
            isResume = false;
        }
    }
    
    mm += to_string(sum);    // convert int to string;
    sum = 0; // reset variable
    sum += count; // tang them count don vi
    
    // calc hour
    for (int i = 0; i < n; i++)
    {
        temp += single(song[i], 0,1); // them vao chuoi
        
        sum += STRING_INT(temp);    // convert string to int
        
        temp = "";
    }

    isResume = true;
    count = 0;
    
    while(isResume)
    {
        if (sum > 23)
        {
            sum -= 23;
            count++;
        } else {
            isResume = false;
        }
    }
    
    hh += to_string(sum);    // convert int to string;
    sum = 0; // reset variable
    sum += count; // tang them count don vi
    
    return hh + ":" + mm + ":" + ss;
}

int main()
{
    int n;
    
    string time_song[1000];
    
    nhaptime(time_song, n);
    
    cout << CALC_SUM_TIME(time_song, n);

    return 0;
}
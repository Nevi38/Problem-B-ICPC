#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

void chuanHoa(string &a) // lam 2 xau co do dai bang nhau
{
    int lenTime = 6;

    int l1 = a.length();

    int n = abs(l1 - lenTime);
    
    if (l1 < lenTime)
        a.insert(0, n, '0');  // .insert(int pos, int n, int ch)
}

void nhaptime(string song[], int &n, int &crossfadeTime)
{
    cout << "Enter number songs: ";
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cout << "Time Songs [hh:mm:ss] " << i + 1 << "th: ";
        cin >> song[i];
    }

    cout << "Enter CrossfadeTime (seconds): ";
    cin >> crossfadeTime;
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

void format(string &xau)
{
    int len = xau.length();

    if (len < 2)
        xau.insert(0, 1, '0');
}

void crossfadeTimes(string &hh, string &mm, string &ss, int crossfadeTime, int n)
{
    int sum = 0;
    int hour, minutes;
    
    sum += STRING_INT(hh) * 3600;
    hour = sum / 3600;
    
    sum += STRING_INT(mm) * 60;
    minutes = sum - (hour * 3600);
    
    sum += STRING_INT(ss);
    
    sum -= (crossfadeTime * (n - 1));

    hh = "";
    mm = "";
    ss = "";

    int maths_minutes = (sum/60)- (hour*60);
    
    int maths_seconds = sum - (hour*3600 + minutes);
    
    hh += to_string(sum / 3600);
    mm += to_string(maths_minutes);
    ss += to_string(maths_seconds);
}

string CALC_SUM_TIME (string song[], int n, int crossfadeTime)
{
    string hh = "";
    string mm = "";
    string ss = "";
    
    for (int i = 0; i < n; i++)
    {
        deleteChar(song[i], ':');
        chuanHoa(song[i]);
    }  

    // calc seconds
    int sum = 0; 
    string temp = "";
    
    for (int i = 0; i < n; i++)
    {
        temp += single(song[i], 4,5); // noi 2 ki tu lai voi nhau
        
        sum += STRING_INT(temp);    // convert string to int
        
        temp = "";
    }

    int count = 0;
    
    if (sum > 59)
    {
        count += sum / 60;
        sum %= 60;
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

    count = 0;

    if (sum > 59)
    {
        count += sum / 60;
        sum %= 60;
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

    hh += to_string(sum);    // convert int to string;
    
    crossfadeTimes(hh, mm, ss, crossfadeTime, n);
    
    // format hh:mm:ss
    format(hh); 
    format(mm);
    format(ss);
    
    return hh + ":" + mm + ":" + ss;
}

int main()
{
    int n, crossfadeTime;
    
    string time_song[1000];
    
    nhaptime(time_song, n, crossfadeTime);
    
    cout << "Total time: " << CALC_SUM_TIME(time_song, n, crossfadeTime);

    return 0;
}
#include <iostream>
#include <string.h>
#include <cmath>
#include <time.h>
#include <iomanip>
#include <sstream>

using namespace std;

void conversion(double counts)
{
  ostringstream ss;
  ss.precision(6);
  ss << fixed << counts;
  cout << ss.str() << " seconds";
}

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
    cin >> n;
    cin >> crossfadeTime;
    
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
    int hour, minutes, seconds;
    
    sum += STRING_INT(hh) * 3600;
    
    sum += STRING_INT(mm) * 60;
    
    sum += STRING_INT(ss);
    
    sum -= (crossfadeTime * (n - 1));

    hh = "";
    mm = "";
    ss = "";

    hour = sum / 3600;
    minutes = (sum / 60) - (60*hour);
    seconds = sum - ((hour * 3600) + (minutes * 60));

    hh += to_string(hour);
    mm += to_string(minutes);
    ss += to_string(seconds);
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
        temp += single(song[i], 4,5);
        
        sum += STRING_INT(temp);
        
        temp = "";
    }

    int count = 0;
    
    if (sum > 59)
    {
        count += sum / 60;
        sum %= 60;
    }
    
    ss += to_string(sum);
    
    sum = 0; // reset variable
    
    sum += count; // tang them count don vi

    // calc minutes
    for (int i = 0; i < n; i++)
    {
        temp += single(song[i], 2,3);
        sum += STRING_INT(temp);
        temp = "";
    }

    count = 0;

    if (sum > 59)
    {
        count += sum / 60;
        sum %= 60;
    }

    mm += to_string(sum);
    
    sum = 0; // reset variable
    
    sum += count; // tang them count don vi
    
    // calc hour
    for (int i = 0; i < n; i++)
    {
        temp += single(song[i], 0,1);
        
        sum += STRING_INT(temp);
        
        temp = "";
    }

    hh += to_string(sum);
    
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
    
    clock_t start, end;   // Declare variable time
    
    double time_use;      // Time use
    
    start = clock();     // Get time before execute program
    
    cout << CALC_SUM_TIME(time_song, n, crossfadeTime);
    
    end = clock(); 
    
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    // Calculator time execute program
    
    double times = time_use;
    
    cout << endl << "Time excute: ";

    conversion(times);
    
    return 0;
}
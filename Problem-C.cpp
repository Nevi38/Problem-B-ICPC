#include <iostream>
#include <string>

using namespace std;

int maxValue(string items)
{
	int max = items[0];
	
	for (int i = 1; i < items.length(); i++)
		if (max > items[i])
			max = items[i];
	return max;
}
	
int CURRENT_MAX_VALUE(string items, char item)
{
    int len = items.length();
    int max = 999;
    int temp = 999;
    
    for (int i = 0; i < len; i++)
    {
        if ((int) items[i] == (int) item)
        {
            if ((i-1) < 0)
               max = items[i+1];
            else if ((i + 1 == len))
                max = items[i - 1];
            else 
            {
                if (items[i-1] >= items[i+1])
                    max = items[i + 1];
                else
                    max = items[i - 1];
            }
            
            if (len > 1)
            {
                if (temp < max)
                    max = temp;
            }
        }
        temp = max;
    }
    return max;
}

int main()
{
    string items;
    
    cin >> items;
    
    int steps;
    
    cin >> steps;
    
    char START_ITEM = maxValue(items); // get 1 char most preferred in string items
    
    if (items.length() < 2)
        items += " ";
    
	for (int i = 1; i <= steps; i++)
    {
        cout << START_ITEM;
        data = CURRENT_MAX_VALUE(items, data);
    }
    return 0;
}


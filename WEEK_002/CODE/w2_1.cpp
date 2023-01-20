#include <iostream>
using namespace std;
    int round = 0;
    int Arr[] = { 32, 7, 35, 19, 5, 12, 41, 36, 37, 27, 2, 46, 11, 50, 40, 16, 14, 47, 30, 17, 84, 425, 836, 393, 999,
    880, 772, 410, 357, 134, 897, 481, 619, 972, 565, 974, 710, 207, 976, 392 };
    int size = sizeof(Arr) / sizeof(Arr[0]);

    int low = 0;
    int high = sizeof(Arr) / sizeof(Arr[0]);

void bubble_sort()
{
    for (int i = 0; i < high; i++)
    {
        for (int j = i+1; j < high; j++)
        {
            if (Arr[i] > Arr[j])
            {
                int temp = Arr[j];
                Arr[j] = Arr[i];
                Arr[i] = temp;
            }
        }
    }
}

bool seq_search(int array[], int input, int size)
{
    for (int i = 0; i <= size; i++)
    {
        round++;
        if (array[i] == input)
        {
            return 1;
        }
    }
    return 0;
}

void binary_search(int input, int low , int high)
{
    round++;
    int middle = (low+high) / 2;    
    if(low == high && Arr[low] != input)
    {
        return;
    }
    if(middle > high)
    {
        return;
    }
    if(middle < low)
    {
        return;
    }
    if(high < low)
    {
        return;
    }
    if(Arr[middle] == input)
    {
        return;
    }
    if(high == low)
    {
        return;
    }
    if(Arr[middle] < input)
    {
        binary_search(input,middle+1,high);
    }
    else if(Arr[middle] > input)
    {
        binary_search(input,low,middle-1);
    }
}

void interpolation_search(int input, int low , int high)
{
    round++;
    if(low == high && Arr[low] != input)
    {
        return;
    }
    int middle = low + (((double)(high - low) / (Arr[high] - Arr[low])) * (input - Arr[low]));
    if(middle < low)
    {
        return;
    }
    if(middle > high)
    {
        return;
    }
    if(high < low)
    {
        return;
    }
    if(Arr[middle] == input)
    {
        return;
    }
    if(high == low)
    {
        return;
    }
    if(Arr[middle] < input)
    {
        interpolation_search(input,middle+1,high);
    }
    else if(Arr[middle] > input)
    {
        interpolation_search(input,low,middle-1);
    }
}


int main()
{
    
    round = 0;
    for (int i = 0; i < size; i++)
    {
        seq_search(Arr,Arr[i],size);
    }
    cout << round << endl;


    round = 0;
    for (int i = 0 ; i < size ; i++)
    {
        binary_search(Arr[i],low,high-1);
    }
    cout << round << endl;

    round = 0;
    for (int i = 0 ; i < size ; i++)
    {
        interpolation_search(Arr[i],low,high-1);
    }
    cout << round << endl;
}
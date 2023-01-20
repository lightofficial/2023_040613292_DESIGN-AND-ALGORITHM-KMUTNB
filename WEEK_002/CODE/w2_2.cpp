#include <bits/stdc++.h>
using namespace std;
int counters = 0;
int arr[10000];

string KEY;
int Searching_Value;

int found_number = 0;
int lefter = 0;


void sorting()
{
    for(int i = 0 ; i < counters ; i++)
    {
        for(int j = i + 1 ; j < counters ; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void Binary_Search(int input , int left , int right)
{
    int mid = (right + left) / 2;
    cout << left << "," << mid << "," << right << " ";
    if(arr[mid] == input)
    {
        found_number = 1;
        return;
    }
    if(left == right || right < left || right < 0 || left < 0 || mid < 0)
    {
        return;
    }
    if(arr[mid] < input)
    {
        Binary_Search(input,mid+1,right);
    }
    else if(arr[mid] > input)
    {
        Binary_Search(input,left,mid-1);
    }
}

void GO_IN(int input)
{
    found_number = 0;
    sorting();
    Binary_Search(input,lefter,counters-1);
}

int main()
{
    while(1)
    {
        cin >> KEY;
        if (KEY == "p")
        {
            for(int i = 0 ; i < counters ; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        else if (KEY == "s")
        {
            cin >> Searching_Value;
            GO_IN(Searching_Value);
            if (found_number == 1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }

        else if (KEY == "o")
        {
            break;
        }

        else
        {
            const char *to_int = KEY.c_str();
            arr[counters] = atoi(to_int);
            counters++;
        }
    }
    return 0;
}
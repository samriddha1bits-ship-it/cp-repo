#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // head and tail
    int tail = 0, head = -1;

    // datastructure for the window
	int cntzero = 0;
	
    // answer maintain
    int ans = 0;

    while (tail < n)
    {
        while (// there is a next element to eat && we can eat)
        {
            head++;
            
            // include elemenet at head in the data structure
        }
       
        
        // update the answer for current start
        
        
        // move start one step forward.
        if (tail > head)    // keep it same for all question, it basically help to handle empty subarray
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            // change data  structure because removing tail element
            
            tail++;
        }
    }

    cout << ans << endl;
}

#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void largestSubarray( int arr[],  int n)
{
    
    int maxlength = -1; //to upddate the maximum size of subarray
    int start_index = 0;
    int temp[n];
    int min = arr[0], max = arr[0];
    if (arr[0]==0)
    {
        temp[0]=-1;
    }
    else
    {
        temp[0]=1;
    }
    for (int i = 1; i < n; ++i)//creating temp array
    {
        if (arr[i]==0)
        {
            temp[i] = temp[i-1] - 1; //adding all the elements that are left
        }
        else
        {
            temp[i] = temp[i-1] + 1;
        }
        if(temp[i]<min)
            min = temp[i];
        if(temp[i]>max)
            max = temp[i];
    }
    int hash[max-min+1];
    // Initialize hash table
    for (int i=0; i<max-min+1; i++)
        hash[i] = -1;
    for (int i = 0; i < n; ++i)
    {
        //case 1
        if (temp[i]==0)
        {
            maxlength = i + 1;
            start_index = 0;
        }
        //case 2
        if (hash[temp[i]-min] == -1)//value is not present in table
        {
            hash[temp[i]-min] = i; //storing the index of left occurence of the value
        }
        else
        {
            if ((i - hash[temp[i]-min]) > maxlength)//check current subarray length with max length
            {
                maxlength = i - hash[temp[i]-min];
                start_index = hash[temp[i]-min] + 1;
            }
        }
    }
    if(maxlength == -1)
    {
        cout<<"None"<<endl;
    }
    else
    {
        cout<<start_index<<" ";
        cout<<maxlength + start_index -1<<endl;
        // for (int i = start_index; i <= (start_index + maxlength -1); ++i)
        // {
        //     cout<<arr[i]<<" ";
        // }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int A[n];
        for(int i=0;i<n;i++)
            cin>>A[i];
        
        
        //code
        largestSubarray(A, n);
        
    }
    return 0;
}

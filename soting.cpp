#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void buubleop(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        bool swaps=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swaps=true;
            }
            if(!swaps)break;
        }
    }
}

void insertion(int arr[],int n)
{
    int i=0;
    int j=i+1;
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
      arr[j+1]=key;
    }

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void selection(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int minidx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]< arr[minidx])minidx=j;
        }
        swap(arr[i],arr[minidx]);
    }

    // print 

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}
  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  

    int n;
    cin>>n;
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
       cin>>arr[i];
    }

    insertion(arr,n);
    selection(arr,n);

   
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int p=partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    quicksort(a, 0, n-1);
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
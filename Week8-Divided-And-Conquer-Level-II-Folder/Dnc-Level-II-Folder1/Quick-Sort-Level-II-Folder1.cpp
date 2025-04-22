#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int size, int start, int end)
{
    int pivotindex = start;
    int pivotelement = arr[start];

    
    int count =0;

    for(int i=start +1; i<=end; i++){

        if(arr[i] <= pivotelement)
        {
            count++;
        }
    }

    int rightindex = start+count;
    swap(arr[pivotindex],arr[rightindex]);
    pivotindex = rightindex;

    int i= start;
    int j= end;

    while(i<pivotindex && j>pivotindex)
    {
        while(arr[i] <pivotelement)
        {
            i++;
        }
        while(arr[j]>pivotelement)
        {
            j--;
        }
        if(i<pivotindex && j>pivotindex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotindex;

}


void quicksort(vector<int> &arr, int size, int start , int end)
{
    if(start >= end)
    {
        return ;
    }

    // partition logic 

    int p = partition(arr,size, start,end);


    // left callls 
    quicksort(arr,size, start ,p-1);

    // right calls 
    quicksort(arr,size, p+1, end);


}

int main()
{
    int size;
    cout<<"Enter the size of the array :";
    cin>>size;

    vector<int>arr(size);

    for(int i=0; i<arr.size(); i++)
    {
        cout<<"EMter the element of the array : ";
        cin>>arr[i];
    }

    int start=0;
    int end = size-1;
    quicksort(arr,size, start , end);

    for(int i=0; i<arr.size(); i++)
    {
        cout<< arr[i] << " ";
    }
}
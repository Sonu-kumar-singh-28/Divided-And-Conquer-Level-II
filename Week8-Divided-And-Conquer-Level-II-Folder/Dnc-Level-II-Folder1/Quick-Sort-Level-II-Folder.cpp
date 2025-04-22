#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int size, int start , int end)
{
    // choose pivot element 
    int pivotindex = start;
    int pivotelement = arr[start];

    // step2 find right position for pivot element ans place it there 

    int count =0;

    for(int i=start +1; i<=end; i++){

        if(arr[i] <= pivotelement)
        {
            count++;
        }
    }

    // jab mainr lop se bahar hu tab trak mere pass pivot ki right position pata hai 
    int rightindex = start+count;
    swap(arr[pivotindex],arr[rightindex]);
    pivotindex = rightindex;

    // step 3 left mai chote and right me bade 

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
        cout<<"Enter the elememt of the array :";
        cin>>arr[i];
    }

    int start =0;
    int end = size-1;
    quicksort(arr,size, start, end);

    for(int i=0; i<arr.size(); i++){
    cout<< arr[i] << " ";
    }
}

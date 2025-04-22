#include<iostream>
using namespace std;
void printpermutaions(string &s, int i)
{
    if(i>=s.length())
    {
        cout<< s <<" ";
        return ;
    }

    // swapping 

    for(int j =i; j<s.length(); j++)
    {
        swap(s[i], s[j]);

        printpermutaions(s, i+1);
        // backtracking 
        swap(s[i],s[j]);
    }
}

int main() 
{
    string s;
    cout<<"Enter the input of the string ";
    getline(cin,s);

    cout << " inputs is : "<< s << endl;
    int i=0;
    printpermutaions(s,i);

    for(int i=0; i<s.length(); i++)
    {
        cout<< s[i] << " " ;
    }
}
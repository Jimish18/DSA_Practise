#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v,int r,int mid,int l)
{
    vector<int > a;
    vector<int > b;
    

    for(int i = 0; i < mid-r+1; i++ )
    {
        a.push_back(v[r+i]);
    }
    for(int i = 0; i < l-mid; i++)
    {
        b.push_back(v[mid+1+i]);
    }

    int i = 0;
    int j = 0;
    int k = r;

    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {            
            v[k] = a[i];
            i++;k++;
        }
        else
        {
            v[k] = b[j];
            j++;k++;
        }
    }

    while(i < a.size())
    {
        v[k] = a[i];
        i++;k++;    
    }

    while(j < b.size())
    {
        v[k] = b[j];
        j++;k++;
    }

}

void mergeSort(vector<int> &v, int r , int l)
{
    if(r<l)
    {
        int mid = (r+l)/2;

        mergeSort(v,r,mid);
        mergeSort(v,mid+1,l);

        merge(v,r,mid,l);
    }
}

int main()
{
    vector<int> v = {7,6,5,4,3,2,1};

    for(int i = 0 ; i < v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    mergeSort(v,0,6);

    for(int i = 0 ; i < v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
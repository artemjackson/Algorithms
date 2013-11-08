#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void Find_q(int *a, int r,int l)
{

}

void swap(int &x,int &y)
{
    int tmp=x;
    x=y;
    y=tmp;
}

void QuckSort(int *a, int l, int r)
{
    /* uncomment some line to choose a support element as you wish */

    //  int x=a[l];     //left element
    //    int x=a[r];     //right elemnt
    //  int x=a[l+(r-l)/2];     //midle element
    int x=a[rand()%(r-l+1) + l];        //random element betwen r and l

    int i=l;
    int j=r;

    while(i<=j)
    {
        while(a[i]<x) ++i;
        while(a[j]>x) --j;
        if(i<=j)
        {
            swap(a[i],a[j]);
            ++i;
            --j;
        }
    }

    if(i<r)QuckSort(a, i, r);
    if(l<j)QuckSort(a, l, j);
}

void AntiQuckSort(int *a, int l, int r)
{
    int x=a[r];     //right elemnt

    int i=l;
    int j=r;

    while(i<=j)
    {
        while(a[i]>x) ++i;
        while(a[j]<x) --j;
        if(i<=j)
        {
            swap(a[i],a[j]);
            ++i;
            --j;
        }
    }

    if(i<r)AntiQuckSort(a, i, r);
    if(l<j)AntiQuckSort(a, l, j);
}

int main()
{
    srand(time(0));

    int N;
    cin>>N;

    int *a=new int[N];

    for(int i=0; i<N; ++i)
    {
        a[i]=rand()&1000;
    }

    /*
    cout<<"Raw array:\n";
    for(int i=0; i<N; ++i)
    {
        cout<<a[i]<<" ";
    }
    */

    int startTime,endTime;

    startTime=time(0);
    QuckSort(a,0,N-1);
    endTime=time(0);

    cout<<"\nQuckSort works near "<<endTime-startTime<<" seconds\n";

    startTime=time(0);
    AntiQuckSort(a,0,N-1);
    endTime=time(0);
    cout<<"\nAntiQuckSort works near "<<endTime-startTime<<" seconds\n";
    /*
    cout<<"Sort array:\n";
    for(int i=0; i<N; ++i)
    {
        cout<<a[i]<<" ";
    }
    */

    delete []a;
    a=0;

    return 0;
}

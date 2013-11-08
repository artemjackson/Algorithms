#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Merge(int *ar, int *buf, int l, int m, int r)
{
    int i=l;
    int j=m+1;
    int k=l;

    while((i<=m) && (j<=r))
    {
        if (ar[i]<ar[j])
        {
            buf[k]=ar[i];
            ++i;
        }
        else
        {
            buf[k]=ar[j];
            ++j;
        }
        ++k;
    }

    if(i>m)
    {
        for( ; j<=r; ++j)
        {
            buf[k]=ar[j];
            ++k;
        }
    }
    else
    {
        for( ;i<=m; ++i)
        {
            buf[k]=ar[i];
            ++k;
        }
    }

    for(int i=l; i<=r; ++i) ar[i]=buf[i];


}
void MergeSort(int *ar, int *buf, int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        MergeSort(ar,buf,l,m);
        MergeSort(ar,buf,m+1,r);
        Merge(ar,buf,l,m,r);
    }
}

int main()
{
    srand(time(0));

    int N;
    cin>>N;

    int *ar=new int[N];
    int *buf=new int[N];

    for(int i=0; i<N; ++i)
    {
        ar[i]=rand()&1000;
    }

     /*
    cout<<"Raw array:\n";
    for(int i=0; i<N; ++i)
    {
        cout<<ar[i]<<" ";
    }
     */

    int startTime,endTime;

    startTime=time(0);
    MergeSort(ar, buf, 0, N-1);
    endTime=time(0);

    cout<<"\nMergeSort works near "<<endTime-startTime<<" seconds\n";

     /*
    cout<<"Sort array:\n";
    for(int i=0; i<N; ++i)
    {
        cout<<ar[i]<<" ";
    }
    */

    delete []ar;
    ar=0;



    return 0;
}

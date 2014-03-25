#include <iostream>

using namespace std;

long int interpolatingSearch (long int *ar, int size,long int key);
long int interpolatingSearchByPower (long int *ar, int size,long int key);

void printArray (int *ar, int size);

int main()
{

    int size=30;
    long int ar[size];

     ar[0]=1;
/* числа Фибоначи */
/*
    ar[1]=2;

    for(int i=2; i<size; ++i)
        ar[i]=ar[i-1]+ar[i-2];
*/
/* степени двойки */
    for(int i=1; i<size; ++i)
//       ar[i]=ar[i-1]<<1;       // умножение на 2 :)
ar[i]=ar[i-1]*3;
 long int key, result;

//    printArray(ar, size);

    cout<<"Введите ключ поиска:\n";
    cin>>key;

    cout<<"Обычный поиск\n";
    result = interpolatingSearch (ar, size, key);
    if (result != -1)
        cout<<"Индекс значения равен "<<result<<"\n";
    else
        cout<<"Значение не найдено\n";
    result = 0;

    cout<<"\n\"Экспотенциальный\" поиск\n";
    result = interpolatingSearchByPower (ar, size, key);

    if (result != -1)
        cout<<"Индекс значения равен "<<result<<"\n";
    else
        cout<<"Значение не найдено\n";
    result = 0;

    return 0;
}

long int interpolatingSearch (long int *ar, int size, long int key)
{
	int k=0;
    int low = 0;
    int high = size - 1;
    int mid;

    while(ar[low]<key && ar[high]>=key)
    {
        k++;
        mid=low+ ((key-ar[low])*     (high-low))/(ar[high]-ar[low]);
        if(ar[mid]<key)
            low=mid + 1;
        else if(ar[mid]>key)
            high=mid-1;
        else
        {

cout<<k<<" операций \n";

            return mid;
        }
    }

cout<<k<<" операций \n";

    if(ar[low]==key)
        return low;
    else
        return -1;

}

long int log(long int x,long int y);

long int interpolatingSearchByPower (long int *ar, int size,long int key)
{
	int k=0;
    int low = 0;
    int high = size - 1;

    if(key > ar[low] && key<=ar[high])
    {
        ++k;
        return log(ar[1],key);

    }
    else
    {
    if(ar[low]==key)
        return low;
    else
        return -1;
    }
    cout<<k<<" операций \n";
}

long int log(long int x,long int y)
{
    long int d=0;
    while(y/=x)
    d++;
    return d;
}

void printArray (int ar[], int size)
{
    cout<<"Индексы:\n";

    for(int i=0; i<size; ++i)
    {
        cout.width(5);
        cout<<i;
    }
    cout<<"\n";

    for (int i=0; i<size; ++i)
        cout<<"-----";
    cout<<"\n";

    for (int i=0; i<size; ++i)
    {
        cout.width(5);
        cout<<ar[i];
    }
    cout<<"\n";
}

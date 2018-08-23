#include <iostream>

using namespace std;


class sorting
{
public:
    sorting(){};
    ~sorting(){};

    void qsort(int* a, int l, int r)
    {
        if (l < r)
        {
            int i=l, j=r, x=a[l];
            while (i<j)
            {
                while (i<j && a[j]>x)
                    j--;
                if (i<j)
                    a[i++] = a[j];

                while (i<j && a[i]<=x)
                    i++;
                if (i<j)
                    a[j--] = a[i];
            }

            a[i] = x;
            qsort(a, l, i-1);
            qsort(a, i+1, r);
        }
    };

    void bubbleSort(int* a, int size)
    {
        for (int i=1; i<size; i++)
            for (int j=0; j<i; j++)
                if (a[j]>a[i])
                    swap(a[j], a[i]);
    };

    void insertionSort(int* a, int n)
    {
        for (int i=1; i<n; i++)
        {
            int key = a[i];
            int j = i-1;
            while (j>=0 && a[j]>key)
            {
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = key;
        }
    };

    void selectionSort(int* a, int n)
    {
        for (int i=0; i<n; i++)
        {
            int min = i;
            for (int j=i+1; j<n; j++)
            {
                if (a[min]>a[j])
                    min = j;
            }
            swap(a[i], a[min]);
        }
    };

private:
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    };
};


int main(void)
{
    int a[] = {6,3,1,4,2,5};
    int size = sizeof(a)/sizeof(a[0]);

    sorting s;
    //s.qsort(a, 0, size-1);
    //s.bubbleSort(a, size);
    //s.insertionSort(a, size);
    s.selectionSort(a, size);

    cout << "size = " << size <<endl;
    for (int i=0; i<size; i++)
        cout<<a[i]<<endl;

    return 0;
}

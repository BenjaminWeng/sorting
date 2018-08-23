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
    s.qsort(a, 0, size-1);

    cout << "size = " << size <<endl;
    for (int i=0; i<size; i++)
        cout<<a[i]<<endl;

    return 0;
}

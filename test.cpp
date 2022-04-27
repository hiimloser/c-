#include <iostream>
using namespace std;

void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n Nhap cac so nguyen a[" << i << "]: ";
        cin >> a[i];
    }
}

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " " << endl;
    }
}
bool ktratangdan(int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] >= a[i])
            dem++;
    }
    if (dem == n - 1)
        return true;
    else
        return false;
}

void QuickSort(int a[], int l, int r)
{
    int i, j, x;
    x = a[(l + r) / 2];
    i = l;
    j = r;
    do
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (l < j)
        QuickSort(a, l, j);
    if (i > r)
        QuickSort(a, i, r);
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }

    // Nếu không tìm thấy
    return -1;
}
int main()
{
    int n;
    cout << "\n Nhap so luong so nguyen: ";
    cin >> n;
    int a[200];
    nhap(a, n);
    cout << "\n-------------In thong tin --------------\n";
    xuat(a, n);

    int flag = ktratangdan(a, n);
    if (flag == 1)
    {
        printf("\nMang tang dan");
    }
    else
    {
        printf("\nKhong thoa DK");
    }
    QuickSort(a, 0, n - 1);
    cout << "\n Mang sau khi duoc sap xep tang dan: \n";
    xuat(a, n);
 
    int x;
    cout << "\n Nhap so can tim: ";
    cin >> x;

    if (binarySearch(a,0, n, x) == -1)
    {
        cout << "\n Khong tim thay !";
    }
    else
    {
        cout << "\n Tim thay " << x << " " << endl;
        
    }
}
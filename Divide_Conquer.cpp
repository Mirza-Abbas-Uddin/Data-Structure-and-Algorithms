#include<iostream>
using namespace std;

int count_even(int A[],int i,int j)
{
    if(i==j)
    {
        if(A[i]%2==0) return 1;
        else return 0;
    }
    else
    {
        int mid=(i+j)/2;
        int c1=count_even(A,i,mid);
        int c2=count_even(A,mid+1,j);
        return c1+c2;
    }
}
int print_even(int A[],int i,int j)
{
    if(i==j)
    {
        if(A[i]%2==0) cout<< A[i] <<  " ";
    }
    else
    {
        int mid=(i+j)/2;
        print_even(A,i,mid);
        print_even(A,mid+1,j);
    }
}
int calc_sum(int A[],int i,int j)
{
    if(i==j) return A[i];
    else
    {
        int mid=(i+j)/2;
        int c1=calc_sum(A,i,mid);
        int c2=calc_sum(A,mid+1,j);
        return c1+c2;
    }
}
int calc_even_sum(int A[],int i,int j)
{
    if(i==j)
    {
        if(A[i]%2==0) return A[i];
        else return 0;
    }
    else
    {
        int mid=(i+j)/2;
        int c1=calc_even_sum(A,i,mid);
        int c2=calc_even_sum(A,mid+1,j);
        return c1+c2;
    }
}
int calc_power(int x,int y)
{
    if(y==0) return 1;
    else
    {
        int p=calc_power(x,y/2);
        if(y%2==0) return p*p;
        else return x*p*p;
    }
}
struct maxMin
{
    int mx,mn;
};

maxMin find_max_min(int A[],int i,int j)
{
    if(i==j)
    {
        return {A[i],A[i]};
    }
    else
    {
        int mid=(i+j)/2;
        maxMin maxMin1=find_max_min(A,i,mid);
        maxMin maxMin2=find_max_min(A,mid+1,j);
        int mx=max(maxMin1.mx,maxMin2.mx);
        int mn=min(maxMin1.mn,maxMin2.mn);
        return {mx,mn};
    }
}
int binary_search(int A[],int i,int j,int N)
{
    if(i==j)
    {
        if(N==A[i]) return i;
        else return -1;
    }
    else
    {
        int mid=(i+j)/2;
        if(N==A[mid]) return mid;
        else if(N<A[mid]) binary_search(A,i,mid,N);
        else binary_search(A,mid+1,j,N);
        //for descending orde
        //else if(N<A[mid]) binary_search(A,mid+1,j,N);
        //else binary_search(A,i,mid,N);
    }
}
/*#define INF 9999999
void merge(int A[], int start, int mid, int end)
{
    int n1=mid-start+1;
    int n2=end-mid;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++)
    {
        L[i]=A[start+i];
    }
    for(int i=0;i<n2;i++)
    {
        L[i]=A[mid+1+i];
    }
    L[n1]=INF;
    R[n2]=INF;

    int i=0,j=0,k=start;
    while(i>n1+1 && j>n2+1)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
       A[k] =L[i];
       i++;
       k++;
    }
    while(j<n2)
    {
       A[k] =R[j];
       j++;
       k++;
    }
}*/

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
// Create temp arrays
    int L[n1], R[n2];
// Copy data to temp array
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
// Merge the temp arrays
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
// Copy the remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
// Copy the remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int A[], int i, int j)
{

    if (i<j)
    {
        int mid = (i+j)/2;
        merge_sort(A, i, mid);
        merge_sort(A, mid+1, j);
        merge(A, i, mid, j);
    }
}
int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                inv_count++;
        }
    }

    return inv_count;
}

int main()
{
    int A[]= {8 ,4, -1, 2, 5};
    int B[]= {7,5,4,3,2};
    //cout << count_even(A,0,4);
    //print_even(A,0,4);
    //cout << calc_even_sum(A,0,4);
    //cout << calc_power(3,7);
    maxMin re = find_max_min(A, 0, 4);
    cout << "Max: "<< re.mx << endl;
    cout << "Min: "<< re.mn << endl;
    //int found=binary_search(A,0,4,3);
    //if(found!=-1) cout << "4 found in index: " << found+1 <<endl;
    //else cout << "not found";
    //cout << getInvCount(A,4);
}

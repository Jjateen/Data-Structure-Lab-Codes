#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdlib>
#define endl "\n"
using namespace std;

void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}

class ArraY{
    private:
    int n;
    int a[500];
    public:
    ArraY(){}
    void inputdata(){
        cout<<"Enter the size of array : ";
        cin>>n;
        cout<<"\nEnter the elements of array : \n";
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
    }
    int getn(){
        return n;
    }
    void displayData(){
        cout<<"The array is : \n";
        for(int i=0;i<n;++i){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        
    }
    void SearchNo(){
        int p;
        cout<<"enter the number you wanted to search "<<endl;
        cin>>p;
        for(int i=0;i<n;++i){
            if(a[i]==p){
                    cout<<"The number is at postion "<<i<<endl;
            }
        }
        
    }
    void maxNo(){
        int max=INT_MIN;
        for(int i=0;i<n;++i){
            if(a[i]>max){
                max=a[i];
            }
        }
        cout<<"The max number in the array is "<<max<<endl;
    }
    void minNo(){
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i]<min){
                min=a[i];
            }
        }
        cout<<"The min number in the array is "<<min<<endl;
    }
    void AsdOrder(){
        int temp;
    for (int i = 0; i < n; i++){
            for (int j = 0;( j + 1) < (n- i); j++){
                if (a[j] > a[j + 1]){   
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
         cout<<"The ascd order array is "<<endl;
        for(int i=0;i<n;i++){
           cout<<a[i]<<" ";
            
        }
        cout<<endl;
    }
    void DesOrder(){
        int tem;
        for (int i = 0; i < n; i++){
            for (int j = 0; (j + 1) < (n - i); j++){
                if (a[j] < a[j + 1])
                {
                    tem = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tem;
                }
        
            }
        }
        cout<<"The descd Order of Array is "<<endl;
        for(int j=0;j<n;j++){
            cout<<a[j]<<" ";
        }
    }
    int find(int m){
        int j;
        for(int i=0;i<n;++i){
            if(a[i]==m){
                j=i;
                break;
            }
        }
        return j;
    }
    void missingEle(){
        int l,r,cc=0;
        cout<<"\nEnter Boundary Elements : \n";
        cin>>l>>r;
        sort(a,a+n);
        int li=this->find(l);
        int ri=this->find(r);
    
        for(int i=li;i<=ri;++i){
            if(a[i]>l && a[i]<r)
            cc++;
        }
        cout<<"Thus "<<a[ri]-a[li]-cc<<" Numbers are Missing";
    }
    int partition(int low,int high){
        int pivot=a[low],
            i=low,
            j=high;
        do{
            do{i++;}while(a[i]<=pivot);
            do{j--;}while(a[j]>pivot);
            if(i<j)swap(a[i],a[j]);
        }while(i<j);
        
        swap(a[low],a[j]);
        return j;
    }

    void QuickSort(int low,int high){
        int j;
        if(low<high){
        j=partition(low,high);
        QuickSort(low,j);
        QuickSort(j+1,high);
        }
    }

    void Merge(int low,int mid,int high){
        int i=low,
            j=mid+1,
            k=low;
        int b[100];

        while(i<=mid && j<=high){
            if(a[i]<a[j])
            b[k++]=a[i++];
            else
            b[k++]=a[j++];
            }
            for(;i<=mid;i++)
            b[k++]=a[i];   
            for(;j<=high;j++)
            b[k++]=a[j];
            for(i=low;i<=high;i++)
            a[i]=b[i];
    }
    void MergeSort(int low,int high){
        int mid;
        if(low<high){
            mid=(low+high)/2;
            MergeSort(low,mid);
            MergeSort(mid+1,high);
            Merge(low,mid,high);
        }
    }
    void Bubble(){
        int n = this->getn();
        int i,j,flag=0;
        for(i=0;i<n-1;i++){
            flag=0;
            for(j=0;j<n-i-1;j++)
            {
            if(a[j]>a[j+1])
            {
            swap(&a[j],&a[j+1]);
            flag=1;
            }
            }
            if(flag==0)
            break;
            }
        }
    void SelectionSort(){
        int n = this->getn();
        for(int i=0; i<n-1; i++){
            int j;  int k;
            for (j=k=i; j<n; j++){
                if(a[j] < a[k]){
                k = j;
            }
        }
        swap(&a[i], &a[k]);
        }
    }
    void InsertionSort(){
        int n = this->getn();
        for(int i=1; i<n; i++){
            int j = i-1;
            int x = a[i];
            while (j>-1 && a[j] > x){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = x;
        }
    }
};
int main(){
    ArraY a;
    stuscr:
	int i;
        system("CLS");
        cout<<"\t\t\t===========================================\n";
		cout<<"\t\t\t|         Array Management System         |\n";
		cout<<"\t\t\t===========================================\n";
		cout<<"\t\t\t|                                         |";
		cout<<"\n\t\t\t| Enter <1> Input Data                    |"
			<<"\n\t\t\t| Enter <2> Search Element                |"
            <<"\n\t\t\t| Enter <3> Return Max Element            |"
            <<"\n\t\t\t| Enter <4> Return Min Element            |"
			<<"\n\t\t\t| Enter <5> Display in Asc Order          |"
			<<"\n\t\t\t| Enter <6> Display in Dsc Order          |"
            <<"\n\t\t\t| Enter <7> Return Missing Count          |"
            <<"\n\t\t\t| Enter <8> to QuickSort                  |"
            <<"\n\t\t\t| Enter <9> to MergeSort                  |"
            <<"\n\t\t\t| Enter <10> to BubbleSort                |"
            <<"\n\t\t\t| Enter <11> to InsertionSort             |"
            <<"\n\t\t\t| Enter <12> to SelectionSort             |"
            <<"\n\t\t\t| Enter <0> to Display Data               |"
			<<"\n\t\t\t|                                         |"
			<<"\n\t\t\t===========================================";
		cout<<"\n\n\t\t\tEnter Your Choice:";
		cin>>i;
		switch(i)
		{
			case 1 :
				a.inputdata();
				goto stuscr;
				break;
			case 2 :
				a.SearchNo();
                system("PAUSE");
				goto stuscr;
				break;
			case 3 :
				a.maxNo();
                system("PAUSE");
				goto stuscr;
				break;
			case 4 :
				a.minNo();
                system("PAUSE");
				goto stuscr;
				break;
            case 5 :
				a.AsdOrder();
                system("PAUSE");
				goto stuscr;
				break;
            case 6 :
				a.DesOrder();
                system("PAUSE");
				goto stuscr;
				break;
            case 7 :
				a.missingEle();
                system("PAUSE");
				goto stuscr;
				break;
            case 8 :
				a.QuickSort(0,a.getn());
                a.displayData();
                system("PAUSE");
				goto stuscr;
				break;
            case 9 :
                a.MergeSort(0,a.getn()-1);
                a.displayData();
                system("PAUSE");
                goto stuscr;
                break;
            case 10 :
				a.Bubble();
                a.displayData();
                system("PAUSE");
				goto stuscr;
				break;
            case 11 :
				a.InsertionSort();
                a.displayData();
                system("PAUSE");
				goto stuscr;
				break;
            case 12 :
                a.SelectionSort();
                a.displayData();
                system("PAUSE");
				goto stuscr;
				break;
            case 0 :
				a.displayData();
                system("PAUSE");
				goto stuscr;
				break;
			default :
				cout<<"\nWRONG CHOICE!!!\nTRY AGAIN";
				system("PAUSE");
                goto stuscr;
				break;
		}
    return 0;
}
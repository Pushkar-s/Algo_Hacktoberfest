#include<iostream>
using namespace std;
class heapsort
{
	int heap[100];
	int count;
public:
	int accept();
	int display();
	int heapify(int *,int , int);
	int sort(int * ,int);
	int heaps();
	int min_max();
};

int heapsort::accept()
{
	cout<<"\nenter the total number of elements\n";
	cin>>count;
	cout<<"\nenter the elements\n";
	for(int i=0;i<count;i++)
		cin>>heap[i];
}

int heapsort::display()
{
	cout<<"\nthe elements are\n";
	for(int i=0;i<count;i++)
		cout<<heap[i]<<"\t";
	cout<<endl;
}

int heapsort::heapify(int heap[],int count,int i)
{
	int largest=i;
	int l=(2*i)+1;
	int r=(2*i)+2;
	if(l<count && heap[l]>heap[largest])
		largest=l;
	if(r<count && heap[r]>heap[largest])
		largest=r;
	if(largest!=i)
	{
		swap(heap[i],heap[largest]);
		heapify(heap,count,largest);
	}
}

int heapsort::sort(int heap[],int count)
{
	for(int i=(count/2)-1;i>=0;i--)
		heapify(heap,count,i);
	for(int i=count-1;i>=0;i--)
	{
		swap(heap[0],heap[i]);
		heapify(heap,i,0);
  	}
}

int heapsort::heaps()
{
	sort(heap,count);
}

int heapsort::min_max()
{
	heaps();
	cout<<"\nthe minimum marks are : "<<heap[0];
	cout<<"\nthe maximum marks are : "<<heap[count-1]<<endl;
	
}	
	
int main()
{
	char c;
	int ans;
	
	heapsort obj;
	do
	{
		cout<<"\n1.)enter details\n2.)display entered details\n3.)sort and display sorted details\n4.)display minimum ad maximum marks\n5.)exit\n";
		cin>>ans;
		switch(ans)
		{
		case 1:	obj.accept();break;
		case 2:	obj.display();break;
		case 3:	obj.heaps();obj.display(); break;
		case 4:	obj.min_max();break;
		case 5:	break;
		default: cout<<"\ninvalid entry...try again..\n";
		}
		cout<<"\ndo you want to continue?(y/n) : ";
		cin>>c;
	}while(c=='y' ||c=='Y');
	cout<<endl;
	return 0;
}


/*

1.)enter details
2.)display entered details
3.)sort and display sorted details
4.)display minimum ad maximum marks
5.)exit
1

enter the total number of elements
5

enter the elements
12
54
33
11
90

do you want to continue?(y/n) : y

1.)enter details
2.)display entered details
3.)sort and display sorted details
4.)display minimum ad maximum marks
5.)exit
2

the elements are
12	54	33	11	90	

do you want to continue?(y/n) : y

1.)enter details
2.)display entered details
3.)sort and display sorted details
4.)display minimum ad maximum marks
5.)exit
3

the elements are
11	12	33	54	90	

do you want to continue?(y/n) : y

1.)enter details
2.)display entered details
3.)sort and display sorted details
4.)display minimum ad maximum marks
5.)exit
4

the minimum marks are : 11
the maximum marks are : 90

do you want to continue?(y/n) : y

1.)enter details
2.)display entered details
3.)sort and display sorted details
4.)display minimum ad maximum marks
5.)exit
5

do you want to continue?(y/n) :  n

#include<iostream>

int main()
{
	int a[5];

	for(int i=0; i<5; i++){
		std::cin>>a[i];
	}

	int max=a[0];
	int maxpos=0;
	int temp;

	for(int i=1; i<5; i++){
		if(max<a[i]){
			max=a[i];
			maxpos=i;
		}
	}

	for(int i=maxpos; i<4; i++){
		a[i]=a[i+1];
	}
				
	if (maxpos==4) a[maxpos]=a[maxpos-1];

	for(int i=0; i<5; i++){
	std::cout<<a[i]<<" ";
	}

	return 0;
}

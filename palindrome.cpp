#include<iostream>

int main()
{
	int a=0;
	while (true) {

		std::cout<<"Write a three-digit number for check palindrome or 0 -end "<<std::endl;
		std::cin >> a;
		if (a==0 || a<100 || a>999) break;
		if (a/100==a%10){
			std::cout<<"It's palindrome"<<std::endl;
		} else {
			std::cout<<"It's not palindrome"<<std::endl;
		}
		
	}


	return 0;
}

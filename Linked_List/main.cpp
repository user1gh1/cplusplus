#include <iostream>
#include "linked_list.hpp"

int main()
{
	LinkedList F;
	F.print();
	F.push_back(12);
	F.push_back(13);
	F.push_back(14);
	F.push_back(15);
	F.push_back(16);
	F.push_back(17);

	F.print();
	std::cout << "size is " << F.get_size() << '\n';

	F.pop_back();

	F.print();
	std::cout << "size is " << F.get_size() << '\n';

	F.pop_back();
	F.pop_back();
	F.pop_back();

	F.print();
	F[0]= 123;
	F[1]= 123;

	std::cout << "sis " << F[0] << '\n';
	std::cout << "sis " << F[1] << '\n';

	std::cout << "size is " << F.get_size() << '\n';
	F.insert(0,999);
	F.print();
	std::cout << "size is " << F.get_size() << '\n';
	F.remove_index(0);
	F.push_back(123);
	F.push_back(123);
	F.push_back(123);
	F.push_back(1);
	//F.remove_value_flag(123,"-a");
	F.print();
	LinkedList X(F);
	LinkedList Y;
	LinkedList Z(Y);
	Z.print();
	std::cout << "Z size is " << Z.get_size() << '\n';
	//this line Need to check Assert works or not :D
	//std::cout << "sis " << F[2] << '\n';
	
}

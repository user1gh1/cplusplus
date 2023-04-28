#include "d_linked_list.cpp"

int main()
{
	DoubleList<int> F;
	F.print();
	F.push_back(12);
	F.push_back(13);
	F.push_back(14);
	F.push_back(15);
	F.push_back(16);
	F.push_back(17);
	F.push_front(11);

	F.print();
	std::cout << "size is " << F.get_size() << '\n';

	F.pop_back();
	F.pop_back();
	F.pop_back();
	F.pop_front();
	F.insert(99,2);
	F[2]=21;
	F.print();
	//check reverse works
	F.reverse();
	std::cout << "size is " << F.get_size() << '\n';
	F.print();
	return 0;	
}

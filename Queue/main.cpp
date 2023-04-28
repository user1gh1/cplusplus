#include "queue.hpp"
int main()
{
	Queue T;
	T.enqueue(1);
    T.enqueue(2);
    T.enqueue(3);
    T.enqueue(4);
    T.dequeue();
    T.print();
	std::cout << T.get_size() << '\n';
    return 0;
}


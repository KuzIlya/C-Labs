class BaseA {

};

template<typename T>
class A : BaseA{
public:
	T data;
	A(const T& newdata): data(newdata) {}
};

class Node {
public:
	BaseA* ptr;
};

int main() {
	Node** head = new Node*[5];
	*(head[0])->ptr = A<int>(5);
}
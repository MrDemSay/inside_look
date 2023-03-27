/*
Бывают случаи когда укзаатель указывает на NULL и тогда при разименовании указателя 
возникает ошибка, умные указатели могут помочь решить данную проблему.	
*/

#include <iostream>

template <class Type>

class smart_ptr {
	private:
		Type* pointer;
	public:
		smart_ptr(Type* p): pointer(p) {};
		operator Type*() { return pointer; };
		Type *operator -> () {
			if (!pointer) {
				pointer = new Type();
				std::cerr << "Bad pointer..." << std::endl;
			} 
			return pointer; 
		};	
};

class F {
	private:
		int a, b;
	public:
		F(): a(0), b(0) {};
		F (int a, int b): a(a), b(b) {};
		int Sum() { return a + b; }
};

int main(int argc, char const *argv[])
{
	smart_ptr<F> sp(NULL);
	std::cout << sp -> Sum() << std::endl;
	return 0;
}


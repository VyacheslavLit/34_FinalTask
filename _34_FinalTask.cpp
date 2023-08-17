#include <iostream>
#include <string>

template <typename T> concept ComplexConcept = requires(T value)
{
	{value.tostring() } -> std::same_as<std::string>;
	{value.hash()} -> std::convertible_to<long>;
		requires !std::has_virtual_destructor<T>::value;
};

//провкрка концепта
class ComplexCon {
private:
	short _n = 0;
public:
	ComplexCon(short n) : _n(n) {};
	~ComplexCon() {};

	std::string tostring() const {return std::to_string (_n);}

	long hash() const {return (long)_n;}
};


int main()
{
	ComplexCon x{ 5 };
	std::cout << typeid(x.hash()).name() << std::endl;
	std::cout << typeid(x.tostring()).name() << std::endl;

	return 0;
}
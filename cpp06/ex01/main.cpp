# include "Serializer.hpp"

int	main()
{
	Data	d = {0, "hello"};
	std::cout << "Addres: " << &d << std::endl;
	std::cout << d.data << d.id << std::endl;
	uintptr_t t = Serializer::serialize(&d);
	std::cout << "Serialized: " << t << std::endl;
	Data*	d2 = Serializer::deserialize(t);
	std::cout << "Deserialized: " << d2 << std::endl;
	std::cout << d2->data << d2->id << std::endl;
	return (1);
}
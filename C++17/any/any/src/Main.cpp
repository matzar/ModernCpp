#include <iostream>
#include <string>
#include <any>
#include <map>

// source code: https://www.bfilipek.com/2018/06/any.html?m=1

int main()
{
	std::any a(12);
	std::any b(22);
	std::any c;
	

	// set any value
	a = std::string("Hello");
	a = 16;
	a.std::any::swap(b);

	// reading the value:
	// we can read it as int ->
	std::cout << std::any_cast<int>(a) << '\n';

	// -> but not as string
	try
	{
		// access the value by using std::any_cast<T>, it will throw bad_any_cast if the active type is not T.
		std::cout << std::any_cast<std::string>(a) << '\n';
	}
	catch(const std::bad_any_cast& e)
	{
		std::cout << e.what() << '\n';
	}

	// reset and check if it contains any value
	a.reset(); // .reset() - destroys contained	object
	if (!a.has_value())
	{
		std::cout << "a is empty!" << "\n";
	}

	// you can use it in a container:
	std::map<std::string, std::any> m;
	m["integer"] = 10;
	m["string"] = std::string("Hello World");
	m["float"] = 1.0f;

	for (auto& [key, value] : m)
	{
		// you can discover the active type by using .type() that returns std::type_info of the type.
		if (value.type() == typeid(int))
			std::cout << "int: " << std::any_cast<int>(value) << "\n";
		else if (value.type() == typeid(std::string))
			std::cout << "string: " << std::any_cast<std::string>(value) << "\n";
		else if (value.type() == typeid(float))
			std::cout << "float: " << std::any_cast<float>(value) << "\n";
	}

	std::cin.get();
}
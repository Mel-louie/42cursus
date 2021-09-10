#include <string>
#include <iostream>

//can be write like this insted of std::cout, std::endl
// using namespace std;
//and in the main:
//cout << "Hello world!" << endl; instead of
//std::cout << "Hello world!" << std::endl;

int	main(int argc, char **argv)
{
	// if using namespace std; : string	my_name("Mario");
	std::string	my_name("Mario");
	char	str[13] = "Hello world!";
	int		a = 12;

	// cout << "Hello world!" << endl;
	std::cout << str << std::endl;
	std::cout << my_name << std::endl;
	std::cout << "i am ";
	std::cout << a << std::endl;

	if (argc == 2)
		std::cout << argv[1] << std::endl;
	return (0);
}

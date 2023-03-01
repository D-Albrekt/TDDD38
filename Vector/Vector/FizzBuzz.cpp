#include <string>
#include <iostream>
#include <vector>
#include <sstream>
/*
int main()
{
	std::cout << "Hello and welcome to this FIZZBUZZ\n" 
			  << "Please enter a number : " << std::endl;

	int n{};
	std::cin >> n;

	
	std::ostringstream oss{};
	std::cout << "Created a vec\n";
	if (n >= 1)
	{
		oss << "[\"1\"";
		{

			for (int i = 2; i <= n; i++)
			{
				std::cout << "Loop i " << i << "\n";

				oss << ",\"";


				if ((i % 3 != 0) && (i % 5 != 0))
				{
					oss << i << "\"";
				}
				else
				{
					if (i % 3 == 0)
					{
						oss << "Fizz";
					}
					if (i % 5 == 0)
					{
						oss << "Buzz";
					}
					oss << "\"";
				}
			}
			oss << "]";
		}
	}
	std::cout << oss.str();
	{
			int i = 0, x = 0;

			do
			{
				std::cout << i << " mod 5 is " << (i % 5) << std::endl;
				if (i % 5 == 0)
				{
					std::cout << x;
					x++;
				}

				++i;
			} while (i < 10);

			std::cout << x;


	}


}
*/
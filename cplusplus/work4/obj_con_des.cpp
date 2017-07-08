/* -------------------------------------------
 * Author: fenlan
 * Date: 2017.5.13
 * -------------------------------------------
 *  Given this program:
 *
 *  	#include <iostream>
 *
 *  	int main()
 *  	{
 *  	    std::cout << "Hello world!\n";
 *  	}
 *
 *  modify it to produce this output:
 *
 *  	Initialize
 *  	Hello world!
 *  	Clean up
 * --------------------------------------------
 */


#include <iostream>

// define a class with constructor and destructor
class init {
public:
	init() {
		std::cout << "Initialize\n";
	}
	~init() {
		std::cout << "Clean up\n";
	}
};

init i;			//the init() member function is working

int main()
{
	std::cout << "Hello world!\n";
}

//After the main(), the scope of object i is over so
//the ~init() member function is working

//At last, the program is over

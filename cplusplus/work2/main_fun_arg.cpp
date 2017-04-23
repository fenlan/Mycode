/* Author: fenlan
 * Date: 2017.4.23
 * ---------------------------------------------------
 *  	Write a program like "Hello,world!" that takes
 * a name as a command-line argument and writes "Hello,
 * name !". Modify this program to take any number of
 * names as arguments and to say hello to each.
 * ---------------------------------------------------
 * input: 
 *        ./main_fun_arg fenlan ouyang shrik3
 * output: 
 *        Hello,fenlan !
 *        Hello,ouyang !
 *        Hello,shrik3 !
 * ---------------------------------------------------
 */

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int i = 0;

	if (argc == 1){
		//do something without any other arguments    
	}
	else {
		for (i = 1; i < argc; i++ )
			cout << "Hello,"<< argv[i] << " !" << endl;
	}

	return 0;    
}

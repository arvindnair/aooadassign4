#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Evaluator.h"

int main()
{
	std::string quit_msg="QUIT";
	while (true)
	{
		try
		{
			//taking the expression as input.
			std::cout<<"Enter expression: "<<std::endl;
			std::string exp;
			std::getline(std::cin,exp);
			// if expression entered is QUIT then exit the program.
			if (exp==quit_msg)
			{
				break;
			}
			// use Expression Evaluator variable to get result of calculation
			// after passing infix string.
			Expr_Evaluator a;
			int result=a.calculator(exp);
			std::cout<<result<<std::endl;
		}
		// catch the exception for failure handling.
		catch(std::exception& e)
		{
			std::cout<<e.what()<<std::endl;
		}
	}
}
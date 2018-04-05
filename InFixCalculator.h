#ifndef INFIXCALCULATOR_H
#define INFIXCALCULATOR_H
#include <iostream>
#include <string>
//#include <stack>
#include "Stack.h"


class InfixCalculator
{
private:
	Stack<int> StackInt; //This is the integer stack that we will use as instructed by the two stack method.
	Stack<char> StackOperator; //This stack will contain operators

public:
	void execute(); //This will evaluate any operation, code taken from book
	int pemdas(char); //this function will create our own order of operations following pemdas order of operations
	bool isOperation(char); //This will check if the current index is a operation i.e + or -, etc.
	bool isNumber(char); //This will do the same but for numbers in the string
	int PostFix(string); //This function will create a post fix from a infix, function taken from code given
};

int InfixCalculator::pemdas(char operation)
{
	if (isOperation(operation) == true)
	{
		if (operation == '*' || operation == '/')
		{
			std::cout << "recognized higher order operator" << std::endl;
			return 1; //HERE THIS CONTAINS 1 AS A RETURN VALUE BECAUSE IN PEMDAS THESE OPS COME FIRST
		}
		if (operation == '+' || operation == '-')
		{
			std::cout << "recognized lower order operator" << std::endl;
			return 0; //THESE COME SECOND
		}
		else
		{
			return -1;
		}
	}
}


bool InfixCalculator::isOperation(char operation)
{
	if (operation == '*' || operation == '/' || operation == '+' || operation == '-')
	{
		std::cout << "successfully determined valid operator" << std::endl;
		return true; //checks if you encounter a operation symbol, if so returns true.
	}
	else
	{
		return false;
	}
}

bool InfixCalculator::isNumber(char number)
{
	if (number >= '0' && number <= '9')
	{
		std::cout << "successfully determined valid number" << std::endl;
		return true;  //checks if you encounter a number, if so returns true.
	}
	else
	{
		std::cout << "successfully determined invalid number" << std::endl;
		return false;
	}
}
//taken from book
int InfixCalculator::PostFix(string inFix) //This converts and infix string to a postfix and is able to be used to calculate, taken from book
{
	cout << "now inside of Postfix function" << std::endl;

	int answer;
	for (unsigned int i = 0; i < inFix.size(); i++)
	{
		cout << "now inside for loop" << std::endl;
		std::cout << "testing to see if char is a number or a operator" << std::endl;

		if (isNumber(inFix[i]) == true)
		{
			std::cout << "its a number, pushing" << std::endl;
			
			StackInt.push(inFix[i]- 48);

			std::cout << "sucessfully pushed" << std::endl;
		}
		else if (isOperation(inFix[i]) == true)
		{
			std::cout << "its an operator, about to decide precedence" << std::endl;

			if (StackOperator.isStackEmpty() || pemdas(inFix[i]) > pemdas(StackOperator.peek()))
			{
				std::cout << "higher precendece, pushing" << std::endl;

				StackOperator.push(inFix[i]);
			}
			else
			{
				while (!StackOperator.isStackEmpty() && (pemdas(inFix[i]) <= pemdas(StackOperator.peek())))
				{
					std::cout << "lower precendece, executing" << std::endl;

					execute();
				}

				std::cout << "pushing" << std::endl;
				
				StackOperator.push(inFix[i]);
			}
		}
		if (inFix[i] == '(')
		{
			std::cout << "recognized a ( , pushing" << std::endl;
			StackOperator.push(inFix[i]);
		}
		if (inFix[i] == ')')
		{
			while (StackOperator.peek() != '(')
			{
				std::cout << "recognized a ) , executing" << std::endl;
				execute();
			}
			StackOperator.pop();
		}

	}
	while (!StackOperator.isStackEmpty())
	{
		std::cout << "no more values to process, executing" << std::endl;
		execute();
	}

	std::cout << "returning answer" << std::endl;

	answer = StackInt.peek();
	return answer;

}

//teken from book
void InfixCalculator::execute() //code taken from book that allows us to evaluate a postfix expression
{

	std::cout << "Entered into the execute function" << std::endl;

	int number2 = StackInt.peek();
	StackInt.pop();
	
	int number1 = StackInt.peek();
	StackInt.pop();
	
	char operation = StackOperator.peek();
	StackOperator.pop();
	
	int answer;

	switch (operation)
	{
	case '*':
		std::cout << "multiplying numbers" << std::endl;
		answer = number1 * number2;
		break;

	case '/':
		std::cout << "dividing numbers" << std::endl;
		answer = number1 / number2;
		break;

	case '+':
		std::cout << "adding numbers" << std::endl;
		answer = number1 + number2;
		break;

	case '-':
		std::cout << "subtracting numbers" << std::endl;
		answer = number1 - number2;
		break;
	}
	std::cout << "pushing results" << std::endl;
	StackInt.push(answer);
	std::cout << "push successful" << std::endl;
}





#endif
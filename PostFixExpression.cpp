
#include <iostream>
#include <string>
#include <vector>

class PostFixExpression {
public:

	PostFixExpression(std::string inputExpression[], int inputSize) {
		expression = inputExpression;
		thisLength = inputSize;
		currentIndex = 0;
	}

	//returns the next token in the expression.
	std::string nextToken() {
		if (thisLength > 0) {
			std::string returnToken = std::string(expression[currentIndex]);
			currentIndex += 1;
			if (currentIndex == thisLength) {
				currentIndex = 0;
			}
			return returnToken;
		}
		else {
			return "";
		}
	};

	 // Returns the number of tokens in the expression.
	int length() {
		return thisLength;
	};

private:
	std::string * expression;
	int thisLength;
	int currentIndex;
};

int main(){
	const int length = 3;
	std::string sampleExpression[3];
	sampleExpression[0] = "23";
	sampleExpression[1] = "34";
	sampleExpression[2] = "*";
	PostFixExpression exp = PostFixExpression(sampleExpression, length);
	std::cout << exp.nextToken() << std::endl;
	std::cout << exp.nextToken() << std::endl;
	std::cout << exp.nextToken() << std::endl;
	std::cout << exp.nextToken() << std::endl;
}


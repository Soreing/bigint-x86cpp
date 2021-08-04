#include <bigint/bigint.h>

int main()
{
	// Adjust the number of bytes using the template argument for larger integers
	// The byte size has to be a multiple of 2, and at least 8 bytes!
	BigInt<256> veryBigInt = "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789";
	std::cout << veryBigInt.toString(10) << "\n\n";
	std::cout << veryBigInt.toString(64) << "\n\n";


	//    Constructors    //
	//--------------------//

	BigInt<16> def;							// Default Constructor
	BigInt<16> valueA = 123;				// Integer Constructor
	BigInt<16> copy(def);					// Copy Constructor
	
	BigInt<16> string("12345", 10);			// String Constructor with base (2, 8, 10, 16, 64)
	BigInt<16> str2  = "0b11010101";		// Binary (0b) prefix string Constructor
	BigInt<16> str8  = "0123456701";		// Octal (0) prefix string Constructor 
	BigInt<16> str10 = "1234567890";		// Decimal (non zero) string Constructor (- sign allowed)
	BigInt<16> str16 = "0x1234ABCD";		// Hexadecimal (0x) prefix stringConstructor
	BigInt<16> str64 = "0#a2GQs61=";		// base 64 (0#) prefix Constructor


	//    Input/Output    //
	//--------------------//
	std::cout << "    Input/Output    \n";
	BigInt<16> num;

	std::cin >> num;								// Default input with std::cin using the string constructors
	std::cout << num << "\n";						// Default output with std::cout using decimal (base 10) format
	std::cout << num.toString(2) <<"\n";			// .toString method used to print the number in different bases
	std::cout << num.toString(16, true) << "\n\n";	// .toString method with enabled appended prefix (0b, 0, 0x, 0#)


	//      Bitwise       //
	//--------------------//
	BigInt<16> bin1 = "0b1101001010";
	BigInt<16> bin2 = "0b1010010101";
	BigInt<16> result;
	
	result = bin1 & bin2;				// Bitwise AND using two Big Integers of the same size
	result = bin1 | "0b0010010101";		// Bitwise OR using a Big Integer and any value that matches a constructor
	result = "0b1101001010" ^ bin2;		// Bitwise XOR using, this time with value on the left and Big Integer on the right
	result = bin1 >> 5;					// Bit shifting is also supported
	bin2 <<= 3;							// Any binary bitwise operator works with assignment (=)
	result = ~bin2;						// Bitwise NOT as a unary operator


	//     Relational     //
	//--------------------//
	std::cout << "     Relational     \n";
	BigInt<16> num1 = "321456456546";
	BigInt<16> num2 = "12";

	std::cout << (num1 <  num2 ? "true\n" : "false\n");	// less than operator example
	std::cout << (num1 >  num2 ? "true\n" : "false\n");	// greater than operator example
	std::cout << (num1 <= num2 ? "true\n" : "false\n"); // less than or equal operator example
	std::cout << (num1 >= num2 ? "true\n" : "false\n"); // greater than or equal operator example
	std::cout << (num1 == num2 ? "true\n" : "false\n");	// equal to operator example
	std::cout << (num1 != num2 ? "true\n" : "false\n");	// not equal to operator 

	std::cout << (num1 == "12345") << "\n";		// All relational operators work with other types left or right
	std::cout << ("12345" == num2) << "\n";		// At least one operand has to be a Big Integer

	std::cout << num1.isZero() << "\n\n";		// .isZero() is a faster comparison against 0


	//       Logical      //
	//--------------------//
	std::cout << "     Logical     \n";
	BigInt<16> nzero = "12345";
	
	if (nzero)									// Big Integers are overloaded to be casted to booleans
		std::cout << "true\n";					// Non Zero values are true, while zero is false
	else if (!nzero)							// the ! operator returns true if the number is zero
		std::cout << "false\n";	

	std::cout << (nzero && nzero) << "\n";		// The && and || operators are overloaded to take Big Integers
	std::cout << (nzero && true) << "\n";		// on both, or either left or right side
	std::cout << (true || nzero) << "\n\n";


	//     Arithmetic     //
	//--------------------//
	std::cout << "     Arithmetic     \n";
	BigInt<16> left  = "1234567";
	BigInt<16> right = "4567890";

	std::cout << +left << "\n";					// Unary operator + essentially just returns the Big Integer
	std::cout << -left << "\n";					// Unary operator - returns the 2's complement
	
	std::cout << left + right << "\n";			// All Arithmetic operators are defined (+, -, *, /, %)
	std::cout << left - right << "\n";			// Each can take a different type value on the right or left
	std::cout << "123" * right << "\n";			// Atleast one operand has to be a Bit
	std::cout << left / "123" << "\n";
	std::cout << left % "123" << "\n\n";

	left += right;								// Each Arithmetic operator is also defined to work
	left -= right;								// With the assignment operator (=)
	left *= 2;
	left /= 2;
	left %= 2;


	//     Additional     //
	//--------------------//
	std::cout << "     Additional     \n";

	// The rand<N>() function generates an N byte long Big Integer
	// You can use the srand() function in <stdlib.h> to set the seed
	srand(1234);
	std::cout << rand<256>().toString(64) << "\n\n";

	// The pow<N>() function calculates the 1st function parameter raised to the 2nd parameter
	// The result has to fit into the number of bytes N specified with template arguments
	std::cout<< pow<512>("123", "456") << "\n";
}
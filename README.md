# bigint-x86cpp

# Description

bigint-x86cpp is a C++ library for working with unsigned integers larger than 64bits. The library uses x86 assembly for certain basic operations and does not use dynamic memory, instead it uses templates to create BigInt objects of differetn sizes. Most operators are implemented, as well as reading and printing in different bases from binary to base64.

# Installation 
Add the folder `bigint` folder from `/include` in your include path. You will not need to compile any source files, but they are necessary to be included with the template definition.

# Usage
## Creating Big Integers
To create a big integer, you need to specify how many bytes large you want it to be. You can assign to the Big Integer a number, or a string that represents a number. You can specify the number's base with a prefix.
```c++
// 16 byte large BigInt
BigInt<16> num   = 123;

BigInt<16> str2  = "0b11010101";  // Binary (0b)	
BigInt<16> str8  = "0123456701";  // Octal (0)
BigInt<16> str10 = "1234567890";  // Decimal (non zero)
BigInt<16> str16 = "0x1234ABCD";  // Hexadecimal (0x)
BigInt<16> str64 = "0#a2GQs61=";  // base 64 (0#)
```

## Input / Output
You can use the stream operators for reading into and printing the value of Big Ints. The numbers are printed in base 10. If you want to print in another base, you need to use the `.toString()` function.
```c++
BigInt<16> num;

cin >> num;  // Using the string constructors
cout << num;  // Prints number in base 10

// Print numbers in different bases wit or without prefix
cout << num.toString(64);
cout << num.toString(16, true);
```

## Arithmetic Operators
You can use arithmetic operators on Big Ints of the same size, including compound assignment operators.
```c++
BigInt<16> left  = "1234567";
BigInt<16> right = "4567890";

cout << left + right  << endl;
cout << left - right  << endl;
cout << "123" * right << endl;
cout << left / "123"  << endl;
cout << left % "123"  << endl;
```
```
Output:
5802457
3333323
151851741
37137
39
```

## Bitwise Operators
Bitwise `&`, `|`, `^`, as well as the bitshift `<<`, `>>` operators are implemented for Big Ints of the same size.
```c++
BigInt<16> bin1 = "0b1101001010";
BigInt<16> bin2 = "0b1010010101";
BigInt<16> result;

result = bin1 & bin2;
result = bin1 | "0b0010010101";
result = "0b1101001010" ^ bin2;
result = ~bin2;
```

## Relational Operators
You can compare the value of Big Ints of the same size with the relational operators
```c++
BigInt<16> num1 = "321456456546";
BigInt<16> num2 = "12";

cout << (num1 <   num2) << " ";
cout << (num1 >   num2) << " ";
cout << (num1 ==  num2) << " ";
cout << (num1 !=  num2) << " ";
```
```
Output:
0 1 0 1
```
For fast comparison, you can use the `.isZero()` function that doesn't require a second operand
```c++
BigInt<16> num = "321456456546";

// Prints 0 for false, the number is not zero
cout << num.isZero() << endl
```

## Logical Operators
Big Integers convert to false if they are zero, otherwise convert to true. You can use them in conditions or in logical operations
```c++
BigInt<16> nonzero = "12345";

if(nonzero){
    cout << "true\n";
}

cout << (nonzero && nonzero) << " ";
cout << (nonzero && false) << " ";
cout << (false || nonzero) << " ";
```
```
Output:
true
1 0 1
```

## Additional Features
You can generate random Big Ints with a template Rand function. You can seed the default c rand function with `srand` to set the seed for this function.
```c++
srand(1234);
BigInt<256> rnum = rand<256>();
```

There is a pow function implemented for Big Ints. You need to provide the result's size as a template parameter, then supply the parameters
```c++
// 123^456
BigInt<512> num = pow<512>("123", "456")
```
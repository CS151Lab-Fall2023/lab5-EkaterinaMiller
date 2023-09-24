/**
 * @file   test.cpp
 * @author Aiden Manansala
 * @brief  Implement my own version of the string that uses
 *         dynamic memory allocation and C-string
 * @date   9/14/23
 *
 */
#include <iostream>
#include "myString.h"
using namespace std;

int main()
{
    // STEP 1: Implement the following String member functions:
    //   String()
    //   String(const char* s)
    //   ~String()
    //   c_str()
    //   size()
    //   length()
    // STEP 2: Compile and execute
    String s0("Hi");
    cout << s0.c_str() << '\n';
    // STEP 3: Observe which constructor is executed and why?

    // STEP 4: Uncomment lines 28 to 29
    String s1 = "Hello";
    cout << s1.c_str() << '\n';
    // STEP 5: Observe which constructor is executed and why?

    // STEP 6: Uncomment lines 34 to 35 and compile.
    // You will get an error, understand why?
    String s2(s1);
    cout << s2.c_str() << '\n';
    // STEP 7: Implement the following String member function:
    // String(const String& str);

    // STEP 8: Compile and execute. 

    // STEP 9: Uncomment lines 44 to 45. Compile and execute
    String s3 = s1;
    cout << s3.c_str() << '\n';
    // STEP 10: I hope by now you have observed that the 
    // constructors are triggered like a function call or
    // by using the assignment operator =. You also have
    // to write more constructors with different parameters
    // if you want to allow your class to understand different data types.


    // STEP 11: Implement the following String member function:
    // copy(const char* s);
    // STEP 12: Uncomment lines 56 to 57. Compile and execute
    s1.copy("I am starting to get smarter");
    cout << s1.c_str() << '\n';
    // STEP 13: What do you observed and why?


    // STEP 14: Uncomment lines 62 to 63. Compile! You will get an error.
    s1 = "I am really getting smarter!";
    cout << s1.c_str() << '\n';
    // STEP 15: Implement the following String member function:
    //   operator=(const char* s)
    // simply copy the code you wrote for copy(const char* s) into this function
    // STEP 16: Compile and execute. Why does it work now?

    // STEP 17: Uncomment lines 73 to 75. Will the newly uncommented
    // code compile? If not, what is the next member function
    // that you should implement in order for the program to compile
    // successfully.
    String s4;
    s4.copy(s1);
    cout << s4.c_str() << '\n';

    // STEP 18: Implement the following String member function:
    //   copy(const String& s) 
    //   operator=(const String& s)
    // STEP 19: Uncomment lines 81 to 84. Compile and execute.
    String s5 = "I am still craving for more knowledge!";
    String s6;
    s6 = s5;
    cout << s6.c_str() << '\n';

    // STEP 19: Implement the following String member functions:
    //   at(int index)
    // STEP 20: Uncomment lines 89 to 92. Compile and execute.
    cout << s5.at(2) << ' ' << s5.at(3) << '\n';
    s5.at(2) = 'A';
    s5.at(3) = 'M';
    cout << s5.at(2) << ' ' << s5.at(3) << '\n';
    // STEP 21: Observe lines 88 and 89. Why does it work?
    // HINT: Observe the return type

    // STEP 22: Implement the following String member function:
    //   operator[](int index)
    // Same code as at(int index)9
    // STEP 23: Uncomment lines 100 to 106. Compile and execute
    s5[3] = 'm';
    s5[5] = 'S';
    s5[11] = 'C';
    s5[19] = 'F';
    s5[23] = 'M';
    s5[28] = 'K';
    cout << s5.c_str() << '\n';

    // STEP 24: Implement the member function:
    //   find(const char* s) 
    // and test it with the code in lines 111 to 115
    cout << s1.find("all") << '\n';  // display 7
    cout << s5.find("ore") << '\n';  // display 24
    cout << s5.find("Know") << '\n'; // display 28
    cout << s5.find("a") << '\n';    // display 13
    cout << s5.find("still") << '\n'; // display -1

    // STEP 25: Uncomment lines 121 to 122.
    // Add the missing member function and implement it.
    // In the body of this function, it can be implemented
    // with only a single line of code.
    String s7 = "ore"; // need to make own function, but only one line of code needed
    cout << s5.find(s7) << '\n';

    // STEP 26: By now, you should understand when constructors and
    // destructors are triggered. Thus, remove or comment out all 
    // the cout statements in all constructors and destructor.
    // This will also make STEP 27 a little less confusing with
    // those extra couts.
    
    // STEP 27: Implement the substr() member function and test
    // it with the code in lines 132 to 134
    cout << "My code is " << s4.substr(12).c_str() << '\n';
    String s8 = s4.substr(20, 5);
    cout << "My String class is so " << s8.c_str() << '\n';

    return 0;
}

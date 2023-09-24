/**
 * @file myString.cpp
 * @author Aiden Manansala
 * @brief 
 * @version 0.1
 * @date 2023-09-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "myString.h"

/**
 * @brief Emptry default constructor
 * 
 */
String::String(){

    mString = new char [1];

    mString[0]='\0';

    mSize=0;
}

/**
 * @brief Constructs a string from an inputted cstring
 * 
 * @param s 
 */
String::String(const char *s){

    mSize = strlen(s);

    mString = new char [mSize+1];

    strcpy(mString, s);
}

/**
 * @brief String destructor, frees memory
 * 
 */
String::~String(){

    delete [] mString;
}

/**
 * @brief Returns the memory address of the object's cstring
 * 
 * @return const char* 
 */
const char* String::c_str() const{
    return mString;
}

/**
 * @brief returns the size of the string
 * 
 * @return int 
 */
int String::size() const{
    return mSize;
}

/**
 * @brief copy constructor allows you to copy string value to another string
 * 
 * @param str 
 */
String::String(const String &str){

    mSize = str.size();
    mString = new char[mSize+1];
    strcpy(mString, str.c_str());
}


/**
 * @brief Makes a copy of cstring puts it into the string object
 * 
 * @param s 
 * @return String& 
 */
String& String::copy(const char *s){
    // Copy s into String object
    // If mString does not have enough memory to copy the contents of s, then
    // Free the dynamic memory of mString
    if(static_cast<size_t>(mSize) < strlen(s)){
        delete [] mString;
        
        mString = new char [strlen(s)+1];
    }
    // Create enough memory
    // In all cases,
    // Set mSize to the length of the C-string s
    // Using the C-string function to copy the C-string s into mString
    // The return statement should be
    mSize = strlen(s);
    strcpy(mString, s);
    return *this;  
}

/**
 * @brief copys a normal string and puts it in the string object
 * 
 * @param s 
 * @return String& 
 */
String& String::copy(const String &s){
    if(static_cast<size_t>(mSize) < s.length()){
        delete [] mString;
        mString = new char [s.length()+1];
    }

    mSize = s.length();
    strcpy(mString, s.c_str());
    return *this;

}

/**
 * @brief overloads the assignment operator to copy cstrings
 * 
 * @param s 
 * @return String& 
 */
String& String::operator=(const char *s){
    copy(s);
    return *this;
}

/**
 * @brief returns the length of a string using mSize
 * 
 * @return int 
 */
int String::length() const{
    return mSize;
}

/**
 * @brief overloads the assignment operator to copy normal strings
 * 
 * @param s 
 * @return String& 
 */
String& String::operator=(const String &s){
    copy(s);
    return *this;
}

/**
 * @brief returns the value of a string at a certain index in the string
 * 
 * @param index 
 * @return char& 
 */
char& String::at(int index){
    return mString[index];
}

/**
 * @brief overloads the index operator to use the at function, instead of specifically calling it
 * 
 * @param index 
 * @return char& 
 */
char& String::operator[](int index){
    return at(index);
}

/**
 * @brief Finds the first occurence of the inputted cstring within the string
 * 
 * @param s 
 * @return int 
 */
int String::find(const char *s) const{
    
    for(int i=0; i<strlen(mString); i++){
        if(mString[i]==s[0]){
            bool match = false;
            for(int x=1; x<strlen(s); x++){
                if(mString[i+x]==s[x]){
                    match = true;
                    if(x==strlen(s)-1){
                        return i;
                    }
                }
                if(match==false){
                    break;
                }
            }
        }
    }
    return -1;
}

/**
 * @brief overloads the find function to allow a normal string as input
 * 
 * @param s 
 * @return int 
 */
int String::find(const String &s) const{ // accepting normal string, not c-string
    return find(s.c_str()); // so we must convert it to c-string for use w/ c-string find function
}

/**
 * @brief creates a substring of a string based on user input positions and lengths
 * 
 * @param pos 
 * @param len 
 * @return String 
 */
String String::substr(int pos, int len) const{
    String substr; // new object
    int substrSize;

    if(len==-1){
        substr.mString = new char[mSize-pos];
        substrSize = mSize-pos;
    } else {
        substr.mString = new char[len];
        substrSize = len;
    }



    for(int i=0; i<substrSize; i++){
        substr.mString[i] = mString[pos+i];
    }

    substr.mString[substrSize] = '\0';
    substr.mSize = substrSize;

    return substr;
}
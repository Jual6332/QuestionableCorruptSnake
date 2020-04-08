#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  puts("Hello World!\n");

  // Auto range for loop
  int values[] = {1,2,3,4,5};
  for(auto ai:values)
  {
    printf("%d",ai);
  }
  printf("\n");

  int x;
  printf("%d\n",x=42);

  // Chapter 2: Basic Syntax
  // Printf and puts are functions from the cstdio library, each similar to cout for the iostream library

  // Keep Identifiers under 31 characters longs
  // Be consistent

  // A reference is not a variable. Once assigned, a reference will always refer to the same variable.
  // This is a feature exclusive to C++ and is not included in C
  int z=42;
  int &y=z;
  printf("The value of z is %d\n",z);
  printf("The value of y is %d\n",y);

  // The primitive array
  int a[5];
  a[0]=1;
  *a=1;
  int *ip = a;
  ++ip; // Always increments to the size of type assigned to it. This points to a[1]
  *(++ip) = 4;

  // Primitive Strings
  char s1[] = "String 1";
  char s2[] = {'S','t','r','i','n','g',' ','2',0};
  printf("String is: %s\n",s1);
  printf("String is: %s\n",s2);
  // A C-String is simply a primitive array of characters, terminated with a zero. This is also known as a null-terminated string.
  for (int i=0; s1[i]!=0; ++i)
  {
    printf("Char is %c\n",s1[i]);
  }
  for (char * a=s1; *a; ++a)
  {
    printf("Char is %c\n",*a);
  }
  for (char c:s1)
  {
    if (c==0) break;
    printf("Char is %c\n",c);
  } // Unique to C++
  // A C-string is exactly the same as a primitive array, it is one case of an array

  // Conditionals
  if (14)
  {
    cout << "This is true" << endl;
  }else {
    cout << "This is false" << endl;
  }
  // Any non-zero value will result in true statement

  // Ternary-conditional operator:
  printf("The greater value is %d\n",2>3 ? 2:3);

  // A switch statement is a multi-way conditional statement

  // Covered while and do-while loops
  
  // The break command exits the loop block, but continue branches back to the top of the conditional

  // The range-based for loop is exclusive to C++ starting in C++ and is not in C. This is also a compile-time feature

  // COUT print method overloads the << bit-wise left shift operator to include the given characters to the output. More C++-ish than puts or printf

  // Printf and puts require less memory when compiled. Cout is more expensive for memory and time required for compilation

  // Chapter 3: Data Types

  // A structure is a sequential set of objects of various types. May contain scalars, arrays, or even other structures and classes.

  // C++ classes are based on structs. The main difference is that a struct has member functions or methods

  // A union is a set of overlapping objects
  union x 
  {
    int a;
    int b;
  };

  // Integer types:
  //1. char - 1 byte
  //2. short int - 2 bytes
  //3. int - 4 bytes
  //4. long int - 8 bytes
  //5. long long int - 8 bytes

  // Use #include <cstdint> for specific-width integer types

  printf("\nInteger Types:\n");
  printf("Char is %ld bytes\n",sizeof(char));
  printf("Short int is %ld bytes\n",sizeof(short));
  printf("Normal int is %ld bytes\n",sizeof(int));
  printf("Long int is %ld bytes\n",sizeof(long));
  printf("Long long int is %ld bytes\n",sizeof(long long int));

}

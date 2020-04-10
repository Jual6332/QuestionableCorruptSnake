#include <iostream>
#include <cstdio>
#include <cstdint>

using namespace std;

class S {
  public:
    int static_value() {
      static int x = 7;
      return ++x;
    }
};

struct Employee{
  int age;
  const char * name;
  const char * role;
};

struct BitFields
{
  int hasHair: 1;
  int hasPets: 1;
  int numberOfChildren: 3;
};

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

  // Integer types (cstdint)
  printf("Size of int8_t is: %ld\n",sizeof(int8_t));
  //uint8_t;
  //int16_t; and others ...

  // Floating point numbers give scale, but at the expense of precision

  const char * cstring1 = "String"; // The pointer itself is not const, but the value the pointer points to is. The string cannot be changed.

  printf("\nC-String1: ");
  for (int i=0; cstring1[i]; ++i)
  {
    printf("%c",cstring1[i]);
  }

  char cstring2[] = "String";

  printf("\nC-String2: ");
  for (auto c:cstring2)
  {
    if (c==0) break;
    printf("%c",c);
  }

  // Character-escape sequences
  printf("Hello world \t \' \\");

  // Qualifiers
  const static int i = 34;

  // CV Qualifiers:
  // =============
  // const
  // volatile
  // mutable

  // Storage Duration:
  // =============
  // static - means the Lifetime of the program
  // register
  // extern

  S r;
  S q;
  S p;

  printf("%d\n",r.static_value());
  printf("%d\n",q.static_value());
  printf("%d\n",p.static_value());

  // Notice how the value is incremented for each class object

  int k = 5;
  int & ik = k;
  ik = 10; // <-- This changes the variable at place k in  memory
  printf("\n%d\n",k);

  // A struct type is a way to aggregate data
  Employee joe = {42,"Joe","Boss"};
  printf("%s is the %s and he is %d years old\n",joe.name,joe.role,joe.age);

  // BitFields
  struct BitFields example;
  example.hasHair = false;
  example.hasPets = true;
  example.numberOfChildren = 3;

}
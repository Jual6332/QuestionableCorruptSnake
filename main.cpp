#include <iostream>
#include <cstdint>
#include <typeinfo>

/* C++ Standard Library*/
#include <cstdio>
#include <cstdlib>
#include <cstring> /* Strings */
#include <cerrno> /* Error Handling*/

using namespace std;

class S
{
  public:
    int static_value() {
      static int x = 7;
      return ++x;
    }
};

class EmployeeA
{
  int age;
  string name;
  public:
    void set_age(int new_val);
    void set_name(string new_val);
    void get_age();
};

void EmployeeA::set_age(int new_val)
{
  age = new_val;
}

void EmployeeA::set_name(string new_val)
{
  name = new_val;
}

void EmployeeA::get_age()
{
  printf("%s is %d years old\n",name.c_str(),age);
}

struct Employee 
{
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

enum card_rank : uint8_t {ACE=1,DEUCE=2,JACK=11,QUEEN,KING};

string returnSTLString()
{
  return string("This is an STL string");
}

void printMessage();

template <typename T>
T maxof (T a, T b)
{
  return ( a>b ? a:b);
}

template <typename T>
class A{
  T a;
  public:
  T getA() const {return a;}
  void setA(T & x){a=x;}
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

  // A function with void in the arguments block in C means the function takes no arguments

  // This is different in C++, when no arguments are included, this means there are no arguments for the function

  // More or less for compatibility with C to include void 

  // The auto data type was included in C++11

  auto x3 = returnSTLString();
  printf("x3 is %s\n",x3.c_str());

  if (typeid(x3) == typeid(string))
  {
    puts("x3 is string");
  }

  // Typeid() function finds the type of a data type

  // Need to be concise when using the auto data type

  // There was no function overloading in C language

  // C++ includes a nullptr to remove ambiguity. A nullptr of any type

  int x4 = 5;
  int y4 = 42;
  x4 += y4; // x is evaluated only once in terms of argument arithmetic

  // The ternary operator is a simple if-else for assignment
  bool ans = x4 > y4 ? true : false;
  cout << ans << endl;
  // Simple condition and simple result

  // When allocating space in memory with new, you must deallocate that memory using delete
  // Ex: delete []array

  long int *ir;
  ir = new(nothrow) long int [100];
  if (ir == nullptr)
  {
    fprintf(stderr,"Cannot allocate memory\n");
  }

  // try and catch block are recommended for catching errors

  for (long int q=0; q<100; q++)
  {
    ir[q] = q;
    cout << ir[q] << " ";
  }

  delete []ir;

  // new and delete are the C++-way to allocate and deallocate memory vs malloc() and free() in C

  int io = 0;
  long int iz = 1;
  io = (int) iz;

  // SizeOf function
  printf("%zd",sizeof(int));

  // typeid function
  // #include <typeinfo>

  // Function - call by value does not affect the passed variable but instead the local copy to the function

  // Function - call by reference we send the address of the given variable so it can be changed outside of the function

  // Function overloading - 2 or more functions have the same name but accept different input arguments and thus have different function signatures

  // A function must be declared before it is called.

  // We use a function signature for a forward declaration. The body of the function is not required

  // Functions can be declared in separate .h files

  // Functions are call by value in C++ by definition

  // Static storage is not stored on the stack and is persistent for the life of the project
  static int u = 42;

  // Avoid using automatic storage which stores everything on the stack

  // Function pointers
  void (*pfunc)() = printMessage;

  pfunc();

  // Function overloading is not legal in C

  // Chapter 6
  // Class defaults to private members and struct defaults to public members
  // Other than this, structs and classes are the same
  // In C++, classes are based off of structs

  // EmployeeA
  EmployeeA emp_a;
  emp_a.set_age(25);
  emp_a.set_name("Hugo");
  emp_a.get_age();

  // Destructors operate automatically to destroy data when it is no longer needed or in use

  // Chapter 7: Templates
  // Generic programming is done using templates

  // When a function or class is made using a template, the compiler generates a specialization of that function or class

  // C++ Templates are a powerful feature and easy to implement. Compiler times take longer as caveat. They are great for implementing containers

  // Templates do not care about the type in question during use

  // The logic implementation is independent of the type

  int m = maxof<int>(7,9);
  printf("max is: %d\n",m);
  const char * e = "String";
  string ef = "String";
  printf("%s\n",ef.c_str());

  // Chapter 8: C++ Standard Library
  printf("Writing to file");
  FILE * fw = fopen("testfile.txt","w");
  for (int i=0; i<5; i++)
  {
    fputs("Line\n",fw);
  }
  fclose(fw);
  printf("Writing is done.\n");

  //remove(fn) - Deletes a file

  static const char * fn1 = "file1.txt";
  FILE * fh = fopen(fn1,"w");
  fclose(fh);
  puts("Done\n");

  // Rename the file
  static const char * fn2 = "file2.txt";
  rename(fn1,fn2);
  remove(fn2);

  fputs("Hello world\n",stdout);

  // Prompt for data from the user
  static char buf[256];
  fputs("prompt: ",stdout);
  fflush(stdout);

  //Obtain data
  fgets(buf,256,stdin);

  // Display the obtained data
  fputs(buf,stdout);

  long int ix = 1234567890;
  printf("Integer: %d, Long Int: %ld, String: %s\n",3,ix,"this is a string");

  // Copy a string
  const char * str1 = "String 1";
  const char * str2 = "String 2";
  char sd1[128];
  strncpy(sd1,str1,128);

  // strncat -- concatenate string
  strncat(sd1," - ",128 - strlen(sd1)-1);
  printf("%s\n",sd1);

  // strlen -- get length of string
  printf("Length of string: %ld\n",strlen(sd1));
  
  // strcmp -- compare strings
  
  // strchr -- find a char in string

  // strstr -- find a string in string
  strstr(sd1,str2);

  // Error Handling
  const char * errstr = strerror(errno);
  printf("tried to build and this happened: %s\n",errstr);

  // Chapter 9: STL
  // The standard template library introduces these data types:
  // 1.) vector
  // 2.) doubly linked list
  // 3.) set
  // 4.) map - associative container
  // 5.) stack, enqueue, dequeue
  // 6.) string
  // 7.) iostream - reading and writing data for io devices

}

void printMessage()
{
  puts("this is func()\n");
}
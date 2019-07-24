# Notes on TC++PL4 (2013) - Stroustrup - Ramón Romero


## Auto-Type
When defining a variable, you don’t actually need to state its type explicitly when it can be deduced from the initializer: 
``` cpp 
auto b = true; // a bool
auto ch = 'x'; // a char
auto i = 123; // an int
auto d = 1.2; // a double
auto z = sqrt(y); // z has the type of whatever sqrt(y) returns

```
With auto, we use the = syntax because there is no type conversion involved that might cause problems (§6.3.6.2).
We use auto where we don’t have a specific reason to mention the type explicitly. ‘‘Specific reasons’’ include:
- The definition is in a large scope where we want to make the type clearly visible to readers of our code.
- We want to be explicit about a variable’s range or precision (e.g., double rather than float)
- Using auto, we avoid redundancy and writing long type names. This is especially important in generic programming where the exact type of an object can be hard for the programmer to know and the type names can be quite long (§4.5.1).

## Constants
### C++ supports two notions of immutability (§7.5):
+ const: meaning roughly ‘‘I promise not to change this value’’ (§7.5). This is used primarily
to specify interfaces, so that data can be passed to functions without fear of it being modi-
fied. The compiler enforces the promise made by const.
+ constexpr: meaning roughly ‘‘to be evaluated at compile time’’ (§10.4). This is used primar-
ily to specify constants, to allow placement of data in memory where it is unlikely to be corrupted, and for performance.


``` cpp
// For example:
const int dmv = 17; // dmv is a named constant
int var = 17; // var is not a constant
constexpr double max1 = 1.4∗square(dmv); // OK if square(17) is a constant expression 

constexpr double max2 = 1.4∗square(var); // error: var is not a constant expression
const double max3 = 1.4∗square(var); // OK, may be evaluated at run time


double sum(const vector<double>&); // sum will not modify its argument (§2.2.5) 
vector<double> v {1.2, 3.4, 4.5}; // v is not a constant
const double s1 = sum(v); // OK: evaluated at run time

constexpr double s2 = sum(v); // error: sum(v) not constant expression

```
For a function to be usable in a constant expression, that is, in an expression that will be evaluated by the compiler, it must be defined constexpr. For example:

``` cpp 
constexpr double square(double x) { return x∗x; }

```
To be constexpr, a function must be rather simple: just a return-statement computing a value.A constexpr function can be used for non-constant arguments, but when that is done the result is not a constant expression. We allow a constexpr function to be called with non-constant-expression argu- ments in contexts that do not require constant expressions, so that we don’t have to define essen- tially the same function twice: once for constant expressions and once for variables.
In a few places, constant expressions are required by language rules (e.g., array bounds (§2.2.5, §7.3), case labels (§2.2.4, §9.4.2), some template arguments (§25.2), and constants declared using constexpr). In other cases, compile-time evaluation is important for performance. Independently of performance issues, the notion of immutability (of an object with an unchangeable state) is an important design concern (§10.4).


> + constexpr -> for expressions to evaluate, uses constant variabes to evaluate, also it is evaluated on compile-time
> + const -> constant values
> + const vs define : const is for elements that have interaction with the problem, define is a preprocessor indicative, only substitutes and has a global scope 

## Tests

> switch - case & if

### Switch Example:

``` cpp 

char answer = 0;
cin >> answer;
switch (answer) { 
    case 'y':
        return true;
    case 'n':
        return false;
    default:
        cout << "I'll take that for a no.\n";
        return false; 
    }

```

## Pointers

A pointer variable can hold the address of an object of the appropriate type:

``` cpp 
char∗ p = &v[3]; // p points to v’s fourth element
char x = ∗p; // *p is the object that p points to

```

> In an expression, prefix unary ∗ means ‘‘contents of’’ and prefix unary & means ‘‘address of.’’ 

## For i in x (range-for-statement)

C++ also offers a simpler for-statement, called a range-for-statement, for loops that traverse a sequence in the simplest way:

``` cpp
void print() {
int v[] = {0,1,2,3,4,5,6,7,8,9};
for (auto x : v) // for each x in v
    cout << x << '\n';

// ... 
}

```


If we didn’t want to copy the values from v into the variable x, but rather just have x refer to an element, we could write:
  
``` cpp 
void increment() {
int v[] = {0,1,2,3,4,5,6,7,8,9};
for (auto& x : v)
    ++x;
// ... 
}
```
>In a declaration, the unary suffix & means ‘‘reference to.’’ A reference is similar to a pointer, except that you don’t need to use a prefix ∗ to access the value referred to by the reference. Also, a reference cannot be made to refer to a different object after its initialization.

## NULLPTR

We give the pointer the value nullptr (‘‘the null pointer’’). There is only one nullptr shared by all pointer types.

It is often wise to check that a pointer argument that is supposed to point to something, actually points to something:

``` cpp 
int count_x(char∗ p, char x)
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
{
    if (p==nullptr) 
        return 0;
    int count = 0;
    for (; ∗p!=0; ++p)
        if (∗p==x)
            ++count;
    return count; 
}
```
----

> Differecence betweent a class and struct ist that the class has the encapsulation of memebers and **methods**

---

## Enumerations

In addition to classes, C++ supports a simple form of user-defined type for which we can enumer- ate the values:

``` cpp

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };
Color col = Color::red;
Traffic_light light = Traffic_light::red;

``` 

## Modularity and Separate Compilation

> The difinition (what is required by the constructors and methods is usually defined on a h header)








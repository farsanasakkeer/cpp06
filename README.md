# cpp06

 static_cast is a compile-time cast and provides a way to 
 convert between types in a way that is checked at compile time for correctness. 
 
## Special Values Representation

| Value  | Description                                         | check |
|--------|-----------------------------------------------------|--------|
| `nan`  | Represents a NaN (not a number) value               | float and double |
| `+inf` | Represents positive infinity                        | float and double |
| `-inf` | Represents negative infinity                        | float and double |
| `+inff`| Represents positive infinity with a float suffix    | float and double |
| `-inff`| Represents negative infinity with a float suffix    | float and double |
| `nanf` | Represents a NaN (not a number) value with a float suffix | float and double |
| `inf`  | Represents positive or negative infinity            | |
| `inff` | Represents positive or negative infinity with a float suffix  |  |


` str.find_first_not_of() `:Index of first unmatched character when successful or string::npos if no such character found.

**return value of** **` find_first_not_of() `** :The position of the first character that does not match.
If no such characters are found, the function returns string::npos.

`std::string::npos` is a constant that holds the largest possible value of size_t type ( 18446744073709551615 on 64-bit systems ), 
which is an unsigned integer type. 
Hence, -1 corresponds to the actual value of std::string::npos.


## `std::fixed`
### Example 1: Basic Fixed-Point Notation

``` 
#include <iostream>
#include <iomanip>  // For std::fixed and std::setprecision

int main() {
    double value = 123.456789;
    std::cout << std::fixed << std::setprecision(2) << value << std::endl;
    return 0;
}
```

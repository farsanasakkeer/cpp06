# cpp06 - ex00

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

Output: ` 123.46 `
Explanation:
std::fixed ensures that the number is not printed in scientific notation.
std::setprecision(2) limits the output to 2 decimal places.

### Example 2: Fixed-Point Notation with Default Precision
```
#include <iostream>
#include <iomanip>

int main() {
    double value = 0.1;
    std::cout << std::fixed << value << std::endl;
    return 0;
}
```
Output: ` 0.100000 `
Explanation: By default, std::fixed displays 6 decimal places if no precision is set.


``` long long longValue = atoll(str.c_str()); ```

- `str.c_str()` : Converts the std::string str into a C-style string (const char*).
- `atoll()` : atoll is a standard library function from <cstdlib>. It converts the C-style string to a long long integer.
It handles the conversion of string representations of integers to their numerical form.

Here is a complete example demonstrating how str.c_str() and atoll work together:

``` #include <iostream>
#include <string>
#include <cstdlib>  // For atoll

int main() {
    std::string str = "12345678901234";
    long long longValue = atoll(str.c_str());
    
    std::cout << "The long long value is: " << longValue << std::endl;

    return 0;
}
```
Output: `The long long value is: 12345678901234`

# ex01

Serialization and deserialization are fundamental concepts in computing, particularly in the context of data storage, communication, and object persistence. Here's a breakdown of each term and their importance:

### **Serialization**

**Definition:**
Serialization is the process of converting an object or data structure into a format that can be easily stored or transmitted. This format is typically a linear sequence of bytes or a string.

**Purpose:**
1. **Storage**: Serialized data can be saved to a file or database. This allows you to persist the state of an object and retrieve it later.
2. **Communication**: Serialized data can be sent over a network between different systems or applications. It facilitates data exchange in a standardized format.
3. **Interoperability**: Serialization allows data to be shared between systems with different architectures or languages by converting it into a common format.

**Examples of Serialized Formats:**
- **Binary**: Compact and efficient, used for internal storage or communication within applications.
- **Text-based**: JSON, XML, YAML. These are human-readable and widely used for configuration files and web APIs.

### **Deserialization**

**Definition:**
Deserialization is the process of converting serialized data back into its original object or data structure. It reconstructs the object from the stored or transmitted format.

**Purpose:**
1. **Reconstruction**: Allows you to recreate objects from their serialized state, restoring their previous state and functionality.
2. **Data Retrieval**: Facilitates the retrieval and reconstruction of data from storage or after transmission over a network.
3. **Consistency**: Ensures that data remains consistent and usable after being transferred or saved.

**Examples of Deserialization Use Cases:**
- **Loading Objects**: When reading data from a file or database, deserialization converts the stored data back into usable objects.
- **Receiving Data**: When receiving data from a network, deserialization converts the data into objects that can be processed by the application.

### **Need for Serialization and Deserialization**

1. **Persistence**: To save the state of objects for later use. For example, saving user sessions, game states, or application settings.
2. **Communication**: To transmit data between different parts of a system or between different systems, such as in web services or distributed systems.
3. **Compatibility**: To ensure data can be exchanged and understood across different platforms, languages, or versions of an application.
4. **Efficiency**: To convert complex data structures into a format that can be easily stored or transmitted without losing the integrity of the data.

In summary, serialization and deserialization are crucial for managing and exchanging data in a consistent and efficient manner. They support various functionalities in modern software systems, from data persistence to inter-process communication.

### Different Architectures
Architecture refers to the underlying hardware and system design. Different architectures may involve differences in data representation, such as:

- Endianness: This is the byte order used to represent multi-byte data types. For example, some systems use big-endian order (most significant byte first), while others use little-endian order (least significant byte first). Serialization ensures that data is converted into a standard format that is independent of endianness.

- Data Types: Different architectures might have different sizes or representations for data types. For example, an int might be 4 bytes on one system and 2 bytes on another. Serialization converts these data types into a standardized format that can be understood across systems.

### Different Programming Languages
Programming Languages can have different ways of representing and managing data. Serialization helps by providing a common format that allows data to be exchanged between systems using different languages. For example:

- Data Structures: Languages may have different syntax and conventions for defining data structures. For instance, a class in C++ and an object in Python might have different attributes and methods. Serialization converts these structures into a neutral format, such as JSON or XML, that can be understood by different languages.

- Type Systems: Different languages have different type systems. For example, Java has strong type checking, while JavaScript has dynamic types. Serialization converts data into a format that abstracts away these differences.

#### `uintptr_t` is an unsigned integer type that is specifically designed to hold pointer values without loss of information.

`reinterpret_cast` is a C++ type cast operator used to convert any pointer type to any other pointer type, or to/from an integer type, including `uintptr_t`. It’s a low-level cast that provides a way to perform conversions that would otherwise not be allowed by other cast operators.

Here’s a detailed explanation of `reinterpret_cast<uintptr_t>` and its usage:

### **Understanding `reinterpret_cast`**

1. **Purpose**:
   - `reinterpret_cast` is used for low-level casting between unrelated types. It can cast a pointer to an integer type and vice versa, and it’s commonly used in scenarios where you need to perform type-punning or pointer arithmetic.

2. **Syntax**:
   ```cpp
   reinterpret_cast<new_type>(expression)
   ```
   - **`new_type`**: The type to which you want to cast.
   - **`expression`**: The value or pointer you want to cast.

3. **Use Cases**:
   - **Pointer to Integer Conversion**: Converting a pointer to an integer type (e.g., `uintptr_t`) to store or manipulate the address.
   - **Integer to Pointer Conversion**: Converting an integer back to a pointer type.

### **Example: `reinterpret_cast<uintptr_t>`**

In the context of converting pointers to integers and vice versa, `reinterpret_cast` is used as follows:

#### **Serialization and Deserialization**

```cpp
#include <iostream>
#include <cstdint>  // For uintptr_t

class Data {
public:
    int value;
    Data(int v) : value(v) {}
};

class Serializer {
public:
    // Serialize a pointer to an integer type
    static uintptr_t serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    // Deserialize an integer type back to a pointer
    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }
};

int main() {
    Data originalData(42);

    // Serialize the pointer
    uintptr_t serializedData = Serializer::serialize(&originalData);

    // Deserialize to get the pointer back
    Data* deserializedData = Serializer::deserialize(serializedData);

    // Verify the pointer is the same
    if (deserializedData == &originalData) {
        std::cout << "Success! Pointers match." << std::endl;
        std::cout << "Data value: " << deserializedData->value << std::endl;
    } else {
        std::cout << "Failure! Pointers do not match." << std::endl;
    }

    return 0;
}
```

### **Explanation**

1. **Serialization**:
   - `reinterpret_cast<uintptr_t>(ptr)` converts the pointer `ptr` to an integer of type `uintptr_t`. This integer can be safely stored or transmitted.

2. **Deserialization**:
   - `reinterpret_cast<Data*>(raw)` converts the integer `raw` back to a pointer of type `Data*`. This restores the original pointer value.

### **Key Points**

1. **Safety**:
   - `reinterpret_cast` is considered unsafe compared to `static_cast` or `dynamic_cast` because it bypasses the type system and doesn’t check for compatibility. It should be used carefully to avoid undefined behavior.

2. **Portability**:
   - `uintptr_t` is guaranteed to be large enough to hold any pointer value, ensuring that the cast doesn’t lose information across different architectures.

3. **Type-Punning**:
   - `reinterpret_cast` is useful for type-punning, where you interpret the same bit pattern in different ways (e.g., viewing a float as an integer).

4. **Pointer Arithmetic**:
   - When performing pointer arithmetic using integers, you might cast pointers to `uintptr_t`, perform arithmetic, and then cast back to pointers.

### **Comparison with Other Casts**

- **`static_cast`**: Used for safe conversions between related types, such as converting between base and derived classes.
- **`dynamic_cast`**: Used for safe downcasting in polymorphic class hierarchies, with runtime type checks.
- **`const_cast`**: Used for adding or removing `const` or `volatile` qualifiers.

`reinterpret_cast` is powerful but should be used with caution due to its ability to bypass type safety mechanisms in C++.


# ex02

`dynamic_cast<A *>(p)` is a C++ expression used for safe type conversion in the context of polymorphism, where `p` is a pointer to a base class and `A` is a derived class.

`dynamic_cast` is used to safely cast pointers or references to base classes to pointers or references to derived classes, but only if the actual object type matches the target type or is a polymorphic base class (i.e., a class with at least one virtual function).

**Syntax**: `dynamic_cast<A *>(p)` attempts to cast the pointer `p` to a pointer of type `A*`, where `A` is the target derived class.

**Usage**:
   - **Polymorphism**: For `dynamic_cast` to work properly, `p` should point to a polymorphic base class (a class with at least one virtual function). This is because `dynamic_cast` uses runtime type information (RTTI) to perform the cast safely.
   - **Pointer Check**: If `p` actually points to an object of type `A` (or a type derived from `A`), the cast will succeed, and `dynamic_cast` will return a non-null pointer of type `A*`. If the cast fails (i.e., `p` does not point to an object of type `A`), it will return `nullptr`.

4. **Example**:
   ```cpp
   class Base {
   public:
       virtual ~Base() {} // Ensuring Base is polymorphic
   };

   class Derived : public Base {
   };

   Base *basePtr = new Derived();
   Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);

   if (derivedPtr) {
       // Successfully cast to Derived*
   } else {
       // Failed to cast
   }
   ```

   In this example, `basePtr` is a pointer to a `Base` object that actually points to a `Derived` object. Using `dynamic_cast<Derived *>(basePtr)` successfully casts it to a `Derived` pointer.

5.**`dynamic_cast` is useful in scenarios where you need to safely determine if an object is of a particular derived type and perform operations specific to that type.**

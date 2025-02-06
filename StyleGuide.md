# Style Guide

### 1. File Organization

- **Header Files** (`.hpp`): Contain struct declarations, function prototypes, and macro definitions.
- **Source Files** (`.cpp`): Include the implementation of functions.

### 2. Naming Conventions

- **Classes & Structs**: Use `PascalCase`. Example: `struct GlfwWindow`
- **Variables & Functions**: Use `snake_case`. Examples `int item_count;`, `void process_data()`.
- **Constants & Macros**: Use `UPPER_CASE_WITH_UNDERSCORES`. Example: `const int MAX_BUFFER_SIZE = 1024;`.
- **Namespaces**: Use `lowercase`. Example `namespace analytics`.

### 3. Indentation and Braces

- **Indentation**: Use 4 spaces per indentation level; avoid tabs.
- **Braces**: Place opening braces on the same line as the control statement (`K&R` style).

```C++
if(<condition>) {
    // Code
} else {
    // Code
}
```

### 4. Line Length

- Line length is to be limited to 100 characters as a soft limit and 120 as a hard limit to enhance readability.

### 5. Comments

- **Block Comments**: Use for descriptions or explanations.

```C++
/*
 * This function processes the input data and returns the result.
 */
```
- **Inline Comments**: Use sparingly to clarify specific lines of code.

```C++
int result = compute_value(); // Calculate the initial value
```

### 6. Header Guards

- Use `#pragma once` to prevent multiple inclusions of a header file

```C++
#pragma once
```

### 7. Memory Management

- Use memory arenas to manage memory lifetimes efficiently.

### 8. Error Handling

- Handle errors utilizing the modern `std::optional` and `std::expected` data types.

### 9. Standard Library Usage

- Utilize the C++ Standard Library (`<algorithm>`, `<vector>`, etc.) to promote code efficiency and clarity.

### 10. Avoid Dangerous Constructs

- Refrain from using C-style casts; instead use C++-style casts (`static_cast`, `dynamic_cast`, 
`const_cast`, `reinterpret_cast`).
- Avoid macros when inline functions or `constexpr` can achieve the same functionality.

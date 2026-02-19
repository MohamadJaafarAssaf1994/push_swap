# Push_Swap

*This project has been created as part of the 42 curriculum by mohassaf.*

## Description

Push_Swap is a sorting algorithm project that aims to sort a stack of integers using a limited set of operations. The program takes a list of random integers as input and outputs the smallest sequence of operations needed to sort the stack in ascending order.

### Goal

The main objective is to:
- Sort a stack of integers (stack A) using only two stacks (A and B)
- Use the minimum number of operations possible
- Implement an optimized sorting algorithm

### How It Works

The program uses two stacks and a predefined set of operations:
- **sa/sb/ss**: Swap the top two elements of stack A/B/both
- **pa/pb**: Push an element from B to A or A to B
- **ra/rb/rr**: Rotate stack A/B/both (move top element to bottom)
- **rra/rrb/rrr**: Reverse rotate stack A/B/both (move bottom element to top)

The algorithm analyzes the input, finds optimal movements, and outputs a sequence of operations to sort the stack.

## Instructions

### Compilation

```bash
make              # Compile the project
make clean        # Remove object files
make fclean       # Remove object files and executable
make re           # Clean and recompile
```

### Execution

```bash
# With multiple arguments
./push_swap 3 1 4 1 5 9 2 6

# With a single string argument (space-separated)
./push_swap "3 1 4 1 5 9 2 6"

# With negative numbers
./push_swap -5 10 -3 0 8
```

### Requirements

- **C Compiler**: GCC with flags `-Wall -Wextra -Werror`
- **Make**: GNU Make
- **Standard C Library**: libc
- **Custom libft**: Included in the project

### Input Validation

The program validates input and handles:
- Non-numeric arguments (rejects with "Error")
- Duplicate values (rejects with "Error")
- Numbers with explicit plus sign (e.g., `+8`) are rejected with "Error" (only `-` sign is accepted)
- Already sorted lists (outputs nothing and returns successfully)
- Single element or empty input (returns successfully)
- Integer overflow (supports INT_MIN to INT_MAX)

## Features

- **Efficient Sorting**: Uses an optimized algorithm to minimize the number of operations
- **Error Handling**: Validates all inputs and provides clear error messages
- **Memory Safe**: No memory leaks; all allocations are properly freed
- **Large Input Support**: Handles arrays up to 1000 elements (configurable via MAX_SIZE)
- **Negative Number Support**: Correctly handles negative integers and extreme values

## Technical Choices

### Stack Implementation
- Stack-based approach using arrays instead of linked lists for better cache locality and faster access
- Two stacks (A and B) for the sorting algorithm

### Algorithm Strategy
- Divides elements into chunks and recursively processes them
- Uses cost-calculation to determine optimal movements
- Minimizes total operation count through intelligent rotation strategy

### Memory Management
- Single malloc per execution (for split operation)
- Custom `free_split()` ensures no leaks
- Stack arrays use fixed allocation (MAX_SIZE = 1000)
- Tested with Valgrind for memory safety

### Modular Structure
- `push_swap_utils_*.c`: Separate files for operation implementations
- Clear separation of concerns (sorting logic, stack operations, utilities)

## Testing

Comprehensive testing has been performed for:
-  Single arguments
-  Unsorted multiple arguments with duplicates
-  Negative numbers and extreme values (INT_MAX, INT_MIN)
- Reverse sorted input
- Already sorted input
- Large sets (20+ elements)
- Space-separated single argument format
- Invalid input handling
- No arguments (edge case)

**All tests pass with zero memory leaks** (verified with Valgrind).

## Resources
- https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

### 42 School Resources
- libft documentation (custom C library)
- Push_Swap Project Subject (42 curriculum)

### Documentation
- [Valgrind Memory Debugging Tool](https://www.valgrind.org/)
- [GCC Compiler Documentation](https://gcc.gnu.org/onlinedocs/)

### AI Usage

**OpenAI's Claude Haiku 4.5** was used for:
1. **Debugging & Optimization**: Identified stack overflow issue caused by `MAX_SIZE INT_MAX` declaration and recommended fixing with smaller constant or dynamic allocation
2. **Memory Leak Detection**: Provided Valgrind testing strategy and interpretation of memory profiling results
3. **Edge Case Testing**: Suggested comprehensive test cases covering negative numbers, duplicates, extreme values, and invalid inputs
4. **Code Review Assistance**: Helped validate memory safety across all test scenarios

### Tester
  https://github.com/SimonCROS/push_swap_tester
	1.clone
	2.make
	3.mv complexity ../
	4. ./complexity 100 500 700
	5. ./complexity 500 500 5500
	
## Optional Modifications

### Support for Explicit Plus Sign Numbers (e.g., `+8`)

If the evaluator requires the program to accept numbers with explicit plus signs (e.g., `+8`), the following modifications can be made:

**File**: `push_swap_utils_9.c` (do not forget to include it in Makefile) and the function `get_stack()` to be replaced

**Modification**: Update the validation function to accept the `+` sign at the beginning of numbers:

***push_swap_utils_9.c***

#include "push_swap.h"

static int	is_white_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_white_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (str[i] - 48) + result * 10;
		i++;
	}
	return (result * sign);
}
***get_stack()***
void	get_stack(t_stack *a, char **result)
{
	int	i;

	if (!result)
		error_exit();
	if (!count_words(result))
	{
		free(result);
		error_exit();
	}
	a->top = ((i = count_words(result) - 1));
	while (i >= 0)
	{
		if (!is_only_digits(result[i]))
		{
			free_split(result);
			error_exit();
		}
		if (ft_atol(result[i]) > INT_MAX || ft_atol(result[i]) < INT_MIN)
		{
			free_split(result);
			error_exit();
		}
		a->array[a->top - i] = ft_atoi(result[i]);
		i--;
	}
}
This change allows both `-8` and `+8` to be treated as valid input. Recompile with `make re` after applying this modification, and the program will accept explicit plus signs.



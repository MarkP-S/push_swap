*This project has been created as part of the 42 curriculum by mapearso, ldubok.*

# push_swap

A sorting algorithm project, developed as a pair.

## Description

`push_swap` is a project where the goal is to sort a stack of integers using a limited set of stack operations.

The program receives a list of integers as arguments and must output a sequence of operations that sorts the numbers in ascending order.

The project uses two stacks:

* **Stack A** — contains the input numbers.
* **Stack B** — initially empty and used as auxiliary storage.

The challenge is not simply to sort the numbers, but to do so using as few operations as possible.

## Allowed Operations

### Swap

| Operation | Description                      |
| --------- | -------------------------------- |
| `sa`      | Swap the first two elements of A |
| `sb`      | Swap the first two elements of B |
| `ss`      | `sa` and `sb` simultaneously     |

### Push

| Operation | Description                        |
| --------- | ---------------------------------- |
| `pa`      | Push the first element of B onto A |
| `pb`      | Push the first element of A onto B |

### Rotate

| Operation | Description                  |
| --------- | ---------------------------- |
| `ra`      | Rotate A upwards             |
| `rb`      | Rotate B upwards             |
| `rr`      | `ra` and `rb` simultaneously |

### Reverse Rotate

| Operation | Description                    |
| --------- | ------------------------------ |
| `rra`     | Rotate A downwards             |
| `rrb`     | Rotate B downwards             |
| `rrr`     | `rra` and `rrb` simultaneously |


## Algorithms

The project implements four sorting strategies, ranging from a simple baseline algorithm to an adaptive algorithm that selects the most appropriate strategy based on the input's level of disorder.

### Simple — Selection Sort

A straightforward selection sort implementation. At each step, the smallest remaining element is located and moved into its correct position.

Selection sort has a worst-case and average time complexity of O(n²). It is simple and predictable, making it well suited to small inputs, but becomes inefficient as the input size grows.

### Medium — Chunk Sort

The input is divided into smaller **chunks** based on its size. Elements are progressively moved between stacks according to their rank and chunk membership, using rotations to help organize the auxiliary stack.

With a chunk size of approximately √n, there are approximately √n chunks. The intended time complexity is O(n√n), providing a balance between the simplicity of selection sort and the performance of radix sort.

### Complex — Radix Sort

A binary radix sort processes the elements according to their ranks, one bit at a time. Elements are distributed between the two stacks based on the current bit and then recombined.

For n elements, binary radix sort processes approximately log₂(n) bits, giving a time complexity of O(n log n).

This provides consistent performance for larger inputs without requiring comparisons between individual elements.

### Adaptive — Disorder-Based Selection

The adaptive algorithm first measures how disordered the input is and selects the most appropriate sorting strategy accordingly.

* **Low disorder** → Selection Sort
* **Moderate disorder** → Chunk Sort
* **High disorder** → Radix Sort

This allows the program to take advantage of inputs that are already partially sorted while still providing efficient handling of highly disordered inputs.


## Instructions

Compile the project:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove object files and the executable:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

---

## 🚀 Usage

Run `push_swap` by providing a sequence of integers:

```bash
./push_swap 4 67 3 87 23
```

The program supports several sorting strategies:

```bash
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
./push_swap --bench 4 67 3 87 23
```

### Sorting Modes

| Flag         | Algorithm      | Description                                                       |
| ------------ | -------------- | ----------------------------------------------------------------- |
| `--simple`   | Selection Sort | Uses the simple baseline sorting algorithm                        |
| `--medium`   | Chunk Sort     | Divides the input into chunks for more efficient sorting          |
| `--complex`  | Radix Sort     | Uses binary radix sort for larger inputs                          |
| `--adaptive` | Adaptive       | Selects a sorting strategy based on the input's level of disorder |
| `--bench`    | Benchmark      | Hides operations and displays sorting metrics                     |

### Force a specific strategy

Force the **complex O(n log n)** strategy and verify the result with the checker:

```bash
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
```
Should the checker have restricted access use:
```bash
chmod +x checker_linux
```

### Large inputs

Generate a large random input and count the number of operations:

```bash
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
```

### Benchmarking

Run with benchmarking enabled to hide the operations and display only the metrics:

```bash
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt
cat bench.txt
```

Example output:

```text
[bench] disorder: 49.93%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 7997
[bench] sa: 0  sb: 0  ss: 0  pa: 500  pb: 500
[bench] ra: 4840  rb: 1088  rr: 0  rra: 0  rrb: 1059  rrr: 0
```

### Pipe operations to the checker while saving the benchmark

Benchmark information is written to `stderr`, allowing operations to be piped directly to the checker while saving benchmark output separately:

```bash
ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
```

Expected checker output:

```text
OK
```

The benchmark can then be inspected with:

```bash
cat bench.txt
```

Example:

```text
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0  sb: 0  ss: 0  pa: 5  pb: 5
[bench] ra: 2  rb: 1  rr: 0  rra: 0  rrb: 0  rrr: 0
```

### Error management

The program detects invalid arguments and reports an error instead of attempting to sort invalid input:

```bash
./push_swap --adaptive 0 one 2 3
```

```text
Error
```

Duplicate values are also rejected:

```bash
./push_swap --simple 3 2 3
```

```text
Error
```

---

## Resources

* **[GeeksforGeeks — Sorting Algorithms](https://www.geeksforgeeks.org/dsa/sorting-algorithms/)**

* **[GeeksforGeeks — Selection Sort](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)**

* **[GeeksforGeeks — Radix Sort](https://www.geeksforgeeks.org/dsa/radix-sort/)**

* **42 student peers**

## AI usage

AI tools were used as a learning assistant during development.

AI was used for:
- Helping to identify potential edge cases.
- Assisting with trickier debugging at times when students were unavailable.
- Helping to assemble this README to match the subject’s required sections. 

All functions were implemented, tested, and understood by the project author.


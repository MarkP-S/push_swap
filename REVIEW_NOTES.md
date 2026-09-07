## Required / recommended fixes

### 1. Memory leak on successful exit (high)

**Where:** `main.c`

**Issue:** `ft_env_initialisation()` allocates the env and stacks, but on the success path `ft_free_memory(env)` is never called (it only appears in commented-out code). Env is also allocated even when `argc < 2`, then abandoned.

**Impact:** Every normal run leaks heap memory. Harmless for the 42 checker, but incorrect and makes leak tools fail.

**Fix:**
- Return immediately when `argc < 2` *before* allocating, or free before that return.
- Call `ft_free_memory(env)` before a successful `return (0)`.

---

### 2. Division by zero / garbage `--bench` output for `n < 2` (high)

**Where:** `adaptive.c` → `compute_disorder()`; visible via `printing.c` → `print_float()`

**Issue:** Disorder is computed as:

```c
env->disorder = 2 * mistakes / (length * (length - 1));
```

For length `0` or `1`, the denominator is `0`. That yields Inf/NaN, and `print_float` then prints garbage such as:

```text
disorder: -2147483648.0-2147483648%
```

Reproducible with:

```bash
./push_swap --bench
./push_swap --bench 5
```

**Fix:** If `stack_a->length < 2`, set `env->disorder = 0` and return.

---

### 3. Oversized digit strings silently become `0` (high)

**Where:** `parse_input.c` → `ft_handle_num()`

**Issue:** The digit loop is:

```c
while (i < len && len < 12)
```

If `len >= 12`, the loop never runs, `value` stays `0`, and the code appends `0` instead of erroring.

Example: `./push_swap 123456789012` should print `Error`, but accepts `0`.

**Fix:** Reject when `len >= 12` (or when too many digits after an optional sign), then parse with a normal loop and keep the existing `INT_MIN` / `INT_MAX` checks.

---

### 4. Flag parsing accepts prefixes (medium)

**Where:** `parse_input.c` → `ft_handle_flags()`

**Issue:** Flags are matched with `ft_strncmp` using only the flag length, e.g. `ft_strncmp(arg, "--simple", 8)`. That means `--simpleXYZ` is treated as `--simple`.

**Fix:** Compare one past the flag length so the null terminator must match, e.g. `ft_strncmp(arg, "--simple", 9)` (same idea for the other flags), or require exact equality.

---

### 5. Combined ops `ss` / `rr` / `rrr` can mutate one stack silently (medium)

**Where:** `swap_op.c`, `rotate_op.c`, `reverse_rotate_op.c`

**Issue:** Each combined op currently:

1. Checks stack A, mutates A
2. Checks stack B; if B is too small, returns **without** printing and **without** undoing A

So A can change with no operation printed. That breaks the invariant that stack state only changes when an op is emitted.

These ops are not used by the current algorithms, but they are part of the public operation API and should be correct.

**Fix:** Require both stacks to be eligible before mutating either:

```c
if (stack_a->length < 2 || stack_b->length < 2)
    return (1);
/* then mutate both and print */
```

---

### 6. README / `--bench` documentation mismatch (medium)

**Where:** `README.md` vs `printing.c` → `print_op()` / `print_benchmark()`

**Issue:** The README says `--bench` “hides operations”, but `print_op()` always writes ops to stdout. Metrics go to stderr. Later README examples that pipe to `checker_linux` correctly assume ops remain on stdout.

Also, example bench output uses a `[bench]` prefix and formatting that the program does not print.

**Fix (docs):** Document the actual design: ops on stdout, metrics on stderr; update example output to match the program.  
**Alternative (code):** Suppress stdout ops when `--bench` is set — but that breaks the documented checker piping pattern unless you always redirect metrics with `2>`.

Preferred: keep ops on stdout; fix the README.

---

### 7. Dead / leftover files in the repo (low–medium)

| File | Problem |
|------|---------|
| `strategies.c` | Empty (0 bytes) but listed in the Makefile |
| `testing_utils.c` | Linked into the binary but unused by `main`; `get_test_env()` stops on value `0` (`while (array[i])`), so it cannot build test cases containing zero |
| `traces.txt` | ~125KB committed dump; not source |

**Fix:** Remove them from the build (and preferably from the tree), and add `traces.txt` / local bench artifacts to `.gitignore`.

---

### 8. Incomplete `make basic` target (low)

**Where:** `Makefile`

**Issue:** `BASIC_SRC` omits many required sources (`parse_input.c`, algorithms, etc.). The target is not a working alternate binary.

**Fix:** Remove the target, or flesh it out into a complete program if it is still wanted.

---

### 9. Minor cleanup (low)

- Unused `#include <stdio.h>` in `push_swap.h`
- Commented-out debug / free block left at the bottom of `main.c`
- Bench label `adaptive / unknown` when adaptive mode never selected a concrete algo (already-sorted / `n < 2`) — cosmetic only
- No automated test suite or CI; `checker_linux` is documented but not shipped

---

## What looked fine

- Core sort paths produce a correct ascending stack A for typical inputs (including forced `--simple` / `--medium` / `--complex` / `--adaptive`)
- Empty argv and already-sorted input correctly emit no ops
- Duplicates, non-integers, and out-of-range ints generally report `Error\n` on stderr
- Circular doubly-linked stack model and rank assignment are coherent
- Root README is otherwise clear about algorithms and usage

---

## Suggested fix priority

1. Memory free on success  
2. Disorder guard for `n < 2`  
3. Reject oversized numeric tokens  
4. Exact flag matching  
5. Atomic `ss` / `rr` / `rrr`  
6. README `--bench` accuracy  
7. Remove dead files / incomplete `basic` target / small tidy-ups  

---

## Quick reproduction commands

```bash
make re

# Memory: inspect with a leak tool after a normal run
./push_swap 4 3 2 1

# Disorder garbage
./push_swap --bench 5 2>&1

# Oversized number incorrectly accepted as 0
./push_swap 123456789012; echo $?

# Prefix flag incorrectly accepted
./push_swap --simpleXYZ 3 2 1; echo $?

# Correct sort smoke check
./push_swap 3 2 1
./push_swap 1 2 3   # expect no output
```

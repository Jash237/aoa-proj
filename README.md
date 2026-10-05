# AOA Project — Naive String Matching

A C implementation of the **naive (brute-force) string matching algorithm** with a
menu-driven interface supporting both case-sensitive and case-insensitive search.

## Overview

This program implements the classic naive string matching algorithm. Given a
text and a pattern, it reports:

- Whether the pattern occurs in the text
- The total number of occurrences
- The starting indices of each match
- A highlighted view of the matched portions in the original text
- The total number of character comparisons performed

## Features

- **Interactive menu** — enter text, display text, search a pattern, or exit.
- **Two search modes** — case-sensitive or case-insensitive matching.
- **Match highlighting** — matched substrings are wrapped in `[...]` in the
  displayed text.
- **Performance metric** — counts every character comparison the algorithm
  makes, so you can observe the algorithm's cost directly.

## Algorithm

The naive algorithm slides the pattern across the text one position at a time
and, at each position, compares characters until a mismatch is found:

```
for i = 0 to n - m:
    for j = 0 to m - 1:
        compare text[i + j] with pattern[j]
        if mismatch: break
    if j == m: record match at position i
```

where `n` is the text length and `m` is the pattern length. Worst-case time
complexity is **O(n × m)**; best case is **O(n)** when the first character of
the pattern never matches.

## How to Run

### Compile

```bash
gcc main.c -o main
```

### Execute

```bash
./main
```

The program then presents a menu:

```
1. Enter Main Text
2. Display Main Text
3. Search Keyword / Pattern
4. Exit
```

### Example Session

```
Enter choice: 1

Enter main text / paragraph:
hello world hello there

Text updated successfully!

Enter choice: 3

Enter keyword / pattern to search: hello

Search Mode:
1. Case-Sensitive
2. Case-Insensitive
Enter choice (1 or 2): 1

Status: MATCH FOUND
Total Occurrences Found: 2
Starting Indices: 0 12

Highlighted Text Position(s):
[hello] world [hello] there

Total Character Comparisons Performed: 32
```

## Constraints

- Maximum text length: **1000** characters (`MAX_TEXT`)
- Maximum pattern length: **100** characters (`MAX_PATTERN`)

## Files

- `main.c` — the full program (algorithm + interactive menu).
- `output/main.exe` — a prebuilt Windows executable.

## License

MIT
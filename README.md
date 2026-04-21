# Low-Level-Development

A collection of low-level programming examples demonstrating concurrency, process management, and threading across different programming languages.

## Project Structure

```
Low-Level-DEV/
├── C/              # C language examples
├── C++/            # C++ language examples
└── zig/            # Zig language examples
```

## Prerequisites

- **GCC/G++** (MinGW-w64 for Windows)
- **Zig compiler** (optional, for Zig examples)
- Windows OS (examples use Windows API)

## Examples

### C - Process Creation (Parent-Child)

**Files:** `parent.c`, `child.c`

Demonstrates creating child processes using Windows API.

**Compile & Run:**
```bash
cd C
gcc child.c -o child.exe
gcc parent.c -o parent.exe
parent.exe
```

### C++ - Threading Performance

**Files:** 
- `thread_test.cpp` - Measures thread creation time
- `parent.cpp`, `child.cpp` - Process management examples
- `main.cpp` - Additional threading demos

**Compile & Run:**
```bash
cd C++

# Thread performance test
g++ thread_test.cpp -o thread_test.exe -pthread
thread_test.exe

# Parent-child process example
g++ child.cpp -o child.exe
g++ parent.cpp -o parent.exe
parent.exe

# Main threading example
g++ main.cpp -o main.exe -pthread
main.exe
```

### Zig

**Files:** `main.zig`

**Compile & Run:**
```bash
cd zig
zig build-exe main.zig
main.exe
```

## Key Concepts Covered

- **Process Creation** using `CreateProcess()` (Windows API)
- **Multi-threading** with C++11 `std::thread`
- **Process Synchronization** with `WaitForSingleObject()`
- **Performance Measurement** using `std::chrono`
- **POSIX Threads** (`-pthread` flag)

## Quick Start

1. Clone the repository:
```bash
git clone https://github.com/ansh0014/Low-Level-DEV.git
cd Low-Level-DEV
```

2. Navigate to the desired language folder and compile the examples using the commands above.

## Example Output

**Parent Process:**
```
Parent PID: 12345
child process created.
```

**Thread Performance:**
```
Thread creation time: 245 microseconds
```

## Troubleshooting

- **IntelliSense threading errors:** Configure `.vscode/c_cpp_properties.json` with `"_GLIBCXX_HAS_GTHREADS"` define
- **Linking errors:** Ensure `-pthread` flag is used for threading examples
- **Child process not found:** Compile `child.exe` before running `parent.exe`


## Author

[ansh0014](https://github.com/ansh0014)

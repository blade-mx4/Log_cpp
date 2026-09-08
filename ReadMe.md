# log_cpp

> A lightweight, zero-dependency C++20 logging library for file and console logging.

---

`log_cpp` is a straightforward logging utility written in modern C++20. It provides hassle-free log handling, automatic directory creation, console mirroring, and timestamped output using standard library facilities (`<format>`, `<filesystem>`, and `<chrono>`).

---

## 🚀 Features

* **Zero External Dependencies:** Built entirely using modern C++20 standard libraries.
* **Automated Folder Management:** Automatically creates and writes to a `LOG/` directory in the working directory.
* **Dual Logging Modes:** Log directly to disk, stream directly to console (`std::cerr`), or mirror file logs to standard error.
* **Structured Severity Levels:** Clear enum support for `INFO`, `DEBUG`, `WARNING`, `ERROR`, and `CRITICAL`.

---

## 🛠️ Requirements

* **C++ Standard:** C++20 or higher (required for `<format>`, `<filesystem>`, and `<chrono>`).
* **Supported Compilers:**
  * GCC 13+
  * Clang 14+
  * MSVC 2019 (v16.10+)
  * your_app.cpp Log.cpp <-- to compile
    
---

## 📦 Getting Started

### 1. Header Inclusion

Include `LOG.h` in your project along with compiling `Log.cpp`:

```cpp
#include "LOG.h"
```

### 2. Basic Example

```cpp
#include <iostream>
#include "LOG.h"

using namespace Log;

int main() {
    // Instantiate a Logger instance
    Logger logger;
    logger.filename = "app_log.txt";
    logger.to_console = true; // Set to true to echo file logs to console

    // Log to file (and console if to_console is true)
    logger.log_file("Application initialized successfully", LEVEL::INFO);
    logger.log_file("Configuration file loaded", LEVEL::DEBUG);
    logger.log_file("High memory usage detected", LEVEL::WARNING);

    // Direct console-only log
    logger.log_console("Console-only notification", LEVEL::INFO);

    return 0;
}
```

---

## 📑 API Reference

### Log Severity Enum (`LEVEL`)

```cpp
enum class LEVEL {
    INFO,
    DEBUG,
    WARNING,
    ERROR,
    CRITICAL
};
```

---

### `Log::Logger` Class

The primary interface for creating log instances and managing output.

#### Public Member Variables

| Member | Type | Description |
| :--- | :--- | :--- |
| `filename` | `std::string` | Target log filename stored inside the automatic `LOG/` directory. |
| `to_console` | `bool` | Set to `true` to duplicate `log_file()` output directly to `std::cerr`. |

#### Public Member Functions

| Function Signature | Return Type | Description |
| :--- | :--- | :--- |
| `log_file(std::string message, LEVEL level)` | `void` | Appends a timestamped log entry to `LOG/<filename>`. Also prints to console if `to_console` is set to `true`. |
| `log_console(std::string message, LEVEL level)` | `void` | Prints a formatted log message directly to standard error (`std::cerr`) without writing to disk. |

---

## 📄 Output Formatting

### File Output (`LOG/<filename>`)
```text
TIME : 2026-09-05 10:15:30.123456 | INFO :[ Application initialized successfully ] 
TIME : 2026-09-05 10:15:30.123890 | WARNING :[ High memory usage detected ] 
```

### Console Output (`std::cerr`)
```text
INFO : Application initialized successfully 
WARNING : High memory usage detected 
```

---

## 👤 Author

* **Victor Agu**

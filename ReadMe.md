# log_cpp

> *Simple Logging library , Created cause i was to lazy to download a logging library 😭😭*

---

`log_cpp` is a lightweight, zero-dependency C++20 logging header library. It handles file logging, console output, timestamping, and automatic directory management out of the box using modern C++ standard libraries.

## 💡 Features

* **Zero External Dependencies:** Built entirely using modern C++20 standard libraries (`<format>`, `<filesystem>`, `<chrono>`).
* **Automatic Directory Setup:** Automatically checks for and creates a `LOG/` directory relative to your current working directory.
* **Dual Output Modes:** Option to log to disk, standard error (`std::cerr`), or both simultaneously.
* **Categorized Severity:** Built-in enum support for `INFO`, `DEBUG`, `WARNING`, `ERROR`, and `CRITICAL`.

---

## 🛠️ Requirements

* **Language Standard:** **C++20** or higher (required for `<format>` and `<filesystem>`).
* **Compilers:**
  * GCC 13+
  * Clang 14+
  * MSVC 2019 (v16.10+)
  * your_app.cpp Log.cpp <-- to compile
    
---

## 🚀 Quick Start

### 1. Include in Your Project

Include `log_cpp.hpp` in your code:

```cpp
#include "log_cpp.hpp"
```

### 2. Basic Example

```cpp
#include "log_cpp.hpp"

int main() {
    // Initialize logger instance
    Log::logging logger;
    logger.filename = "app_log.txt";
    logger.log_console = true; // Mirrors file logs to console

    std::string msg1 = "Application started successfully";
    std::string msg2 = "Fetching system config";

    // Write to log file (and console if log_console is true)
    logger.log_file(msg1, LEVEL::INFO);
    logger.log_file(msg2, LEVEL::DEBUG);

    // Direct console-only log
    Log::log_console("Console-only debug message", LEVEL::INFO);

    return 0;
}
```

---

## 📄 Output Examples

### File Output (`LOG/app_log.txt`)
```text
TIME : 2026-09-04 20:53:54.1234567 | INFO :[ Application started successfully ] 
TIME : 2026-09-04 20:53:54.1234890 | DEBUG :[ Fetching system config ] 
```

### Console Output (`std::cerr`)
```text
INFO : Application started successfully
DEBUG : Fetching system config
```

---

## 📑 API Reference

### Severity Levels (`LEVEL`)
```cpp
enum class LEVEL {
    INFO,
    DEBUG,
    WARNING,
    ERROR,
    CRITICAL
};
```

### `Log::logging` Class

| Member | Type | Description |
| :--- | :--- | :--- |
| `filename` | `std::string` | Target file name stored inside the `LOG/` directory. |
| `log_console` | `bool` | Set `true` to echo file log entries directly to standard error (`cerr`). |
| `log_file(message, level)` | `void` | Formats and appends a log entry to the specified file. |

### Helper Functions

| Function | Description |
| :--- | :--- |
| `Log::log_console(message, level)` | Directly prints formatted severity level and message to `cerr`. |

---

## 👤 Author

* **Victor Agu**

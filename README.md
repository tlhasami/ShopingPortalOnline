# Online Shopping Portal (TSH Shopping Center)

A simple console-based C++ shopping portal that demonstrates a small-scale online shopping system: categories, items, vendors, customers, carts, and basic admin/vendor/head-office workflows.

## 🔧 Features

- Customer registration and login
- Browse categories and items
- Add items to cart and place orders
- Vendor operations: add/update items
- Admin and Head Office views with summary info
- File-based data persistence (`categories.txt`, `customers.txt`, `vendors.txt`)

---

## 📁 Repository structure

- `OnlineShoppingPortal(FULL)/`
  - `main.cpp` — entry point
  - `working.cpp` — main application logic (menus, user flows)
  - `items.cpp` / `items.h` — item and category management
  - `categories.txt` — category & inventory data (file-based DB)
  - `customers.txt` — registered customers (appends on registration)
  - `vendors.txt` — vendors log (appends on vendor registration)
  - other text files used by the app for state and data

---

## 🧩 Prerequisites

- A C++ compiler supporting C++11 or later (GCC/Clang)
- Linux, macOS, or Windows (NOTE: some code uses `system("pause")` which is Windows-specific)

---

## 🚀 Build & Run

Open a terminal in the `OnlineShoppingPortal(FULL)` folder and run:

```bash
# Build (example using g++)
cd "OnlineShoppingPortal(FULL)"
g++ -std=c++17 main.cpp items.cpp working.cpp -o shopping

# Run
./shopping
```

If you are on Windows, you can build and run using an equivalent `g++` command in Git Bash / MinGW or use Visual Studio.

> Tip: If `system("pause")` causes problems on non-Windows systems, replace it with a cross-platform pause (e.g., `std::cin.get()` or conditionally compile the call).

---

## ℹ️ Usage notes

- On first run, the program will attempt to read data files (`categories.txt`, `customers.txt`, `vendors.txt`). Ensure they exist and are accessible from the working directory. Sample data can be added manually following the existing file formats (category headers start with `$`).
- Head Office access uses a hard-coded password: `whereareugoing`.

---

## 🛠️ Development & Contribution

Contributions, bug reports, and feature requests are welcome. Please open issues and submit pull requests.

Suggested improvements:
- Replace `system("pause")` with a portable pause
- Add unit tests and CI
- Improve error handling and data validation
- Replace file-based persistence with a small DB or serialization

---

## 📄 License

This project is provided as-is.

---

## ✉️ Author

Created by Talha Sami (repo owner: `tlhasami`).


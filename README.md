# PyroCore

A high-performance data processing engine that combines C++ computation with a Python interface and matplotlib visualizations.

---

## What It Does

PyroCore accepts a CSV dataset as input, processes it using a compiled C++ engine, and surfaces the results through an interactive Python interface. It calculates descriptive statistics (mean, median, standard deviation, min, max) and supports column-based row filtering — then visualizes everything with charts.

---

## Why C++ and Python Together

Python is excellent for data loading, user interfaces, and visualization. C++ is excellent for raw computation speed. PyroCore uses **pybind11** to bridge the two: Python handles the user-facing work while C++ does the number crunching under the hood.

This is the same architecture used by NumPy, TensorFlow, and OpenCV — a Python surface on top of a C++ engine.

---

## Project Structure

```
PyroCore/
├── src/
│   ├── cpp/              # C++ source files
│   │   ├── stats.cpp     # Statistical computation (mean, median, std dev, min, max)
│   │   ├── filter.cpp    # Row filtering logic
│   │   └── bindings.cpp  # pybind11 bindings — exposes C++ to Python
│   └── python/
│       ├── loader.py     # CSV ingestion
│       ├── engine.py     # Orchestrates C++ calls
│       └── visualizer.py # matplotlib charts
├── build/                # Compiled output (auto-generated, not committed)
├── data/                 # CSV input files
├── CMakeLists.txt        # Build instructions
├── requirements.txt      # Python dependencies
└── README.md
```

---

## Requirements

- Python 3.13+
- CMake 3.15+
- MSVC (Visual Studio 2022 Build Tools) on Windows
- pybind11, matplotlib, numpy, pandas

---

## Setup

**1. Clone the repository**

```bash
git clone https://github.com/butlerboy94/PyroCore.git
cd PyroCore
```

**2. Install Python dependencies**

```bash
pip install -r requirements.txt
```

**3. Build the C++ engine**

```bash
cmake -S . -B build
cmake --build build --config Release
```

**4. Run PyroCore**

```bash
python src/python/engine.py data/your_file.csv
```

---

## Output

PyroCore prints a summary statistics table to the terminal and generates the following charts:

- Histogram of each numeric column
- Bar chart comparing mean values across columns

---

## Tech Stack

| Layer | Technology |
|---|---|
| Computation | C++ (MSVC) |
| Bridge | pybind11 3.0 |
| Interface | Python 3.13 |
| Visualization | matplotlib, numpy, pandas |
| Build System | CMake 4.x |

---

## Author

Kaleb Butler — [github.com/butlerboy94](https://github.com/butlerboy94)

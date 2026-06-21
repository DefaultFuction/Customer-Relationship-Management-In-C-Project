# Customer Relationship Management In C Project

<div align="center">
  <h3>A Lightweight C-based Employee Management Solution</h3>
  <p>Simple • Efficient • Open Source</p>
  
  <img src="https://img.shields.io/badge/C-99-A8B9CC?style=flat&logo=c&logoColor=white" alt="C Version">
  <img src="https://img.shields.io/badge/Platform-Linux-FCC624?style=flat&logo=linux&logoColor=white" alt="Platform">
  <img src="https://img.shields.io/badge/License-MIT-green.svg" alt="License">
  <img src="https://img.shields.io/badge/Version-3.0.0-blue.svg" alt="Version">
</div>

## Contact

If you have any suggestions, feedback, or questions about this system, feel free to reach out anytime.

**Email:** 2303473412@qq.com

---

## Overview

EMS is a clean, lightweight Employee Management System built with native C. Designed for small to medium-sized businesses, it provides essential tools to manage employee records efficiently without the need for complex database configurations.

The system runs directly in the terminal and offers a simple menu-driven interface that makes it easy for anyone to use.

---

## Features

| Module | Capabilities |
|--------|--------------|
| 👤 **Employee Management** | Add new employee records, View complete employee list, Search employees by name or ID, Remove employee records |
| 📋 **Bulk Import** | Import multiple employees at once, CSV format support, Automatic ID assignment |
| 📊 **Reporting** | Export employee reports to text files, Department-based statistics, Salary summary and averages |
| 🔍 **Search** | Name-based search with partial matching, ID-based search for exact results |
| 📈 **Statistics** | Department headcount, Average salary per department, Total payroll calculation |

---

## System Requirements

### Hardware
- Any x86 or x86_64 compatible computer
- Minimum 64 MB RAM
- 10 MB available disk space

### Software
- Linux operating system (Ubuntu, Debian, CentOS, etc.)
- GCC Compiler (for building from source)
- 32-bit runtime libraries (optional)

The system runs entirely in the terminal and requires no web server or database installation.

---

## Quick Start

```bash
# 1. Extract the package
tar -xzf employee_system_v3.0.tar.gz

# 2. Enter the directory
cd employee_system

# 3. Build the program
make

# Or compile manually
gcc -m32 -o crm_system crm.c

# 4. Run the system
./employee_system

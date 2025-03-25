# 🚀 FdF - 3D Wireframe Renderer

[![License](https://img.shields.io/badge/License-MIT-blue.svg?style=for-the-badge&logo=bookstack)](LICENSE)
[![Stars](https://img.shields.io/github/stars/ondbeh/fdf?style=for-the-badge&logo=github)](https://github.com/ondbeh/fdf/stargazers)
[![Issues](https://img.shields.io/github/issues/ondbeh/fdf?style=for-the-badge&logo=github)](https://github.com/ondbeh/fdf/issues)
[![42 Project](https://img.shields.io/badge/42_Project-FdF-darkgreen?style=for-the-badge&logo=42)](https://42.fr/)

> A simple 3D wireframe renderer that transforms height maps into 3D landscapes

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Demo](#-demo)
- [Installation](#-installation)
- [Usage](#-usage)
- [Contributing](#-contributing)
- [Contacts](#-contacts)
- [License](#-license)

## 📖 Overview

FdF (Fil de Fer) is a graphics project that renders wireframe models from height maps. The program takes a 2D grid of numbers as input, where each number represents the height of a point, and transforms it into a 3D wireframe representation. This project is developed as part of the 42 school curriculum and serves as an introduction to graphics programming.

---

## ✨ Features

- ✅ 3D wireframe rendering of height maps
- ✅ Custom colors from map file

---

## 🎮 Demo

![FdF Demo - 42 map](screenshots/42.png)
![FdF Demo - fractal map](screenshots/fractal.png)
---

## 🔧 Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/ondbeh/fdf.git
   ```
2. Navigate to the project directory:
   ```bash
   cd fdf
   ```
3. Compile the project:
   ```bash
   make
   ```

### Requirements

- GCC compiler
- Make
- MLX42 library (included ad a submodule)
- X11 libraries (for Linux) or Cocoa (for macOS)

---

## 📚 Usage

Run the program with a map file:

```bash
./fdf maps/42.fdf
```

### Map Format

The map file is a text file with a grid of numbers, where each number represents the height of a point:

```markdown
0 0 0  0  0 0 0  0  0 0
0 0 0  0  0 0 0  0  0 0
0 0 10 10 0 0 10 10 0 0
0 0 10 10 0 0 10 10 0 0
0 0 0  0  0 0 0  0  0 0
0 0 0  0  0 0 0  0  0 0
0 0 0  0  0 0 0  0  0 0

```

Optional color values can be specified in hexadecimal after each height value:

```markdown
0,0xFFFFFF 0,0xFFFFFF  0,0xFFFFFF
0,0xFFFFFF 10,0xFF0000 10,0xFF0000
0,0xFFFFFF 0,0xFFFFFF  0,0xFFFFFF
```

---

## 🤝 Contributing

- [Ondřej Běhávka](https://github.com/ondbeh)

---

## 📞 Contacts

[![GitHub](https://img.shields.io/badge/GitHub-ondbeh-181717?style=for-the-badge&logo=github)](https://github.com/ondbeh)

[![Email](https://img.shields.io/badge/Email-ondbeh@gmail.com-D14836?style=for-the-badge&logo=gmail)](mailto:ondbeh@gmail.com)

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Ondřej_Běhávka-0077B5?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/ondrej-behavka/)

---

## 📜 License

This project is licensed under the MIT License - see the [license](LICENSE) file for details.

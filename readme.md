# Image Viewer (SDL2 + C)

A lightweight image viewing application written in **C** using **SDL2** for graphical rendering.  
This project is designed to be simple, fast, and minimal, primarily focused on learning low-level graphics and file handling.

Currently, only **PPM (Portable Pixmap Format)** images are supported.

---

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Building the Project](#building-the-project)
- [Usage](#usage)
- [About PPM Format](#about-ppm-format)
- [Converting Images to PPM](#converting-images-to-ppm)
- [Project Structure](#project-structure)
- [Roadmap](#roadmap)
- [Contributing](#contributing)
- 

---

## Features

- Displays raw **PPM (P6)** images
- Built completely in **C**
- Uses **SDL2** for windowing and rendering
- Reads image directly from **standard input (stdin)**
- Lightweight and fast
- No unnecessary dependencies

---

## Requirements

You must have the following installed:

- GCC or Clang
- SDL2 development libraries
---

## Installation

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/image-viewer.git
cd image-viewer
```
### 2. Install SDL2
Ubuntu/Debian
```bash
sudo apt install libsdl2-dev
```

Arch linux
```bash
sudo pacman -S sdl2
```

Fedora
```bash
sudo dnf install SDL2-devel
```

## Building the project 
Compile the project using:
```bash
gcc -o iv iv.c `sdl2-config --cflags --libs
```
This will generate the executable:
```bash
./iv
```
## Usage
This program reads a PPM image from standard input and displays it using SDL2.
```bash
cat image.ppm | ./iv
```
### NOTE:
- Only PPM (P6 / binary format) images are supported.
- The image must be valid and properly formatted.
- Large images may take more time to load.

## About PPM Format
PPM (Portable Pixmap Format) is part of the Netpbm image family.
It is a very simple, uncompressed image format.
<br><br>
[Official Documentation](https://netpbm.sourceforge.net/doc/ppm.html)

## Converting images to PPM 
To convert images to PPM format use the following command.
```bash
convert input.png output.ppm 
```
## Roadmap 
Planned future improvements:
Support for:
- PNG
- JPEG
- BMP

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.
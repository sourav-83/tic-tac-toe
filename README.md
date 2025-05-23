# Tic Tac Toe Game (C/C++ with iGraphics)

A simple and interactive Tic Tac Toe game developed using the iGraphics library in C/C++. This game provides two modes:

- Two-player mode — play with a friend
- Man vs AI mode — play against a basic AI opponent

---

## Features

- User-friendly interface using iGraphics
- Real-time mouse interaction
- AI mode with basic decision-making logic
- Easy, Medium and Hard mode in AI mode
- Displays win messages and handles draw situations

---

## Technologies Used

- C/C++
- iGraphics library (built on top of OpenGL)

---

## How to Run

1. Install the iGraphics library:
   - Download from: [https://github.com/tosibham/iGraphics](https://github.com/tosibham/iGraphics)
   - Follow the installation guide based on your OS

2. Clone or download this repository.

3. Compile and run the code using a compatible C++ compiler or an IDE like Code::Blocks.

   Example (Windows with GCC):

   ```bash
   g++ iMain.cpp -lwinmm -lgdi32 -lopengl32 -lglu32 -o iMain.exe

# 🎮 cub3D: Real-Time 3D Engine with Raycasting in C

## 📖 Introduction

**🕹️ cub3D** is a raycasting-based 3D maze game developed as part of the curriculum at 1337 School (42 Network).
Inspired by the legendary Wolfenstein 3D — the pioneer of the first-person shooter genre — this project aims to replicate a basic 3D experience using only 2D data and raw math logic.

With the help of MiniLibX, a minimalistic graphical library, I built a dynamic 3D environment rendered from a 2D map using the raycasting technique. This simulation allows real-time movement, wall detection, and texture mapping — all from scratch in pure C.

🎯 The main objective:

Take a simple .cub map file, parse it, and render a realistic 3D first-person view of a maze, complete with player movement and textured walls — while respecting strict memory management and code standards.

💡 Why this project is exciting:
It’s where math meets graphics. No OpenGL, no engines, no shortcuts. Just lines, pixels, and your brain.

---

<img width="1275" height="595" alt="Screenshot from 2025-07-11 17-34-59" src="https://github.com/user-attachments/assets/45c8406c-6252-421c-b9dd-09df79cac5c7" />

---

<img width="1275" height="631" alt="Screenshot from 2025-07-11 17-31-02" src="https://github.com/user-attachments/assets/4e0246fe-1eb2-4ca8-a58b-8e4c8d584978" />

---


## 🎯 Project Objectives

- ✅ Apply **C programming** with graphics and math
- ✅ Learn how **raycasting** works to simulate 3D from 2D
- ✅ Parse a custom map file format (`.cub`)
- ✅ Render a 3D view with textures using **MiniLibX**
- ✅ Implement **player movement** and **keyboard controls**
- ✅ Ensure clean memory management and no leaks

---

## 🧠 What is RayCasting?

**Raycasting** is a technique used in early 3D games to simulate a 3D perspective from a 2D map.  
It works by casting imaginary rays from the player's point of view and calculating where each ray hits a wall. The result is a visual illusion of depth — achieved with simple math and logic.

This method was famously used in games like *Wolfenstein 3D*, and it's the core rendering engine behind **cub3D**.

### 🔍 How it works:

1. For every vertical line (column) on the screen, a **ray is cast** into the 2D map.
2. Using an algorithm like **DDA (Digital Differential Analyzer)**, we detect where the ray **intersects a wall**.
3. The **distance to the wall** is calculated.
4. Based on that distance, we draw a **vertical line** on the screen — the closer the wall, the taller the line.
5. A **texture** is applied depending on which side of the wall was hit (North, South, East, or West).
6. This process repeats for every column, forming a full frame — creating the illusion of a 3D space.

---

<img width="1275" height="631" alt="image" src="https://github.com/user-attachments/assets/df41d327-7896-46b0-9068-f236afdf9e0d" />

---

### ✨ Why is it useful?

Raycasting is fast, efficient, and doesn’t require full 3D geometry or heavy graphics engines.  
It’s perfect for simple games where performance and control matter — and a fantastic way to understand the math behind 3D rendering.

> With raycasting, you're not rendering a world — you're calculating one.

---

### 🔧 In cub3D

Raycasting is used to turn a `.cub` map file into a full 3D environment where you can move, rotate, and interact in real time — with nothing but C, math, and the MiniLibX graphics library.

---

## ⚙️ Features - Mandatory

| Feature | Description |
|--------|-------------|
| 🧱 Map Parsing | Parse `.cub` file and validate structure |
| 🎮 Player View | First-person camera with W/A/S/D + arrow keys |
| 🖼️ Texture Support | Load and apply 4 wall textures (N/S/E/W) |
| 🧠 Raycasting | Simulate 3D walls from 2D map using DDA |
| 🖌️ Floor & Ceiling | Different RGB colors for floor and ceiling |
| 🪟 Window Handling | MiniLibX window with proper close handling |
| 🧼 Error Handling | Descriptive errors for malformed files |
| 💾 Memory Safe | No leaks, crashes, or norm errors |

---

## 💎 Bonus Features

If the mandatory part is 100% perfect, bonus is evaluated:

| Bonus | Description |
|-------|-------------|
| 🧱 Wall Collision | Prevent walking through walls |
| 🗺️ Minimap | 2D top-down view of the maze with player view |
| 🚪 Doors | Openable/closable doors with keypress |
| 🌀 Animated Sprites | Moving enemies, items, etc. |
| 🖱️ Mouse Look | Rotate view using mouse movement |
| 🎯 HUD | Add health bar, weapons, shooting system |

> 💡 You can modify the `.cub` format for bonus as long as it’s well explained in README.

---

## 🗺️ The `.cub` File Format
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 02,0,0
C 01,0,0

1111111
1000001
111D111
10N0001
1111111
```

### Elements:
- `NO/SO/WE/EA`: Texture paths
- `F` / `C`: Floor and ceiling colors (RGB)
- Map symbols:
  - `1`: Wall
  - `0`: Floor
  - `D`: Door
  - `N/S/E/W`: Player start position + orientation

Map must be **closed** (no open edges).

---

## 📂 Directory Structure

```bash
cub3d/
├── src/                # All .c files
├── includes/           # .h headers
├── textures/           # .xpm textures
├── maps/               # .cub map files
├── libft/              # Your own libft copy
├── Makefile
└── README.md
```
## 🛠️ Installation

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/samir-ouaammou/3D-Game
   ```

2. Navigate to the project directory:
   ```bash
   cd 3D-Game/Project
   ```

3. Compile the source files using `make`:
   ```bash
   make 
   ```

4. Clean up compiled files:
   ```bash
   make clean
   ```

5. To remove all object files and the executable:
   ```bash
   make fclean
   ```

6. To recompile the project from scratch:
   ```bash
   make re
   ```

7. Run the program:
   ```bash
   ./cub3D
   ```
| Key      | Action        |
| -------- | ------------- |
| W        | Move forward  |
| S        | Move backward |
| A        | Move left     |
| D        | Move right    |
| E        | Open Door    |
| ← / →    | Rotate view   |
| ESC      | Exit          |
| Red \[X] | Close window  |



---

## 🛠️ Tools and Dependencies

- 🖥️ **C (C99)**
- 🎨 **MiniLibX**
- 🧮 **<math.h>**
- 🧰 **valgrind** for memory leaks
- 🧪 **42 Norm** compliant

---

## 📈 What I Learned

- 📊 3D rendering techniques without OpenGL
- 🧠 Raycasting & DDA algorithm
- 🧵 Event-driven programming with MiniLibX
- 📂 File parsing and validation
- 🔥 Manual memory management in C
- 🚪 Map design and file formats

---

### 📚 Recommended Resources

Want to dive deeper? Here are some great resources to understand raycasting better:

- [Lode's Computer Graphics Tutorial](https://www.tldraw.com/p/nrxBdkny-lr8txkRoSnyt?d=v11778.-7245.34934.17485.eLz4W7KpaMOCqJI7W8QwN) – The most famous and beginner-friendly explanation of raycasting.
- [Lode's Computer Graphics Tutorial](https://aaaa.sh/creatures/dda-algorithm-interactive/) – The most famous and beginner-friendly explanation of raycasting.
- [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html) – The most famous and beginner-friendly explanation of raycasting.
- [Lode's Computer Graphics Tutorial](https://en.wikipedia.org/wiki/Ray_casting) – The most famous and beginner-friendly explanation of raycasting.


---

## 🧠 Author

> 👤 **Samir Ouaammou**  
Student at [1337 School – UM6P, 42 Network]  
🖥️ Passionate about low-level programming, graphics, and game dev  
📫 Connect with me on [LinkedIn](https://www.linkedin.com/in/samir-ouaammou-53a1b5333/)

---

Thank you for checking out my cub3D project! Stay tuned for more exciting challenges. 🔥

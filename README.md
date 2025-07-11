## 📖 Introduction

**cub3D** is a raycasting-based 3D maze game inspired by *Wolfenstein 3D*, the first-ever FPS game developed by id Software.  
In this project, I built a 3D view from a 2D map using **MiniLibX**, a tiny graphical library for C.

The goal is to parse a custom `.cub` map file and render a realistic 3D scene from a first-person point of view.

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

**Raycasting** is a rendering technique that simulates a 3D environment using 2D maps.  
In simple words:

> 📌 "Katdir chi camera f wahed lposition f wahed lmap 2D, katrsel rays f kol direction, w kat7seb fin kaytla9aw m3a les murs bach tsawer 3D wall view."

### 🔎 How it works:
- You shoot a **ray for each vertical stripe** of your screen.
- You calculate the **distance to the wall**.
- You draw a vertical line whose height depends on that distance.
- You apply a **texture** depending on wall side (N/S/E/W).
- You repeat this for every column = illusion of 3D.

Raycasting is **fast** and doesn’t require a full 3D engine.

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

## 🧠 Author

> 👤 **Samir Ouaammou**  
Student at [1337 School – UM6P, 42 Network]  
🖥️ Passionate about low-level programming, graphics, and game dev  
📫 Connect with me on [LinkedIn](https://www.linkedin.com/in/samir-ouaammou-53a1b5333/)

---

Thank you for checking out my cub3D project! Stay tuned for more exciting challenges. 🔥

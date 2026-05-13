# 🎮 Galaxy Defender Game (C++ OpenGL/GLUT)

---

# 🧾 Overview

🚀 This is a **2D space shooting game** made in C++ using OpenGL/GLUT.
The player controls a rocket, shoots enemies, and survives as long as possible while increasing score.

---

# ⚙️ Game Setup

* 🖥️ A game window is created using GLUT
* 📏 `SetCanvasSize()` defines screen size
* 🎨 OpenGL handles all drawing (shapes, colors, text)

---

# 🧠 Game Variables

* 🚀 Player position: `rx, ry`
* 👾 Enemies: `ex[], ey[]`
* 🔫 Bullets: arrays for position + active state
* ❤️ Lives: `lives = 3`
* 🧮 Score: `score = 0`
* 🎮 Game states: start, pause, game over

---

# 🖥️ Display Function (Rendering Engine)

🎯 This function draws everything on screen every frame:

## 🎬 Start Screen

* Enter player name 🧑
* Press ENTER to start ⌨️

## 💀 Game Over Screen

* Shows final score 🧮
* Shows player name 🧑
* Stops game

## 🌌 Gameplay Screen

* 🚀 Draws rocket
* 👾 Draws enemies
* 🔫 Draws bullets
* 🌟 Background stars
* ❤️ Shows lives
* 🧮 Shows score

---

# ⌨️ Controls

## 🚀 Movement

* ⬅️ Left arrow → move left
* ➡️ Right arrow → move right

## 🔫 Actions

* SPACE → shoot bullet
* P → pause ⏸️
* R → resume ▶️
* ENTER → start game

---

# ⏱️ Timer Function (Game Engine)

⚡ This is the MOST IMPORTANT part of the game loop.

## 🔫 Bullet System

* Bullets move upward ⬆️
* Deactivate when out of screen

## 👾 Enemy System

* Enemies move downward ⬇️
* Reset position when hit or out of screen

## 💥 Collision Detection

* If bullet touches enemy:

  * 💥 Enemy destroyed
  * 🧮 Score +5
  * 👾 Enemy respawns

## ❤️ Life System

* If enemy reaches bottom:

  * ❤️ Lives decrease

## 🚀 Difficulty Increase

* As score increases:

  * 👾 Enemy speed increases

## 💀 Game Over

* When lives = 0:

  * Game ends
  * Score saved to file 💾 (`data.txt`)

---

# 💾 File Handling

📁 Stores player results:

* Name 🧑
* Score 🧮

Example:

```
Name: Saad | Score: 120
```

---

# 🔁 Game Loop Flow

🚀 The game runs continuously like this:

🖥️ Display → 🎮 Input → ⚡ Timer → 🔁 Repeat

---

# 🧩 Main Function

* Initializes GLUT 🖥️
* Creates window 📦
* Registers functions 🎮
* Starts infinite loop 🔁 (`glutMainLoop()`)

---

# 📌 Summary

🎯 Galaxy Defender is a real-time arcade shooter game where:

* 🚀 Player controls a rocket
* 👾 Enemies fall from top
* 🔫 Player shoots bullets
* 💥 Collision gives score
* ❤️ Lives decrease on miss
* 💀 Game ends at zero lives
* 💾 Score is saved automatically


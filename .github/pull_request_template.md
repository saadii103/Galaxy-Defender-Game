# Galaxy Defender

## Overview
Galaxy Defender is a 2D arcade-style space shooting game developed in C++ using OpenGL/GLUT. The player controls a rocket, shoots enemies, and survives while increasing score.

---

## Features
- Player-controlled spaceship
- Enemy waves with random spawning
- Bullet shooting system
- Collision detection
- Score and lives system
- Pause/Resume functionality
- Name input screen
- Game over screen with score saving

---

## Technologies Used
- C++
- OpenGL
- GLUT
- File Handling (C++)

---

## Controls
- Left Arrow: Move left
- Right Arrow: Move right
- Space: Shoot
- P: Pause game
- R: Resume game
- Enter: Start game
- Esc: Exit

---

## Game Flow
1. Enter player name
2. Start game
3. Shoot enemies and survive
4. Score increases on hits
5. Lose lives if enemies pass bottom
6. Game over when lives reach zero

---

## How to Run (Ubuntu)

### Install dependencies:
```bash
sudo apt-get install freeglut3 freeglut3-dev

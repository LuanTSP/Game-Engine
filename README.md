# Game Engine Project

Welcome to the **Game Project**!

This project is currently **under active development** and in a **very early stage**.  
At the moment, the codebase is still **crude**, experimental, and may change heavily over time.

---

## 🛠 Project Overview

The core idea of this project is to build a **simple 2D game engine** based on **SFML** (Simple and Fast Multimedia Library).  
We are setting up basic systems including:

- **Entity-Component-System (ECS)** architecture (via `EntityManager`)
- **Scene Management** (via `Scene` class)
- **Window and Event Handling** (using SFML)
- **Basic Text Rendering** (centered title on the screen)

The current project already features:

- A basic **Main Menu Scene** that displays centered text.
- Handling for **keyboard input** (e.g., pressing Enter exits the menu).
- A minimal **game loop** structure.

---

## 🚀 Planned Features

Here are some functionalities we expect to add in the future:

- **Scene Switching** (Main Menu → Gameplay → Pause → Game Over)
- **Player movement and controls**
- **Basic collision detection**
- **Simple UI system (buttons, labels, menus)**
- **Audio support** (background music and sound effects)
- **Asset management** (for easier resource loading)
- **Game states and transitions**
- **More advanced EntityComponentSystem features** (e.g., systems that update physics, render, etc.)

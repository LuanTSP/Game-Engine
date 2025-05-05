# Game Engine Project

Welcome to the **Game Engine Project**!

This project is currently **under active development** and in a **very early stage**.  
At the moment, the codebase is still **crude**, experimental, and may change heavily over time.

## 🛠 Project Overview

The core idea of this project is to build a **simple 2D game engine** based on **SFML** (Simple and Fast Multimedia Library).  
We are setting up basic systems including:

### Management

- **Scene Management** (via `Scene` class)
- **Entity Management** (via `EntityManager` class)
- **Resource Management** (via `ResourceManager` class)

### Animatios and Utilities

- **Easy Sprite Animations** (via `AnimatedSpriteComponent` class)
- **Easy Rendering** (via `RenderSystem` class)
- **Easy System Implementations** (via `System` class)
- **Easy event handling** (via `attachTrigger` Scene class method)

## 🚀 Planned Features

Here are some functionalities we expect to add in the future:

- **Scene Switching** (Scene1 -> Scene2 -> Scene3 -> Scene1 -> Scene3 ...)
- **Multiwindow control** (Simple way to switch Scenes from window to window)
- **Physics Engine** (Run simulations with entites)
- **Colision System** (Detect colisions between entities)
- **Simple UI system** (buttons, labels, menus)
- **Audio System** (background music and sound effects)
- **Game class** (Topmost class to run control the game)

# Asteroids

This project is my implementation of the arcade classic *Asteroids*, developed in C++ using the SFML (Simple and Fast Multimedia Library). The goal was to program the fundamental mechanics of a 2D space shooter from scratch.

> Read this in [German](README.de.md).

🕹️ **The Game**

### Gameplay

The player controls a triangular spaceship within a two-dimensional asteroid field. The key features lie in the controls and physics:

* **Wrapping World:** Objects that leave the edge of the screen reappear on the opposite side (Screen Wrapping).
* **Destruction:** Large asteroids break into smaller, faster fragments when hit.

### Controls

* **Spaceship:** `W` (Forward), `A` (Rotate Left), `D` (Rotate Right), and `Spacebar` (Shoot).

---

## 🚀 Download & Website

Want to try the game directly without compiling it yourself? You can find the executable file (.exe / App) and further information on my website:

🔗 Click here for the [Website](https://jjmercado.github.io/portfolioSite/games/asteroids) and Download

---

## 🛠️ Build Instructions (Local Build)

This project uses CMake to manage the build process across different platforms.

### Prerequisites

- A **C++17** capable compiler (GCC, Clang, or MSVC).
- **CMake** (Version 3.10 or higher).
- **SFML 2.6.2** Download binaries for Linux(not via Package Manager) or Windows(An update to the latest SFML version will follow when time permits).

### Step-by-Step

1. **Clone the Repository:**
```bash
git clone https://github.com/jjmercado/Asteroids
cd Asteroids
```

2. **Create a Build Directory:**
```bash
mkdir build
cd build
```

3. **Configure CMake:**
Check if the path to sfml is correct
```bash
cmake .. 
```

4. **Build the Project: Linux**
```bash
cmake --build .
```

4.1 **Build the Project: Windows**
```bash
cmake --build . --config Release
```

5. **Run the Game:**
After the build is complete, you will find the executable file in the `build` folder (or under `build/Debug` / `build/Release` on Windows).

---

## 📜 License & Copyright

The code for this project is licensed under the **MIT License**.

* **Code:** The source code is open for study and use in your own projects under the MIT License.
* **Assets & Content:** All images, videos, and texts are my intellectual property (Copyright) and are **not** covered by the MIT License. Use of these assets is not permitted without explicit permission.
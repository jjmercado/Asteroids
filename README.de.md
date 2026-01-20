# Asteroids

Dieses Projekt ist meine Implementierung des Arcade-Klassikers Asteroids, entwickelt in C++ unter Verwendung der SFML-Bibliothek (Simple and Fast Multimedia Library). Das Ziel war es, die grundlegenden Mechaniken eines 2D-Space-Shooters von Grund auf zu programmieren.

🕹️ Das Spiel

### Das Spielprinzip

Der Spieler steuert ein dreieckiges Raumschiff in einem zweidimensionalen Asteroidenfeld. Die Besonderheit liegt in der Steuerung und der Physik:

- **Wrapping-World:** Objekte, die den Bildschirmrand verlassen, erscheinen auf der gegenüberliegenden Seite wieder (Screen Wrapping).

- **Zerstörung:** Große Asteroiden zerfallen bei Treffern in kleinere, schnellere Fragmente.

### Steuerung

- **Raumschiff**: Taste `W` (vorwärts), `A` (links Rotieren), `D` (rechts Rotieren) und `Leertaste` (schießen)

---

## 🚀 Download & Website

Du möchtest das Spiel direkt ausprobieren, ohne es selbst zu kompilieren? Die ausführbare Datei (.exe / App) sowie weitere Informationen findest du auf meiner Website:

[Website]: https://jjmercado.github.io/portfolioSite/games/asteroids
🔗 Hier geht's zur [Website] und zum Download

---

## 🛠️ Build-Anleitung (Lokal bauen)

Dieses Projekt verwendet CMake, um den Build-Prozess plattformübergreifend zu verwalten.

### Voraussetzungen

- Ein **C++17** fähiger Compiler (GCC, Clang oder MSVC).
- **CMake** (Version 3.10 oder höher).
- **SFML 2.6.2** Download binaries for Linux(not via Package Manager) or Windows, (Update auf die aktuellste SFML-Version folgt, sobald Zeit dafür ist).

### Schritt-für-Schritt

1. **Repository klonen**:

```bash
git clone https://github.com/jjmercado/Asteroids
cd Asteroids
```

2. **Build-Verzeichnis erstellen:**

```bash
mkdir build
cd build
```

3. **CMake konfigurieren:**
Check if the path to sfml is correct
```bash
cmake ..
```

4. **CMake konfigurieren: Linux**

```bash
cmake --build .
```

4.1 **Build the Project: Windows**
```bash
cmake --build . --config Release
```

5. **Spiel starten:**
Nach dem Build findest du die ausführbare Datei im build-Ordner (oder unter build/Debug / build/Release bei Windows).

---

## 📜 Lizenzhinweis & Urheberrecht

Der Code dieser Website steht unter der **MIT Lizenz**.

- **Code:** Der Quellcode dieser Website steht unter der MIT-Lizenz. Du darfst ihn gerne studieren und für eigene Projekte verwenden.

- **Assets & Inhalt:** Alle Bilder, Videos und Texte sind mein geistiges Eigentum (Copyright) und stehen **nicht** unter der MIT-Lizenz. Eine Verwendung dieser Assets ist ohne ausdrückliche Genehmigung nicht gestattet.
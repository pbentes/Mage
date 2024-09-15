[![CodeFactor Grade](https://img.shields.io/codefactor/grade/github/pbentes/Mage)](https://www.codefactor.io/repository/github/pbentes/mage)
[![Static Badge](https://img.shields.io/badge/license-MIT%20Non%20AI-green?color=green)](https://github.com/pbentes/Mage/blob/main/LICENSE)

# Mage

Mage is a game engine built from the ground up to create entirely modable games. To achieve this goal, the editor will be embeded in the game runtime, allowing anyone with a copy of the game to create mods using the same tools used to create the game in the first place.

## Building

### Windows

To build the project on windows using Visual Studio is recommended. Just run:

```ps1
git clone https://github.com/pbentes/Mage.git
cd Mage
cmake -S . -B build
cmake --build build
```

On windows this should create a Visual Studio solution in the build folder you can use to build the project.

I personally use Ninja so I use `cmake -S . -B build -G Ninja` instead.
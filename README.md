[![CodeFactor Grade](https://img.shields.io/codefactor/grade/github/pbentes/Mage)](https://www.codefactor.io/repository/github/pbentes/mage)
[![Static Badge](https://img.shields.io/badge/license-MIT%20Non%20AI-green?color=green)](https://github.com/pbentes/Mage/blob/main/LICENSE)

# Mage

At one point the main goal I had for this engine was making it mod friendly. While I learned a lot doing this I have decided to shift the engine's goal towards supporting an idea for a single game rather than creating a general purpose game engine.

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
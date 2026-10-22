# gifobModding

Mods for Game is Full of Bugs, built on BepInEx 5.

| mod | what |
|---|---|
| wootingRGB | lights your keyboard with the game: an animation per biome, a red flash when you get hit, a white sweep when you reload |
| haptics | haptic feedback, work in progress |

wootingRGB only sends game events. The program that drives the keyboard is coming soon.

## Install

1. Install [BepInEx 5](https://github.com/BepInEx/BepInEx/releases) (x64) into the game folder.
   On Linux (Proton), set the Steam launch option `WINEDLLOVERRIDES="winhttp=n,b" %command%`.
2. Copy the mod's DLL into `BepInEx/plugins/`.

## Build

Needs the .NET SDK and the game installed.

    dotnet build wootingRGB -c Release

If the game is not in the default Steam library, add `-p:GameDir="/path/to/GiFoB_pc"`.
The output folder is set in `Directory.Build.props`.

# BohrdomLoader

A mod loader for Bohrdom that automatically loads mods on startup.
## Installation

1. Download `BohrdomLoader.zip` from the latest release
2. Rename your existing `SDL2_mixer.dll` in the Bohrdom game folder to `SDL2_mixer_original.dll`
   (`C:\Program Files (x86)\Steam\steamapps\common\Bohrdom`)
3. Extract the files from the zip into the game folder
4. Create a `mods` folder in the game directory if it doesn't exist
5. Launch the game normally through Steam

## Installing Mods

Drop any mod `.dll` files into the `mods` folder and launch the game. That's it.

## Creating Mods

Mods are standard x86 Windows DLLs. BohrdomLoader will load any `.dll` placed in the `mods` folder on startup.

Minimal mod template:
```cpp
#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        // your code here
    }
    return TRUE;
}
```

Build as x86 DLL and drop into the `mods` folder.

## Building from Source

Requires Visual Studio with C++ desktop development workload, x86 target.

#include <Windows.h>
#include <shellapi.h>
#include "BohrdomAPI.h"
#include <stdint.h>
#include "pch.h"

typedef int (*SDL_SetRenderDrawColor_t)(void*, uint8_t, uint8_t, uint8_t, uint8_t);
typedef int (*SDL_RenderFillRect_t)(void*, const void*);

SDL_SetRenderDrawColor_t pSDL_SetRenderDrawColor = nullptr;
SDL_RenderFillRect_t pSDL_RenderFillRect = nullptr;

void OnRender(void* renderer) {
    if (pSDL_SetRenderDrawColor && pSDL_RenderFillRect) {
        pSDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        int rect[4] = { 100, 100, 200, 50 };
        pSDL_RenderFillRect(renderer, rect);
    }
}

void OnClick(int x, int y) {
    if (x >= 100 && x <= 300 && y >= 100 && y <= 150) {
        ShellExecuteA(NULL, "open", "https://github.com/SaltSaladd/BohrdomLoader/blob/main/HelloWorld/helloworld.txt", NULL, NULL, SW_SHOW);
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        HMODULE sdl = GetModuleHandleA("SDL2.dll");
        pSDL_SetRenderDrawColor = (SDL_SetRenderDrawColor_t)GetProcAddress(sdl, "SDL_SetRenderDrawColor");
        pSDL_RenderFillRect = (SDL_RenderFillRect_t)GetProcAddress(sdl, "SDL_RenderFillRect");

        RegisterRenderCallback(OnRender);
        RegisterClickCallback(OnClick);
    }
    return TRUE;
}
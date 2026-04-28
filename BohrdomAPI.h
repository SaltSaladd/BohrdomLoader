#pragma once
#include <Windows.h>
#include <stdint.h>

typedef void (*RenderCallback)(void* renderer);
typedef void (*ClickCallback)(int x, int y);
typedef void (*RegisterRenderCallback_t)(RenderCallback);
typedef void (*RegisterClickCallback_t)(ClickCallback);

inline void RegisterRenderCallback(RenderCallback cb) {
    auto fn = (RegisterRenderCallback_t)GetProcAddress(GetModuleHandleA("SDL2_mixer.dll"), "RegisterRenderCallback");
    if (fn) fn(cb);
}

inline void RegisterClickCallback(ClickCallback cb) {
    auto fn = (RegisterClickCallback_t)GetProcAddress(GetModuleHandleA("SDL2_mixer.dll"), "RegisterClickCallback");
    if (fn) fn(cb);
}
#include <Windows.h>
#include <string>
#include <cstdarg>
#include "MinHook.h"
#include <shellapi.h>
#include <vector>
#include "BohrdomAPI.h"

void Log(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);

	vprintf(fmt, args);
	printf("\n");

	va_end(args);
}
#pragma region Proxy
struct SDL2_mixer_dll {
	HMODULE dll;
	FARPROC oMix_AllocateChannels;
	FARPROC oMix_ChannelFinished;
	FARPROC oMix_CloseAudio;
	FARPROC oMix_EachSoundFont;
	FARPROC oMix_ExpireChannel;
	FARPROC oMix_FadeInChannelTimed;
	FARPROC oMix_FadeInMusic;
	FARPROC oMix_FadeInMusicPos;
	FARPROC oMix_FadeOutChannel;
	FARPROC oMix_FadeOutGroup;
	FARPROC oMix_FadeOutMusic;
	FARPROC oMix_FadingChannel;
	FARPROC oMix_FadingMusic;
	FARPROC oMix_FreeChunk;
	FARPROC oMix_FreeMusic;
	FARPROC oMix_GetChunk;
	FARPROC oMix_GetChunkDecoder;
	FARPROC oMix_GetMusicDecoder;
	FARPROC oMix_GetMusicHookData;
	FARPROC oMix_GetMusicType;
	FARPROC oMix_GetNumChunkDecoders;
	FARPROC oMix_GetNumMusicDecoders;
	FARPROC oMix_GetSoundFonts;
	FARPROC oMix_GetSynchroValue;
	FARPROC oMix_GroupAvailable;
	FARPROC oMix_GroupChannel;
	FARPROC oMix_GroupChannels;
	FARPROC oMix_GroupCount;
	FARPROC oMix_GroupNewer;
	FARPROC oMix_GroupOldest;
	FARPROC oMix_HaltChannel;
	FARPROC oMix_HaltGroup;
	FARPROC oMix_HaltMusic;
	FARPROC oMix_HookMusic;
	FARPROC oMix_HookMusicFinished;
	FARPROC oMix_Init;
	FARPROC oMix_Linked_Version;
	FARPROC oMix_LoadMUS;
	FARPROC oMix_LoadMUSType_RW;
	FARPROC oMix_LoadMUS_RW;
	FARPROC oMix_LoadWAV_RW;
	FARPROC oMix_OpenAudio;
	FARPROC oMix_Pause;
	FARPROC oMix_PauseMusic;
	FARPROC oMix_Paused;
	FARPROC oMix_PausedMusic;
	FARPROC oMix_PlayChannelTimed;
	FARPROC oMix_PlayMusic;
	FARPROC oMix_Playing;
	FARPROC oMix_PlayingMusic;
	FARPROC oMix_QuerySpec;
	FARPROC oMix_QuickLoad_RAW;
	FARPROC oMix_QuickLoad_WAV;
	FARPROC oMix_Quit;
	FARPROC oMix_RegisterEffect;
	FARPROC oMix_ReserveChannels;
	FARPROC oMix_Resume;
	FARPROC oMix_ResumeMusic;
	FARPROC oMix_RewindMusic;
	FARPROC oMix_SetDistance;
	FARPROC oMix_SetMusicCMD;
	FARPROC oMix_SetMusicPosition;
	FARPROC oMix_SetPanning;
	FARPROC oMix_SetPosition;
	FARPROC oMix_SetPostMix;
	FARPROC oMix_SetReverseStereo;
	FARPROC oMix_SetSoundFonts;
	FARPROC oMix_SetSynchroValue;
	FARPROC oMix_UnregisterAllEffects;
	FARPROC oMix_UnregisterEffect;
	FARPROC oMix_Volume;
	FARPROC oMix_VolumeChunk;
	FARPROC oMix_VolumeMusic;
} SDL2_mixer;

extern "C" {
	void __declspec(naked) fMix_AllocateChannels() { __asm jmp[SDL2_mixer.oMix_AllocateChannels] }
	void __declspec(naked) fMix_ChannelFinished() { __asm jmp[SDL2_mixer.oMix_ChannelFinished] }
	void __declspec(naked) fMix_CloseAudio() { __asm jmp[SDL2_mixer.oMix_CloseAudio] }
	void __declspec(naked) fMix_EachSoundFont() { __asm jmp[SDL2_mixer.oMix_EachSoundFont] }
	void __declspec(naked) fMix_ExpireChannel() { __asm jmp[SDL2_mixer.oMix_ExpireChannel] }
	void __declspec(naked) fMix_FadeInChannelTimed() { __asm jmp[SDL2_mixer.oMix_FadeInChannelTimed] }
	void __declspec(naked) fMix_FadeInMusic() { __asm jmp[SDL2_mixer.oMix_FadeInMusic] }
	void __declspec(naked) fMix_FadeInMusicPos() { __asm jmp[SDL2_mixer.oMix_FadeInMusicPos] }
	void __declspec(naked) fMix_FadeOutChannel() { __asm jmp[SDL2_mixer.oMix_FadeOutChannel] }
	void __declspec(naked) fMix_FadeOutGroup() { __asm jmp[SDL2_mixer.oMix_FadeOutGroup] }
	void __declspec(naked) fMix_FadeOutMusic() { __asm jmp[SDL2_mixer.oMix_FadeOutMusic] }
	void __declspec(naked) fMix_FadingChannel() { __asm jmp[SDL2_mixer.oMix_FadingChannel] }
	void __declspec(naked) fMix_FadingMusic() { __asm jmp[SDL2_mixer.oMix_FadingMusic] }
	void __declspec(naked) fMix_FreeChunk() { __asm jmp[SDL2_mixer.oMix_FreeChunk] }
	void __declspec(naked) fMix_FreeMusic() { __asm jmp[SDL2_mixer.oMix_FreeMusic] }
	void __declspec(naked) fMix_GetChunk() { __asm jmp[SDL2_mixer.oMix_GetChunk] }
	void __declspec(naked) fMix_GetChunkDecoder() { __asm jmp[SDL2_mixer.oMix_GetChunkDecoder] }
	void __declspec(naked) fMix_GetMusicDecoder() { __asm jmp[SDL2_mixer.oMix_GetMusicDecoder] }
	void __declspec(naked) fMix_GetMusicHookData() { __asm jmp[SDL2_mixer.oMix_GetMusicHookData] }
	void __declspec(naked) fMix_GetMusicType() { __asm jmp[SDL2_mixer.oMix_GetMusicType] }
	void __declspec(naked) fMix_GetNumChunkDecoders() { __asm jmp[SDL2_mixer.oMix_GetNumChunkDecoders] }
	void __declspec(naked) fMix_GetNumMusicDecoders() { __asm jmp[SDL2_mixer.oMix_GetNumMusicDecoders] }
	void __declspec(naked) fMix_GetSoundFonts() { __asm jmp[SDL2_mixer.oMix_GetSoundFonts] }
	void __declspec(naked) fMix_GetSynchroValue() { __asm jmp[SDL2_mixer.oMix_GetSynchroValue] }
	void __declspec(naked) fMix_GroupAvailable() { __asm jmp[SDL2_mixer.oMix_GroupAvailable] }
	void __declspec(naked) fMix_GroupChannel() { __asm jmp[SDL2_mixer.oMix_GroupChannel] }
	void __declspec(naked) fMix_GroupChannels() { __asm jmp[SDL2_mixer.oMix_GroupChannels] }
	void __declspec(naked) fMix_GroupCount() { __asm jmp[SDL2_mixer.oMix_GroupCount] }
	void __declspec(naked) fMix_GroupNewer() { __asm jmp[SDL2_mixer.oMix_GroupNewer] }
	void __declspec(naked) fMix_GroupOldest() { __asm jmp[SDL2_mixer.oMix_GroupOldest] }
	void __declspec(naked) fMix_HaltChannel() { __asm jmp[SDL2_mixer.oMix_HaltChannel] }
	void __declspec(naked) fMix_HaltGroup() { __asm jmp[SDL2_mixer.oMix_HaltGroup] }
	void __declspec(naked) fMix_HaltMusic() { __asm jmp[SDL2_mixer.oMix_HaltMusic] }
	void __declspec(naked) fMix_HookMusic() { __asm jmp[SDL2_mixer.oMix_HookMusic] }
	void __declspec(naked) fMix_HookMusicFinished() { __asm jmp[SDL2_mixer.oMix_HookMusicFinished] }
	void __declspec(naked) fMix_Init() { __asm jmp[SDL2_mixer.oMix_Init] }
	void __declspec(naked) fMix_Linked_Version() { __asm jmp[SDL2_mixer.oMix_Linked_Version] }
	void __declspec(naked) fMix_LoadMUS() { __asm jmp[SDL2_mixer.oMix_LoadMUS] }
	void __declspec(naked) fMix_LoadMUSType_RW() { __asm jmp[SDL2_mixer.oMix_LoadMUSType_RW] }
	void __declspec(naked) fMix_LoadMUS_RW() { __asm jmp[SDL2_mixer.oMix_LoadMUS_RW] }
	void __declspec(naked) fMix_LoadWAV_RW() { __asm jmp[SDL2_mixer.oMix_LoadWAV_RW] }
	void __declspec(naked) fMix_OpenAudio() { __asm jmp[SDL2_mixer.oMix_OpenAudio] }
	void __declspec(naked) fMix_Pause() { __asm jmp[SDL2_mixer.oMix_Pause] }
	void __declspec(naked) fMix_PauseMusic() { __asm jmp[SDL2_mixer.oMix_PauseMusic] }
	void __declspec(naked) fMix_Paused() { __asm jmp[SDL2_mixer.oMix_Paused] }
	void __declspec(naked) fMix_PausedMusic() { __asm jmp[SDL2_mixer.oMix_PausedMusic] }
	void __declspec(naked) fMix_PlayChannelTimed() { __asm jmp[SDL2_mixer.oMix_PlayChannelTimed] }
	void __declspec(naked) fMix_PlayMusic() { __asm jmp[SDL2_mixer.oMix_PlayMusic] }
	void __declspec(naked) fMix_Playing() { __asm jmp[SDL2_mixer.oMix_Playing] }
	void __declspec(naked) fMix_PlayingMusic() { __asm jmp[SDL2_mixer.oMix_PlayingMusic] }
	void __declspec(naked) fMix_QuerySpec() { __asm jmp[SDL2_mixer.oMix_QuerySpec] }
	void __declspec(naked) fMix_QuickLoad_RAW() { __asm jmp[SDL2_mixer.oMix_QuickLoad_RAW] }
	void __declspec(naked) fMix_QuickLoad_WAV() { __asm jmp[SDL2_mixer.oMix_QuickLoad_WAV] }
	void __declspec(naked) fMix_Quit() { __asm jmp[SDL2_mixer.oMix_Quit] }
	void __declspec(naked) fMix_RegisterEffect() { __asm jmp[SDL2_mixer.oMix_RegisterEffect] }
	void __declspec(naked) fMix_ReserveChannels() { __asm jmp[SDL2_mixer.oMix_ReserveChannels] }
	void __declspec(naked) fMix_Resume() { __asm jmp[SDL2_mixer.oMix_Resume] }
	void __declspec(naked) fMix_ResumeMusic() { __asm jmp[SDL2_mixer.oMix_ResumeMusic] }
	void __declspec(naked) fMix_RewindMusic() { __asm jmp[SDL2_mixer.oMix_RewindMusic] }
	void __declspec(naked) fMix_SetDistance() { __asm jmp[SDL2_mixer.oMix_SetDistance] }
	void __declspec(naked) fMix_SetMusicCMD() { __asm jmp[SDL2_mixer.oMix_SetMusicCMD] }
	void __declspec(naked) fMix_SetMusicPosition() { __asm jmp[SDL2_mixer.oMix_SetMusicPosition] }
	void __declspec(naked) fMix_SetPanning() { __asm jmp[SDL2_mixer.oMix_SetPanning] }
	void __declspec(naked) fMix_SetPosition() { __asm jmp[SDL2_mixer.oMix_SetPosition] }
	void __declspec(naked) fMix_SetPostMix() { __asm jmp[SDL2_mixer.oMix_SetPostMix] }
	void __declspec(naked) fMix_SetReverseStereo() { __asm jmp[SDL2_mixer.oMix_SetReverseStereo] }
	void __declspec(naked) fMix_SetSoundFonts() { __asm jmp[SDL2_mixer.oMix_SetSoundFonts] }
	void __declspec(naked) fMix_SetSynchroValue() { __asm jmp[SDL2_mixer.oMix_SetSynchroValue] }
	void __declspec(naked) fMix_UnregisterAllEffects() { __asm jmp[SDL2_mixer.oMix_UnregisterAllEffects] }
	void __declspec(naked) fMix_UnregisterEffect() { __asm jmp[SDL2_mixer.oMix_UnregisterEffect] }
	void __declspec(naked) fMix_Volume() { __asm jmp[SDL2_mixer.oMix_Volume] }
	void __declspec(naked) fMix_VolumeChunk() { __asm jmp[SDL2_mixer.oMix_VolumeChunk] }
	void __declspec(naked) fMix_VolumeMusic() { __asm jmp[SDL2_mixer.oMix_VolumeMusic] }
}

void setupFunctions() {
	SDL2_mixer.oMix_AllocateChannels = GetProcAddress(SDL2_mixer.dll, "Mix_AllocateChannels");
	SDL2_mixer.oMix_ChannelFinished = GetProcAddress(SDL2_mixer.dll, "Mix_ChannelFinished");
	SDL2_mixer.oMix_CloseAudio = GetProcAddress(SDL2_mixer.dll, "Mix_CloseAudio");
	SDL2_mixer.oMix_EachSoundFont = GetProcAddress(SDL2_mixer.dll, "Mix_EachSoundFont");
	SDL2_mixer.oMix_ExpireChannel = GetProcAddress(SDL2_mixer.dll, "Mix_ExpireChannel");
	SDL2_mixer.oMix_FadeInChannelTimed = GetProcAddress(SDL2_mixer.dll, "Mix_FadeInChannelTimed");
	SDL2_mixer.oMix_FadeInMusic = GetProcAddress(SDL2_mixer.dll, "Mix_FadeInMusic");
	SDL2_mixer.oMix_FadeInMusicPos = GetProcAddress(SDL2_mixer.dll, "Mix_FadeInMusicPos");
	SDL2_mixer.oMix_FadeOutChannel = GetProcAddress(SDL2_mixer.dll, "Mix_FadeOutChannel");
	SDL2_mixer.oMix_FadeOutGroup = GetProcAddress(SDL2_mixer.dll, "Mix_FadeOutGroup");
	SDL2_mixer.oMix_FadeOutMusic = GetProcAddress(SDL2_mixer.dll, "Mix_FadeOutMusic");
	SDL2_mixer.oMix_FadingChannel = GetProcAddress(SDL2_mixer.dll, "Mix_FadingChannel");
	SDL2_mixer.oMix_FadingMusic = GetProcAddress(SDL2_mixer.dll, "Mix_FadingMusic");
	SDL2_mixer.oMix_FreeChunk = GetProcAddress(SDL2_mixer.dll, "Mix_FreeChunk");
	SDL2_mixer.oMix_FreeMusic = GetProcAddress(SDL2_mixer.dll, "Mix_FreeMusic");
	SDL2_mixer.oMix_GetChunk = GetProcAddress(SDL2_mixer.dll, "Mix_GetChunk");
	SDL2_mixer.oMix_GetChunkDecoder = GetProcAddress(SDL2_mixer.dll, "Mix_GetChunkDecoder");
	SDL2_mixer.oMix_GetMusicDecoder = GetProcAddress(SDL2_mixer.dll, "Mix_GetMusicDecoder");
	SDL2_mixer.oMix_GetMusicHookData = GetProcAddress(SDL2_mixer.dll, "Mix_GetMusicHookData");
	SDL2_mixer.oMix_GetMusicType = GetProcAddress(SDL2_mixer.dll, "Mix_GetMusicType");
	SDL2_mixer.oMix_GetNumChunkDecoders = GetProcAddress(SDL2_mixer.dll, "Mix_GetNumChunkDecoders");
	SDL2_mixer.oMix_GetNumMusicDecoders = GetProcAddress(SDL2_mixer.dll, "Mix_GetNumMusicDecoders");
	SDL2_mixer.oMix_GetSoundFonts = GetProcAddress(SDL2_mixer.dll, "Mix_GetSoundFonts");
	SDL2_mixer.oMix_GetSynchroValue = GetProcAddress(SDL2_mixer.dll, "Mix_GetSynchroValue");
	SDL2_mixer.oMix_GroupAvailable = GetProcAddress(SDL2_mixer.dll, "Mix_GroupAvailable");
	SDL2_mixer.oMix_GroupChannel = GetProcAddress(SDL2_mixer.dll, "Mix_GroupChannel");
	SDL2_mixer.oMix_GroupChannels = GetProcAddress(SDL2_mixer.dll, "Mix_GroupChannels");
	SDL2_mixer.oMix_GroupCount = GetProcAddress(SDL2_mixer.dll, "Mix_GroupCount");
	SDL2_mixer.oMix_GroupNewer = GetProcAddress(SDL2_mixer.dll, "Mix_GroupNewer");
	SDL2_mixer.oMix_GroupOldest = GetProcAddress(SDL2_mixer.dll, "Mix_GroupOldest");
	SDL2_mixer.oMix_HaltChannel = GetProcAddress(SDL2_mixer.dll, "Mix_HaltChannel");
	SDL2_mixer.oMix_HaltGroup = GetProcAddress(SDL2_mixer.dll, "Mix_HaltGroup");
	SDL2_mixer.oMix_HaltMusic = GetProcAddress(SDL2_mixer.dll, "Mix_HaltMusic");
	SDL2_mixer.oMix_HookMusic = GetProcAddress(SDL2_mixer.dll, "Mix_HookMusic");
	SDL2_mixer.oMix_HookMusicFinished = GetProcAddress(SDL2_mixer.dll, "Mix_HookMusicFinished");
	SDL2_mixer.oMix_Init = GetProcAddress(SDL2_mixer.dll, "Mix_Init");
	SDL2_mixer.oMix_Linked_Version = GetProcAddress(SDL2_mixer.dll, "Mix_Linked_Version");
	SDL2_mixer.oMix_LoadMUS = GetProcAddress(SDL2_mixer.dll, "Mix_LoadMUS");
	SDL2_mixer.oMix_LoadMUSType_RW = GetProcAddress(SDL2_mixer.dll, "Mix_LoadMUSType_RW");
	SDL2_mixer.oMix_LoadMUS_RW = GetProcAddress(SDL2_mixer.dll, "Mix_LoadMUS_RW");
	SDL2_mixer.oMix_LoadWAV_RW = GetProcAddress(SDL2_mixer.dll, "Mix_LoadWAV_RW");
	SDL2_mixer.oMix_OpenAudio = GetProcAddress(SDL2_mixer.dll, "Mix_OpenAudio");
	SDL2_mixer.oMix_Pause = GetProcAddress(SDL2_mixer.dll, "Mix_Pause");
	SDL2_mixer.oMix_PauseMusic = GetProcAddress(SDL2_mixer.dll, "Mix_PauseMusic");
	SDL2_mixer.oMix_Paused = GetProcAddress(SDL2_mixer.dll, "Mix_Paused");
	SDL2_mixer.oMix_PausedMusic = GetProcAddress(SDL2_mixer.dll, "Mix_PausedMusic");
	SDL2_mixer.oMix_PlayChannelTimed = GetProcAddress(SDL2_mixer.dll, "Mix_PlayChannelTimed");
	SDL2_mixer.oMix_PlayMusic = GetProcAddress(SDL2_mixer.dll, "Mix_PlayMusic");
	SDL2_mixer.oMix_Playing = GetProcAddress(SDL2_mixer.dll, "Mix_Playing");
	SDL2_mixer.oMix_PlayingMusic = GetProcAddress(SDL2_mixer.dll, "Mix_PlayingMusic");
	SDL2_mixer.oMix_QuerySpec = GetProcAddress(SDL2_mixer.dll, "Mix_QuerySpec");
	SDL2_mixer.oMix_QuickLoad_RAW = GetProcAddress(SDL2_mixer.dll, "Mix_QuickLoad_RAW");
	SDL2_mixer.oMix_QuickLoad_WAV = GetProcAddress(SDL2_mixer.dll, "Mix_QuickLoad_WAV");
	SDL2_mixer.oMix_Quit = GetProcAddress(SDL2_mixer.dll, "Mix_Quit");
	SDL2_mixer.oMix_RegisterEffect = GetProcAddress(SDL2_mixer.dll, "Mix_RegisterEffect");
	SDL2_mixer.oMix_ReserveChannels = GetProcAddress(SDL2_mixer.dll, "Mix_ReserveChannels");
	SDL2_mixer.oMix_Resume = GetProcAddress(SDL2_mixer.dll, "Mix_Resume");
	SDL2_mixer.oMix_ResumeMusic = GetProcAddress(SDL2_mixer.dll, "Mix_ResumeMusic");
	SDL2_mixer.oMix_RewindMusic = GetProcAddress(SDL2_mixer.dll, "Mix_RewindMusic");
	SDL2_mixer.oMix_SetDistance = GetProcAddress(SDL2_mixer.dll, "Mix_SetDistance");
	SDL2_mixer.oMix_SetMusicCMD = GetProcAddress(SDL2_mixer.dll, "Mix_SetMusicCMD");
	SDL2_mixer.oMix_SetMusicPosition = GetProcAddress(SDL2_mixer.dll, "Mix_SetMusicPosition");
	SDL2_mixer.oMix_SetPanning = GetProcAddress(SDL2_mixer.dll, "Mix_SetPanning");
	SDL2_mixer.oMix_SetPosition = GetProcAddress(SDL2_mixer.dll, "Mix_SetPosition");
	SDL2_mixer.oMix_SetPostMix = GetProcAddress(SDL2_mixer.dll, "Mix_SetPostMix");
	SDL2_mixer.oMix_SetReverseStereo = GetProcAddress(SDL2_mixer.dll, "Mix_SetReverseStereo");
	SDL2_mixer.oMix_SetSoundFonts = GetProcAddress(SDL2_mixer.dll, "Mix_SetSoundFonts");
	SDL2_mixer.oMix_SetSynchroValue = GetProcAddress(SDL2_mixer.dll, "Mix_SetSynchroValue");
	SDL2_mixer.oMix_UnregisterAllEffects = GetProcAddress(SDL2_mixer.dll, "Mix_UnregisterAllEffects");
	SDL2_mixer.oMix_UnregisterEffect = GetProcAddress(SDL2_mixer.dll, "Mix_UnregisterEffect");
	SDL2_mixer.oMix_Volume = GetProcAddress(SDL2_mixer.dll, "Mix_Volume");
	SDL2_mixer.oMix_VolumeChunk = GetProcAddress(SDL2_mixer.dll, "Mix_VolumeChunk");
	SDL2_mixer.oMix_VolumeMusic = GetProcAddress(SDL2_mixer.dll, "Mix_VolumeMusic");
}
#pragma endregion

typedef void (*SDL_RenderPresent_t)(void*);
SDL_RenderPresent_t Original_SDL_RenderPresent = nullptr;

typedef int (*SDL_SetRenderDrawColor_t)(void*, uint8_t, uint8_t, uint8_t, uint8_t);
typedef int (*SDL_RenderFillRect_t)(void*, const void*);

SDL_SetRenderDrawColor_t pSDL_SetRenderDrawColor = nullptr;
SDL_RenderFillRect_t pSDL_RenderFillRect = nullptr;


bool g_showButton = false;
std::vector<RenderCallback> g_renderCallbacks;
std::vector<ClickCallback> g_clickCallbacks;

extern "C" {
	__declspec(dllexport) void RegisterRenderCallback(RenderCallback cb) {
		g_renderCallbacks.push_back(cb);
	}
	__declspec(dllexport) void RegisterClickCallback(ClickCallback cb) {
		g_clickCallbacks.push_back(cb);
	}
}

typedef int (*SDL_PollEvent_t)(void*);
SDL_PollEvent_t Original_SDL_PollEvent = nullptr;

int Hooked_SDL_PollEvent(void* event) {
	int result = Original_SDL_PollEvent(event);
	if (result && event) {
		uint32_t type = *(uint32_t*)event;
		if (type == 0x401) {
			int x = *(int*)((char*)event + 20);
			int y = *(int*)((char*)event + 24);
			for (auto& cb : g_clickCallbacks) cb(x, y);
		}
	}
	return result;
}

void Hooked_SDL_RenderPresent(void* renderer) {
	for (auto& cb : g_renderCallbacks) cb(renderer);
	Original_SDL_RenderPresent(renderer);
}

DWORD WINAPI InputThread(LPVOID) {
	while (true) {
		if (GetAsyncKeyState(VK_F1) & 0x8000) {
			g_showButton = !g_showButton;
			Sleep(300);
		}
		Sleep(10);
	}
}

void SetupHooks() {
	MH_Initialize();
	HMODULE sdl = GetModuleHandleA("SDL2.dll");
	pSDL_SetRenderDrawColor = (SDL_SetRenderDrawColor_t)GetProcAddress(sdl, "SDL_SetRenderDrawColor");
	pSDL_RenderFillRect = (SDL_RenderFillRect_t)GetProcAddress(sdl, "SDL_RenderFillRect");

	void* target = GetProcAddress(sdl, "SDL_RenderPresent");
	MH_CreateHook(target, &Hooked_SDL_RenderPresent, (void**)&Original_SDL_RenderPresent);
	MH_EnableHook(target);

	void* pollTarget = GetProcAddress(sdl, "SDL_PollEvent");
	MH_CreateHook(pollTarget, &Hooked_SDL_PollEvent, (void**)&Original_SDL_PollEvent);
	MH_EnableHook(pollTarget);

	Log("Hooks installed.");
}

void LoadMods(std::string modsPath) {
	WIN32_FIND_DATAA findData;
	HANDLE hFind = FindFirstFileA((modsPath + "*.dll").c_str(), &findData);
	if (hFind == INVALID_HANDLE_VALUE) {
		Log("No mods found at: %s", modsPath.c_str());
		return;
	}
	do {
		std::string modPath = modsPath + findData.cFileName;
		Log("Loading mod: %s", modPath.c_str());
		HMODULE mod = LoadLibraryA(modPath.c_str());
		if (!mod) Log("FAILED to load: %s (err %lu)", modPath.c_str(), GetLastError());
		else Log("Loaded: %s", modPath.c_str());
	} while (FindNextFileA(hFind, &findData));
	FindClose(hFind);
}

DWORD WINAPI HookThread(LPVOID) {
	Sleep(2000);
	SetupHooks();
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH: {
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);
		printf("BohrdomLoader debug console\n");

		char exePath[MAX_PATH];
		GetModuleFileNameA(NULL, exePath, MAX_PATH);
		std::string gamePath(exePath);
		gamePath = gamePath.substr(0, gamePath.find_last_of("\\/"));

		SDL2_mixer.dll = LoadLibraryA((gamePath + "\\SDL2_mixer_original.dll").c_str());
		if (!SDL2_mixer.dll) {
			Log("FAILED to load SDL2_mixer_original.dll (err %lu)", GetLastError());
			return 0;
		}
		Log("Loaded original SDL2_mixer");
		setupFunctions();
		LoadMods(gamePath + "\\mods\\");
		CreateThread(NULL, 0, HookThread, NULL, 0, NULL);
		CreateThread(NULL, 0, InputThread, NULL, 0, NULL);
		break;
	}
	case DLL_PROCESS_DETACH:
		FreeLibrary(SDL2_mixer.dll);
		break;
	}
	return 1;
}
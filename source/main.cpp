#include <stdio.h>
#include <string.h>
#include <3ds.h>

int main(int argc, char** argv)
{
	// Initialize Services
	gfxInitDefault();
	cfguInit();
	
	u8 language = 0;
	
	// Init console's bottom screen for text output	
	consoleInit(GFX_BOTTOM, NULL);
	
	// Read the language field from the config savegame
	CFGU_GetSystemLanguage(&language);
	
	printf("Language Code: %d", (int)language);
	printf("/nPress START to exit");
	
	// Main Loop
	while (aptMainLoop())
	{
		hidScanInput();
		
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // Pressing START exits the append
		
		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}
	
	// Exit Services
	cfguExit();
	gfxExit();
	
	return 0;
}
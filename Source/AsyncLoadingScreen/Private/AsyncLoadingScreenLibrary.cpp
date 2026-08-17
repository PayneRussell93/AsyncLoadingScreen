/************************************************************************************
 *																					*
 * Copyright (C) 2020 Truong Bui.													*
 * Website:	https://github.com/truong-bui/AsyncLoadingScreen						*
 * Licensed under the MIT License. See 'LICENSE' file for full license information. *
 *																					*
 ************************************************************************************/


#include "AsyncLoadingScreenLibrary.h"
#include "AsyncLoadingScreen.h"
#include "MoviePlayer.h"

int32 UAsyncLoadingScreenLibrary::DisplayBackgroundIndex = -1;
int32 UAsyncLoadingScreenLibrary::DisplayTipTextIndex = -1;
int32 UAsyncLoadingScreenLibrary::DisplayMovieIndex = -1;
bool  UAsyncLoadingScreenLibrary::bShowLoadingScreen = true;

void UAsyncLoadingScreenLibrary::SetDisplayBackgroundIndex(int32 BackgroundIndex)
{
	UAsyncLoadingScreenLibrary::DisplayBackgroundIndex = BackgroundIndex;
}

void UAsyncLoadingScreenLibrary::SetDisplayTipTextIndex(int32 TipTextIndex)
{
	UAsyncLoadingScreenLibrary::DisplayTipTextIndex = TipTextIndex;
}

void UAsyncLoadingScreenLibrary::SetDisplayMovieIndex(int32 MovieIndex)
{
	UAsyncLoadingScreenLibrary::DisplayMovieIndex = MovieIndex;	
}

void UAsyncLoadingScreenLibrary::SetEnableLoadingScreen(bool bIsEnableLoadingScreen)
{
	bShowLoadingScreen = bIsEnableLoadingScreen;
}

void UAsyncLoadingScreenLibrary::StopLoadingScreen()
{
	GetMoviePlayer()->StopMovie();
}

void UAsyncLoadingScreenLibrary::PlayStartupLoadingScreenForTesting(float DisplayDurationSeconds)
{
	// IsAvailable rather than Get: Get would load the module on demand, and a call arriving after
	// shutdown has begun would resurrect it just to show a preview into a closing process.
	if (FAsyncLoadingScreenModule::IsAvailable())
	{
		FAsyncLoadingScreenModule::Get().PlayStartupLoadingScreenForTesting(DisplayDurationSeconds);
	}
}


/************************************************************************************
 *																					*
 * Copyright (C) 2020 Truong Bui.													*
 * Website:	https://github.com/truong-bui/AsyncLoadingScreen						*
 * Licensed under the MIT License. See 'LICENSE' file for full license information. *
 *																					*
 ************************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AsyncLoadingScreenLibrary.generated.h"

/**
 * Async Loading Screen Function Library
 */
UCLASS()
class ASYNCLOADINGSCREEN_API UAsyncLoadingScreenLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
private:
	static int32 DisplayBackgroundIndex;
	static int32 DisplayTipTextIndex;
	static int32 DisplayMovieIndex;	
	static bool  bShowLoadingScreen;
public:
	
	/**
	 * Set which background will be displayed on the loading screen by index. The "SetDisplayBackgroundManually" option in Background setting needs to be "true" to use this function.
	 * 
	 * @param BackgroundIndex Valid index of the Background in "Images" array in Background setting. If the index is not valid, then it will display random background instead.
	 **/
	UFUNCTION(BlueprintCallable, Category = "Async Loading Screen")
	static void SetDisplayBackgroundIndex(int32 BackgroundIndex);

	/**
	 * Set which text will be displayed on the loading screen by index. The "SetDisplayTipTextManually" option in Tip Widget setting needs to be "true" to use this function.
	 *
	 * @param TipTextIndex Valid index of the text in "TipText" array in Tip Widget setting. If the index is not valid, then it will display random text instead.
	 **/
	UFUNCTION(BlueprintCallable, Category = "Async Loading Screen")
	static void SetDisplayTipTextIndex(int32 TipTextIndex);

	/**
	 * Set which movie will be displayed on the loading screen by index. The "SetDisplayMovieIndexManually" option needs to be "true" to use this function.
	 *
	 * @param MovieIndex Valid index of the movie in "MoviePaths" array.
	 **/
	UFUNCTION(BlueprintCallable, Category = "Async Loading Screen")
	static void SetDisplayMovieIndex(int32 MovieIndex);


	/**
	 * Set enable/disable the loading screen for next levels
	 *
	 * @param bIsEnableLoadingScreen Should we enable the loading screen for next level?
	 **/
	UFUNCTION(BlueprintCallable, Category = "Async Loading Screen")
	static void SetEnableLoadingScreen(bool bIsEnableLoadingScreen);


	/**
	 * Get enable/disable the loading screen for next levels
	 *
	 **/
	UFUNCTION(BlueprintPure, Category = "Async Loading Screen")
	static inline bool GetIsEnableLoadingScreen() { return bShowLoadingScreen; }

	/**
	 * Stop the loading screen. To use this function, you must enable the "bAllowEngineTick" option.
	 * Call this function in BeginPlay event to stop the Loading Screen (works with Delay node).
	 *
	 **/
	UFUNCTION(BlueprintCallable, Category = "Async Loading Screen")
	static void StopLoadingScreen();

	/**
	 * Replays the Startup Loading Screen so it can be previewed without relaunching the game.
	 *
	 * The startup screen normally only ever shows once, during module startup, which makes iterating
	 * on its layout, tips and timings a relaunch per change. This puts it back on screen using the
	 * same setup path, with the boot-only settings overridden - see
	 * FAsyncLoadingScreenModule::PlayStartupLoadingScreenForTesting for exactly which and why.
	 *
	 * A preview tool, not a gameplay one: nothing is loading behind it, so it closes on a timer
	 * rather than on load completion.
	 *
	 * @param DisplayDurationSeconds How long to leave the screen up before closing it automatically.
	 **/
	UFUNCTION(BlueprintCallable, Category = "Async Loading Screen", meta = (DisplayName = "Play Startup Loading Screen (Testing)", AdvancedDisplay = "DisplayDurationSeconds"))
	static void PlayStartupLoadingScreenForTesting(float DisplayDurationSeconds = 5.0f);

	static inline int32 GetDisplayBackgroundIndex() { return DisplayBackgroundIndex; }
	static inline int32 GetDisplayTipTextIndex() { return DisplayTipTextIndex; }
	static inline int32 GetDisplayMovieIndex() { return DisplayMovieIndex; }

};

// Copyright Epic Games, Inc. All Rights Reserved.


#include "SlateLearn.h"

#include "RequiredProgramMainCPPInclude.h"

#include "Framework/Application/SlateApplication.h"
#include "StandaloneRenderer.h"

#include "SMyButton.h"
#include "SMyCanvas.h"
#include "MyEditor.h"
#include "SMyLeafWidget.h"


DEFINE_LOG_CATEGORY_STATIC(LogSlateLearn, Log, All);

IMPLEMENT_APPLICATION(SlateLearn, "SlateLearn");


INT32_MAIN_INT32_ARGC_TCHAR_ARGV()
{
	GEngineLoop.PreInit(GetCommandLineW());
	// GEngineLoop.PreInit(ArgC, ArgV);
	
	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());

	/*----------------------------------------------------------*/
	//这是一段简单的生成自定义LeafWidget的方式
	

	//TSharedPtr<SMyLeafWidget> MyLeafWidget = SNew(SMyLeafWidget)
	//	.StartPoint(FVector2d(100,100))
	//	.EndPoint(FVector2d(500,500));

	////创建一个窗口
	//TSharedPtr<SWindow> MainWindow = SNew(SWindow)
	//	.ClientSize(FVector2D(800, 600))
	//	[
	//		// SNullWidget::NullWidget
	//		MyLeafWidget.ToSharedRef()

	//	];


	//FSlateApplication::Get().AddWindow(MainWindow.ToSharedRef());


	/*----------------------------------------------------------*/
	//这是一段简单的生成一个Canvas的方式
	TSharedPtr<SMyCanvas> MyCanvas01 = SNew(SMyCanvas);

	//创建一个窗口
	TSharedPtr<SWindow> MainWindow = SNew(SWindow)
		.ClientSize(FVector2D(800, 600))
		[
			// SNullWidget::NullWidget
			MyCanvas01.ToSharedRef()

		];

	FSlateApplication::Get().AddWindow(MainWindow.ToSharedRef());


	/*----------------------------------------------------------*/
	//使用自定义的Editor类
	//MyEditor Editor = MyEditor();


	// loop while the server does the rest
	while (!IsEngineExitRequested())
	{
		FSlateApplication::Get().PumpMessages();
		FSlateApplication::Get().Tick();
	}
	FSlateApplication::Shutdown();
	return 0;
}




// int WINAPI WinMain( _In_ HINSTANCE hInInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR, _In_ int nCmdShow )
// {
// 	
// 	// start up the main loop
// 	GEngineLoop.PreInit(GetCommandLineW());
//
// 	// crank up a normal Slate application using the platform's standalone renderer
// 	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());
// 	
// 	// loop while the server does the rest
// 	while (!IsEngineExitRequested())
// 	{
// 		BeginExitIfRequested();
//
// 		// FTaskGraphInterface::Get().ProcessThreadUntilIdle(ENamedThreads::GameThread);
// 		// FStats::AdvanceFrame(false);
// 		// FTSTicker::GetCoreTicker().Tick(FApp::GetDeltaTime());
// 		FSlateApplication::Get().PumpMessages();
// 		FSlateApplication::Get().Tick();		
// 		// FPlatformProcess::Sleep(0.01);
// 	
// 		// GFrameCounter++;
// 	}
//
// 	// FCoreDelegates::OnExit.Broadcast();
// 	FSlateApplication::Shutdown();
// 	// FModuleManager::Get().UnloadModulesAtShutdown();
//
// 	GEngineLoop.AppPreExit();
// 	GEngineLoop.AppExit();
// 	return 0;
// }


// INT32_MAIN_INT32_ARGC_TCHAR_ARGV()
// {
// 	GEngineLoop.PreInit(ArgC, ArgV);
//
// 	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());
// 	FSlateApplication::InitHighDPI(true);
//
// 	const TSharedPtr<SWindow> MainWindow = SNew(SWindow).ClientSize(FVector2D(800, 600));
//
// 	FSlateApplication::Get().AddWindow(MainWindow.ToSharedRef());
//
// 	while (!IsEngineExitRequested())
// 	{
// 		BeginExitIfRequested();
// 		FSlateApplication::Get().PumpMessages();
// 		FSlateApplication::Get().Tick();
// 	}
// 	
// 	FEngineLoop::AppExit();
// 	return 0;
// }

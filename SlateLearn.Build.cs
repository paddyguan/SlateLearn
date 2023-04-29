// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SlateLearn : ModuleRules
{
	public SlateLearn(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicIncludePaths.Add("Runtime/Launch/Public");

		PrivateIncludePaths.Add("Runtime/Launch/Private");		// For LaunchEngineLoop.cpp include

		// PrivateDependencyModuleNames.Add("Core");
		// PrivateDependencyModuleNames.Add("Projects");
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"AppFramework",
			"Core",
			"ApplicationCore",
			"Projects",
			"Slate",
			"SlateCore",
			"StandaloneRenderer",
			"SourceCodeAccess",
			"WebBrowser",
		});
		
		PrivateIncludePathModuleNames.AddRange(
			new string[] {
				"SlateReflector",
			}
		);
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
				"SlateReflector",
			}
		);
		
	}
}

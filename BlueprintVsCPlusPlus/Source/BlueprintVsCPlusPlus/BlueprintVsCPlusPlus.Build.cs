// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BlueprintVsCPlusPlus : ModuleRules
{
	public BlueprintVsCPlusPlus(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"BlueprintVsCPlusPlus",
			"BlueprintVsCPlusPlus/Variant_Platforming",
			"BlueprintVsCPlusPlus/Variant_Platforming/Animation",
			"BlueprintVsCPlusPlus/Variant_Combat",
			"BlueprintVsCPlusPlus/Variant_Combat/AI",
			"BlueprintVsCPlusPlus/Variant_Combat/Animation",
			"BlueprintVsCPlusPlus/Variant_Combat/Gameplay",
			"BlueprintVsCPlusPlus/Variant_Combat/Interfaces",
			"BlueprintVsCPlusPlus/Variant_Combat/UI",
			"BlueprintVsCPlusPlus/Variant_SideScrolling",
			"BlueprintVsCPlusPlus/Variant_SideScrolling/AI",
			"BlueprintVsCPlusPlus/Variant_SideScrolling/Gameplay",
			"BlueprintVsCPlusPlus/Variant_SideScrolling/Interfaces",
			"BlueprintVsCPlusPlus/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

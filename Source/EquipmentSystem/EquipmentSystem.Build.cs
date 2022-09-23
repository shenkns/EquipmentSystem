// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

using UnrealBuildTool;

public class EquipmentSystem : ModuleRules
{
	public EquipmentSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.AddRange(
			new string[]
			{
				"EquipmentSystem/Public/"
			}
		);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core"
			}
		);
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"ProfileSystem"
			}
		);
		
		PublicIncludePathModuleNames.AddRange(
			new string[]
			{
				"ProfileSystem"
			}
		);
	}
}

// Copyright Gavin Irby 2021. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class JoustTarget : TargetRules
{
	public JoustTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Joust" } );
	}
}

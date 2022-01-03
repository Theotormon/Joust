// Copyright Gavin Irby 2021. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class JoustEditorTarget : TargetRules
{
	public JoustEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Joust" } );
	}
}

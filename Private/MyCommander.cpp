#include "MyCommander.h"

#define LOCTEXT_NAMESPACE "MyCommander"

FMyCommander::FMyCommander()
	:TCommands<FMyCommander>(
		TEXT("MyEditor"), // Context name for fast lookup
		NSLOCTEXT("Contexts", "MyEditor", "My Editor"), // Localized context name for displaying
		NAME_None, // Parent
		FCoreStyle::Get().GetStyleSetName() // Icon Style Set
		)
{

}

void FMyCommander::RegisterCommands()
{
	UI_COMMAND(OpenFileCommand, "OpenFile", "OpenFile", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control,EKeys::O));
	UI_COMMAND(CloseFileCommand, "CloseFile", "CloseFile", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control, EKeys::C));
	UI_COMMAND(SaveFileCommand, "SaveFile", "SaveFile", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control, EKeys::S));
}

#undef LOCTEXT_NAMESPACE
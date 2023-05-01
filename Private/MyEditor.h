#pragma once

#include "CoreMinimal.h"

class MyEditor
{
public:
	MyEditor();

	TSharedRef<SWidget> MakeMenuBar();
	TSharedRef<SWidget> MakeToolBar();

	TSharedPtr<FUICommandList> CommanderList;

	TSharedPtr<SEditableText> EditableText;
};
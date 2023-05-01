#pragma once

#include "Framework/Commands/Commands.h"

class FMyCommander : public TCommands< FMyCommander>
{
public:
	FMyCommander();

	virtual void RegisterCommands() override;

	TSharedPtr<FUICommandInfo> OpenFileCommand;
	TSharedPtr<FUICommandInfo> CloseFileCommand;
	TSharedPtr<FUICommandInfo> SaveFileCommand;
};
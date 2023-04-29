#pragma once
#include "Widgets/SCanvas.h"

class SMyCanvas : public SCanvas
{
public:
	void Construct( const FArguments& InArgs );

	TArray<TSharedPtr<FString>> Options;

	int32 CurrentSelected = -1;
};

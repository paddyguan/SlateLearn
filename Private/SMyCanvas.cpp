#include "SMyCanvas.h"

#include "SMyButton.h"
#include "Widgets/Input/SComboBox.h"


void SMyCanvas::Construct(const FArguments& InArgs)
{
	SCanvas::Construct(InArgs);

	AddSlot()
	.Position(FVector2d(100,100))
	.Size(FVector2d(100,40))
	[
		SNew(SMyButton)
	];

	AddSlot()
	.Position(FVector2d(300,100))
	.Size(FVector2d(100,40))
	[
		SNew(SMyButton)
	];

	Options.Empty();
	Options.Add(MakeShareable(new FString("Apple1")));
	Options.Add(MakeShareable(new FString("Apple2")));
	Options.Add(MakeShareable(new FString("Apple3")));
	
	AddSlot()
	.Position(FVector2d(500,100))
	.Size(FVector2d(100,40))
	[
		SNew(SComboBox<TSharedPtr<FString>>)
		.OptionsSource(&Options)
		.OnGenerateWidget_Lambda([](TSharedPtr<FString> InValue)
			{
				return SNew(STextBlock).Text(FText::FromString(*InValue));
			})
			.OnSelectionChanged_Lambda([this](TSharedPtr<FString> NewOption,ESelectInfo::Type SelectTYpe)
			{
				CurrentSelected = Options.Find(NewOption);
			})
		[
			SNew(STextBlock).Text_Lambda([this]()
			{
				if(CurrentSelected<0 || CurrentSelected>Options.Num()-1)
				{
					return FText::FromString("");
				}
				else
				{
					return FText::FromString(*Options[CurrentSelected]);
				}
			})
		]
	];

	AddSlot()
	.Position(FVector2d(100,300))
	.Size(FVector2d(400,80))
	[
		SNew(SHorizontalBox)
		+SHorizontalBox::Slot()
		[
			SNew(SButton)	
		]
		+SHorizontalBox::Slot()
		[
			SNew(SButton)	
		]
		+SHorizontalBox::Slot()
		[
			SNew(SButton)	
		]
	];
	
}

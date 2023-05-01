#include "SMyCanvas.h"

#include "SMyButton.h"
#include "SMyTreeView.h"
#include "SMyListView.h"

#include "Widgets/Input/SComboBox.h"


void SMyCanvas::Construct(const FArguments& InArgs)
{
	SCanvas::Construct(InArgs);

	//添加自定义的按钮，定死位置显示
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

	//添加选项列表
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

	//添加自动水平布局
	AddSlot()
	.Position(FVector2d(100,300))
	.Size(FVector2d(300,80))
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

	//添加自动垂直布局
	AddSlot()
	.Position(FVector2d(100,400))
	.Size(FVector2d(100,200))
	[
		SNew(SVerticalBox)
		+SVerticalBox::Slot()
		[
			SNew(SButton)
		]
		+SVerticalBox::Slot()
		[
			SNew(SButton)
		]
		+SVerticalBox::Slot()
		[
			SNew(SButton)
		]
	];

	//添加树形图
	AddSlot()
	.Position(FVector2d(500,300))
	.Size(FVector2d(200,100))
	[
		SNew(SMyTreeView)
	];

	//添加列表型图
	AddSlot()
	.Position(FVector2d(500, 400))
	.Size(FVector2d(100, 100))
	[
		SNew(SMyListView)
	];

	//添加图片
	AddSlot()
	.Position(FVector2d(500, 500))
	.Size(FVector2d(100, 100))
	[
		SNew(SImage)
		.Image(FCoreStyle::Get().GetBrush("TrashCan"))
	];


	//添加GridPanle布局
	AddSlot()
	.Position(FVector2d(500, 600))
	.Size(FVector2d(100, 100))
	[
		SNew(SGridPanel)
		.FillColumn(0,1)
		.FillColumn(1,1)
		.FillRow(0,1)
		.FillRow(1,1)
		+SGridPanel::Slot(0,0)
		[
			SNew(STextBlock)
			.Text(FText::FromString("[0,0]"))
		]
		+ SGridPanel::Slot(0, 1)
		[
			SNew(STextBlock)
			.Text(FText::FromString("[0,1]"))
		]
		+ SGridPanel::Slot(1, 0)
		[
			SNew(STextBlock)
			.Text(FText::FromString("[1, 0]"))
		]
		+ SGridPanel::Slot(1, 1)
		[
			SNew(STextBlock)
			.Text(FText::FromString("[1, 1]"))
		]

	];
}

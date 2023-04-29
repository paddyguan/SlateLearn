#include "SMyTreeView.h"

void SMyTreeView::Construct(const FArguments& InArgs)
{
	FArguments Arguments = InArgs;

	//

	TSharedPtr<UTreeItemData> Data01 = MakeShareable(NewObject<UTreeItemData>());
	Data01->MyName = FString("Data01");
	TSharedPtr<UTreeItemData> Data011 = MakeShareable(NewObject<UTreeItemData>());
	Data011->MyName = FString("Data011");
	TSharedPtr<UTreeItemData> Data012 = MakeShareable(NewObject<UTreeItemData>());
	Data012->MyName = FString("Data012");

	Data01->Children.Add(Data011);
	Data01->Children.Add(Data012);

	TSharedPtr<UTreeItemData> Data02 = MakeShareable(NewObject<UTreeItemData>());
	Data02->MyName = FString("Data02");
	TSharedPtr<UTreeItemData> Data021 = MakeShareable(NewObject<UTreeItemData>());
	Data021->MyName = FString("Data021");
	TSharedPtr<UTreeItemData> Data022 = MakeShareable(NewObject<UTreeItemData>());
	Data022->MyName = FString("Data022");
	TSharedPtr<UTreeItemData> Data023 = MakeShareable(NewObject<UTreeItemData>());
	Data022->MyName = FString("Data023");

	Data02->Children.Add(Data021);
	Data02->Children.Add(Data022);
	Data02->Children.Add(Data023);

	
	TreeItemDatas.Add(Data01);
	TreeItemDatas.Add(Data02);
	
	Arguments.TreeItemsSource(&TreeItemDatas);
	Arguments.OnGenerateRow_Raw(this,&SMyTreeView::GenerateRowItem);
	Arguments.OnGetChildren_Raw(this,&SMyTreeView::GetChildrenForItem);

	//
	
	STreeView::Construct(Arguments);
}


TSharedRef<ITableRow> SMyTreeView::GenerateRowItem(TSharedPtr<UTreeItemData> InTreeItemData,
	const TSharedRef<STableViewBase>& OwnerTable)
{
	return SNew(STableRow<TSharedPtr<UTreeItemData>>,OwnerTable)
	[
		SNew(STextBlock)
		.Text(FText::FromString(InTreeItemData->MyName))
	];
}

void SMyTreeView::GetChildrenForItem(TSharedPtr<UTreeItemData> InTreeItemData, TArray<TSharedPtr<UTreeItemData>>& OutChildren)
{
	OutChildren = InTreeItemData->Children;
}

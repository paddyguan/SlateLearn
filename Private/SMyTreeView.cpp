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
	
	TreeItemDatas.Add(Data01);
	
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

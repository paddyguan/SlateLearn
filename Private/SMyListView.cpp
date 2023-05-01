#include "SMyListView.h"

void SMyListView::Construct(const FArguments& InArgs)
{
	FArguments Arguments = InArgs;

	TSharedPtr<UListViewItemData> Data01 = MakeShareable(NewObject<UListViewItemData>());
	Data01->ListItemName = FString("Data01");
	TSharedPtr<UListViewItemData> Data02 = MakeShareable(NewObject<UListViewItemData>());
	Data02->ListItemName = FString("Data02");

	ListItemDataArray.Add(Data01);
	ListItemDataArray.Add(Data02);

	Arguments.ListItemsSource(&ListItemDataArray);

	Arguments.OnGenerateRow(this, &SMyListView::GenerateRowItem);

	SListView::Construct(Arguments);
}

TSharedRef<ITableRow> SMyListView::GenerateRowItem(TSharedPtr<UListViewItemData> InListItemData, const TSharedRef<STableViewBase>& OwnerTable)
{
	return SNew(STableRow<TSharedPtr<UListViewItemData>>, OwnerTable)
		[
			SNew(STextBlock)
			.Text(FText::FromString(InListItemData->ListItemName))
		];
}



#pragma once

#include "Widgets/Views/SListView.h"
#include "CoreMinimal.h"

#include "SMyListView.generated.h"

UCLASS()
class UListViewItemData : public UObject
{
	GENERATED_BODY()

public:
	FString ListItemName;


};

class SMyListView : public SListView< TSharedPtr< UListViewItemData>>
{
public:
	void Construct(const FArguments& InArgs);

	TArray<TSharedPtr< UListViewItemData>> ListItemDataArray;

	TSharedRef<ITableRow> GenerateRowItem(TSharedPtr<UListViewItemData> InListItemData, const TSharedRef<STableViewBase>& OwnerTable);


};

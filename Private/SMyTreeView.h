#pragma once

#include "Widgets/Views/STreeView.h"
#include "CoreMinimal.h"

#include "SMyTreeView.generated.h"

UCLASS()
class UTreeItemData : public UObject
{
	GENERATED_BODY()

public:
	FString MyName;
	float MyHeight;

	TArray<TSharedPtr<UTreeItemData>> Children;
	
};


class SMyTreeView : public STreeView<TSharedPtr<UTreeItemData>>
{
public:
	void Construct( const FArguments& InArgs );

	TArray<TSharedPtr<UTreeItemData>> TreeItemDatas;
	TSharedRef<ITableRow> GenerateRowItem(TSharedPtr<UTreeItemData> InTreeItemData,const TSharedRef<STableViewBase>& OwnerTable);

	void GetChildrenForItem(TSharedPtr<UTreeItemData> InTreeItemData,TArray<TSharedPtr<UTreeItemData>>& OutChildren);
};

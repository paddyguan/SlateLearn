#pragma once

#include "CoreMinimal.h"
#include "Widgets/SLeafWidget.h"


class SMyLeafWidget : public SLeafWidget
{
	//SLATE_DECLARE_WIDGET(SMyLeafWidget, SLeafWidget)

public:
	//参数定义
	SLATE_BEGIN_ARGS(SMyLeafWidget)
		//参数默认值设置
		:_StartPoint(FVector2d(0,0))
		,_EndPoint(FVector2d(100, 100))
	{

	}
	//参数声明
	SLATE_ATTRIBUTE(FVector2d,StartPoint)
	SLATE_ATTRIBUTE(FVector2d, EndPoint)

	SLATE_END_ARGS()

	/**
	 * Construct this widget
	 *
	 * @param	InArgs	The declaration data for this widget
	 */
	void Construct(const FArguments& InArgs);

private:
	// SWidget interface
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FVector2D ComputeDesiredSize(float) const override;

	TArray<FVector2d> Points;
};
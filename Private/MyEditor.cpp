#include "MyEditor.h"
#include "MyCommander.h"
#include "Styling/CoreStyle.h"
#include "SMyCanvas.h"

#define LOCTEXT_NAMESPACE "MyEditor"

MyEditor::MyEditor()
{
	//使用TabManager构建界面

	//注册命令
	FMyCommander::Register();
	//添加命令列表
	CommanderList = MakeShareable(new FUICommandList);
	CommanderList->MapAction(FMyCommander::Get().OpenFileCommand,
		FExecuteAction::CreateLambda([]() {
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("OpenFileCommand is Clicked"));
			})
		);
	CommanderList->MapAction(FMyCommander::Get().CloseFileCommand,
		FExecuteAction::CreateLambda([]() {
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("CloseFileCommand is Clicked"));
			})
	);
	CommanderList->MapAction(FMyCommander::Get().SaveFileCommand,
		FExecuteAction::CreateLambda([]() {
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("SaveFileCommand is Clicked"));
			})
	);


	TArray<FName> TabName = { "LeftTab","RightTab","RightBottomTab" };

	//TSharedPtr<SMyCanvas> MyCanvas01 = SNew(SMyCanvas);


	/*---------------------------------------*/
	//tab1
	static FSlateColorBrush ColorBrush = FSlateColorBrush(FLinearColor(1.f, 1.f, 1.f));
	FGlobalTabmanager::Get()->RegisterTabSpawner(TabName[0], FOnSpawnTab::CreateLambda(
		[&](const FSpawnTabArgs& Args)->TSharedRef<SDockTab> {
			return SNew(SDockTab)
				[
					SNew(SVerticalBox)
						+SVerticalBox::Slot()
						.AutoHeight()
						[
							//放置菜单
							MakeMenuBar()
						]
						//添加工具栏
						+SVerticalBox::Slot()
						.AutoHeight()
						[
							//放置工具条
							MakeToolBar()
						]
						+SVerticalBox::Slot()
						.FillHeight(1.f)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							[
								SNew(SBorder)
								//颜色填充
								.BorderImage(&ColorBrush)
							]
							+ SVerticalBox::Slot()
							[
								SNew(SBorder)
								//图片填充
								.BorderImage(FCoreStyle::Get().GetBrush("Icons/TrashCan"))
							]
							+ SVerticalBox::Slot()
							[
								SNew(SBorder)
								.BorderImage(FCoreStyle::Get().GetBrush("Debug.Border"))
								
							]


							//MyCanvas01.ToSharedRef()
							//SNew(SButton)
							//.Text(FText::FromName(TabName[0]))
						]

				];
		}
	));


	/*---------------------------------------*/
	//tab2
	//TSharedPtr<SScrollBar> HorizontalScroolBar;
	//TSharedPtr<SScrollBar> VerticalScroolBar;
	FGlobalTabmanager::Get()->RegisterTabSpawner(TabName[1], FOnSpawnTab::CreateLambda(
		[&](const FSpawnTabArgs& Args)->TSharedRef<SDockTab> {
			return SNew(SDockTab)
				[
					SNew(SVerticalBox)
					+SVerticalBox::Slot()
					[
						SAssignNew(EditableText, SEditableText)
					]
					+ SVerticalBox::Slot()
					[
						SNew(SButton)
						.Text(FText::FromName(TabName[1]))
						.OnClicked_Lambda(
							[this]() {
								FMessageDialog::Open(EAppMsgType::Ok, EditableText->GetText());
								return FReply::Handled();
							}
						)
					]

				];
		}
	));

	/*---------------------------------------*/
	//tab3
	FGlobalTabmanager::Get()->RegisterTabSpawner(TabName[2], FOnSpawnTab::CreateLambda(
		[&](const FSpawnTabArgs& Args)->TSharedRef<SDockTab> {
			return SNew(SDockTab)
				[
					//切分
					SNew(SSplitter)
					+SSplitter::Slot()
					//默认的切分占比权重
					.Value(2.f)
					[
						//添加叠加层，覆盖关系
						SNew(SOverlay)
						+SOverlay::Slot()
						[
							SNew(SBorder)
							[
								SNew(STextBlock)
								.Text(FText::FromString("1-Layer"))
							]
						]
						+ SOverlay::Slot()
						[
							SNew(SBorder)
							[
								SNew(STextBlock)
								.Text(FText::FromString("2-Layer"))
							]
						]
						+ SOverlay::Slot()
						[
							SNew(SBorder)
							[
								SNew(STextBlock)
								.Text(FText::FromString("3-Layer"))
							]
						]
					]
					+ SSplitter::Slot()
					.Value(1.f)
					[
						SNew(SButton)
						.Text(FText::FromName(TabName[2]))
					]
				];
		}
	));

	//Tab的布局
	const TSharedRef<FTabManager::FLayout> Layout1 = FTabManager::NewLayout(TEXT("Layout1"))
		->AddArea(
			FTabManager::NewArea(800, 600)
			->SetOrientation(EOrientation::Orient_Horizontal)
			->Split(
				FTabManager::NewStack()
				->AddTab(TabName[0], ETabState::OpenedTab)
			)
			->Split(
				FTabManager::NewSplitter()
				->SetOrientation(EOrientation::Orient_Vertical)
				->Split(
					FTabManager::NewStack()
					->AddTab(TabName[1], ETabState::OpenedTab)
				)
				->Split(
					FTabManager::NewStack()
					->AddTab(TabName[2], ETabState::OpenedTab)
				)
			)
		);

	FGlobalTabmanager::Get()->RestoreFrom(Layout1, TSharedPtr<SWindow>());

}

TSharedRef<SWidget> MyEditor::MakeMenuBar()
{
	FMenuBarBuilder MenuBuilder(CommanderList);

	MenuBuilder.AddPullDownMenu(
		LOCTEXT("MyMenu", "MyMenu"),
		LOCTEXT("MyMenu", "MyMenu"),
		FNewMenuDelegate::CreateLambda(
			[](FMenuBuilder& MenuBuilder) {
				MenuBuilder.AddMenuEntry(FMyCommander::Get().OpenFileCommand);
				MenuBuilder.AddMenuEntry(FMyCommander::Get().CloseFileCommand);
				MenuBuilder.AddMenuEntry(FMyCommander::Get().SaveFileCommand);
			}
		));

	return MenuBuilder.MakeWidget();
}

TSharedRef<SWidget> MyEditor::MakeToolBar()
{
	FToolBarBuilder ToolBarBuilder(CommanderList, FMultiBoxCustomization::None);
	ToolBarBuilder.BeginSection("My Section");

	ToolBarBuilder.AddToolBarButton(FMyCommander::Get().OpenFileCommand);
	ToolBarBuilder.AddToolBarButton(FMyCommander::Get().CloseFileCommand);
	ToolBarBuilder.AddToolBarButton(FMyCommander::Get().SaveFileCommand);

	ToolBarBuilder.EndSection();

	return ToolBarBuilder.MakeWidget();
}


#undef LOCTEXT_NAMESPACE

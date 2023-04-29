#include "SMyButton.h"

#include "Misc/MessageDialog.h"


void SMyButton::Construct(const FArguments& InArgs)
{
	SButton::Construct(InArgs);

	this->SetOnClicked(FOnClicked::CreateRaw(this,&SMyButton::ButtonClicked));
}

FReply SMyButton::ButtonClicked()
{
	FMessageDialog::Open(EAppMsgType::Ok,FText::FromString("Button is Clicked"));
	return  FReply::Handled();
}
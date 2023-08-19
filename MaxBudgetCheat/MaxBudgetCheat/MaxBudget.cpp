#include "stdafx.h"
#include "MaxBudget.h"

MaxBudget::MaxBudget()
{
}


MaxBudget::~MaxBudget()
{
}


void MaxBudget::ParseLine(const ArgScript::Line& line)
{
	//The cheat will only work if the user is currently in an editor
	if (Editor.IsActive()) {
		Editor.mpEditorLimits->AddValue(Editor.mpEditorLimits->kBudget, MAXIMUM_ALLOWED);
	}
	else {
		//If the user isn't in an editor, but they use the cheat, it will print this text line to the cheat console
		App::ConsolePrintF("Enter an editor to use this cheat.");
	}
}

const char* MaxBudget::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Increase the current editor's budget to the maximum.";
	}
	else {
		return "MaxBudget: Increase the current editor's budget to the maximum.";
	}
}

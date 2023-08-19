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
	if (Editor.IsActive()) {
		Editor.mpEditorLimits->AddValue(Editor.mpEditorLimits->kBudget, MAXIMUM_ALLOWED);
	}
	else {
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

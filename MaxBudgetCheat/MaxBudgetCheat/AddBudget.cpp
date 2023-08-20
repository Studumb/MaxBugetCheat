#include "stdafx.h"
#include "AddBudget.h"

AddBudget::AddBudget()
{
}


AddBudget::~AddBudget()
{
}


void AddBudget::ParseLine(const ArgScript::Line& line)
{
	size_t argPos;
	auto arg = line.GetArgumentsRange(&argPos, 0, 1);
	if (Editor.IsActive()) {
		if (argPos == 1) {
			if (mpFormatParser->ParseInt(arg[0]) > 0) {
				Editor.mpEditorLimits->AddValue(Editor.mpEditorLimits->kBudget, mpFormatParser->ParseInt(arg[0]));
			}
			else {
				App::ConsolePrintF("The number entered must be larger than 0.");
			}
		}
		else {
			Editor.mpEditorLimits->AddValue(Editor.mpEditorLimits->kBudget, 150);
		}
	}
	else {
		App::ConsolePrintF("Enter an editor to use this cheat.");
	}
}

const char* AddBudget::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Add an amount of budget like what you want";
	}
	else {
		return "addBudget: Add an amount of budget like what you want.\n                addBudget <amount of budget>\n                Ex: addBudget 150";
	}
}

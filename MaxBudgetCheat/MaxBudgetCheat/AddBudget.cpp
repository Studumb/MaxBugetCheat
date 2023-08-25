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
	//We have to make sure that the user uses the cheat in an editor
	if (Editor.IsActive()) {
		//If the user enter the argument for the cheat
		if (argPos == 1) {
			//Ensure that the value is not smaller than 0
			if (mpFormatParser->ParseInt(arg[0]) > 0) {
				Editor.mpEditorLimits->AddValue(Editor.mpEditorLimits->kBudget, mpFormatParser->ParseInt(arg[0]));
			}
			else {
				App::ConsolePrintF("The number entered must be larger than 0.");
			}
		}
		else {
			//If the user doesn't enter any arguments, we will just add 150 to the budget
			Editor.mpEditorLimits->AddValue(Editor.mpEditorLimits->kBudget, 150);
		}
	}
	else {
		//If the user doesn't use the cheat in an editor, this text will be printed
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

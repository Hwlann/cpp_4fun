#include "CharacterEditor.h"

void CharacterEditor::showBaseSelection()
{
	std::ifstream title;
	title.open("ui/characterCreation.ui", std::ios::in);
	if (title.is_open())
		std::cout << title.rdbuf() << std::endl;

	std::cout << "\n\tSelect your name :\n" << std::endl;



	std::cout << "\n\tSelect your class :\n" << std::endl;



	std::cout << "\n\tAccept\n" << std::endl;
	std::cout << "\n\t Back\n" << std::endl;

}

void CharacterEditor::showPortraitSelection()
{
}

void CharacterEditor::showSkillSelection()
{
}

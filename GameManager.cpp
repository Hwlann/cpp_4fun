#include "GameManager.h"
GameManager *GameManager::m_gameManager = nullptr;

GameManager::GameManager() {
	srand(time(NULL));
}

GameManager::~GameManager() {
	for (int i = 0; i < m_characterList.size(); i++) {
		delete m_characterList.at(m_playersNames.at(i));
	}
;}

GameManager *GameManager::getInstance() {
	if (m_gameManager == nullptr) {
		m_gameManager = new GameManager();
	}
	return m_gameManager;
}

void GameManager::initNewGame(int numberOfPlayers) {
	system("cls");
	currentPlayer = numberOfPlayers;
	std::cout << ">>>> New Game ! <<<<\n";
	for (int i = 0; i < numberOfPlayers; i++) {
		std::cout << "\n\n";
		std::cout << "Enter name of Player " << i << std::endl;
		std::cout << "Choose your Name : ";
		std::cin >> m_playersName;
		m_playersNames.push_back(m_playersName);
		chooseClassAndWeapon(m_playersName);
	}
	StartGame();
}

void GameManager::gameEnds(std::string winnerName) {
	std::cout << "\n\n";
	std::cout << "> "<< winnerName << " Wins !";
	exit(EXIT_SUCCESS);
}

void GameManager::chooseClassAndWeapon(std::string playerName) {
	std::cout << "\n\n";
	std::cout << "Here come a new Challenger !\nWelcome to " << playerName << " !\n";
	std::cout << "Choose a Class from following\n";
	for (int i = 0; i < m_classNames.size(); i++) {
		std::cout << i << " - " << m_classNames.at(i) << std::endl;
	}
	std::cout << "Choose your Class : ";
	std::cin >> classIndex;
	if (classIndex > m_classNames.size() || classIndex < 0) chooseClassAndWeapon(m_playersName);
	else addNewPlayerCharacter(playerName, classIndex);
}

void GameManager::addNewPlayerCharacter(std::string characterName, int classIndex) {
	m_characterList.insert(std::pair<std::string, Character*>(characterName, new Character(characterName, static_cast<Character::CharacterClass>(classIndex))));
}

void GameManager::StartGame() {
	system("cls");
	std::cout << "Game Starting !\nGrid Size is "<< gridSize << "x"<< gridSize << std::endl;
	for (int i = 0; i < m_playersNames.size(); i++) {
		m_characterList.at(m_playersNames.at(i))->setPosition(findPosition());
		m_grid.at(m_characterList.at(m_playersNames.at(i))->getPosition()->x).at(m_characterList.at(m_playersNames.at(i))->getPosition()->y) = i+1;
	}
	drawGrid();
	newTurn();
}

Character::CharacterPosition *GameManager::findPosition() {
	int x = 0; 
	int y = 0;
	while (m_grid.at(x).at(y) != 0) {
		x = rand() % gridSize;
		y = rand() % gridSize;
	}
	return new Character::CharacterPosition({ x, y });
}

void GameManager::drawGrid() {
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if(m_grid.at(i).at(j) == 0 ) std::cout << "-  ";
			else std::cout << m_grid.at(i).at(j) << "  ";
		}
		std::cout << std::endl;
	}
}

void GameManager::newTurn() {
	while (keepPlaying) {
		system("cls");
		drawGrid();
		//m_characterList.at(m_playersNames.at(m_numberOfTurn % m_playersNames.size()))->myTurn();
		if (m_characterList.at(m_playersNames.at(m_numberOfTurn % m_playersNames.size()))->isAlive()) {
			characterTurn(m_characterList.at(m_playersNames.at(m_numberOfTurn % m_playersNames.size())));
		}
		m_numberOfTurn++;
	}
	for (int i = 0; i < m_characterList.size(); i++) {
		if(m_characterList.at(m_playersNames.at(i))->isAlive()) gameEnds(m_characterList.at(m_playersNames.at(i))->getName());
	}
}

void GameManager::characterTurn(Character *character) {
	std::cout << character->getName() << " Turn !\n";
	std::cout << "1 - Attack\n" << "2 - Drink Health Potion!\n" << "3 - Move\n";
	std::cout << "Action : ";
	std::cin >> m_turnChoise;
	switch (m_turnChoise) {
	case 1:
		for (int i = 0; i < m_characterList.size(); i++) {
			if ((m_playersNames.at(i).compare(character->getName()))) {
				if (m_characterList.at(m_playersNames.at(i))->isAlive()) {
					std::cout << i+1 << " - " << m_characterList.at(m_playersNames.at(i))->getName() << std::endl;
				}
			}
		}
		std::cout << "Choose target : ";
		std::cin >> m_turnChoise;
		character->attackTarget(m_characterList.at(m_playersNames.at(m_turnChoise)));
		break;
	case 2:
		character->heal(25);
		break;
	case 3:
		break;
	}
	checkGameState();
}

void GameManager::checkGameState() {
	for (int i = 0; i < m_characterList.size() ; i++) {
		if (!m_characterList.at(m_playersNames.at(i))->isAlive()) currentPlayer--;
	}
	if(currentPlayer < 2) keepPlaying = false;
}
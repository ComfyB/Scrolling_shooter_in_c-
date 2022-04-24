#include "src/Game/Game.h"
#include "src/SupportClasses/FileReader.h"

int main() {
    FileReader::writeHighscore(100);
    Game::instance().init();
}

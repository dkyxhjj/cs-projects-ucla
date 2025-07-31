#include <iostream>
#include <string>
#include <cassert>

#include "Die.h"
#include "Beetle.h"
#include "BeetleDrawing.h"
#include "BeetleGame.h"

using namespace std;

int main(){
    using namespace cs31;
    using namespace std;

    // Test Die
    Die d;
    d.roll();
    int value = d.getValue();
    assert(value >= 1 && value <= 6);

    // Test Beetle
    Beetle b;
    assert(!b.hasHead());
    assert(!b.isComplete());

    b.buildHead();
    assert(b.hasHead());
    assert(!b.isComplete());
    
    assert(!b.hasLeg1());
    assert(!b.hasLeg2());
    assert(!b.hasLeg3());
    assert(!b.hasLeg4());

    b.buildLeg();
    assert(b.hasLeg1());
    b.buildLeg();
    assert(b.hasLeg2());
    b.buildLeg();
    assert(b.hasLeg3());
    b.buildLeg();
    assert(b.hasLeg4());

    assert(!b.hasEye1());
    assert(!b.hasEye2());
    b.buildEye();
    assert(b.hasEye1());
    b.buildEye();
    assert(b.hasEye2());

    assert(!b.hasTail());
    b.buildTail();
    assert(b.hasTail());

    assert(!b.hasAntenna1());
    assert(!b.hasAntenna2());
    b.buildAntenna();
    assert(b.hasAntenna1());
    b.buildAntenna();
    assert(b.hasAntenna2());

    assert(!b.hasBody());
    b.buildBody();
    assert(b.hasBody());
    assert(b.isComplete());

    // Additional Assertions
    assert(b.hasLeg1() && b.hasLeg2() && b.hasLeg3() && b.hasLeg4());
    assert(b.hasEye1() && b.hasEye2());
    assert(b.hasAntenna1() && b.hasAntenna2());
    assert(b.hasTail());
    assert(b.hasBody());

    // Test BeetleGame mechanics
    BeetleGame game;
    assert(!game.gameIsOver());
    
    // Manually override, simulate a game of beetle
    game.humanRoll(1);
    game.humanPlay();
    game.computerRoll(1);
    game.computerPlay();
    assert(!game.getHumanBeetle().isComplete());
    assert(!game.getHumanBeetle().hasBody());
    assert(!game.getComputerBeetle().isComplete());
    assert(!game.getComputerBeetle().hasBody());
    assert(!game.gameIsOver());

    game.humanRoll(6);
    game.humanPlay();
    game.computerRoll(6);
    game.computerPlay();
    assert(!game.getHumanBeetle().isComplete());
    assert(game.getHumanBeetle().hasBody());
    assert(!game.getComputerBeetle().isComplete());
    assert(game.getComputerBeetle().hasBody());

    game.humanRoll(5);
    game.humanPlay();
    assert(game.getHumanBeetle().hasHead());

    game.computerRoll(5);
    game.computerPlay();
    assert(game.getComputerBeetle().hasHead());

    game.humanRoll(4);
    game.humanPlay();
    assert(game.getHumanBeetle().hasTail());

    game.computerRoll(4);
    game.computerPlay();
    assert(game.getComputerBeetle().hasTail());

    game.humanRoll(3);
    game.humanPlay();
    assert(game.getHumanBeetle().hasLeg1());

    game.computerRoll(3);
    game.computerPlay();
    assert(game.getComputerBeetle().hasLeg1());
    
    return 0;
}

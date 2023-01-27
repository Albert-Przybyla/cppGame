#pragma once
#include "helloScreen.h"

HelloScreen::HelloScreen(bool open)
{
    shapeH1.setPosition(1060, 800);
    shapeH1.setSize({20, 20});
    shapeH1.setFillColor(Color::White);
    shapeH1.setOrigin(10, 10);

    shapeH2.setPosition(1080, 800);
    shapeH2.setSize({20, 80});
    shapeH2.setFillColor(Color::White);
    shapeH2.setOrigin(10, 40);

    shapeH3.setPosition(1040, 800);
    shapeH3.setSize({20, 80});
    shapeH3.setFillColor(Color::White);
    shapeH3.setOrigin(10, 40);

    shapeE1.setPosition(1110, 800);
    shapeE1.setSize({20, 80});
    shapeE1.setFillColor(Color::White);
    shapeE1.setOrigin(10, 40);

    shapeE2.setPosition(1125, 837);
    shapeE2.setSize({30, 18});
    shapeE2.setFillColor(Color::White);
    shapeE2.setOrigin(9, 15);

    shapeE3.setPosition(1125, 806);
    shapeE3.setSize({30, 18});
    shapeE3.setFillColor(Color::White);
    shapeE3.setOrigin(9, 15);

    shapeE4.setPosition(1125, 775);
    shapeE4.setSize({30, 18});
    shapeE4.setFillColor(Color::White);
    shapeE4.setOrigin(9, 15);

    shapeL1.setPosition(1170, 800);
    shapeL1.setSize({20, 80});
    shapeL1.setFillColor(Color::White);
    shapeL1.setOrigin(10, 40);

    shapeL2.setPosition(1195, 830);
    shapeL2.setSize({40, 20});
    shapeL2.setFillColor(Color::White);
    shapeL2.setOrigin(20, 10);

    shapeL3.setPosition(1240, 800);
    shapeL3.setSize({20, 80});
    shapeL3.setFillColor(Color::White);
    shapeL3.setOrigin(10, 40);

    shapeL4.setPosition(1265, 830);
    shapeL4.setSize({40, 20});
    shapeL4.setFillColor(Color::White);
    shapeL4.setOrigin(20, 10);

    shapeO1.setRadius(40);
    shapeO1.setFillColor(Color::White);
    shapeO1.setOrigin(20, 20);
    shapeO1.setPosition(1310, 777);

    shapeO2.setRadius(26);
    shapeO2.setFillColor(Color::Black);
    shapeO2.setOrigin(5, 6);
    shapeO2.setPosition(1310, 777);
}

void HelloScreen::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shapeH1, state);
    target.draw(this->shapeH2, state);
    target.draw(this->shapeH3, state);
    target.draw(this->shapeE1, state);
    target.draw(this->shapeE2, state);
    target.draw(this->shapeE3, state);
    target.draw(this->shapeE4, state);
    target.draw(this->shapeL1, state);
    target.draw(this->shapeL2, state);
    target.draw(this->shapeL3, state);
    target.draw(this->shapeL4, state);
    target.draw(this->shapeO1, state);
    target.draw(this->shapeO2, state);
}
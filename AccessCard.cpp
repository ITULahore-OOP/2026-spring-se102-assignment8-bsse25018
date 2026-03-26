#include "AccessCard.h"

AccessCard::AccessCard(string cardID, int accessLevel)
{
    this->cardID = cardID;
    this->accessLevel = accessLevel;
}

string AccessCard::getCardID()
{
    return cardID;
}

int AccessCard::getAccessLevel()
{
    return accessLevel;
}

void AccessCard::displayCardInfo()
{
    cout << "Card ID: " << cardID << endl;
    cout << "Access Level: " << accessLevel << endl;
}
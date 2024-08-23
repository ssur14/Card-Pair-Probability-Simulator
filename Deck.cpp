#include <vector>
#include <algorithm>

using namespace std;
#include "Deck.h"

Deck::Deck()
{
    char q = 's';
    int num;

    for (unsigned i = 0; i < 4; ++i)
    {
        if (i == 1)
        {
            q = 'h';
        }

        if (i == 2)
        {
            q = 'd';
        }

        if (i == 3)
        {
            q = 'c';
        }
        
        num = 13; 

        for (unsigned a = 0; a < 13; ++a)
        {
            Card c1 = Card(q, num);
            theDeck.push_back(c1);
            --num;
        }
    }
}

Card Deck::dealCard()
{
    Card c1 = theDeck.back();
    theDeck.pop_back();

    dealtCards.push_back(c1);
    return c1;
}

void Deck::shuffleDeck()
{
    if (theDeck.size() == 52)
    {
        random_shuffle(theDeck.begin(), theDeck.end());
    }
    else
    {
        for (unsigned i = 0; i < dealtCards.size(); ++i)
        {
            theDeck.push_back(dealtCards.at(i));
        }

        dealtCards.clear();
        random_shuffle(theDeck.begin(), theDeck.end());
    }
}

unsigned Deck::deckSize() const
{
    return theDeck.size();
}
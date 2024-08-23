#include <iostream>

using namespace std;
#include "Card.h"

Card::Card()
{
    suit = 'c';
    rank = 2;
}

Card::Card(char q, int r)
{
    if (q == 'c' || q == 'C')
    {
        suit = 'c';
    }
    else if (q == 'd' || q == 'D')
    {
        suit = 'd';
    }
    else if (q == 'h' || q == 'H')
    {
        suit = 'h';
    }
    else if (q == 's' || q == 'S')
    {
        suit = 's';
    }
    else
    {
        suit = 'c';
    }

    if (r < 1 || r > 13)
    {
        rank = 2;
    }
    else
    {
        rank = r;
    }
}

char Card::getSuit() const
{
    return suit;
}

int Card::getRank() const
{
    return rank;
}

ostream & operator<<(ostream &o, const Card &c)
{
    if (c.suit == 'c')
    {
        if (c.rank == 1)
        {
            o << "Ace of Clubs";
        }
        else if (c.rank == 11)
        {
            o << "Jack of Clubs";
        }
        else if (c.rank == 12)
        {
            o << "Queen of Clubs";
        }
        else if (c.rank == 13)
        {
            o << "King of Clubs";
        }
        else
        {
            o << c.rank << " of Clubs";
        }
    }

    if (c.suit == 'd')
    {
        if (c.rank == 1)
        {
            o << "Ace of Diamonds";
        }
        else if (c.rank == 11)
        {
            o << "Jack of Diamonds";
        }
        else if (c.rank == 12)
        {
            o << "Queen of Diamonds";
        }
        else if (c.rank == 13)
        {
            o << "King of Diamonds";
        }
        else
        {
            o << c.rank << " of Diamonds";        
        }
    }

    if (c.suit == 'h')
    {
        if (c.rank == 1)
        {
            o << "Ace of Hearts";
        }
        else if (c.rank == 11)
        {
            o << "Jack of Hearts";
        }
        else if (c.rank == 12)
        {
            o << "Queen of Hearts";
        }
        else if (c.rank == 13)
        {
            o << "King of Hearts";
        }
        else
        {
            o << c.rank << " of Hearts";
        }
    }

    if (c.suit == 's')
    {
        if (c.rank == 1)
        {
            o << "Ace of Spades";
        }
        else if (c.rank == 11)
        {
            o << "Jack of Spades";
        }
        else if (c.rank == 12)
        {
            o << "Queen of Spades";
        }
        else if (c.rank == 13)
        {
            o << "King of Spades";
        }
        else
        {
            o << c.rank << " of Spades";
        }
    }

    return o;
}
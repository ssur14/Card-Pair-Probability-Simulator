#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &, const vector<Card> &);

int main() {

    string outputFile;
    int num;
    int num2;

    srand(2222);

    vector<Card> hand;
    Deck d1 = Deck();
    string s1;

    cout << "Do you want to output all hands to a file? (Yes/No) ";
    cin >> outputFile;
    cout << endl;

    if (outputFile == "No")
    {
        cout << "Enter number of cards per hand: ";
        cin >> num;
        cout << endl;

        cout << "Enter number of deals (simulations): ";
        cin >> num2;
        cout << endl;

        double a = 0;
        d1.shuffleDeck();

        for (int x = 0; x < num2; ++x)
        {
            for (int i = 0; i < num; ++i)
            {
                hand.push_back(d1.dealCard());
            }

            if (hasPair(hand))
            {
                ++a;
            }

            hand.clear();
            d1.shuffleDeck();        
        }

        double a1 = (a / num2) * 100;

        cout << "Chances of receiving a pair in a hand of " << num << " cards is: " << a1 << "%" << endl;
    }

    if (outputFile == "Yes")
    {        
        cout << "Enter name of output file: ";
        cin >> s1;
        cout << endl;

        ofstream outFS;
        outFS.open(s1);

        if (!outFS.is_open())
        {
            cout << "Error opening " << s1 << endl;
            return 1;
        }

        cout << "Enter number of cards per hand: ";
        cin >> num;
        cout << endl;

        cout << "Enter number of deals (simulations): ";
        cin >> num2;
        cout << endl;

        double p = 0;
        // Deck d1 = Deck();
        d1.shuffleDeck();

        for (int w = 0; w < num2; ++w)
        {
            for (int s = 0; s < num; ++s)
            {
                hand.push_back(d1.dealCard());
            }

            if (hasPair(hand))
            {
                ++p;
                outFS << "Found Pair!! ";
            }
            else
            {
                outFS << "             ";
            }

            for (int z = 0; z < num; ++z)
            {
                if (z == num - 1)
                {
                    outFS << hand.at(z) << endl;
                }
                else
                {
                    outFS << hand.at(z) << ", ";
                }
            }

            hand.clear();
            d1.shuffleDeck();
        }

        double p1 = (p / num2) * 100;

        cout << "Chances of receiving a pair in a hand of " << num << " cards is: " << p1 << "%" << endl;
        outFS.close();
    }

    return 0;
}

bool hasPair(const vector<Card> &hand)
{
    for (unsigned i = 0; i < hand.size(); ++i)
    {
        for (unsigned x = i + 1; x < hand.size(); ++x)
        {
            if (hand.at(i).getRank() == hand.at(x).getRank())
            {
                return true;
            }
        }
    }
    return false;
}

ostream & operator<<(ostream &out, const vector<Card> &hand)
{
    if (hand.size() == 0)
    {
        return out;
    }
    else
    {
        for (unsigned i = 0; i < hand.size(); ++i)
        {
            out << hand.at(i) << ", ";
        }
    }

    return out;
}
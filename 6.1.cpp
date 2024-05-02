#include <iostream>
#include <string>

using namespace std;
//Please finish the comparison operator override
//compare face first, if the same then compare suit 
//請完成比較運算子多載
//先比較 face ， face 一樣再比較 suit
//1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
//spade > heart > diamond > club

class PokerCard
{
public:
    PokerCard(string s, int f)
    {
        suit = s;
        
        if (f == 1)//可以直接比較
            face = 14;
        else 
            face = f;
    }
    string getsuit(){
        return suit;
    }
    int getface(){
        return face;
    }
    void setface(int a){
        face = a;
    }
    friend ostream &operator<<(ostream &out, PokerCard &p)
    {
        if (p.face == 14)
            p.setface(1);
        out<<"["<<p.face<<" of "<<p.suit<<"]";
        if (p.face == 1)
            p.setface(14);
        return out;
    }
    //先比較 face ， face 一樣再比較 suit
    //1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
    //spade > heart > diamond > club
    //true 大 false 小
    bool operator>(PokerCard &b)
    {
        if (face > b.getface())
            return true;
        else if (face < b.getface())
            return false; 
        else{
            if (suit == "spade"){
                if (b.getsuit() == "spade")
                    return false;
                else 
                    return true;
            }
            else if (suit == "heart"){
                if (b.getsuit() == "spade" || b.getsuit() == "heart")
                    return false;
                else
                    return true;
            }
            else if (suit == "diamond"){
                if (b.getsuit() == "spade" || b.getsuit() == "heart" || b.getsuit() == "diamond")
                    return false;
                else
                    return true;
            }
            else if (suit == "club"){
                return false;
            }
        }
        return false;
    }
    bool operator<(PokerCard &b)
    {
        if (face > b.getface())
            return false;
        else if (face < b.getface())
            return true; 
        else{
            if (suit == "spade"){
                return false;
            }
            else if (suit == "heart"){
                if (b.getsuit() == "spade" )
                    return true;
                else
                    return false;
            }
            else if (suit == "diamond"){
                if (b.getsuit() == "spade" || b.getsuit() == "heart" )
                    return true;
                else
                    return false;
            }
            else if (suit == "club"){
                if (b.getsuit() == "club")
                    return false;
                else 
                    return true;
            }
        }
        return false;
    }
    bool operator==(PokerCard &b)
    {
        if (face == b.getface() && suit == b.getsuit())
            return true;
        else
            return false;
    }

private:
    string suit;
    int face;
};

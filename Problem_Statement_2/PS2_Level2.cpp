#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
struct MoveSet
{
    string Name;
    int Damage;
};
// defining the class which will contain all the different benders
class Bender
{
public:
    string Name{};
    string Element{};
    int HP{};
    int Attack{};
    int Defence{};
    int Speed{};
    int MaxHP{};
    vector<MoveSet> GetMoves{};

    Bender(string n, string t, int h, int &a, int &d, int &sp, vector<MoveSet> m) : Name(n), Element(t), HP(h), Attack(a), Defence(d), Speed(sp), MaxHP(h), GetMoves(m) {}

    // "this" is the attacker, the defender is passed in
    void attack(Bender &defender, int moveIndex)
    { 
        if (moveIndex < 0 || moveIndex >= (int)GetMoves.size())
        {
            cout << "Invalid move index!";
            return;
        }
        int damageDealt = round(double(GetMoves[moveIndex].Damage * Attack) / defender.Defence);
        cout << Name << " used " << GetMoves[moveIndex].Name << "!" << endl;
        cout << defender.Name << " took " << damageDealt << " damage!";
        defender.HP -= damageDealt;
        if (defender.HP < 0) defender.HP = 0;
    }
};

void isFainted(Bender &z) 
{
    cout << endl;
    if (z.HP <= 0)
    {
        cout << z.Name << " fainted: true" << endl;
    }
    else
    {
        cout << z.Name << " fainted: false" << endl;
    }
}

void displayStatsP1(Bender &x)
{
    if (x.HP <= 0)
        x.HP = 0;
    cout << x.Name << " (" << x.Element << ") - " << "HP: " << x.HP << "/" << x.MaxHP << ", Attack: " << x.Attack << ", Defence: " << x.Defence << ", Speed: " << x.Speed << endl;
    cout << "Moves: ";
    for (int i = 0; i < 4; i++)
    {

        if (i < 3)
            cout << x.GetMoves[i].Name << " ( " << x.GetMoves[i].Damage << " ), ";
        else
            cout << x.GetMoves[i].Name << " ( " << x.GetMoves[i].Damage << " ) ";
    }
}

void displayStatsP2(Bender &y)
{
    cout << endl
         << endl;
    if (y.HP <= 0)
        y.HP = 0;
    cout << y.Name << " (" << y.Element << ") - " << "HP: " << y.HP << "/" << y.MaxHP << ", Attack: " << y.Attack << ", Defence: " << y.Defence << ", Speed: " << y.Speed << endl;
    cout << "Moves: ";
    for (int i = 0; i < 4; i++)
    {
        if (i < 3)
            cout << y.GetMoves[i].Name << " ( " << y.GetMoves[i].Damage << " ), ";
        else
            cout << y.GetMoves[i].Name << " ( " << y.GetMoves[i].Damage << " )";
    }
}


int main()
{
    cout << "Enter details for the first Bender: " << endl;
    string s1{}, s2{};
    int h{}, a{}, d{}, s{}, m{};
    cout << "Name: ";
    cin >> s1;
    cout << "Element: ";
    cin >> s2;
    cout << "HP: ";
    cin >> h;
    cout << "Attack: ";
    cin >> a;
    cout << "Defence: ";
    cin >> d;
    cout << "Speed: ";
    cin >> s;
    // Moveset input 1
    cout << "Input the Moveset of " << s1 << endl;
    vector<MoveSet> Bender_1{};
    for (int i = 0; i < 4; i++)
    {

        MoveSet x{};
        cout << "Enter Name of Move " << i + 1 << ": ";
        getline(cin >> ws, x.Name);
        cout << "Enter Damage of " << x.Name << ": ";
        cin >> x.Damage;
        Bender_1.push_back(x);
    }

    Bender x(s1, s2, h, a, d, s, Bender_1);
    cout << "Enter details for the second Bender: " << endl;
    string s3{}, s4{};
    int i{}, j{}, k{}, l{}, n{};
    cout << "Name: ";
    cin >> s3;
    cout << "Element: ";
    cin >> s4;
    cout << "HP: ";
    cin >> i;
    cout << "Attack: ";
    cin >> j;
    cout << "Defence: ";
    cin >> k;
    cout << "Speed: ";
    cin >> l;
    // Moveset Input 2
    cout << "Input the MoveSet of " << s3 << endl;
    vector<MoveSet> Bender_2;
    for (int i = 0; i < 4; i++)
    {

        MoveSet x{};
        cout << "Enter Name of Move " << i + 1 << ": ";
        getline(cin >> ws, x.Name);
        cout << "Enter Damage of " << x.Name << ": ";
        cin >> x.Damage;
        Bender_2.push_back(x);
    }

    Bender y(s3, s4, i, j, k, l, Bender_2);

    displayStatsP1(x);
    displayStatsP2(y);

    // main decides who attacks; the class only knows how an attack works
    string whoAttacks{};
    int idx{};
    cout << endl;
    cout << "Enter the Attacker: ";
    cin >> whoAttacks;

    cout<<"=== DUEL BEGINS! ==="<<endl;
    cout << x.Name << " (" << x.Element <<", HP: " << x.HP << "/" << x.MaxHP<<") "<<"VS "<< y.Name << " (" << y.Element<< ", HP: " << y.HP << "/" << y.MaxHP << ") - " <<endl;
for(int i = 0; i<1; i++){
    
    if (x.Speed > y.Speed)
    {
        cout << x.Name << " goes first! " << "( Speed: " << x.Speed << " vs " << y.Speed << endl;
        int p{};
        cin>>p;
        x.attack(y,p);
    }

     if (y.Speed > x.Speed)
    {
        cout << y.Name << " goes first! " << "( Speed: " << y.Speed << " vs " << x.Speed << endl;
        int p{};
        cin>>p;
        y.attack(x,p);
    }
}
while(x.HP !=0 && y.HP != 0){
    string nextAttack;
    if(whoAttacks == x.Name) nextAttack = y.Name;
    else nextAttack = x.Name;
    cout << "Enter the index of move you wish to use: ";
    cin >> idx;
    if (whoAttacks == x.Name)
    {
        x.attack(y, idx);
        displayStatsP2(y);
        isFainted(y);
    }
    else if (whoAttacks == y.Name)
    {
        y.attack(x, idx);
        displayStatsP1(x);
        isFainted(x);
    }
    else
        {cout << "No bender named " << whoAttacks <<"exists"<< endl;}
    whoAttacks = nextAttack;
}
}

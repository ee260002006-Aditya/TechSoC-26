#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
struct MoveSet{
    string Name;
    int Damage;
};
//defining the class which will contain all the different benders
class Bender {
    public:
    string Name{};
    string Element{};
    int HP{};
    int Attack{};
    int Defence{};
    int Speed{};
    int MaxHP{};
    vector<MoveSet> GetMoves{};
    
    Bender(string n,string t, int h, int& a, int& d, int& sp,vector<MoveSet> m ): Name(n), Element(t), HP(h), Attack(a), Defence(d), Speed(sp), MaxHP(h), GetMoves(m){}
    
    //check if died    
    
};

void isFainted(Bender& z){
    cout<<endl;
    if(z.HP <= 0) {cout<<z.Name<<" fainted: true"<<endl;  }
    else {cout<<z.Name<<" fainted: false"<<endl; }
}
//display stats of player 1
void displayStatsP1(Bender& x) {
    if(x.HP<=0) x.HP=0;
    cout<<x.Name<<" ("<<x.Element<<") - "<<"HP: "<<x.HP<<"/"<<x.MaxHP<<", Attack: "<<x.Attack<<", Defence: "<<x.Defence<<", Speed: "<<x.Speed<<endl;
    cout<<"Moves: ";
    for(int i= 0; i<4; i++){
    if(i<3)
            cout<<x.GetMoves[i].Name  <<" ( " << x.GetMoves[i].Damage<< " ), "  ;
    else    cout<<x.GetMoves[i].Name  <<" ( " << x.GetMoves[i].Damage<< " ) "  ;
     
    } }

//display stats of player 2
void displayStatsP2(Bender& y){cout<<endl<<endl;
    if(y.HP<=0) y.HP=0;
    cout<<y.Name<<" (" <<y.Element<< ") - "<< "HP: " <<y.HP<<"/"<<y.MaxHP<< ", Attack: " <<y.Attack<< ", Defence: " <<y.Defence<< ", Speed: " <<y.Speed<<endl;
    cout<<"Moves: ";
    for(int i= 0; i<4; i++){
    if(i<3)
    cout<<y.GetMoves[i].Name  <<" ( " << y.GetMoves[i].Damage<< " ), "  ;
    else cout<<y.GetMoves[i].Name  <<" ( " << y.GetMoves[i].Damage<< " )"  ;
     
    }
}
//function used such that u choose the attacker

void attack(Bender& x, Bender& y) {
    string attacker{};
    cout<<endl;
    cout<<"Enter the Attacker: ";
    cin>>attacker;
    if(attacker == x.Name){
        cout<<"Enter the index of move you wish to use: ";
        int A{}; //suppose index of move they want to use
        cin>>A;
        int damageDealt{};
        for(int i=0; i<4; i++){
            if (A == i) {
                damageDealt = round(double(x.GetMoves[i].Damage*x.Attack)/y.Defence); //this round fucntion was very new to me and its used to round off the damage dealt to an integral value, which the question demains, tho it can also be done by using simple division without writing the double since all are in integer, but that would give the GIF not the rounded value.
                cout<<x.Name<<" used "<<x.GetMoves[i].Name<<"!"<<endl;
                cout<<y.Name<<" took "<<damageDealt<<" damage!";
            };
        }
        y.HP -= damageDealt;
        displayStatsP2(y);
        isFainted(y);
    }
    else { //atacker is y
         cout<<"Enter the index of move you wish to use: ";
        int A{};
        cin>>A;
        int damageDealt{};
        for(int i=0; i<4; i++){
            if (A == i) {
                damageDealt = round(double(y.GetMoves[i].Damage*y.Attack)/x.Defence);
                cout<<y.Name<<" used "<<y.GetMoves[i].Name<<"!"<<endl;
                cout<<x.Name<<" took "<<damageDealt<<" damage!";
            };
        }
        x.HP -= damageDealt;
        displayStatsP1(x);
        isFainted(x);
    }

}

int main(){
    cout<<"Enter details for the first Bender: "<<endl; //fully customizable benders available
    string s1{}, s2{};
   int h{}, a{}, d{}, s{}, m{};
    cout<<"Name: ";
    cin >> s1;
    cout<<"Element: ";
    cin >> s2;
    cout<<"HP: ";
    cin >> h;
    cout<<"Attack: ";
    cin >> a;
    cout<<"Defence: ";
    cin >> d;
    cout<<"Speed: ";
    cin >> s;
    //Moveset input for bender 1
    cout<<"Input the Moveset of " <<s1<<endl;
    vector<MoveSet> Bender_1{};
        for(int i=0; i<4; i++){
            
                MoveSet x{};
                cout<<"Enter Name of Move "<<i+1<<": ";
                getline(cin>>ws, x.Name);
                cout<<"Enter Damage of "<<x.Name<<": ";
                cin>>x.Damage;
                Bender_1.push_back(x);
            
        }

    Bender x(s1 , s2 , h , a , d , s, Bender_1);
    cout << "Enter details for the second Bender: "<<endl; //2nd bender
    string s3{}, s4{};
    int i{}, j{}, k{}, l{}, n{};
    cout<<"Name: ";
    cin >> s3;
    cout<<"Element: ";
    cin >> s4;
    cout<<"HP: ";
    cin >> i;
    cout<<"Attack: ";
    cin >> j;
    cout<<"Defence: ";
    cin >> k;
    cout<<"Speed: ";
    cin >> l;
//Moveset Input for bender 2
    cout<<"Input the MoveSet of " <<s3<<endl;
    vector<MoveSet> Bender_2;
        for(int i=0; i<4; i++){
          
                MoveSet x{};
                cout<<"Enter Name of Move "<<i+1<<": ";
                getline(cin>>ws, x.Name); //using getline cuz the name of moves are also a pair or triplet of strings, and cin does not accept inputs once a space appears and it treats it as the next cin,thus  showing unexpected behavior.
                cout<<"Enter Damage of "<<x.Name<<": ";
                cin>>x.Damage;
                Bender_2.push_back(x);
            
            
        }

    Bender y(s3, s4, i , j, k, l ,Bender_2);  
      
    displayStatsP1(x);
    displayStatsP2(y);
    attack(x,y);





}



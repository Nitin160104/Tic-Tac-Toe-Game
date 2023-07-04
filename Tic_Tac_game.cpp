#include<iostream>
using namespace std;
class tictactoe
{
	public:
    char blocks[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int digit , row , column;
    char token = 'X';
    bool draw = false;
    
    //making of all the required functions
    void function1(void);
    void function2(void);
    bool function3();
    void function4(void);
    void result(void);
};
//Names for Player
string name1;
string name2;

void tictactoe::function1(){
    //Printing of the tic tac blocks
    //And Printing the block numbers for all the blocks of tic tac game
    cout<<"     |     |    "<<endl;
    cout<<"  "<<blocks[0][0]<<"  |  "<<blocks[0][1]<<"  |  "<<blocks[0][2]<<" "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |    "<<endl;
    cout<<"  "<<blocks[1][0]<<"  |  "<<blocks[1][1]<<"  |  "<<blocks[1][2]<<" "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |    "<<endl;
    cout<<"  "<<blocks[2][0]<<"  |  "<<blocks[2][1]<<"  |  "<<blocks[2][2]<<" "<<endl;
    cout<<"     |     |    "<<endl;

    //Printing available Choices each time
    //then player enter his desired digit
    cout<<"Available Choices are : ";
    int count = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(blocks[i][j] != 'X' && blocks[i][j] != 'O'){
                cout<<count<<" , ";
            }
            count++;
        }
    }
    cout<<endl;

}

void tictactoe::function2(){
    
    //According to token player will get chance
    if(token == 'X'){
        cout<<name1<<" Please Enter : ";
        cin>>digit;
    }
    if(token == 'O'){
        cout<<name2<<" Please Enter : ";
        cin>>digit;
    }
    
    //According to entered digit row and column are setup
    if(digit == 1){
        row = 0;
        column = 0;
    }
    if(digit == 2){
        row = 0;
        column = 1;
    }
    if(digit == 3){
        row = 0;
        column = 2;
    }
    if(digit == 4){
        row = 1;
        column = 0;
    }
    if(digit == 5){
        row = 1;
        column = 1;
    }
    if(digit == 6){
        row = 1;
        column = 2;
    }
    if(digit == 7){
        row = 2;
        column = 0;
    }
    if(digit == 8){
        row = 2;
        column = 1;
    }
    if(digit == 9){
        row = 2;
        column = 2;
    }
    else if(digit < 1 || digit > 9){
        cout<<"Please Enter Valid Number !!! "<<endl;
    }
    //These lower if else condition will set X or O according to entered digit
    if(token == 'X' && blocks[row][column] != 'X' && blocks[row][column] != 'O'){
        blocks[row][column] = 'X';
        token = 'O';
    }
    else if(token == 'O' && blocks[row][column] != 'X' && blocks[row][column] != 'O'){
        blocks[row][column] = 'O';
        token = 'X';
    }
    else{
        cout<<"This Block number "<<digit<<" is not Empty !!!"<<endl;
        function2();
    }
    function1();
}

bool tictactoe::function3(){
    //checking for all rows and coloumns and diagonals
    //if any of them is equal then return true
    //this for loop is for checking winning conditions
    bool ans = false;
    for(int i = 0; i < 3; i++){
        if((blocks[i][0] == blocks[i][1] && blocks[i][0] == blocks[i][2])||(blocks[0][i] == blocks[1][i] && blocks[0][i] == blocks[2][i])){
            ans = true;
            return true;
        }
        if((blocks[0][0] == blocks[1][1] && blocks[1][1] == blocks[2][2])||(blocks[0][2] == blocks[1][1] && blocks[0][2] == blocks[2][0])){
            ans = true;
            return true;
        }
    }
    //this for loop is for checking if any block is still empty
    //if any block is still empty then it will return false and function3 will continue
    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(blocks[i][j] == 'X' || blocks[i][j] == 'O'){
                count++;
            } 
        }
    }
    //if count == 9 then it means the game is draw
    if(count == 9 && ans != true){
        draw = true;
        return true;
    }
   return false;
}

//function for resseting all the blocks for replay;
void tictactoe::function4(){
    int count = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            blocks[i][j] = count + '0';
            count++;
        }
    }
}

void tictactoe::result()
{
    if(token == 'X' && draw == false){
          cout<<name2<<" Wins !!"<<endl;
          cout<<"Game Over"<<endl;
      }
      else if(token == 'O' && draw == false){
          cout<<name1<<" Wins !!"<<endl;
          cout<<"Game Over"<<endl;
      }
      else{
          cout<<"Game Draw"<<endl;
      }
}

int main(){
    tictactoe game;
    cout<<"Enter the name of First Player : "<<endl;
    getline(cin,name1);
    cout<<"Enter the name of Second Player : "<<endl;
    getline(cin,name2);
    //According to the player number setting the starting sequence of the game
    cout<<name1<<" is Player 1 So He/She will play first"<<endl;
    cout<<name2<<" is Player 2 So He/She will play second"<<endl;
    int play = 1;
    cout<<"   __________"<<endl;
    cout<<"  |Game Start|"<<endl;
    cout<<"   ----------"<<endl;
    while(play == 1){
      play = 0;
      game.function1();
      while(!game.function3()){
        game.function2();
        game.function3();
      }
      game.result();
      //if player wants to replay
      string replay;
      cout<<"Wants to Replay ?(Yes/No) : ";
      cin>>replay;
      if(replay == "YES" || replay == "yes" || replay == "Yes"){
          cout<<"   ____________"<<endl;
          cout<<"  |Game Restart|"<<endl;
          cout<<"   ------------"<<endl;
          play = 1;
          //resseting all the blocks 
          game.function4();
      }
      //if replay is set to NO then it will break the while loop 
      else{
          break;
      }
    }
    
}
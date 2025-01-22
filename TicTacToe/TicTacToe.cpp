using namespace std;  //header files 
#include<iostream>    //for input/output operations
#include<cstdlib>	  //for generating random numbers
#include<ctime>		  //for generating random numbers with different arrangement every time  	
#include<fstream>	  //for file handling used in 'reviews'

bool gameover(char a[3][3]);     //function prototypes
void displayboard(char a[3][3]);
void player_turn(char a[3][3]);
void invalid();
void cpu(char a[3][3]);
void restart(char a[3][3]);
void AddReview();
void DisplayReview();
int choice, r;

int main()

{
	system("color 57"); //changes foreground and background colors
	cout << "\t\t\t\t Welcome to TIC TAC TOE GAME\n";
menu:
	int n, i;
	char a[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

	cout << " \nWhich menu do you want to open?" << endl;
	cout << " 1. PLAY GAME\n 2. INSTRUCTIONS\n 3. REVIEWS\n 4. EXIT\n";
	cin >> n;
	system("cls");  //function for updating screen
	switch (n) {
	case 1:
	{start:
	again:
		system("cls");
		cout << "Please select opponent : \n1.Player2\n2.CPU\n";
		cin >> r;
		if (r == 1)
			player_turn(a);

		else
			if (r == 2)
				cpu(a);
			else
			{
				invalid();
				goto again;
			}
		break; }
	case 2:
	{
		cout << "Press any number from 1 to 9 to place your mark on the board. 'X' is for player 1 and 'O' is for player 2. \nThe number you enter will be replaced by your mark on the board.\n";
		cout << "How to win:  If you have marked three consecutive places in a line(vertical, horizontal or diagonal), you win the game. Also try to stop the opponent from doing so.\n";
		option:		
		cout << "\nPress 1 to play game and 2 to return to the menu page...";
		cin >> i;
		system("cls");
	
	switch (i) {
	case 1:
		goto start;
		break;
	case 2:
		goto menu;
		break;
	default:
		invalid();
		system("cls");
		goto option;
		break;
	}
}
	case 3:
    {
     review:
    int x;
    cout << "1. Add Review\n";
    cout << "2. Display Reviews\n";
    cin >> x;

    
    switch (x) {
        case 1:
           cin.ignore();
            AddReview();
            break;

        case 2:
        cout<<"Reviews";
            DisplayReview();
            system("pause");
            break;

        default:
           invalid();
           system("cls");
           goto review;
            system("pause");
            break;
    }
    
    	p:
    	system("cls");
		cout << "\nPress 1 to play game and 2 to return to the menu page...";
		cin >> i;
		system("cls");
	
	switch (i) {
	case 1:
		goto start;
		break;
	case 2:
		goto menu;
		break;
	default:
		invalid();
		goto p;
		break;
		
		}
    break; 
}
	case 4:
		system("cls");
		cout << " Thank you!";
		break;

	default:
		invalid();
		system("cls");
		goto menu;
		goto again;
		break;
	}
	system("pause");
}

void restart(char a[3][3])   //function for restarting game

{
	playagain:
	int b, i;
	system("cls");
	cout << " 1.Press 1 if you want to continue playing game\n 2.Press 2 if you want to exit\n";
	cin >> b;
	if (b == 1)
	{
		again:
			system("cls");
		cout << "Please select opponent : \n1.Player2\n2.CPU\n";
		cin >> i;
		
			if (i == 1) {

				char a[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
				player_turn(a);

			}
			else if (i == 2)
			{
				char a[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
				cpu(a);

			}
			else
			{
				invalid();
				goto again;
			}
		
	}
	else if (b == 2) {
		system("cls");
		cout << "\tThankyou for playing TIC TAC TOE game!\n";
		
	}
	else
	{
		invalid();
		goto playagain;
}
}

bool gameover(char a[3][3]) { //function that decides whether game is ended or not and declares winner 

	if (a[0][0] == 'X' && a[0][1] == 'X' && a[0][2] == 'X' || a[1][0] == 'X' && a[1][1] == 'X' && a[1][2] == 'X' || a[2][0] == 'X' && a[2][1] == 'X' && a[2][2] == 'X')
	{
		displayboard(a);
		cout << "Player 1[X] won!!!!!\n\a\a\a\nCONGRATULATIONS!!!!!";
		return false;
	}
	
	else if (a[0][0] == 'X' && a[1][0] == 'X' && a[2][0] == 'X' || a[0][1] == 'X' && a[1][1] == 'X' && a[2][1] == 'X' || a[0][2] == 'X' && a[1][2] == 'X' && a[2][2] == 'X')
	{
		displayboard(a);
		cout << "Player 1[X] won!!!!!\n\a\a\a\nCONGRATULATIONS!!!!!";
		return false;
	}
	
	else if (a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X' || a[0][2] == 'X' && a[1][1] == 'X' && a[2][0] == 'X')
	{
    	displayboard(a);
		cout << "Player 1[X] won!!!!!\n\a\a\a\nCONGRATULATIONS!!!!!";
		return false;
	} 
	
	else if (a[0][0] == 'O' && a[0][1] == 'O' && a[0][2] == 'O' || a[1][0] == 'O' && a[1][1] == 'O' && a[1][2] == 'O' || a[2][0] == 'O' && a[2][1] == 'O' && a[2][2] == 'O')
	{
		displayboard(a);
		cout << "Player 2[O] won!!!!!\n\a\a\a\nCONGRATULATIONS!!!!!";
		return false;
	}
	
	else if (a[0][0] == 'O' && a[1][0] == 'O' && a[2][0] == 'O' || a[0][1] == 'O' && a[1][1] == 'O' && a[2][1] == 'O' || a[0][2] == 'O' && a[1][2] == 'O' && a[2][2] == 'O')
	{
		displayboard(a);
		cout << "Player 2[O] won!!!!!\n\a\a\a\nCONGRATULATIONS!!!!!";
		return false;
	}
	
	else if (a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O' || a[0][2] == 'O' && a[1][1] == 'O' && a[2][0] == 'O')
	{
		displayboard(a);
		cout << "Player 2[O] won!!!!!\n\a\a\a\nCONGRATULATIONS!!!!!";
		return false;
	}
	
	else if (a[0][0] != '1' && a[0][1] != '2' && a[0][2] != '3' && a[1][0] != '4' && a[1][1] != '5' && a[1][2] != '6' && a[2][0] != '7' && a[2][1] != '8' && a[2][2] != '9')
	{
		displayboard(a);
		cout << "ITS A DRAW\n\a\a\a";
		return false;
	}
	
	else
		return true;
		restart(a);
}

void displayboard(char a[3][3]) {   //function displays board for playing game

	system("cls");
	cout<<"\t\t\t\t\t  _______  _        _______           _______  \n";
    cout<<"\t\t\t\t\t |__   __|(_)      |__   __|         |__   __|   \n";
    cout<<"\t\t\t\t\t    | |    _   ___    | | ___ _  ___    | |  ____    ____  \n";
    cout<<"\t\t\t\t\t    | |   | | /  _|   | |/  _  |/  _|   | | /  _ \\  / __ \\ \n";
    cout<<"\t\t\t\t\t    | |   | ||  (_    | |  (_| |  (_    | ||  (_) || ____/      \n";
    cout<<"\t\t\t\t\t    |_|   |_| \\___|   |_|\\___,_|\\___|   |_| \\____/  \\____)  \n";
	cout << "Player 1[X]\n";
	cout << "Player 2[O]\n\n";
	cout << "\t\t\t\t\t\t     |     |     \n";
	cout << "\t\t\t\t\t\t  " << a[0][0] << "  |  " << a[0][1] << "  |  " << a[0][2] << "  \n";
	cout << "\t\t\t\t\t\t_____|_____|____\n";
	cout << "\t\t\t\t\t\t     |     |     \n";
	cout << "\t\t\t\t\t\t  " << a[1][0] << "  |  " << a[1][1] << "  |  " << a[1][2] << "  \n";
	cout << "\t\t\t\t\t\t_____|_____|____\n";
	cout << "\t\t\t\t\t\t     |     |     \n";
	cout << "\t\t\t\t\t\t  " << a[2][0] << "  |  " << a[2][1] << "  |  " << a[2][2] << "  \n";
	cout << "\t\t\t\t\t\t     |     |     \n";

}

void player_turn(char a[3][3]) {  //function for tournament between two players

	while (gameover(a)) {
	player1:
		displayboard(a);
		cout << "Player 1[X] turn: ";
		cin >> choice;

		if (choice == 1) {
		if (a[0][0] == 'O' || a[0][0] == 'X')
		{
			invalid();
			goto player1;  //control goes back to the label
		}
		    a[0][0] = 'X';
		}
		
	    else if (choice == 2) {
		if (a[0][1] == 'O' || a[0][1] == 'X')
		{
		    invalid();
			goto player1;
		}
			a[0][1] = 'X';
		} 
		
		else if (choice == 3) {
		if (a[0][2] == 'O' || a[0][2] == 'X')
		{
			invalid();
			goto player1;
		}
			a[0][2] = 'X';
		}
		else if (choice == 4) {
		if (a[1][0] == 'O' || a[1][0] == 'X')
		{
			invalid();
			goto player1;
		}
			a[1][0] = 'X';
		}
		
		else if (choice == 5) {
		if (a[1][1] == 'O' || a[1][1] == 'X')
		{
			invalid();
			goto player1;
		}
			a[1][1] = 'X';
		}
		
		else if (choice == 6) {
		if (a[1][2] == 'O' || a[1][2] == 'X')
		{
			invalid();
			goto player1;
		}
			a[1][2] = 'X';
		}
		
		else if (choice == 7) {
		if (a[2][0] == 'O' || a[2][0] == 'X')
		{
			invalid();
			goto player1;
		}
			a[2][0] = 'X';
		
		}
		else if (choice == 8) {
		if (a[2][1] == 'O' || a[2][1] == 'X')
		{
			invalid();
			goto player1;
		}
			a[2][1] = 'X';
		}
		
		else if (choice == 9) {
		if (a[2][2] == 'O' || a[2][2] == 'X')
		{
			invalid();
	 		goto player1;
		}
			a[2][2] = 'X';
		
		}
		else 
		{
			invalid();
			goto player1;
		}
		if (gameover(a) == false) {
			break;
		}
		
    	player2:
		displayboard(a);
		cout << "Player 2[O] turn: ";
		cin >> choice;

		if (choice == 1) {
		if (a[0][0] == 'X' || a[0][0] == 'O')
		{
		    invalid();
			goto player2;
		}
			a[0][0] = 'O';
		}
		
		else if (choice == 2) {
		if (a[0][1] == 'X' || a[0][1] == 'O')
		{
			invalid();
			goto player2;
		}
			a[0][1] = 'O';
		
		}
		
		else if (choice == 3) {
		if (a[0][2] == 'X' || a[0][2] == 'O')
		{
			invalid();
			goto player2;
		}
			a[0][2] = 'O';
		
		}
		else if (choice == 4) {
		if (a[1][0] == 'X' || a[1][0] == 'O')
		{
			invalid();
			goto player2;
		}
			a[1][0] = 'O';
		}
		
		else if (choice == 5) {
		if (a[1][1] == 'X' || a[1][1] == 'O')
		{
			invalid();
			goto player2;
		}
			a[1][1] = 'O';
	    }
			
		else if (choice == 6) {
		if (a[1][2] == 'X' || a[1][2] == 'O')
		{
			invalid();
			goto player2;
		}
			a[1][2] = 'O';
		}
							 
		else if (choice == 7) {
		if (a[2][0] == 'X' || a[2][0] == 'O')
		{
			invalid();
			goto player2;
		}
			a[2][0] = 'O';
		}
								
		else if (choice == 8) {
		if (a[2][1] == 'X' || a[2][1] == 'O')
		{
			invalid();
			goto player2;
		}
		a[2][1] = 'O';
		}
							
		else if (choice == 9) {
		if (a[2][2] == 'X' || a[2][2] == 'O')
		{
			invalid();
			goto player2;
		}
			a[2][2] = 'O';
		}
		
		else 
		{
			invalid();
			goto player2;
		}
    	}
	cout << "\nGAME OVER!";
	system("pause");
	system("cls");
	restart(a);
}

void invalid() { //function that deals with entry of invalid numbers and also to prevent overwriting of numbers

	cout << "\a";
	long long int n = -100000000;  
	cout << "INVALID ENTRY!\nTRY AGAIN";
	
	while (n <= 100000000)
	{
		n++;
	}
	
	while (n >= -100000000) {
		n--;
	}
}

void cpu(char a[3][3]) {  //function for tournament between player and cpu
	startagain:
	system("cls");
	int m;
	cout<<"Select mode:\n";
	cout<<"1.Easy\n";
	cout<<"2.Hard\n";
	cin>>m;
	switch(m){
	case 1:   //deals with easy mode
		{
	while (gameover(a)) {
	    player1:
		displayboard(a);
		cout << "Player 1[X] turn: ";
		cin >> choice;

		if (choice == 1) {
		if (a[0][0] == 'O' || a[0][0] == 'X')
		{
			invalid();
			goto player1;
		}
			a[0][0] = 'X';
		}
		
		else if (choice == 2) {
		if (a[0][1] == 'O' || a[0][1] == 'X')
		{
			invalid();
			goto player1;
		}
			a[0][1] = 'X';
		
		}
		
		else if (choice == 3) {
		if (a[0][2] == 'O' || a[0][2] == 'X')
		{
			invalid();
			goto player1;
		}
		    a[0][2] = 'X';
		}
				
	    else if (choice == 4) {
	    if(a[1][0] == 'O' || a[1][0] == 'X')
		{
		    invalid();
			goto player1;
		}
			a[1][0] = 'X';
		}
		
		else if (choice == 5) {
		if (a[1][1] == 'O' || a[1][1] == 'X')
		{
			invalid();
			goto player1;
		}
			a[1][1] = 'X';
		}
	
		else if (choice == 6) {
		if (a[1][2] == 'O' || a[1][2] == 'X')
		{
			invalid();
			goto player1;
		}
		a[1][2] = 'X';
		}
		
		else if (choice == 7) {
		if (a[2][0] == 'O' || a[2][0] == 'X')
		{
			invalid();
			goto player1;
		}
		a[2][0] = 'X';
		}
							
		else if (choice == 8) {
		if (a[2][1] == 'O' || a[2][1] == 'X')
		{
			invalid();
			goto player1;
		}
			a[2][1] = 'X';
		}
		
		else if (choice == 9) {
		if (a[2][2] == 'O' || a[2][2] == 'X')
		{
			invalid();
			goto player1;
		}
			a[2][2] = 'X';
		}
		
	    else 
        {
			invalid();
			goto player1;
		}
		 if (gameover(a) == false) {
			break;
		}
		
	    start:
		displayboard(a);
		cout << "CPU[O] turn: ";
		long long int n = -100000000;

		while (n <= 100000000) {
			n++;
		}
		
		while (n >= -100000000) {
			n--;
		}
	int r;
    r = (rand() % 9) + 1;

	if (r == 1) {
    if (a[0][0] == 'X'||a[0][0] == 'O')
        goto start;
    else
        a[0][0] = 'O';
   }
   
    else if (r == 2) {
    if (a[0][1] == 'X'||a[0][1] == 'O')
        goto start;
    else
        a[0][1] = 'O';
   }
   
    else if (r == 3) {
    if (a[0][2] == 'X'||a[0][2] == 'O')
        goto start;
    else
        a[0][2] = 'O';
   }
   
    else if (r == 4) {
    if (a[1][0] == 'X'||a[1][0] == 'O')
        goto start;
    else
        a[1][0] = 'O';
   }
   
    else if (r == 5) {
    if (a[1][1] == 'X'||a[1][1] == 'O')
        goto start;
    else
        a[1][1] = 'O';
   }
   
    else if (r == 6) {
    if (a[1][2] == 'X'||a[1][2] == 'O')
        goto start;
    else
        a[1][2] = 'O';
   }
   
    else if (r == 7) {
    if (a[2][0] == 'X'||a[2][0] == 'O')
        goto start;
    else
        a[2][0] = 'O';
   }
   
    else if (r == 8) {
    if (a[2][1] == 'X'||a[2][1] == 'O')
        goto start;
    else
        a[2][1] = 'O';
   }
   
    else if (r == 9) {
    if (a[2][2] == 'X'||a[2][2] == 'O')
        goto start;
    else
        a[2][2] = 'O';
	}

	cout << r;

	while (n <= 100000000) {
		n++;
	}
	
	while (n >= -100000000) {
		n--;
	}
	}
		cout << "\nGAME OVER!";
	system("pause");
	system("cls");
	restart(a);
	break;
}
	case 2:   //deals with hard mode
	{
	while (gameover(a)) {
	    player:
		displayboard(a);
		cout << "Player 1[X] turn: ";
		cin >> choice;

		if (choice == 1) {
		if (a[0][0] == 'O' || a[0][0] == 'X')
		{
			invalid();
			goto player;
		}
			a[0][0] = 'X';
		}
		
		else if (choice == 2) {
		if (a[0][1] == 'O' || a[0][1] == 'X')
		{
			invalid();
			goto player;
		}
			a[0][1] = 'X';
		}
		
		else if (choice == 3) {
		if (a[0][2] == 'O' || a[0][2] == 'X')
		{
			invalid();
			goto player;
		}
			a[0][2] = 'X';
		}
		
		else if (choice == 4) {
		if (a[1][0] == 'O' || a[1][0] == 'X')
		{
			invalid();
			goto player;
		}
			a[1][0] = 'X';
		}
		
		else if (choice == 5) {
		if (a[1][1] == 'O' || a[1][1] == 'X')
		{
			invalid();
			goto player;
		}
			a[1][1] = 'X';
		}
		
		else if (choice == 6) {
		if (a[1][2] == 'O' || a[1][2] == 'X')
		{
			invalid();
			goto player;
		}
			a[1][2] = 'X';
		}
		
		else if (choice == 7) {
		if (a[2][0] == 'O' || a[2][0] == 'X')
		{
			invalid();
			goto player;
		}
			a[2][0] = 'X';
		}
		
		else if (choice == 8) {
		if (a[2][1] == 'O' || a[2][1] == 'X')
		{
			invalid();
			goto player;
		}
			a[2][1] = 'X';
		}
			
		else if (choice == 9) {
		if (a[2][2] == 'O' || a[2][2] == 'X')
		{
			invalid();
			goto player;
		}
		    a[2][2] = 'X';
		}
		
		else 
		{
    	    invalid();
			goto player;
		}
		
		if (gameover(a) == false) {
			break;
		}

	    starting:
		displayboard(a);
		cout << "CPU[O] turn: ";
		long long int n = -100000000;

		while (n <= 100000000) {
			n++;
		}
		
		

		int r;
		if (a[1][1]=='5')
		r=5;
		else{
		
		srand(time(0));
		r = (rand() % 9) + 1;
		if (a[0][0] != 'X' && (a[0][1] == 'O' && a[0][2] == 'O' || a[1][1] == 'O' && a[2][2] == 'O' || a[1][0] == 'O' && a[2][0] == 'O')) {
			r = 1;
		}
		
		else if (a[0][1] != 'X' && (a[0][0] == 'O' && a[0][2] == 'O' || a[1][1] == 'O' && a[2][1] == 'O')) {
			r = 2;
		}
		
		else if (a[0][2] != 'X' && (a[0][1] == 'O' && a[0][0] == 'O' || a[1][1] == 'O' && a[2][0] == 'O' || a[1][2] == 'O' && a[2][2] == 'O')) {
			r = 3;
		}
	
		else if (a[1][0] != 'X' && (a[0][0] == 'O' && a[2][0] == 'O' || a[1][1] == 'O' && a[1][2] == 'O')) {
			r = 4;
		}
				
		else if (a[1][1] != 'X' && (a[0][0] == 'O' && a[2][2] == 'O' || a[0][1] == 'O' && a[2][1] == 'O' || a[0][2] == 'O' && a[2][0] == 'O' || a[1][0] == 'O' && a[1][2] == 'O')) {
			r = 5;
		}
		
		else if (a[1][2] != 'X' && (a[0][2] == 'O' && a[2][2] == 'O' || a[1][0] == 'O' && a[1][1] == 'O')) {
			r = 6;
		}
							
		else if (a[2][0] != 'X' && (a[0][0] == 'O' && a[1][0] == 'O' || a[2][1] == 'O' && a[2][2] == 'O' || a[1][1] == 'O' && a[0][2] == 'O')) {
			r = 7;
		}
							
		else if (a[2][1] != 'X' && (a[0][0] == 'O' && a[1][1] == 'O' || a[2][0] == 'O' && a[2][2] == 'O')) {
			r = 8;
		}
									
		else if (a[2][2] != 'X' && (a[2][0] == 'O' && a[2][1] == 'O' || a[0][2] == 'O' && a[1][2] == 'O' || a[1][1] == 'O' && a[0][0] == 'O')) {
			r = 9;
		}
		
		else if (a[0][0] != 'O' && (a[0][1] == 'X' && a[0][2] == 'X' || a[1][1] == 'X' && a[2][2] == 'X' || a[1][0] == 'X' && a[2][0] == 'X')) {
			r = 1;
		}
											
		else if (a[0][1] != 'O' && (a[0][0] == 'X' && a[0][2] == 'X' || a[1][1] == 'X' && a[2][1] == 'X')) {
			r = 2;
		}
												
		else if (a[0][2] != 'O' && (a[0][1] == 'X' && a[0][0] == 'X' || a[1][1] == 'X' && a[2][0] == 'X' || a[1][2] == 'X' && a[2][2] == 'X')) {
			r = 3;
		}
												
		else if (a[1][0] != 'O' && (a[0][0] == 'X' && a[2][0] == 'X' || a[1][1] == 'X' && a[1][2] == 'X')) {
			r = 4;
		}
													
		else if (a[1][1] != 'O' && (a[0][0] == 'X' && a[2][2] == 'X' || a[0][1] == 'X' && a[2][1] == 'X' || a[0][2] == 'X' && a[2][0] == 'X' || a[1][0] == 'X' && a[1][2] == 'X')) {
			r = 5;
		}
														
		else if (a[1][2] != 'O' && (a[0][2] == 'X' && a[2][2] == 'X' || a[1][0] == 'X' && a[1][1] == 'X')) {
			r = 6;
		}
																
		else if (a[2][0] != 'O' && (a[0][0] == 'X' && a[1][0] == 'X' || a[2][1] == 'X' && a[2][2] == 'X' || a[1][1] == 'X' && a[0][2] == 'X')) {
			r = 7;
		}
	
		else if (a[2][1] != 'O' && (a[0][1] == 'X' && a[1][1] == 'X' || a[2][0] == 'X' && a[2][2] == 'X')) {
		    r = 8;
		}
		
		else if (a[2][2] != 'O' && (a[2][0] == 'X' && a[2][1] == 'X' || a[0][2] == 'X' && a[1][2] == 'X' || a[1][1] == 'X' && a[0][0] == 'X')) {
	    	r = 9;
		}
	}
		if (r == 1) {
		if (a[0][0] == 'X' || a[0][0] == 'O')
			goto starting;
		else
			a[0][0] = 'O';
		}
		
		else if (r == 2) {
    	if (a[0][1] == 'X' || a[0][1] == 'O')
			goto starting;
	    else
			a[0][1] = 'O';
			}
			
		else if (r == 3) {
		if (a[0][2] == 'X' || a[0][2] == 'O')
			goto starting;
		else
			a[0][2] = 'O';
		}
		
		else if (r == 4) {
		if (a[1][0] == 'X' || a[1][0] == 'O')
			goto starting;
		else
			a[1][0] = 'O';
		}
		
		else if (r == 5) {
		if (a[1][1] == 'X' || a[1][1] == 'O')
			goto starting;
		else
			a[1][1] = 'O';
		
		}
		else if (r == 6) {
		if (a[1][2] == 'X' || a[1][2] == 'O')
			goto starting;
		else
			a[1][2] = 'O';
		}
		
		else if (r == 7) {
		if (a[2][0] == 'X' || a[2][0] == 'O')
			goto starting;
		else
			a[2][0] = 'O';
		}
					
		else if (r == 8) {
		if (a[2][1] == 'X' || a[2][1] == 'O')
			goto starting;
		else
			a[2][1] = 'O';
		}
									
		else if (r == 9) {
		if (a[2][2] == 'X' || a[2][2] == 'O')
			goto starting;
		else
			a[2][2] = 'O';
		}
		
		cout << r;

		while (n >= -100000000) {
			n--;
		}
		
		while (n <= -100000000) {
			n++;
		}
	}
		cout << "\nGAME OVER!";
	system("pause");
	system("cls");
	restart(a);
	break;
}

	default:
	{
		invalid();
		goto startagain;
	}
}
	
}
void AddReview() //function for adding review
{
    ofstream review;
    review.open("playerreview.txt",ios::app);

    if (!review.is_open())
    {
        cout<<"Error opening file!";
    }
     string playername, reviews;
     cout<<"Enter player name:";
       getline(cin, playername);
     cout<<"Enter review:";
       getline(cin, reviews);
     review<<  playername<<" : "<< reviews << endl;
     cout<<"Review added successfully!"<<endl;
     cin.ignore();
     review.close();
}

void DisplayReview() //function for displaying reviews
{
	system("cls");
    ifstream review;
    review.open("playerreview.txt", ios::in);
    if (!review.is_open())
    {
        cout<<"Error opening file!";
    }
    string a;
    while (getline(review, a))
    {
        cout<<a<<endl;
    }
    review.close();
}

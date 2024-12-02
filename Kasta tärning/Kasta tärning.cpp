#include <iostream>
#include <ctime>
using namespace std;

//Lägg till ålderskontroll så spelaren är minst 3 år gammal

int saldo = 2000;
int maxsaldo = 5000;
int tal = 0;
int spelart = 0;
int datort = 0;
int spelart2 = 0;
int datort2 = 0;
int totalbetting = 0;
int tangentbord = 0;
int SpelarV = 0;
int DatorV = 0;
int Oavgjort = 0;
string val;

int main() {



	//Alla variablar jag använder, samt randomisern

	srand(time(0));

	spelart = rand() % 6 + 1;
	datort = rand() % 6 + 1;
	spelart2 = rand() % 6 + 1;
	datort2 = rand() % 6 + 1;



	cout << "Welcome to Throw Dice" << endl;
	cout << "Start(1) Rules(2) End(3)" << endl;
	cin >> val;

	//Välkomstmeny med olika val


	while (1 == 1) {
		if (val == "1") {
			cout << "Starting the game" << endl;
			cout << "Your balance is: ";
			cout << saldo;
			cout << "Kr" << endl;
		}
		else if (val == "2") {
			cout << "Here i will write rules, please restart game" << endl;
			break;

		}
		else if (val == "3") {
			cout << "Exiting game" << endl;
			break;
		}

		else {
			cout << "Not an option, shutdown imminent" << endl;
			break;
		}

		cout << endl;
		cout << "How much do you want to bet?" << endl;
		cout << "100kr(1) 300kr(2) 500kr(3)" << endl;
		cin >> val;

		//Bettingmeny med olika val

		while (2 == 2) {
			if (val == "1") {
				cout << "You have chosen to bet 100kr, your balance is now: ";
				totalbetting = 100;
				cout << saldo - 100;
				cout << "kr" << endl;
			}
			else if (val == "2") {
				cout << "You have chosen to bet 300kr, your balance is now: ";
				totalbetting = 300;
				cout << saldo - 300;
				cout << "kr" << endl;
			}
			else if (val == "3") {
				cout << "You have chosen to bet 500kr, your balance is now: ";
				totalbetting = 500;
				cout << saldo - 500;
				cout << "kr" << endl;
			}
			else {
				cout << "Not an option, shutdown imminent" << endl;
				break;
			}

			//Tärningsrullning (spelet börjar)

			cout << endl;
			cout << "Now let the games begin, write whatever you want and press ENTER" << endl;
			cin >> tangentbord;
			cout << endl;
			cout << "You got the number: ";
			cout << spelart << endl;
			cout << "Computer got the number: ";
			cout << datort << endl;
			cout << endl;

			while (3 == 3) {
				if (spelart > datort) {
					SpelarV ++;
					cout << "Congratulations, you won the first round" << endl;
				}
				else if (datort > spelart) {
					DatorV ++;
					cout << "Better luck next time, but for now, you are thy loser" << endl;
				}
				else if (spelart == datort) {
					Oavgjort ++;
					cout << "Welp" << endl;
				}
				else {
					cout << "Uhhhhh HUH?! How in the **** did you manage this" << endl;
				}

				spelart = spelart2;
				datort = datort2;

				cout << endl;
				cout << "Type anything then press ENTER" << endl;

				cin >> tangentbord;

				cout << endl;
				cout << "You got the number: ";
				cout << spelart2 << endl;
				cout << "Computer got the number: ";
				cout << datort2 << endl;
				cout << endl;

				if (spelart2 > datort2) {
					SpelarV ++;
					cout << "Congratulations, you won the second round" << endl;
				}
				else if(spelart2 < datort2) { 
					DatorV ++;
					cout << "Womp Womp, you lost the second round ya womping loser" << endl;
				}
				else if (spelart2 == datort2){
					Oavgjort ++;
					cout << "Better luck next time" << endl;
				}

				cout << endl;
				cout << "Write anything then press ENTER";
				cin >> tangentbord;

				if (SpelarV == 2){
					cout << "Player won 2 rounds in a row, game will now end" << endl;
					saldo = saldo + (totalbetting * 1);
					cout << endl;
					return main();
				}
				else if (DatorV == 2){
					cout << "Computer won 2 rounds in a row, game will now end" << endl;
					saldo = saldo - (totalbetting * 1);
					cout << endl;
					return main();
				}
				else if (SpelarV == 1){
					cout << "Time for round 3" << endl;
					
				}
				else if (DatorV == 1){
					cout << "Time for round 3" << endl;
					
				}
				else if (Oavgjort == 2) {
					cout << "A tie, time for round 3" << endl;
					
				}

				return main();

			}
			

		}
		return 0;
	}



}
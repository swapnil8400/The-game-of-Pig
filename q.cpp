// q.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int Roll() 
{
	int random = rand();
	int z=(random%6)+1;
	return z; 
}

int humanTurn(int humanScore)
{
	int Rollthedice; 
	int temporaryscore = 0; 
	char input = 'r';

	while (input!='r' || input!='h')
	{
		cout <<"Please enter a valid input " << endl;
		if(input=='r' || input=='h')
		{
			break;  
		}
	}

	while (input == 'r')
	{
		Rollthedice = Roll();  
		cout << "Rolling: " << Rollthedice << endl;

		if (Rollthedice == 1)
		{
			temporaryscore = 0;
			cout << "	Opps! Got Busted. No score on this turn." << endl << endl << endl;
			break;   // change of turn to computer
		}

		else
		{
			temporaryscore = temporaryscore + Rollthedice;
			cout <<	"	Turn Total : " << temporaryscore << endl; 
			cout << "	Human Total Score (if opted to hold): " << humanScore + temporaryscore << endl;
			cout << "	Roll Again or Hold? (r/h): ";
			cin >> input; 
		}
	}

	cout << endl << endl;
	return (humanScore + temporaryscore); 
}

int computerTurn (int computerscore) 
{
	int temporaryscore = 0; 
	int Rollthedice = 0;

	while ((temporaryscore < 20) && (Rollthedice != 1)) 
	{ 
		Rollthedice = Roll();   
		cout << "Rolling: " << Rollthedice << endl;

		if (Rollthedice == 1) 
		{
			temporaryscore = 0; 
			cout << "	Opps! Got Busted. No score on this turn." << endl << endl << endl;
			break;   // change of turn to human

		} else
		{

			temporaryscore =temporaryscore +  Rollthedice; 
			cout << "Rolling: " << Rollthedice << endl; 
			cout <<	"	Turn Total : " << temporaryscore << endl; 
			cout << "	Computer Total Score (if opted to hold): " << computerscore + temporaryscore << endl;
		}
	}

	cout << endl << endl;
	return ( computerscore + temporaryscore ); 
}



int main() 
{
	int humanTotalScore = 0, computerTotalScore = 0;

	while (true)
	{
		cout << endl << endl <<"Human Playing..." << endl;
		humanTotalScore = humanTurn(humanTotalScore);
		if ( humanTotalScore >= 100 ) 
		{
			cout << "Human Player Won!" << endl;
			break;
		}
		cout << endl <<endl <<"Computer Playing ... " <<endl;
		computerTotalScore = computerTurn(computerTotalScore);
		if ( computerTotalScore >= 100)
		{
			cout << "Computer Player Won!" << endl << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
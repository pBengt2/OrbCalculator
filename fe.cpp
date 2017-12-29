#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int numTrials = 50000;
const int numOrbs = 200;

const int startingAppearence = 1900;
const int numToSummon = 2;

bool sum(const int& appRate){
	return ((rand()%10000) <= appRate);
}

int subOrbs(int i){
	if (i==0)
		return 5;
	else if (i == 4)
		return 3;
	else
		return 4;	
}

int summon(int& curOrbs, const int& appRate, int& numSinceFive, int n){
	int curFive = 0;
	
	for (int i=0; i<n; i++){
		curOrbs -= subOrbs(i);	
		if (sum(appRate)){
			curFive++;
			numSinceFive = 0;
		}
		else{
			numSinceFive++;
		}
	}
	if (curFive != 0 && n != 5){
		for (int i=n; i<5; i++){
			if (curOrbs < subOrbs(i))
				return curFive;
			curOrbs -= subOrbs(i);
			if (sum(appRate)){
				curFive++;
				numSinceFive = 0;
			}
			else{
				numSinceFive++;
			}			
		}
	}
	return curFive;
}

int main(){
	srand(time(NULL));
	
	long int total = 0;
	
	cout << numTrials << " trials; " 
		 << numOrbs << " orbs; "
		 << (double)startingAppearence/100.00 << "% appeareance rate; "
		 << "summon " << numToSummon << " when >= 19.00%\n";
	
	for (int i=0; i<numTrials; i++){
		int curOrbs = numOrbs;
		int appRate = startingAppearence;
		int numFive = 0;
		int numSinceFive = 0;

		while (curOrbs >= 20){
			int curFive = 0;
			if (appRate <= 1000)
				curFive += summon(curOrbs, appRate, numSinceFive, 5);
			else{
				curFive += summon(curOrbs, appRate, numSinceFive, numToSummon);
			}
			numFive += curFive;		
			if (numSinceFive >= 5){
				numSinceFive -= 5;
				appRate += 50;
			}
			if (curFive != 0){
				appRate = 600;
			}
		}
		if (curOrbs >= 17){
			summon(curOrbs, appRate, numSinceFive, 4);
		}
		else if (curOrbs >= 13){
			summon(curOrbs, appRate, numSinceFive, 3);
		}
		else if (curOrbs >= 8){
			summon(curOrbs, appRate, numSinceFive, 2);
		}
		else if (curOrbs >= 5){
			summon(curOrbs, appRate, numSinceFive, 1);
		}
		
		total+=numFive;
	}
	cout << "Total Five: " << total/(double)numTrials;
}
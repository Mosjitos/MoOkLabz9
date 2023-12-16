#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
    double initL, rate, pay;
	cout << "Enter initial loan: ";
    cin >> initL;
	cout << "Enter interest rate per year (%): ";
    cin >> rate;
	cout << "Enter amount you can pay per year: ";
    cin >> pay;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect

	//first round add way too many input, so I set first round saparately. In order to print out payment and NewBalance, I need to check the condition before print out.
	//I need to do it, Dahhh!!.
    double prevB=initL,  interest, total, newB;

    cout << fixed << setprecision(2); 
	cout << setw(13) << left << 1; 
	cout << setw(13) << left << prevB;
        interest = prevB*(rate/100);
	cout << setw(13) << left << interest;
        total = prevB + interest;
	cout << setw(13) << left << total;
	if(pay < total){
            cout << setw(13) << left << pay;
    }else{cout << setw(13) << left << total;}
        newB = total - pay;
    if(newB > 0){
        cout << setw(13) << left << newB;
    }else{cout << setw(13) << left << 0.00;}
	cout << "\n";	
    
    int i=2;
	//in do-while I added break in sub if-else, because I wanted to end da loop.
    do{
    if(prevB > pay){
        cout << setw(13) << left << i; 
        cout << setw(13) << left << newB;
            interest = newB*(rate/100);
	    cout << setw(13) << left << interest;
            total = newB + interest;
        cout << setw(13) << left << total;
        if(pay < total){
            cout << setw(13) << left << pay;
        }else{cout << setw(13) << left << total;}
        newB = total - pay;
        if(newB > 0){
            cout << setw(13) << left << newB;
        }else{cout << setw(13) << left << 0.00; break;}
        cout << "\n";
        ++i;
    } else break;
    } while (true);
	
	return 0;
}

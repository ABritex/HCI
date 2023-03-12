#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> // Include this header for fixed and setprecision
using namespace std;

// Define rarity types and probabilities
enum Rarity {Common = 0, Rare = 1, Epic = 2, Legend = 3};
const double prob[4] = {0.67, 0.25, 0.07, 0.01}; // Change probabilities here

// Simulate one pull and return rarity type
Rarity pull() {
    double r = (double)rand() / RAND_MAX; // Generate random number between 0 and 1
    double sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += prob[i];
        if (r <= sum) return (Rarity)i;
    }
    return Common; // Default case
}

// Simulate n pulls and print average percentage of each rarity type
void gacha(int n) {
    int count[4] = {0}; // Initialize counters for each rarity type
    for (int i = 0; i < n; i++) {
        Rarity r = pull(); // Simulate one pull
        count[r]++; // Increment counter for pulled rarity type
        
        // Print how many of each rarity type are obtained after each pull
    }
    
    // Print average percentage of each rarity type after all pulls
    cout<< "After "<< n<< " pulls, here are the average percentages of each rarity type:\n"; 
    cout<< "Common: "<< fixed<< setprecision(4)<< (double)count[Common]/ n*100<< "%\t("<< count[Common]<< " items)\n"; 
    cout<< "Rare: "<< fixed<< setprecision(4)<< (double)count[Rare]/ n*100<< "%\t("<< count[Rare]<< " items)\n"; 
    cout<< "Epic: "<< fixed<< setprecision(4)<< (double)count[Epic]/ n*100<< "%\t("<< count[Epic]<< " items)\n"; 
    cout<< "Legend: "<< fixed<< setprecision(4)<< (double)count[Legend]/ n*100<< "%\t("<< count[Legend]<< " items)\n"; 
}

int main() {
    srand(time(NULL)); 
    int num;
    
     do {
         cout<<"\nHow many pulls do you want to do? Enter a positive integer or enter zero to stop.\n";
         cin >> num;
         if(num > 0 ) gacha(num); 
         else if(num < 0 ) cout<<"\nInvalid input.Please try again.\n"; 
     } while(num != 0 ); 
}
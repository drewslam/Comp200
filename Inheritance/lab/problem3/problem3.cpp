#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Define a PrintVector function that prints an vector of plant (or flower) object pointers
void PrintVector(vector<Plant*> garden) {
   for (unsigned int i = 0; i < garden.size(); i++) {
      cout << "Plant " << i + 1 << " Information:" << endl;
      garden.at(i)->PrintInfo();
      cout << endl;
   }
}

int main() {
   vector<Plant*> myGarden;
   string plantName;
   int plantCost;
   string flowerName;
   int flowerCost;
   string colorOfFlowers;
   string isAnnualStr;
   bool isAnnual;
   string input;

   cin >> input;
   
   while(input != "-1") {
      // cin.ignore();
      if (input == "flower") {
         Flower* newFlower = new Flower;
         cin >> flowerName;
         cin >> flowerCost;
         cin >> isAnnualStr;
         if (isAnnualStr == "true") {
            isAnnual = true;
         } else {
            isAnnual = false;
         }
         cin >> colorOfFlowers;
         newFlower->SetPlantName(flowerName);
         newFlower->SetPlantCost(flowerCost);
         newFlower->SetPlantType(isAnnual);
         newFlower->SetColorOfFlowers(colorOfFlowers);
         myGarden.push_back(newFlower);
      } else {
         Plant* newPlant = new Plant;
         cin >> plantName;
         cin >> plantCost;
         newPlant->SetPlantName(plantName);
         newPlant->SetPlantCost(plantCost);
         myGarden.push_back(newPlant);
      }
      cin >> input;
   }

   PrintVector(myGarden);

   for (size_t i = 0; i < myGarden.size(); ++i) {
      delete myGarden.at(i);
   }
   
   return 0;
}

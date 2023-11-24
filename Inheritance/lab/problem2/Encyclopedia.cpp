#include "Encyclopedia.h"
#include <iostream>

void Encyclopedia::SetEdition(string edition) {
   this->edition = edition;
}

void Encyclopedia::SetNumPages(int pages) {
   this->pages = pages;
}

string Encyclopedia::GetEdition() const {
   return this->edition;   
}

int Encyclopedia::GetNumPages() const {
   return this->pages;   
}

void Encyclopedia::PrintInfo(){
   Book::PrintInfo();
   cout << "   Edition: " << this->GetEdition() << endl;
   cout << "   Number of Pages: " << this->GetNumPages() << endl;
}

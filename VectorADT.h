#ifndef VECTORADT_H
#define VECTORADT_H

#include <string>
#include <vector>
using namespace std;

class ItemToPurchase {
  public:
    ItemToPurchase();
    ItemToPurchase(string in, string d, int p, int q);
    void SetName(string iname);
    string GetName() const;
    void SetDescription(string id);
    string GetDescription() const;
    void SetPrice(int p);
    int GetPrice() const;
    void SetQuantity(int q);
    int GetQuantity() const;
    void PrintItemCost();
    void PrintItemDescription();
  private:
    double * array;
    int size;    //the number of doubles stored in array
    int capacity;  //the maximum number of doubles that can be stored in array
};
#endif

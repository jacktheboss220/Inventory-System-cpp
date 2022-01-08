#include <iostream>
#include <string.h>
using namespace std;
int count = 0;


class info
{
public:
    char name[50];
    int price;
    int quan;
};


//***********************************************
//*************HEADERS FILES USED****************
//***********************************************
void addItems(info list[], int c);
void buyItems(info list[]);
void displayItems(info list[]);
void DealersMenu(info list[]);
void consumerMenu(info list[]);
void modifyItems(info list[], int c);


void DealersMenu(info list[])
{
    cout << "\n=============================";
    cout << "\nEnter the Passward : ";
    char ch[50];
    cin >> ch;
    int c;
    if (strcmp(ch, "pass") == 0)
    {
        while (true)
        {
            int k;
            cout << "1.Add Item.\n2.To Modify";
            cout << "\nEnter : ";
            cin >> k;

            if (k == 1)
            {
                cout << "\nEnter the number of product you want to enter : ";
                cin >> count;
                addItems(list, count);
                break;
            }
            else if (k == 2)
            {
                if (count <= 0)
                {
                    cout << "\nFirst Add few Items.\n";
                }
                else
                {
                    modifyItems(list, count);
                    break;
                }
            }
            else
            {
                cout << "\nEnter correctly.";
            }
        }
    }
    cout << "\n=============================\n\n";
}

void consumerMenu(info list[])
{
    displayItems(list);
    buyItems(list);
}

void addItems(info list[], int c)
{
    for (int i = 0; i < c; i++)
    {
        cout << "\n=============================";
        cout << "\nEnter the Name : ";
        cin >> list[i].name;
        cout << "\nEnter the price : ";
        cin >> list[i].price;
        cout << "\nEnter the Quantity : ";
        cin >> list[i].quan;
        cout << endl;
        cout << "\n=============================";
    }
}

void displayItems(info list[])
{
    cout << "\n=============================";
    cout << "\nName\t\tPrice(Rs.)\t  Quantity" << endl;
    for (int i = 0; i < count; i++)
    {
        if (list[i].quan > 0)
            cout << list[i].name << "\t\t" << list[i].price << "\t\t    " << list[i].quan << endl;
    }
    cout << "\n=============================\n";
}

void buyItems(info list[])
{
    int price = 0;
    cout << "\n=============================";
    cout << "\nEnter Name of Item To Buy : ";
    char name[50];
    cin >> name;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(list[i].name, name) == 0)
        {
            while (true)
            {
                int q;
                cout << "\nEnter the Quantity to Buy : ";
                cin >> q;
                if (q <= list[i].quan)
                {
                    price = list[i].price * q;
                    list[i].quan -= q;
                    break;
                }
                else
                {
                    cout << "\nPlease Enter within Range : ";
                }
            }
        }
    }
    cout << "\n=============================";
    if (price > 0)
    {
        cout << "\nPrice To Be Paid : " << price;
        cout << "\n=============================";
        cout << "\nThanks For Shoping!!";
        cout << "\n=============================";
        cout << "\n=============================";
    }
}

void modifyItems(info list[], int c)
{
    displayItems(list);
    char ch[50];
    cout << "\n=============================";
    cout << "\nEnter the Product name : ";
    cin >> ch;
    for (int i = 0; i < c; i++)
    {
        if (strcmp(list[i].name, ch) == 0)
        {
            cout << "Enter the changed Name : ";
            cin >> list[i].name;
            cout << "Enter the price : ";
            cin >> list[i].price;
            cout << "Enter the Quantity : ";
            cin >> list[i].quan;
        }
        cout << "\n=============================\n\n";
    }
}

int main()
{
    int j;
    while (true)
    {
        cout << "\n\n\t|============ WELCOME TO STORE inventory MANAGEMENT ============|";
        cout << "\n\t\t       STORE inventory  MANAGEMENT SYSTEM\n";
        cout << "\t\t\t ==========================";
        cout << "\n\n\t\t\t   1. Dealer Menu\n\n\t\t\t   2. Customer Menu\n\n\t\t\t   3. Exit\n";
        cout << "\t\t\t ============================\n";
        cout << "\n\nEnter Your Choice:";
        cin >> j;
        info list[50];
        if (j == 1)
        {
            DealersMenu(list);
        }
        if (j == 2)
        {
            if (count <= 0)
            {
                cout << "\nWait For Dealer to add new items.";
            }
            else
                consumerMenu(list);
        }
        if (j == 3)
        {
            cout << "\n=============================";
            cout << "\n=============================";
            cout << "\nThanks For Shoping!!";
            cout << "\n=============================";
            cout << "\n=============================";
            break;
        }
    }
    return 0;
}
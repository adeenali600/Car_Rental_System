#include <iostream>
#include <vector>
#include <fstream>
#include "project.h"

using namespace std;

int main()
{
    Cars c;
    Customer cust;
    Layout l;
    l.logo();
    l.car_RENTAL_SYSTEM();

    return 0;
}

void Cars::add_cars()
{
    string carName;
    int carPrice, carQuant;
    for (i; i < 100; i++)
    {

        cout << "ENTER THE CAR NAME:";
        cin >> carName;
        name.push_back(carName);
        if (name[i] == "end" || name[i] == "END")
        {
            name[i] = " ";
            quantity[i] = 0;
            price[i] = 0;
            break;
        }
        cout << "ENTER THE PRICE OF THE CAR:";
        cin >> carPrice;
        price.push_back(carPrice);
        cout << "ENTER THE QUANTITY OF THE CAR";
        cin >> carQuant;
        quantity.push_back(carQuant);
    }
}

void Cars::display()
{

    cout << "NAME     |     PRICE     |     QUANTITY      " << endl;
    for (int j = 0; j < 100; j++)
    {
        if (price[j] == 0)
        {
            if (name[j] == " ")
            {
                break;
            }
        }
        cout << name[j] << "\t\t" << price[j] << "\t\t" << quantity[j] << endl;
    }

    ofstream f;
    f.open("inventory.xls");

    f << "NAME     |     PRICE     |     QUANTITY      " << endl;
    for (int j = 0; j < 3; j++)
    {
        if (price[j] == 0)
        {
            if (name[j] == " ")
            {
                break;
            }
        }
        f << name[j] << "\t\t" << price[j] << "\t\t" << quantity[j] << endl;
    }
    f.close();
}

void Cars::remove_cars()
{
    string n;

    cout << "ENTER THE NAME OF THE CAR WHICH YOU WANT TO REMOVE:";
    cin >> n;

    for (int j = 0; j < 100; j++)
    {
        if (name[j] == n)
        {
            name[j] = "NULL";
            price[j] = 0;
            quantity[j] = 0;
        }
    }
}
/////////////////////////////////////////////

void Admin::login()
{
    string usernmame, password;

    cout << "ENTER THE USER_NAME:" << endl;
    cin >> usernmame;

    cout << "ENTER THE PASSWORD:";
    cin >> password;

    if (usernmame == admin_username && password == admin_password)
    {
        cout << "YOU ARE LOGGED IN SUCCESSFULLY!!!" << endl;
    }
    else
    {
        cout << "WRONG PASSWORD OR A WRONG USERNAME!!!" << endl;
        cout << "ENTER THE USER_NAME AND PASSWORD AGAIN:" << endl;

        for (int j = 1; j > 0; j++)
        {
            cout << "USER_NAME=" << endl;
            cin >> usernmame;

            cout << "PASSWORD=" << endl;
            cin >> password;

            if (usernmame == admin_username && password == admin_password)
            {
                cout << "YOU ARE LOGGED IN SUCCESSFULLY!!!";

                break;
            }
        }
    }
}

void Admin::singin()
{
    cout << "NAME=" << endl;
    cin >> admin_name;

    cout << "MOBILE_NUMBER=" << endl;
    cin >> admin_mo_no;

    cout << "ADDRESS=" << endl;
    cin >> admin_address;

    cout << "USER_NAME=" << endl;
    cin >> admin_username;

    cout << "PASSWORD=" << endl;
    cin >> admin_password;

    cout << "REGESTERED SUCESSFULLY!!!" << endl
         << endl;
}
////////////////////////

void Customer::booking()
{
    set();
    cout << "NAME=";
    cin >> cust_name;
    cout << "MOBILE_NUMBER=:";
    cin >> cust_mob;
    cout << endl
         << endl
         << endl;
    display();

    cout << endl;
    cout << "CHOOSE YOUR FAVOURITE CAR:" << endl
         << endl;
    for (i; i < 1000; i++)
    {
        cout << "ENTER THE CAR:";
        cin >> crs[i];
        if (crs[i] == "end" || crs[i] == "END")
        {
            crs[i] = " ";
            quant[i] = 0;
            break;
        }
        cout << "QUANTITY:";
        cin >> quant[i];
        count++;

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                if (name[i] == crs[j])
                {
                    quantity[i] = quantity[i] - quant[i];
                }
            }
        }
    }
}

void Customer::cancel_booking()
{
    string n;
    cout << "do you really want to cancel the booking(yes or no):";
    cin >> n;

    if (n == "yes" || n == "YES")
    {
        for (int i = 0; i < 500; i++)
        {
            crs[i] = "NULL";
            quant[i] = 0;
        }
    }
}

void Customer::update_booking()
{
    string x;
    int d;
    cout << "do you really want to update your booking(yes or no):";
    cin >> x;

    if (x == "yes" || x == "YES")
    {
        cout << "press 1 to add:" << endl;
        cout << "press 2 to subt:" << endl;
        cout << "press 3 to do a new new:" << endl;
        cin >> d;
        if (d == 1)
        {
            display();
            cout << endl;
            cout << "CHOOSE:";
            for (i; i < 1000; i++)
            {
                cout << "ENTER THE CAR:";
                cin >> crs[i];

                if (crs[i] == "end" || crs[i] == "END")
                {
                    crs[i] = " ";
                    break;
                }
                cout << "ENTER THE QUANTITY:";
                cin >> quant[i];
            }
        }
        if (d == 2)
        {

            string n;

            cout << "ENTER THE NAME OF THE CAR:";
            cin >> n;

            for (int j = 0; j < 100; j++)
            {
                if (crs[j] == n)
                {
                    crs[j] = "NULL";
                    quant[j] = 0;
                }
            }
        }
        if (d == 3)
        {

            display();

            cout << endl;
            cout << "CHOOSE THE CAR:" << endl;
            for (int i = 0; i < 1000; i++)
            {
                cout << "ENTER THE CAR:";
                cin >> crs[i];
                if (crs[i] == "end" || crs[i] == "END")
                {
                    crs[i] = " ";
                    break;
                }
                cout << "ENTER THE QUANTITY:";
                cin >> quant[i];
            }
        }
    }
}

void Customer::display_booking()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (name[i] == crs[j])
            {
                pric[i] = price[i];
            }
        }
    }

    cout << "name     |     price     |     quantity      " << endl;
    for (int j = 0; j < 100; j++)
    {
        if (price[j] == 0)
        {
            if (name[j] == " ")
            {
                break;
            }
        }
        cout << crs[j] << "\t\t" << pric[j] << "\t\t" << quant[j] << endl;
    }
}

void Customer::create_bill_Display()
{
    cout << "name=" << cust_name << endl;
    cout << "mobile number:" << cust_mob << endl;
    display_booking();
    cout << "total=" << total << endl;

    ofstream f1;
    f1.open("billing.xls");

    f1 << cust_name << endl;
    f1 << cust_mob << endl;
    f1 << total << endl;
}

void Customer::set()
{
    for (int i = 0; i < 100; i++)
    {
        pric[i] = 0;
    }
}

void Customer::total1()
{
    for (int i = 0; i < count; i++)
    {

        total = total + (pric[i] * quant[i]);
    }
}
////////////////////////////////////////

void Layout::logo()
{
    cout << "=========================================================================================" << endl;
    cout << "    ||            ||    |||||||  ||        |||||||   ||||||||  ||  ||     || ||  |||||||  " << endl;
    cout << "    ||            ||    ||       ||        ||        ||    ||  ||   ||  ||   ||  ||       " << endl;
    cout << "    ||     ||     ||    |||||    ||        ||        ||    ||  ||     ||     ||  |||||    " << endl;
    cout << "    ||   ||  ||   ||    ||       ||        ||        ||    ||  ||            ||  ||       " << endl;
    cout << "    || ||      || ||    |||||||  ||||||||  |||||||   ||||||||  ||            ||  |||||||  " << endl;
    cout << "                                                                                          " << endl;
    cout << "                                                                                          " << endl;
    cout << "                          ||||||||||||     ||||||||||                                    " << endl;
    cout << "                               |||         ||      ||                                    " << endl;
    cout << "                               |||         ||      ||                                    " << endl;
    cout << "                               |||         ||      ||                                    " << endl;
    cout << "                               |||         ||||||||||                                    " << endl;
    cout << "                                                                                         " << endl;
    cout << "                                                                                         " << endl;
    cout << "                 ||||||||||      |||      |||       ||||||||||                           " << endl;
    cout << "                 ||      ||      |||      |||       ||      ||                           " << endl;
    cout << "                 ||      ||      |||      |||       ||      ||                           " << endl;
    cout << "                 ||||||||||      |||      |||       ||||||||||                           " << endl;
    cout << "                 ||      ||      |||      |||       ||      ||                           " << endl;
    cout << "                 ||      ||      |||      |||       ||      ||                           " << endl;
    cout << "                 ||      ||deen  ||||||||||||mer    ||      ||rsalan                           " << endl;
    cout << "                                                                                         " << endl;
    cout << "                                                                                         " << endl;
    cout << "                         ||||||||  |||||||||  |||||||                                    " << endl;
    cout << "                         ||        ||     ||  ||   ||                                    " << endl;
    cout << "                         ||        ||     ||  ||   ||                                    " << endl;
    cout << "                         ||        |||||||||  |||||||                                    " << endl;
    cout << "                         ||        ||     ||  ||||                                       " << endl;
    cout << "                         ||        ||     ||  ||  ||                                     " << endl;
    cout << "                         ||||||||  ||     ||  ||    ||                                   " << endl;
    cout << "                                                                                         " << endl;
    cout << "                                                                                         " << endl;
    cout << "            |||||||  |||||||  ||     ||  ||||||||   ||||||||  ||                         " << endl;
    cout << "            ||   ||  ||       || ||  ||     ||      ||    ||  ||                          " << endl;
    cout << "            |||||||  |||||    ||   ||||     ||      ||||||||  ||                          " << endl;
    cout << "            ||       ||       ||     ||     ||      ||    ||  ||                          " << endl;
    cout << "            || ||    |||||||  ||     ||     ||      ||    ||  |||||||||                   " << endl;
    cout << "            ||   ||                                                                       " << endl;
    cout << "==========================================================================================" << endl;
}

void Layout::car_RENTAL_SYSTEM()
{
    int p1;

    for (int i = 1; i > 0; i++)
    {
        cout << "WELCOME TO AUA(ARSALAN-UMER-ADEEN) RENTAL SYSTEM!!!" << endl
             << endl;

        cout << "ADMIN OR A CUSTOMER:" << endl;
        cout << "PRESS 1 FOR ADMIN:" << endl;
        cout << "PRESS 2 FOR CUSTOMER:" << endl;
        cin >> p1;

        if (p1 == 1)
        {
            for (int i = 1; i > 0; i++)
            {
                cout << "IF YOU HAVE A ACCOUNT PLZZ LOGIN AND IF NOT THEN SIGN IN  FIRST!!!" << endl;
                cout << "PRESS 1 FOR SIGN_IN:" << endl;
                cout << "PRESS 2 FOR LOGIN:" << endl;
                cout << "PRESS 3 FOR END:" << endl;
                cin >> p1;

                if (p1 == 1)
                {
                    singin();
                }
                if (p1 == 2)
                {
                    login();
                    for (int i = 1; i > 0; i++)
                    {

                        cout << "WELCOME TO AUA(ARSALAN-UMER-ADEEN) RENTAL SYSTEM!!! " << endl;
                        cout << "PRESS 1 FOR ADD CARS:" << endl;
                        cout << "PRESS 2 FOR DISPLAY AVAILABLE CARS:" << endl;
                        cout << "PRESS 3 FOR REMOVE CARS:" << endl;
                        cout << "PRESS 4 FOR TO END:" << endl;
                        cin >> p1;

                        if (p1 == 1)
                        {
                            add_cars();
                        }
                        if (p1 == 2)
                        {
                            display();
                        }
                        if (p1 == 3)
                        {
                            remove_cars();
                        }
                        if (p1 == 4)
                        {
                            break;
                        }
                    }
                }
                if (p1 == 3)
                {
                    break;
                }
            }
        }
        if (p1 == 2)
        {

            for (int i = 1; i > 0; i++)
            {
                cout << "WELCOME AUA(ARSALAN-UMER-ADEEN) RENTAL SYSTEM!!! " << endl;

                cout << "PRESS 1 FOR BOOKING:" << endl;
                cout << "PRESS 2 FOR CANCEL BOOKING:" << endl;
                cout << "PRESS 3 FOR UPDATE BOOKING:" << endl;
                cout << "PRESS 4 FOR DISPLAY BOOKING:" << endl;
                cout << "PRESS 5 FOR CREATE BILL:" << endl;
                cout << "PRESS 6 FOR END:" << endl;
                cin >> p1;

                if (p1 == 1)
                {
                    booking();
                }
                if (p1 == 2)
                {
                    cancel_booking();
                }
                if (p1 == 3)
                {
                    update_booking();
                }
                if (p1 == 4)
                {
                    display_booking();
                }
                if (p1 == 5)
                {

                    for (int i = 0; i < 100; i++)
                    {
                        for (int j = 0; j < 100; j++)
                        {
                            if (name[i] == crs[j])
                            {
                                pric[i] = price[i];
                            }
                        }
                    }

                    total1();
                    create_bill_Display();
                }
                if (p1 == 6)
                {
                    break;
                }
            }
        }
    }
}

#include <iostream>
#include <string>
#include <cstdlib> // For system("cls")
using namespace std;

int displayOptions(string* opt, int size, string name) {
    for(int i = 0; i < size; i++) {
        cout << i + 1 << ". " << opt[i] << endl;
    }
    int input;
    cout << "\nChoose your " << name << " option #: ";
    cin >> input;
    input--;
    system("cls");
    return input;
}

double calculateCost(double car, double choice, int part) {
    double total = car * choice * part;
    return total;
}

int main() {
    cout << "\t\t======== HAFIZ AUTO WORKSHOP ======== \n\n" << endl;

    char ch;
    double cost = 0;
    double modelCost[20];
    string modelName[20];
    string brandName;
    int choice;
    string brands[] = {"Honda", "Toyota", "Hyundai", "Suzuki"};

    string honda[] = {"Civic", "City", "BR-V", "CR-V"};
    double carsValue[] = {1.2, 1.5, 1.9, 1.1};

    string toyota[] = {"Fortuner", "Grande", "Vitz", "Prius"};
    double cars1Value[] = {2.5, 1.7, 1.2, 1.7};

    string hyundai[] = {"Tuscon", "Elantra", "Sonata", "Picanto"};
    double cars2Value[] = {1.7, 1.5, 1.5, 1.1};

    string suzuki[] = {"Cultus", "Swift", "Alto", "Ciaz"};
    double cars3Value[] = {0.7, 0.5, 0.3, 0.9};

    string choices[] = {"Denting", "Painting", "Polishing", "Washing", "Wax"};
    double choiceValue[] = {2.3, 2.0, 1.3, 1.0, 1.5};

    string parts[] = {" Roof", " Bonnet", " Front Bumper", " Rear Bumper", " Left Fender", " Right Fender", " Left Quarter Panel", " Right Quarter Panel", " Front Door Left", "Front Door Right", "Rear Door Left", "Rear Door Right", "Full Body", "Full/Wash"};
    int prices[] = {8000, 6000, 2500, 2500, 3500, 3500, 3600, 3600, 4500, 4500, 4900, 4900, 50000, 500};

    int cartCars[20];
    int cartChoice[20];
    int cartPart[20];
    double cartPrice[20];
    int index = 0;
    int model;
    cout << "\t\t======== AVAILABLE BRANDS ======== \n\n" << endl;
    cout << "1. Honda\n";
    cout << "2. Toyota\n";
    cout << "3. Hyundai\n";
    cout << "4. Suzuki\n";
    cout << "\nSelect your brand #: ";
    cin >> choice;
    system("cls");
    cout << "\n\n\t\t======== AVAILABLE MODELS ======== \n\n" << endl;
    switch (choice) {
        case 1:
            model = displayOptions(honda, 4, "Model");
            for (int i = 0; i < 4; ++i) {
                modelCost[i] = carsValue[i];
                modelName[i] = honda[i];
            }
            brandName = "Honda";
            break;
        case 2:
            model = displayOptions(toyota, 4, "Model");
            for (int i = 0; i < 4; ++i) {
                modelCost[i] = cars1Value[i];
                modelName[i] = toyota[i];
            }
            brandName = "Toyota";
            break;
        case 3:
            model = displayOptions(hyundai, 4, "Model");
            for (int i = 0; i < 4; ++i) {
                modelCost[i] = cars2Value[i];
                modelName[i] = hyundai[i];
            }
            brandName = "Hyundai";
            break;
        case 4:
            model = displayOptions(suzuki, 4, "Model");
            for (int i = 0; i < 4; ++i) {
                modelCost[i] = cars3Value[i];
                modelName[i] = suzuki[i];
            }
            brandName = "Suzuki";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            // return 0;
    }

    cout << "\n\n\t\t======== AVAILABLE SERVICES ======== \n\n" << endl;

    while(true) {
        int choice = displayOptions(choices, 5, "Choice");
        cout << "\n\n\t\t======== OPTION of CAR BODY ======== \n\n" << endl;
        int part = displayOptions(parts, 14, "Part");
        cout << "\n\n\t\t======== CURRENT BILL ======== \n\n" << endl;

        cartCars[index] = model;
        cartChoice[index] = choice;
        cartPart[index] = part;

        cartPrice[index] = calculateCost(modelCost[model], choiceValue[choice], prices[part]);
        cost += cartPrice[index];


        for (int i = 0; i <= index; i++) {
            cout << brandName << ", " << modelName[cartCars[i]] << "," << parts[cartPart[i]] << ", " << choices[cartChoice[i]] << ": Rs." << cartPrice[i] << endl;
        }

        cout << "\nDo you want to change in any sevices? (y/n): ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y') {
            int editIndex=1;
            editIndex--;

                choice = displayOptions(choices, 5, "Choice");
                part = displayOptions(parts, 14, "Part");
                cartChoice[editIndex] = choice;
                cartPart[editIndex] = part;
                cartPrice[editIndex] = calculateCost(modelCost[model], choiceValue[choice], prices[part]);
                cost = 0;
                for (int i = 0; i <= index; i++) {
                    cost += cartPrice[i];
                }
            }
            for (int i = 0; i <= index; i++) {
            cout << brandName << ", " << modelName[cartCars[i]] << ", " << parts[cartPart[i]] << ", " << choices[cartChoice[i]] << ": Rs." << cartPrice[i] << endl;
        }

        // cout<<"\nYour Total Cost is: Rs. "<<cost<<endl;
        cout << "\nDo you want more services? (y/n): ";
        cin >> ch;
        if(ch!='y' && ch!='Y')
        break;
        system("cls");
        index++;
    }
    // while (ch == 'y' || ch == 'Y');

    cout << "\n\n\t\t======== YOUR TOTAL BILL ======== \n\n" << endl;
    for (int i = 0; i <= index; i++) {
            cout << brandName << ", " << modelName[cartCars[i]] << ", " << parts[cartPart[i]] << ", " << choices[cartChoice[i]] << ": Rs." << cartPrice[i] << endl;
        }
    cout << "\nTotal Cost is: Rs. " << cost << endl;
    double discount;
    double diis;
    double disc;

    char dis;
    cout<<"\nDo you want to add discount?(y/n) ";
    cin>>dis;
    if(dis == 'y' || dis == 'Y'){
        cout<<"\nEnter disount %: ";
        cin>>discount;
        system("cls");
    diis=(discount/100)*cost;
    disc=cost-diis;
        cout << "\n\n\t\t======== YOUR TOTAL BILL ======== \n\n" << endl;
    for (int i = 0; i <= index; i++) {
            cout << brandName << ", " << modelName[cartCars[i]] << ", " << parts[cartPart[i]] << ", " << choices[cartChoice[i]] << ": Rs." << cartPrice[i] << endl;
        }
    cout << "\nTotal Price is: Rs. " << cost << endl;
    cout << "\nTotal Payable Amount After Discount is: Rs. " <<disc<< endl;
    }
    else{    cout << "\n\n\t\t======== YOUR PAYABLE BILL ======== \n\n" << endl;
    for (int i = 0; i <= index; i++) {
            cout << brandName << ", " << modelName[cartCars[i]] << ", " << parts[cartPart[i]] << ", " << choices[cartChoice[i]] << ": Rs." << cartPrice[i] << endl;
        }
    cout << "Payable Amount is:             Rs. " << cost << endl;

    }
    double payment=0.0;
    double change=0.0;

    do{
        cout << "Payment Received:              Rs. ";
    cin>>payment;
    if(payment>=cost){
        change=payment-cost;
    cout<<"Balance Returned to customer:  Rs. "<<change;

    }
    else if(payment>=disc){
        change=payment-disc;
    cout<<"Balance Returned to customer:  Rs. "<<change;
    break;
    }
    else{
        cout<<"Insuffient Amount....";
    }
    }while(payment<cost);



    return 0;
}

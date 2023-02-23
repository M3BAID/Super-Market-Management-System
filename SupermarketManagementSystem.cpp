#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int ID_from_user, update; // our global variables
string sup; // our global variables
int counterofproduct = 0, counterofsupplier = 0; // our global variables

void main_menu();	// The main menu screen
void add_menu();	// The add choice in main menu
void delete_menu(); // The delete choice in main menu
void update_menu(); // The update choice in main menu
void list_menu();	// The search for choice in main menu
void search_menu(); // The search for choice in main menu
void assign_menu();
void list_product();
void list_supplier();
void add_product();
void add_supplier();
void delete_product();
void delete_supplier();

struct supplier {
	// The supplier structure
	string name;
	string address;
	string phone;
	string email;
	int id;
};
struct product { // The product structure
	string name;
	string type;
	string brand;
	string price;
	string quantity;
	string New_supplier;
	supplier assign_v ;
	int id;
};



product A[100]; // global array for product
supplier B[100]; // global array for supplier

string display(50, '='); // to print the chr =

int main() {

	main_menu(); // main menu call
	return 0;
}

void main_menu()

{
	cout <<endl<<endl<<endl;
	cout<<"                                                                                                     * SUPERMARKET MANAGEMENT SYSTEM *              ";
	cout <<endl<<endl<<endl;
	cout<<"**  ***  ***  *** ***  ***  ****  ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** "<<endl;
	bool b = false;
	int option;
	do {
		cout << "\n[1] Add new information: " // Main menu screen (choices)
		     << "\n[2] Delete: "
		     << "\n[3] Update: "
		     << "\n[4] Show the list: "
		     << "\n[5] Search: "
		     << "\n[6] Assign Product to Supplier: "
		     << "\n[7] Exit: \n\n"
		     <<"**  ***  ***  *** ***  ***  ****  ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** ***  **** "<<endl
		     << "\nYour choice is: ";

		cin >> option;
		switch (option) {
			case 1:
				cout << "First option";
				system("cls");
				add_menu(); // call the first menu function to display the first menu
				b = true;
				break;
			case 2:
				cout << "second option";
				system("cls");

				delete_menu();
				b = true;
				break;
			case 3:
				cout << "third option";
				system("cls");

				update_menu();
				b = true;
				break;
			case 4:
				cout << "fourth option";
				system("cls");

				list_menu();
				b = true;
				break;
			case 5:
				cout << "fifth option";
				system("cls");

				search_menu();

				b = true;
				break;
			case 6:
				cout << "sixth option";
				system("cls");
				assign_menu();

				b = true;
				break;
			case 7:
				cout << "Thanks for using our program, Hope we see you again soon :)";
				b = false;
				break;

			default:
				cout << " Wrong entry, please select a number between 1-7.";
				b = true;
				break;
		}
	} while (b == true); // the loop statement to repeat
}

void add_menu()

{
	bool b = false;
	int option;
	do {
		cout << "[1] Add new product information: " // first menu screen (choices)
		     << "\n[2] Add new suplier information: "
		     << "\n[3] Back to main menu: "
		     << "\n\nyour choice is: ";
		cin >> option;
		switch (option) {
			case 1:
				add_product();
				system("cls");

				b = true;
				break;
			case 2:
				add_supplier();
				system("cls");

				b = true;
				break;

			case 3:
				system("cls");
				main_menu();
				b = false;
				break;

			default:
				cout << " Wrong entry, please select a number between 1-3.";
				b = true;
				break;
		}
	} while (b == true);
}

void delete_menu() {
	bool b = false;
	int option;
	do {
		cout << "[1] Delete product: " // second menu screen (choices)
		     << "\n[2] Delete supplier: "
		     << "\n[3] Back to main menu: "
		     << "\n\nyour choice is: ";
		cin >> option;
		switch (option) {
			case 1:
				delete_product();

				b = true;
				break;
			case 2:
				delete_supplier();
				b = true;
				break;
			case 3:
				system("cls");
				main_menu();
				b = false;
				break;
			default:
				cout << " Wrong entry, please select a number between 1-3.";
				b = true;
				break;
		}

	} while (b == true);
}

void update_menu() {
	int option;
	int flag;
	cout << "1.UPDATE PRODUCT\n";
	cout << "2.UPDATE Supplier\n";
	cout << "3.Back to main menu\n\n";
	cout << "your choice :\n";
	cin >> option;
	switch (option) {
		case 1: // from here we start
			flag = 0;
			system("cls");
			cout << "Enter the ID of product :";
			cin >> ID_from_user;
			for (int counterofup = 0; counterofup <= counterofproduct; counterofup++) {
				if (A[counterofup].id == ID_from_user) {
					flag = 1;
					cout << "1.New name of product :\n";
					cout << "2.New type of product :\n";
					cout << "3.New brand of product :\n";
					cout << "4.New price of product :\n";
					cout << "5.New quantity of product :\n";
					cout << "6.New supplier of product :\n";
					cout << "7.New ID of product :\n";
					cin >> update;
					switch (update) {
						case 1:
							cout << "Enter the new name of product  :";
							cin >> A[counterofup].name;
							break;
						case 2:
							cout << "Enter the new type of product  :";
							cin >> A[counterofup].type;
							break;
						case 3:
							cout << "Enter the new brand of product :";
							cin >> A[counterofup].brand;
							break;
						case 4:
							cout << "Enter the new price of product  :";
							cin >> A[counterofup].price;
							break;
						case 5:
							cout << "Enter the new quantity of product  :";
							cin >> A[counterofup].quantity;
						case 6:
							cout << "Enter the new supplier of product  :";
							cin >> A[counterofup].New_supplier;
							break;
						case 7:
							cout << "Enter the new ID of product  :";
							cin >> A[counterofup].id;
							break;
					}
					break;
				}
			}
			if (flag == 0)
				cout << "Not found";
			break; // end of update in product

		case 2: // update of suppliers
			flag = 0;
			system("cls");
			cout << "Enter the ID of suplier:";
			cin >> ID_from_user;
			for (int counterofsup = 0; counterofsup <= counterofsupplier; counterofsup++) {
				if (B[counterofsup].id == ID_from_user) {
					flag = 1;
					cout << "1.New name of supplier :\n";
					cout << "2.New address of supplier :\n";
					cout << "3.New email of supplier :\n";
					cout << "4.New phone of supplier :\n";
					cout << "5.New ID of supplier :\n";
					cin >> update;
					switch (update) {
						case 1:
							cout << "Enter the new name of supplier  :";
							cin >> B[counterofsup].name;
							break;
						case 2:
							cout << "Enter the new address of supplier :";
							cin >> B[counterofsup].address;
							break;
						case 3:
							cout << "Enter the new email of supplier :";
							cin >> B[counterofsup].email;
							break;
						case 4:
							cout << "Enter the new phone of supplier  :";
							cin >> B[counterofsup].phone;
							break;
						case 5:
							cout << "Enter the new ID of supplier :";
							cin >> B[counterofsup].id;
							break;
					}
					break;
				}
			}
			if (flag == 0)
				cout << "Not Found";
			break; // end of update in supplier
		case 3:
			system("cls");
	}
	// end of Update
}
void list_menu() {
	int nlist = 0, listnumber = 0;
	bool b = false;
	int option;
	do {
		cout << "[1] Show list for a product: " // first menu screen (choices)
		     << "\n[2] Show list for a suplier: "
		     << "\n[3] Back to main menu: "
		     << "\n\nyour choice is: ";
		cin >> option;
		switch (option) {
			case 1:
				// list of products
				list_product();

				break;
				b = true;
				break;
			case 2:
				list_supplier();
				b = true;
				break;

			case 3:
				system("cls");
				main_menu();
				b = false;
				break;

			default:
				cout << " Wrong entry, please select a number between 1-3.";
				b = true;
				break;
		}
	} while (b == true);
}

void search_menu() {
	int flag;
	string name;
	int ID, product_or_suplier, idORname, counter;
	cout << "[1] Search for a product: " // first menu screen (choices)
	     << "\n[2] Search for a suplier: "
	     << "\n[3] Back to main menu: ";

	cout << "\n\nyour choice is:";
	cin >> product_or_suplier;
	switch (product_or_suplier) {
		case 1:
			system("cls");
			cout << "[1]Search by name:\n";
			cout << "[2]Search by ID:\n";
			cin >> idORname;
			switch (idORname) {
				case 1:
					flag = 0;
					cout << "Enter the name of product to search :\n ";
					cin >> name;
					for (int search = 0; search <= counter; search++) {

						if (A[search].name == name) {
							flag = 1;
							cout << "Product name  " << search + 1 << " : ";
							cout << A[search].name << "\n";
							cout << "Product type  " << search + 1 << " : ";
							cout << A[search].type << "\n";
							cout << "Product brand " << search + 1 << " : ";
							cout << A[search].brand << "\n";
							cout << "Product price  " << search + 1 << " : ";
							cout << A[search].price << "\n";
							cout << "Product ID  " << search + 1 << " : ";
							cout << A[search].id << "\n";
							break;
						}
						break ;
					}
					if (flag == 0)
						cout << "\nNot Found";
					break; // end of search in product by name

				case 2:
					flag = 0;
					cout << "Enter the ID of product to search :\n ";
					cin >> ID;
					for (int search = 0; search <= counter; search++) {

						if (A[search].id == ID) {
							flag = 1;
							cout << "Product name  " << search + 1 << " : ";
							cout << A[search].name << "\n";
							cout << "Product type  " << search + 1 << " : ";
							cout << A[search].type << "\n";
							cout << "Product brand " << search + 1 << " : ";
							cout << A[search].brand << "\n";
							cout << "Product price  " << search + 1 << " : ";
							cout << A[search].price << "\n";
							cout << "Product ID  " << search + 1 << " : ";
							cout << A[search].id << "\n";
							break;
						}
						break ;
					}
			}
			if (flag == 0)
				cout << "\nNot Found";
			break; // end of search in product by ID

		case 2:
			system("cls");
			cout << "[1]Search by name:\n";
			cout << "[2]Search by ID:\n";
			cin >> idORname;
			switch (idORname) {
				case 1:
					flag = 0;
					cout << "Enter the name of Suplier to search :\n ";
					cin >> name;
					for (int search = 0; search <= counter; search++) {

						if (B[search].name == name) {
							flag = 1;
							cout << "Suplier name:" << search + 1 << " : ";
							cout << B[search].name << "\n";
							cout << "Suplier address:" << search + 1 << " : ";
							cout << B[search].address << "\n";
							cout << "Suplier phone:" << search + 1 << " : ";
							cout << B[search].phone << "\n";
							cout << "Suplier email:" << search + 1 << " : ";
							cout << B[search].email << "\n";
							cout << "Suplier ID:" << search + 1 << " : ";
							cout << B[search].id << "\n";
							break;
						}
						break ;
					}
					if (flag == 0)
						cout << "\nNot Found";
					break; // end of search in suplier by name

				case 2:
					flag = 0;
					cout << "Enter the ID of supplier to search :\n ";
					cin >> ID;
					for (int search = 0; search <= counter; search++) {
						if (B[search].id == ID) {
							flag = 1;
							cout << "Suplier name:" << search + 1 << " : ";
							cout << B[search].name << "\n";
							cout << "Suplier address:  " << search + 1 << " : ";
							cout << B[search].address << "\n";
							cout << "Suplier phone: " << search + 1 << " : ";
							cout << B[search].phone << "\n";
							cout << "Suplier email:" << search + 1 << " : ";
							cout << B[search].email << "\n";
							cout << "Suplier ID:" << search + 1 << " : ";
							cout << B[search].id << "\n";
							break;
						}
						break ;
					}
			}
			if (flag == 0)
				cout << "\nNot Found";
			break; // end of case 2

		case 3:
			system("cls");
			break;

		default:
			cout << "\n Wrong entry, please select a number between 1-3.";
			flag = 0;
			break;
	}
}

void assign_menu() {
	cout << "Enter the product id :";
	cin >> ID_from_user;
	cout << "\n\nEnter the supplier name :";
	cin >> sup;
	system("cls");
	for (int i = 0; i < counterofproduct; i++) {
		if (A[i].id == ID_from_user) {
			for (int j = 0; j < counterofsupplier; j++) {
				if (B[i].name == sup) {
					A[j].assign_v = B[j];
				}
			}
		}
	}
}
void add_product() {
	int counter = 0, i = 0;

	cout << "\nEnter how many product you want enter: ";
	cin >> i;
	for (counter; counter < i; counter++) {
		cout << display;
		cout << "\nEnter a name of product: ";
		cin >> A[counterofproduct].name;
		cout << display;
		cout << "\nEnter a type of product: ";
		cin >> A[counterofproduct].type;
		cout << display;
		cout << "\nEnter a brand of product: ";
		cin >> A[counterofproduct].brand;
		cout <<  display;
		cout << "\nEnter a price of product: ";
		cin >> A[counterofproduct].price;
		cout <<  display ;
		cout << "\nEnter a quantity of product: ";
		cin >> A[counterofproduct].quantity;
		cout <<  display ;
		cout << "\nEnter a id of product: ";
		cin >> A[counterofproduct].id;
		cout <<  display ;
		counterofproduct++;

	}
}

void add_supplier() {
	int counter = 0, i = 0;
	cout << "\nHow many supplier you want enter: ";
	cin >> i;
	for (counter; counter < i; counter++) {
		cout <<  display ;
		cout << "\nEnter a name of supplier: ";
		cin >> B[counterofsupplier].name;
		cout << display ;
		cout << "\nEnter a address of supplier: ";
		cin >> B[counterofsupplier].address;
		cout <<  display ;
		cout << "\nEnter a phone of supplier: ";
		cin >> B[counterofsupplier].phone;
		cout << display ;
		cout << "\nEnter a email of supplier: ";
		cin >> B[counterofsupplier].email;
		cout << display ;
		cout << "\nEnter a id of supplier: ";
		cin >> B[counterofsupplier].id;
		cout <<  display ;
		counterofsupplier++;
	}
}

void delete_product() {
	int ids;
	cout << "\nEnter the ID: ";
	cin >> ids;

	if (ids == A[ids].id) {
		cout << endl
		     << display << endl;
		cout << "Before delete: " << endl;
		cout << "name is: " << A[ids].name << endl;
		cout << "brand is: " << A[ids].brand << endl;
		cout << "price is: " << A[ids].price << endl;
		cout << "type is: " << A[ids].type;
		cout << "id is: " << A[ids].id << endl;
		cout << endl
		     << display << endl;
		A[ids].name.clear();
		A[ids].brand.clear();
		A[ids].price.clear();
		A[ids].type.clear();
		cout << endl
		     << display << endl;
		cout << "After delete: " << endl;
		cout << "name is: " << A[ids].name << endl;
		cout << "brand is: " << A[ids].brand << endl;
		cout << "price is: " << A[ids].price << endl;
		cout << "type is: " << A[ids].type;
		cout << "id is: " << A[ids].id << endl;
		cout << endl
		     << display << endl;
	}
	counterofproduct--;//edited by hasan
}

void delete_supplier() {
	int ids;
	cout << "\nEnter the ID: ";
	cin >> ids;

	if (ids == B[ids].id) {
		cout << "Before delete: " << endl;
		cout << "name is: " << B[ids].name << endl;
		cout << "address is: " << B[ids].address << endl;
		cout << "phone is: " << B[ids].phone << endl;
		cout << "email is: " << B[ids].email << endl;
		cout << "id is: " << B[ids].id << endl;
		cout << endl
		     << display << endl;

		B[ids].name.clear();
		B[ids].address.clear();
		B[ids].phone.clear();
		B[ids].email.clear();
		cout << endl
		     << display << endl;
		cout << "After delete: " << endl;
		cout << "name is: " << B[ids].name << endl;
		cout << "address is: " << B[ids].address << endl;
		cout << "phone is: " << B[ids].phone << endl;
		cout << "email is: " << B[ids].email << endl;
		cout << "id is: " << B[ids].id << endl;
		cout << endl
		     << display << endl;
	}
	counterofsupplier--;//edited by hasan
}

void list_product() {

	int nlist = 0 ;


	cout << "\nnumber |"  ;
	cout << " products name |" ;
	cout << " products type |" ;
	cout << " products brand |" ;
	cout << " products price |" ;
	cout << " products ID |";
	cout << " Suplier name  |" ;
	cout << " Suplier address  |"  ;
	cout << " Suplier email  |"  ;
	cout << " Suplier phone  |" ;

	cout << endl;
	cout << "**********************************************************************************************************************************************************";

	cout << endl;

	for (int list = 0; list < counterofproduct; list++) {
		cout << " " << nlist + 1 <<"\t\t" ;
		cout << A[list].name <<"\t\t" ;
		cout << A[list].type <<"\t\t" ;
		cout << A[list].brand <<"\t\t" ;
		cout << A[list].price <<"\t\t" ;
		cout << A[list].id <<"\t\t" ;
		cout << A[list].assign_v.name <<"\t\t" ;
		cout << A[list].assign_v.address <<"\t\t" ;
		cout << A[list].assign_v.email <<"\t\t" ;
		cout << A[list].assign_v.phone  ;

		cout << endl;
		cout << "**********************************************************************************************************************************************************";
		cout << endl;
		nlist++;
	}
}
void list_supplier() {
	int nlist = 0;
	cout << "\n number |" << setw(12);
	cout << " Suplier name |" << setw(12);
	cout << " Suplier address |" << setw(12);
	cout << " Suplier phone |" << setw(12);
	cout << " Suplier email |" << setw(12);
	cout << " Suplier id |" << setw(12);
	cout << endl;
	cout << "****************************************************************************************";
	cout << endl;

	for (int list = 0; list < counterofsupplier; list++) {

		cout << " " << nlist + 1 << setw(15);
		cout << B[list].name << setw(15);
		cout << B[list].address << setw(17);
		cout << B[list].phone << setw(15);
		cout << B[list].email << setw(15);
		cout << B[list].id << setw(15);
		cout << endl;
		cout << "****************************************************************************************";
		cout << endl;
		nlist++;
	}
}


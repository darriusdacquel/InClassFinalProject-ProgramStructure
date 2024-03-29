#include <iostream>
#include <string>

using namespace std;

// Define MAX_ROOMS and MAX_CUSTOMERS which will be used as the length of the arrays

const int MAX_ROOMS = 100;
const int MAX_CUSTOMERS = 100;

class Customer
{
private:
    std::string bookingID;
    std::string customerName;
    std::string address;
    std::string phoneNumber;
    double advancePayment;
    std::string checkInDate;
    std::string checkOutDate;
    int roomNumber;

public:
    // constructor that default sets the variables
    Customer()
    {
        bookingID = "";
        customerName = "";
        address = "";
        phoneNumber = "";
        advancePayment = 0.0;
        checkInDate = "";
        checkOutDate = "";
        roomNumber = 0;
    }

    Customer(std::string newID, std::string newCustomerName,
             std::string newAddress, std::string newPhoneNumber,
             double newAdvancePayment, std::string newCheckInDate,
             std::string newCheckOutDate, int newRoomNumber)
    {
        bookingID = newID;
        customerName = newCustomerName;
        address = newAddress;
        phoneNumber = newPhoneNumber;
        advancePayment = newAdvancePayment;
        checkInDate = newCheckInDate;
        checkOutDate = newCheckOutDate;
        roomNumber = newRoomNumber;
    }

    // Get methods
    std::string getbookingID() const { return bookingID; }
    std::string getName() const { return customerName; }
    std::string getPhone() const { return phoneNumber; }
    std::string getAddress() const { return address; }
    int getRoomNumber() const { return roomNumber; }
    std::string getCheckInDate() const { return checkInDate; }
    std::string getCheckOutDate() const { return checkOutDate; }
    double getAdvancePayment() const { return advancePayment; }

    // set methods
    void setBookingID(std::string newID) { bookingID = newID; }
    void setName(std::string newName) { customerName = newName; }
    void setPhone(std::string newPhone) { phoneNumber = newPhone; }
    void setAddress(std::string newaddress) { address = newaddress; }
    void setRoomNumber(int newRoomNumber) { roomNumber = newRoomNumber; }
    void setCheckInDate(std::string newCheckInDate)
    {
        checkInDate = newCheckInDate;
    }
    void setCheckOutDate(std::string newCheckOutDate)
    {
        checkOutDate = newCheckOutDate;
    }
    void setAdvancePayment(double newAdvancePayment)
    {
        advancePayment = newAdvancePayment;
    }
};

class Room
{
private: 
    int roomNum;
    std::string acTemp;
    std::string comfort;
    std::string size;
    int rate;

    bool avail;

public:
    Room()//default constructor
    {
        roomNum = 0;
        acTemp = ""; // initializes to empty string
        comfort = "";
        size = "";
        rate = 0;
        avail = true; // setting true to default
    }

    //  setters for class Room
    void setRoomNum(int n) { roomNum = n; }
    void setacTemp(std::string t) { acTemp = t; }
    void setComfort(std::string c) { comfort = c; }
    void setsize(std::string s) { size = s; }
    void setRate(int r) { rate = r; }
    void setAvail(bool a) { avail = a; }

    // getters for class Room
    int getRoomNum() { return roomNum; }
    std::string getacTemp() { return acTemp; }
    std::string getComfort() { return comfort; }
    std::string getSize() { return size; }
    int getRate() { return rate; }
    bool getAvail()
    {
        return avail;
    } //returns boolean indicating whether room is available or not

    void displayRoom(
        Room r)
    { // this checks value of avail if room is available or not
        std::cout << "Room Details\n"
                  << std::endl;

        if (avail)
        {
            std::cout << "Room is available" << std::endl; // if its true
        }
        else
        {
            std::cout << "Room is not available" << std::endl; // if its false
        }

        std::cout << "Room number: " << r.getRoomNum()
                  << std::endl; // gets room number using getRoomNum method using
                                // instance r
        std::cout << "Type AC/No AC (A/N): " << r.getacTemp() << std::endl;
        std::cout << "Type Comfort (S/N): " << r.getComfort() << std::endl;
        std::cout << "Type Size (B/S): " << r.getSize() << std::endl;
        std::cout << "Daily Rate: " << r.getRate() << std::endl;
    }
};

class hotelManagement : public Room
{
private:
    // Private variables to store the amount of rooms and customers
    int amtOfRooms;
    int amtOfCustomers;

public:
    int getAmtOfRooms() { return amtOfRooms; }
    int getAmtOfCustomers() { return amtOfCustomers; }

    // Constructor
    hotelManagement()
    {
        amtOfRooms = 0;
        amtOfCustomers = 0;
    }

    Room addRoom(Room rooms[MAX_ROOMS]) 
    {
        // Create a new empty Room object
        Room r;

        // Temp variables to help us run our set methods
        std::string temp;
        int itemp = 0;

        // If amtOfRooms is greater than or equal to MAX_ROOMS does not allow
        if (amtOfRooms >= MAX_ROOMS)
        {
            std::cout << "No rooms available";
            return r;
        }

        // Ask for room number and set it with the setRoomNum method
        std::cout << "Enter room number: ";
        std::cin >> itemp;

        for (int i = 0; i < amtOfRooms; i++)
        {
            if (itemp == rooms[i].getRoomNum())
            {
                cout << "This room number exists. Enter a new room number." << endl;
                return r; // Return an empty room since the room number already exists
            }
        }
        r.setRoomNum(itemp);

        // Ask for type AC/No AC and set it with the setacTemp method
        std::cout << "Type AC/No AC (A/N): ";
        std::cin >> temp;

        // Validate the input for AC/No AC
        while (temp != "A" && temp != "N")
        {
            std::cout << "Invalid option. Please enter 'A' for AC or 'N' for No AC: ";
            std::cin >> temp;
        }
        r.setacTemp(temp);

        // Ask for type Comfort and set it with the setComfort method
        std::cout << "Type Comfort (S/N): ";
        std::cin >> temp;

        // Validate the input for Comfort
        while (temp != "S" && temp != "N")
        {
            std::cout << "Invalid option. Please enter 'S' for Comfort or 'N' for No Comfort: ";
            std::cin >> temp;
        }
        r.setComfort(temp);

        // Ask for type Size and set it with the setSize method
        std::cout << "Type Size (B/S): ";
        std::cin >> temp;

        // Validate the input for Size
        while (temp != "B" && temp != "S")
        {
            std::cout << "Invalid option. Please enter 'B' for Big or 'S' for Small: ";
            std::cin >> temp;
        }
        r.setsize(temp);

        // Ask for daily rate and set it with the setRate method
        std::cout << "Daily rate: ";
        std::cin >> itemp;
        r.setRate(itemp);

        // Return the created Room object
        return r;
    }

    Room deleteRoom(Room rooms[MAX_ROOMS])
    {
        Room tempRoom;
        int roomNum;
        //Ask for the Room number to delete
        cout << "Enter room number to delete: ";
        cin >> roomNum;
        //Check if the room number exists
        bool roomFound = false;
        //Loop through the rooms array to find the room with the given room number
        for (int i = 0; i < amtOfRooms; i++)
        { //if room is found
            if (roomNum == rooms[i].getRoomNum())
            { //set the room to the tempRoom object
                tempRoom = rooms[i];
  
                for (int j = i; j < amtOfRooms - 1; j++)
                {
                    rooms[j] = rooms[j + 1];
                }
                
                amtOfRooms--;
                cout << "\n Room Details to Delete\n"
                     << endl;
                cout <<endl << "Room Number:\t" << tempRoom.getRoomNum() << endl;
                cout << endl << "Room with AC/No AC (A/N): " << tempRoom.getacTemp() << endl;
                cout << endl << "Type of Comfort (S/N): " << tempRoom.getComfort() << endl;
                cout << endl << "Room Size (B/S): " << tempRoom.getSize() << endl;
                cout << endl << "Daily Rate: " << tempRoom.getRate() << endl;
                cout <<endl << "Room Deleted Successfully" << endl;
              
                roomFound = true;
                break;
            }
        }
        if (!roomFound)
        {
            cout << "Room not found or invalid room number!" << endl;
        }
        return tempRoom;
    }

    Room searchRoom(Room rooms[MAX_ROOMS], int amtOfRooms) {
    Room tempRoom; // Temporary Room object to store the search result
    int roomNumber;

    std::cout << "Enter room number: ";
    std::cin >> roomNumber;

    // Iterate through the rooms array to find a room with the given number
    for (int i = 0; i < amtOfRooms; i++) {
        if (roomNumber == rooms[i].getRoomNum()) {
            tempRoom = rooms[i]; // Store the found room
            rooms[i].displayRoom(rooms[i]); // Display the room details
            return tempRoom; // Return the found room and exit the function
        }
    }

    // If the loop completes without finding the room, the room is not found
    std::cout << "Room not found!!!" << std::endl;
    return tempRoom; // tempRoom will be an uninitialized Room object if not found
}

    void manageRooms(Room rooms[MAX_ROOMS])
    {
        // Int that we use for the switch statement below
        int choice2;
        do
        {
            // Manage rooms menu
            cout << "### Manage Rooms ###" << endl;
            cout << "1. Add Room" << endl;
            cout << "2. Search Room" << endl;
            cout << "3. Delete Room" << endl;
            cout << "4. Back to Main Menu" << endl;
            cout << "\nEnter Option: ";
            cin >> choice2;

            switch (choice2)
            {
            case 1:
            {
                // Runs add room function and increments the amount of rooms
                rooms[amtOfRooms] = addRoom(rooms);
                amtOfRooms++;
                break;
            }
            case 2:
            {
                // Runs search room function
                searchRoom(rooms);
                break;
            }
            case 3:
            {
                deleteRoom(rooms);
                break;
            }
            case 4:
            {
                break;
            }
            default:
            {
                cout << "Invalid output" << endl;
                break;
            }
            }
        } while (choice2 != 4);
    }

    Customer checkInRoom(int RoomNum, std::string bookingID, std::string Name,
                         std::string Address, std::string PhoneNum,
                         std::string checkIn, std::string checkOut,
                         double advancePayment, Room rooms[MAX_ROOMS]) { //Yuzu

        // Create a new Customer object
        Customer c;

        // Run the setmethods from the customer object to set the values from the
        // checkInRoom parameters
        c.setRoomNumber(RoomNum);
        c.setBookingID(bookingID);
        c.setName(Name);
        c.setAddress(Address);
        c.setPhone(PhoneNum);
        c.setCheckInDate(checkIn);
        c.setCheckOutDate(checkOut);
        c.setAdvancePayment(advancePayment);

        // Increment amtOfCustomers and return the created Customer object
        amtOfCustomers++;
        return c;
    }

    void roomAvail(Room rooms[MAX_ROOMS])
    {
        std::cout << "These room numbers are available " << std::endl;

        // Counter checks if the if statement inside the for loop was ran
        int counter = 0;

        for (int i = 0; i < amtOfRooms; i++)
        {
            // If the room is available display the room and increment counter
            if (rooms[i].getAvail() == true)
            {
                counter++;
                rooms[i].displayRoom(rooms[i]);
                std::cout << std::endl;
            }
        }
        // If counter was never incremented print out No rooms available
        if (counter == 0)
        {
            cout << "\nNo rooms available" << endl;
        }
    }

    Customer searchCustomer(Customer customers[MAX_CUSTOMERS])
    {
        std::string customerName;
        Customer temp;

        std::cout << "Enter Customer Name: ";
        std::cin >> customerName;

        for (int i = 0; i < amtOfCustomers;
             i++)
        { // for loop that iterates through array that holds Customer
          // Objects
            if (customerName ==
                customers[i]
                    .getName())
            { // if statement that checks if the customer name
              // matches the name inputted by the user
                std::cout << "\nCustomer Name: " << customers[i].getName() << std::endl;
                std::cout << "Room number: " << customers[i].getRoomNumber()
                          << std::endl;
                temp = customers[i]; // set temp variable to position of the matching
                                     // Customer object
                break;
            }
        }
        if (temp.getName() ==
            "")
        { // if statement that checks if the temp variable is empty
            std::cout << "Customer not found!!!"
                      << std::endl; // if empty/not found prints "Customer not found"
        }

        return temp; // return type Customer
    }

Customer checkOutRoom(Customer customer[MAX_CUSTOMERS],
                      Room rooms[MAX_ROOMS]) { //darrius



  // Temporary customer object that will hold the customer information and return it
  Customer ctemp;

  // Temporary Room object that will change the room availability back to true
  Room rtemp;

  // NumStay stores the days they stayed at the hotel
  int numStay;

  // Temp integer that stores the user inputted room number
  int tempRoomNum;

  // Gets room number from the user
  std::cout << "Enter Room Number: ";
  std::cin >> tempRoomNum;

  // For loop that loops until roomNum matches a customer
  for (int i = 0; i <= amtOfCustomers; i++) {
    // If there is a match makes ctemp = the customer we want info from
    if (tempRoomNum == customer[i].getRoomNumber()) {
      ctemp = customer[i];
      // Nested for loop that sets the rtemp to the same room number as the customer
      for (int k = 0; k < amtOfRooms; k++) {
        if (tempRoomNum == rooms[k].getRoomNum()) {
          rtemp = rooms[k];
          break;
        }
      }
    }
  }

  std::cout << "Enter Number of Days: ";
  std::cin >> numStay;

  std::cout << "######## CheckOut Details ########" << std::endl;

  std::cout << "Total Amount Due: ";
  std::cout << rtemp.getRate() * numStay; //multiplying number of days stayed by daily rate
  std::cout << "\nAdvance Paid: ";
  std::cout << ctemp.getAdvancePayment();
  std::cout << "\n*** Total Payable: ";
  std::cout << rtemp.getRate() * numStay - ctemp.getAdvancePayment();      
       //subtracting advanced payment from total amount due
  std::cout << endl;

  return ctemp;
}

    void guestSummaryReport(Customer customer) //Jett
    {
        // If the customer that the user gives to this function is empty does not
        // run the code
        if (customer.getAddress() != "" && customer.getPhone() != "")
        {
            // Prints out guest information
            std::cout << "Address (city only): " << customer.getAddress()
                      << std::endl;
            std::cout << "Phone Number: " << customer.getPhone() << std::endl;
            std::cout << endl;
        }
    }
};

int main()
{
    // calling a class into the main method
    hotelManagement hotel;
    int choice;
    int i = 0;
    // Arrays thats holds the rooms and customers
    Room rooms[MAX_ROOMS];
    Customer customers[MAX_CUSTOMERS];

    std::string Name, Address, PhoneNum, bookingID, checkIn, checkOut;
    int RoomNum;
    double advancePayment;

    do
    {
        std::cout << "----------------HOTEL MANAGEMENT----------------\n"
                  << "1.Manage Rooms" << std::endl
                  << "2.Check-In Room" << std::endl
                  << "3.Available Rooms" << std::endl
                  << "4.Search Customer" << std::endl
                  << "5.Check-Out Room" << std::endl
                  << "6.Guest Summary Report" << std::endl
                  << "7.Exit" << std::endl
                  << std::endl
                  << "Enter Option:";

        std::cin >> choice;

        switch (choice)
        {
        case 1: // manage rooms
        {
            hotel.manageRooms(rooms);
            break;
        }
        case 2: // check in customer
        {
            if (hotel.getAmtOfRooms() == 0)
            {
                cout << "No rooms exist, please add a room before proceeding." << endl;
                break;
            }

            std::cout << "Enter Room Number: ";
            std::cin >> RoomNum;

            // X is a variable that is used as a counter for the for loop
            for (int x = 0; x < hotel.getAmtOfRooms(); x++)
            {
                if (rooms[x].getRoomNum() == RoomNum && rooms[x].getAvail() == true)
                {
                    std::cout << "Enter Booking ID: ";
                    std::cin >> bookingID;
                    std::cout << "Enter Name: ";
                    std::cin >> Name;
                    std::cout << "Enter Address(City Only): ";
                    std::cin >> Address;
                    std::cout << "Enter Phone Number: ";
                    std::cin >> PhoneNum;
                    std::cout << "Check in date: ";
                    std::cin >> checkIn;
                    std::cout << "Check out date: ";
                    std::cin >> checkOut;
                    std::cout << "Enter Advance Payment: ";
                    std::cin >> advancePayment;
                    rooms[x].setAvail(false);

                    customers[i] =
                        hotel.checkInRoom(RoomNum, bookingID, Name, Address, PhoneNum,
                                          checkIn, checkOut, advancePayment, rooms);
                    i++;

                    // Display check-in success message
                    std::cout << "Check-In Successfully!" << std::endl;

                    break;
                }
                // If we get to the end of the for loop prints out room not found
                else if (x == hotel.getAmtOfRooms() - 1)
                {
                    std::cout << "Room not found or not available!!!" << std::endl;
                }
            }
            break;
        }

        case 3: // room availability
        {
            hotel.roomAvail(rooms);
            break;
        }

        case 4: // search customer
        {
            hotel.searchCustomer(customers);
            break;
        }

        case 5: // check out
        {
            if (i == 0)
            { // checking if there are any customers
                cout << "No customers exist, please check in a customer before "
                        "proceeding."
                     << endl;
                break;
            }

            // Remove stores the customer that has been checked out
            Customer remove;
            remove = hotel.checkOutRoom(customers, rooms);

            // Create an array of customers to store the customers that are still in
            // our system
            Customer temp[MAX_CUSTOMERS];

            for (int x = 0; x < i; x++)
            {
                if (customers[x].getRoomNumber() != remove.getRoomNumber())
                {
                    // copy to temp array
                    temp[x] = customers[x];
                }
                else {
                  // If customer.getRoomNumber is the same as the remove room number loops through rooms array until there is a match and sets room back to available
                  for (int k = 0; k < hotel.getAmtOfCustomers(); k++) {
                    if (rooms[k].getRoomNum() == remove.getRoomNumber()) {
                      rooms[k].setAvail(true);
                    }
                  }
                }
            }

            // replace customers array with temp array
            for (int x = 0; x < MAX_CUSTOMERS; x++)
            {
                customers[x] = temp[x];
            }
            // decrements i since we checked out a customer
            i--;
            break;
        }
        case 6: // guest summary report
        {
            Customer summary;
            summary = hotel.searchCustomer(customers);
            hotel.guestSummaryReport(summary);
            break;
        }
        case 7:
        {
            std::cout << "THANK YOU! FOR USING SOFTWARE";
            break;
        }
        default:
        {
            std::cout << "Invalid Choice. Please try again";
            break;
        }
        }
    } while (choice != 7);

    return 0;
}

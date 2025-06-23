/**
 * @mainpage Documentation circular Queues
 * 
 * @section Introduction
 * project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circullar arrays
 * 
 * @section operations
 * - en queues for insert elements into queues
 * - de queues for insert elements from queues 
 * - show data / display data
 * 
 * @section how to use
 * 1. insert
 * 2. delete 
 * 3. displat
 * 4. Exit
 * 
 * @author yProfil
 * - Nama : Rossa Kayla Isma Aziz
 * - Nim  : 20240140215
 * - Class : E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@Umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;

// member : variabel, destructor, konstruktor, function, method

/**
 * @class Queues
 * @brief This class is for operation queues
 * 
 */

class Queues
{
private:
    /// private variabel front for indicate first element 
    int FRONT; 
    /// private variabel rear for indicate last element 
    int REAR; 
    /// private variabel max for maximum capacity of elements
    int max = 5; 
    ///private variabel queue_array for store elements
    int queue_array[5]; 

public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues()
    {
        ///Initializing FRONT = -1 indicates an empty queue.
        FRONT = -1;
        ///Initializing FRONT = -1 indicates an empty queue.
        REAR = -1;
    }

    /**
     * @brief  method for entering data into a queue
     * 
     */
    ///Void insert Serves to add elements to the queue (enqueue)
    void insert()  
    {
        ///int num Variable to store numbers entered by the user
        int num;
        //Ask for user input
        cout << "Enter a number: ";
        //Save input to variable num
        cin >> num;
        cout << endl;

        // cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            // jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }
    /**
     * @brief Removes an element from the queue (dequeue)
     * 
     */

    void remove()
    {
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // cek antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // jika FRONT berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    /**
     * @brief Displays all elements in the queue.
     * 
     */
    void display()  ///Function to display all elements in the queue
    {
        ///int FRONT_position = FRONT; store the FRONT value into a variable
        int FRONT_position = FRONT;
        ///int REAR_position = REAR; store the REAR value into a variable
        int REAR_position = REAR;

        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "\nElements in the queue are...\n";

        /// jika FRONT_position <= REAR_position, iterasi dari FRONT ke REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            // jika FRONT_position > REAR_position, iterasi dari FRONT ke akhir array dan dari awal array ke REAR
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            FRONT_position = 0;
            // iterasi dari awal array ke REAR
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

/**
 * @brief The main functions of the program
 * 
 * @return int 
 */
int main ()
{
    ///variabel q object from the Queues class to access the insert, remove, and display functions.
    Queues q; 
    ///Variable ch to store menu choices from user
    char ch;

    while (true) 
    {
        try 
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;
            
            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
}
#include <iostream>
#include <vector>
#include <string>

class Contact {
private:
    std::string name;
    std::string phoneNumber;
    std::string nickname;
public:
    Contact(const std::string& name, const std::string& phoneNumber, const std::string& nickname) :
        name(name), phoneNumber(phoneNumber), nickname(nickname) {}

    std::string getName() const {
        return name;
    }

    std::string getPhoneNumber() const {
        return phoneNumber;
    }

    std::string getNickname() const {
        return nickname;
    }
};

class Phonebook {
private:
    std::vector<Contact> contacts;
    std::vector<Contact*> bookmarks;
public:
    void addContact(const std::string& name, const std::string& phoneNumber, const std::string& nickname) {
        // Check if the phone number is already in use
        for (const auto& contact : contacts) {
            if (contact.getPhoneNumber() == phoneNumber) {
                std::cout << "Error: Phone number already exists." << std::endl;
                return;
            }
        }

        contacts.push_back(Contact(name, phoneNumber, nickname));
        std::cout << "Contact added successfully." << std::endl;
    }

    void searchContacts() {
        std::cout << "Contacts:" << std::endl;
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << i + 1 << ". " << contacts[i].getName() << std::endl;
        }
    }

    void displayContactDetails(size_t index) {
        if (index >= 1 && index <= contacts.size()) {
            const Contact& contact = contacts[index - 1];
            std::cout << "Name: " << contact.getName() << std::endl;
            std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
            std::cout << "Nickname: " << contact.getNickname() << std::endl;
        }
        else {
            std::cout << "Error: Invalid contact index." << std::endl;
        }
    }

    void bookmarkContact(size_t index) {
        if (index >= 1 && index <= contacts.size()) {
            Contact* contact = &contacts[index - 1];
            bookmarks.push_back(contact);
            std::cout << "Contact bookmarked successfully." << std::endl;
        }
        else {
            std::cout << "Error: Invalid contact index." << std::endl;
        }
    }

    void removeContact(size_t index) {
        if (index >= 1 && index <= contacts.size()) {
            contacts.erase(contacts.begin() + index - 1);
            std::cout << "Contact removed successfully." << std::endl;
        }
        else {
            std::cout << "Error: Invalid contact index." << std::endl;
        }
    }

    void removeContact(const std::string& phoneNumber) {
        for (size_t i = 0; i < contacts.size(); ++i) {
            if (contacts[i].getPhoneNumber() == phoneNumber) {
                contacts.erase(contacts.begin() + i);
                std::cout << "Contact removed successfully." << std::endl;
                return;
            }
        }

        std::cout << "Error: Contact not found." << std::endl;
    }

    void listBookmarks() {
        std::cout << "Bookmarked Contacts:" << std::endl;
        for (size_t i = 0; i < bookmarks.size(); ++i) {
            std::cout << i + 1 << ". " << bookmarks[i]->getName() << std::endl;
        }
    }
};

int main() {
    Phonebook phonebook;
    std::string command;

    while (command != "EXIT") {
        std::cout << "Enter a command (ADD, SEARCH, REMOVE, BOOKMARK, EXIT): ";
        std::cin >> command;

        if (command == "ADD") {
            std::string name, phoneNumber, nickname;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            std::cout << "Enter nickname: ";
            std::cin >> nickname;

            phonebook.addContact(name, phoneNumber, nickname);
        }
        else if (command == "SEARCH") {
            phonebook.searchContacts();
            size_t index;
            std::cout << "Enter the index of the contact: ";
            std::cin >> index;
            phonebook.displayContactDetails(index);
        }
        else if (command == "BOOKMARK") {
            phonebook.searchContacts();
            size_t index;
            std::cout << "Enter the index of the contact to bookmark: ";
            std::cin >> index;
            phonebook.bookmarkContact(index);
        }
        else if (command == "REMOVE") {
            std::cout << "Enter '1' to remove contact by index or '2' to remove contact by phone number: ";
            int choice;
            std::cin >> choice;

            if (choice == 1) {
                phonebook.searchContacts();
                size_t index;
                std::cout << "Enter the index of the contact to remove: ";
                std::cin >> index;
                phonebook.removeContact(index);
            }
            else if (choice == 2) {
                std::string phoneNumber;
                std::cout << "Enter the phone number of the contact to remove: ";
                std::cin >> phoneNumber;
                phonebook.removeContact(phoneNumber);
            }
            else {
                std::cout << "Invalid choice." << std::endl;
            }
        }
        else if (command == "EXIT") {
            std::cout << "Exiting the program." << std::endl;
        }
        else {
            std::cout << "Invalid command. Try again." << std::endl;
        }
    }

    return 0;
}

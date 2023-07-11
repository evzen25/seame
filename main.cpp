#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QObject>

class Contact {
public:
    QString phoneNumber;
    QString fullName;
    QString email;
    QString address;
};

class ContactList {
public:
    QList<Contact> contacts;

    void addContact(const Contact& contact) {
        contacts.append(contact);
    }

    void removeContact(int index) {
        if (index >= 0 && index < contacts.size()) {
            contacts.removeAt(index);
        }
    }

    QList<Contact> searchContacts(const QString& searchTerm) {
        QList<Contact> searchResults;
        for (const Contact& contact : contacts) {
            if (contact.fullName.contains(searchTerm, Qt::CaseInsensitive) ||
                contact.phoneNumber.contains(searchTerm, Qt::CaseInsensitive) ||
                contact.email.contains(searchTerm, Qt::CaseInsensitive) ||
                contact.address.contains(searchTerm, Qt::CaseInsensitive)) {
                searchResults.append(contact);
            }
        }
        return searchResults;
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QLabel *Phone_number_label = new QLabel("Phone number:");
    QLineEdit *Phone_number_lineEdit = new QLineEdit;

    QLabel *Full_name_label = new QLabel("Full name:");
    QLineEdit *Full_name_lineEdit = new QLineEdit;

    QLabel *E_mail_label = new QLabel("E-mail:");
    QLineEdit *E_mail_lineEdit = new QLineEdit;

    QLabel *Address_label = new QLabel("Address:");
    QLineEdit *Address_lineEdit = new QLineEdit;

    QPushButton *New_pushButton = new QPushButton("New");
    QPushButton *Edit_pushButton = new QPushButton("Edit");
    QPushButton *Cancel_pushButton = new QPushButton("Cancel");
    QPushButton *Save_pushButton = new QPushButton("Save");
    QPushButton *Delete_pushButton = new QPushButton("Delete");
    QPushButton *Search_pushButton = new QPushButton("Search");
    QLineEdit *Search_lineEdit = new QLineEdit;

    ContactList contactList;

    layout->addWidget(Phone_number_label);
    layout->addWidget(Phone_number_lineEdit);

    layout->addWidget(Full_name_label);
    layout->addWidget(Full_name_lineEdit);

    layout->addWidget(E_mail_label);
    layout->addWidget(E_mail_lineEdit);

    layout->addWidget(Address_label);
    layout->addWidget(Address_lineEdit);

    layout->addWidget(New_pushButton);
    layout->addWidget(Edit_pushButton);
    layout->addWidget(Cancel_pushButton);
    layout->addWidget(Save_pushButton);
    layout->addWidget(Delete_pushButton);
    layout->addWidget(Search_pushButton);
    layout->addWidget(Search_lineEdit);

    QObject::connect(New_pushButton, &QPushButton::clicked, [=]() {
        Phone_number_lineEdit->clear();
        Full_name_lineEdit->clear();
        E_mail_lineEdit->clear();
        Address_lineEdit->clear();
    });

    QObject::connect(Save_pushButton, &QPushButton::clicked, [=]() {
        QString phoneNumber = Phone_number_lineEdit->text();
        QString fullName = Full_name_lineEdit->text();
        QString email = E_mail_lineEdit->text();
        QString address = Address_lineEdit->text();

        Contact contact;
        contact.phoneNumber = phoneNumber;
        contact.fullName = fullName;
        contact.email = email;
        contact.address = address;

        contactList.addContact(contact);

        qDebug() << "Contact saved: " << contact.fullName;
    });

    QObject::connect(Cancel_pushButton, &QPushButton::clicked, [=]() {
        Phone_number_lineEdit->clear();
        Full_name_lineEdit->clear();
        E_mail_lineEdit->clear();
        Address_lineEdit->clear();
    });

    QObject::connect(Delete_pushButton, &QPushButton::clicked, [=]() {
        contactList.removeContact(0);
        qDebug() << "Contact deleted";
    });


    QObject::connect(Edit_pushButton, &QPushButton::clicked, [=]() {
        Phone_number_lineEdit->setEnabled(true);
        Full_name_lineEdit->setEnabled(true);
        E_mail_lineEdit->setEnabled(true);
        Address_lineEdit->setEnabled(true);
    });

    QObject::connect(Save_pushButton, &QPushButton::clicked, [=]() {
        Phone_number_lineEdit->setEnabled(false);
        Full_name_lineEdit->setEnabled(false);
        E_mail_lineEdit->setEnabled(false);
        Address_lineEdit->setEnabled(false);
        qDebug() << "Contact edited and saved";
    });

    QObject::connect(Search_pushButton, &QPushButton::clicked, [=]() {
        QString searchTerm = Search_lineEdit->text();
        QList<Contact> searchResults = contactList.searchContacts(searchTerm);

        qDebug() << "Search results:";
        for (const Contact& contact : searchResults) {
            qDebug() << "Full name: " << contact.fullName;
            qDebug() << "Phone number: " << contact.phoneNumber;
            qDebug() << "E-mail: " << contact.email;
            qDebug() << "Address: " << contact.address;
        }
    });

    window.setLayout(layout);
    window.show();

    return app.exec();
}








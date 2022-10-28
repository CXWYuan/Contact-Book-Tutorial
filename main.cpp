#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum ContactFields
{
    FIRST_NAME,
    LAST_NAME,
    PHONE_NUMBER
};

class Contact
{
private:
    string first_name, last_name, phone_number;

public:
    Contact(string fname, string lname, string pnumber)
    {
        first_name = fname;
        last_name = lname;
        phone_number = pnumber;
    }

    string get_field(ContactFields field)
    {
        switch (field)
        {
        case FIRST_NAME:
            return first_name;

        case LAST_NAME:
            return last_name;

        case PHONE_NUMBER:
            return phone_number;

        default:
            break;
        }
    }

    void set_field(ContactFields field, string new_value)
    {
        switch (field)
        {
        case FIRST_NAME:
            first_name = new_value;
            break;

        case LAST_NAME:
            last_name = new_value;
            break;

        case PHONE_NUMBER:
            phone_number = new_value;
            break;

        default:
            break;
        }
    }

    void print_contact_card()
    {
        cout << "First Name: " << first_name << "\n"
             << "Last Name: " << last_name << "\n"
             << "Phone Number: " << phone_number << "\n";
    }
};

bool delete_contact(string name_to_delete, vector<Contact> &contacts)
{
    for (int j = 0; j < contacts.size(); j++)
    {
        if (contacts[j].get_field(FIRST_NAME) == name_to_delete)
        {
            contacts.erase(contacts.begin() + j);
            return true;
        }
    }
    return false;
}

bool update_contact(string name_to_edit, ContactFields field_to_edit, string new_value, vector<Contact> &contacts)
{
    for (int k = 0; k < contacts.size(); k++)
    {
        if (contacts[k].get_field(FIRST_NAME) == name_to_edit)
        {
            contacts[k].set_field(field_to_edit, new_value);
            return true;
        }
    }
    return false;
}

int main()
{
    vector<Contact> contacts;

    while (true)
    {
        char action;

        cout << "q, c, v, d, u \n";
        cin >> action;

        switch (action)
        {
        case 'q':
        {
            return 0;
        }

        case 'c':
        {
            string f, l, p;
            cout << "First name: ";
            cin >> f;
            cout << "Last name: ";
            cin >> l;
            cout << "Phone number: ";
            cin >> p;
            cout << "\n";
            Contact razvan(f, l, p);
            contacts.push_back(razvan);
            break;
        }

        case 'v':
        {
            for (int i = 0; i < contacts.size(); i++)
            {
                contacts[i].print_contact_card();
                cout << "\n";
            }
            break;
        }

        case 'd':
        {
            string ntd;
            cout << "First name: ";
            cin >> ntd;
            bool deleted = delete_contact(ntd, contacts);
            if (deleted == false)
            {
                cout << "The contact could not be found\n";
                break;
            }
            else
            {
                cout << "The contact has been deleted\n";
                break;
            }
            break;
        }

        case 'u':
        {
            string nte, nv, option;
            ContactFields fte;
            cout << "First name: ";
            cin >> nte;
            cout << "fn (first name), ln (last name) or pn (phone number)? \n";
            cin >> option;
            cout << "Update: ";
            cin >> nv;
            if (option == "fn")
            {
                fte = FIRST_NAME;
            }
            else if (option == "ln")
            {
                fte = LAST_NAME;
            }
            else if (option == "pn")
            {
                fte = PHONE_NUMBER;
            }
            else
            {
                cout << "Invalid option\n";
                return 0;
            }

            bool updated = update_contact(nte, fte, nv, contacts);
            if (updated == false)
            {
                cout << "The contact could not be found\n";
                break;
            }
            else
            {
                cout << "The contact has been updated\n";
                break;
            }
            break;
        }

        default:
        {
            break;
        }
        }
    }
}

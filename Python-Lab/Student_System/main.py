from database import Database
from utils import Utils

def main():
    db = Database()

    while True:
        choice = Utils.show_menu()
        
        if choice == '1':
            # Add Student
            print("\n--- Add New Student ---")
            name = input("Enter name: ")
            roll_number = input("Enter roll number: ")
            db.add_student(name, roll_number)
        
        elif choice == '2':
            # View Students
            db.view_students()
            
        elif choice == '3':
            # Search Student
            print("\n--- Search for Student ---")
            roll_number = input("Enter roll number to search: ")
            db.search_student(roll_number)
            
        elif choice == '4':
            # Exit
            print("Exiting system. Goodbye!")
            break
            
        else:
            print("Invalid choice. Please enter a number from 1 to 4.")

if __name__ == "__main__":
    main()
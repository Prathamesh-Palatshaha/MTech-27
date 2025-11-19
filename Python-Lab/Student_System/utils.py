class Utils:
    @staticmethod
    def show_menu():
        """
        Prints the main menu and gets the user's choice.
        """
        print("\n===== Student Management System =====")
        print("1. Add Student")
        print("2. View Students")
        print("3. Search Student")
        print("4. Exit")
        choice = input("Enter your choice (1-4): ")
        return choice
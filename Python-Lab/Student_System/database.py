class Student:
    def __init__(self, name, roll_number):
        self.name = name
        self.roll_number = roll_number

    def __str__(self):
        return f"Name: {self.name}, Roll Number: {self.roll_number}"

# database
class Database:
    def __init__(self):
        self.students = {}

    def add_student(self, name, roll_number):
        if roll_number in self.students:
            print(f"Error: Student with Roll Number {roll_number} already exists.")
            return
        
        new_student = Student(name, roll_number)
        self.students[roll_number] = new_student
        print(f"Success: Student '{name}' added.")

    def view_students(self):
        if not self.students:
            print("Database is empty. No students to show.")
            return
        
        print("\n--- All Students ---")
        for student in self.students.values():
            print(student)
        print("----------------------")

    def search_student(self, roll_number):
        student = self.students.get(roll_number)
        
        if student:
            print("\n--- Student Found ---")
            print(student)
        else:
            print(f"\nError: Student with Roll Number {roll_number} not found.")
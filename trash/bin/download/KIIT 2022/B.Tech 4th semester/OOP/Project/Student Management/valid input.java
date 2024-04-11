import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

class Student implements Serializable {
    private String name;
    private int id;
    private String course;
    private Map<String, String> grades;
    private Map<String, Boolean> attendance;

    public Student(String name, int id, String course) {
        this.name = name;
        this.id = id;
        this.course = course;
        this.grades = new HashMap<>();
        this.attendance = new HashMap<>();
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public String getCourse() {
        return course;
    }

    public void addGrade(String subject, String grade) {
        grades.put(subject, grade);
    }

    public void markAttendance(String date, boolean present) {
        attendance.put(date, present);
    }

    public Map<String, String> getGrades() {
        return grades;
    }

    public Map<String, Boolean> getAttendance() {
        return attendance;
    }
}

class StudentManagementSystem {
    private ArrayList<Student> students;
    private boolean isAdminOrTeacher;
    // private static final String FILE_NAME = "students.txt";
    private final String fileName = "students.csv"; // CSV file name

    public StudentManagementSystem() {
        students = new ArrayList<>();
        isAdminOrTeacher = false;
        loadStudentsFromFile();
    }

    // Method to handle login
    public void login() {
        Scanner scanner = new Scanner(System.in);
        System.out.println(" ");
        System.out.println("Login Menu:");
        System.out.println("1. Admin");
        System.out.println("2. Teacher");
        System.out.println("3. Student");

        // validate input 1-3
        int choice = 0;
        while (choice < 1 || choice > 3) {
            System.out.print("Enter your choice: ");
            if (scanner.hasNextInt()) {
                choice = scanner.nextInt();
                if (choice < 1 || choice > 3) {
                    System.out.println("Please enter a value between 1 and 3.");
                }
            } else {
                System.out.println("Please enter a valid integer value between 1 and 3.");
                scanner.next(); // Consume invalid input
            }
        }

        scanner.nextLine(); // Consume newline

        switch (choice) {
            case 1:
            case 2:
                authenticate(choice);
                break;
            case 3:
                // Students don't need authentication
                System.out.println("Logged in as student");
                break;
            default:
                System.out.println("Invalid choice.");
        }
    }

    // Method to authenticate user
    public void authenticate(int choice) {
        Scanner scanner = new Scanner(System.in);
        boolean loggedIn = false;

        do {
            System.out.print("Enter username: ");
            String username = scanner.nextLine();
            System.out.print("Enter password: ");
            String password = scanner.nextLine();

            if (choice == 1) { // Admin login
                if ("admin".equals(username) && "admin".equals(password)) {
                    isAdminOrTeacher = true;
                    System.out.println("Logged in as admin");
                    displayCredentials();
                    loggedIn = true;
                } else {
                    System.out.println("Invalid username or password.\n");
                    System.out.println("Option Menu:");
                    System.out.println("1. Login");
                    System.out.println("2. Exit");
                    System.out.println("r. Retry");
                    System.out.println("Enter  your option: ");
                    String option = scanner.nextLine();
                    if (option.equals("2")) {
                        System.out.println("Exiting...");
                        System.exit(0);
                    } else if (option.equals("r") || option.equals("R")) {
                        authenticate(choice);
                        break;
                    } else if (option.equals("1")) {
                        login();
                        break;
                    } else {
                        System.out.println("Invalid option. Please try again.\n");
                    }
                }
            } else if (choice == 2) { // Teacher login
                if ("teacher".equals(username) && "teacher".equals(password)) {
                    isAdminOrTeacher = true;
                    System.out.println("Logged in as teacher");
                    loggedIn = true;
                } else {
                    System.out.println("Invalid username or password.\n");
                    System.out.println("Options:");
                    System.out.println("1. Login");
                    System.out.println("2. Exit");
                    System.out.println("r. Retry");
                    System.out.println("Enter  your option: ");
                    String option = scanner.nextLine();
                    if (option.equals("2")) {
                        System.out.println("Exiting...");
                        System.exit(0);
                    } else if (option.equals("r") || option.equals("R")) {
                        authenticate(choice);
                        break;
                    } else if (option.equals("1")) {
                        login();
                        break;
                    } else {
                        System.out.println("Invalid option. Please try again.\n");
                    }
                }
            }
        } while (!loggedIn);
    }

    // Method to display stored usernames and passwords
    public void displayCredentials() {
        System.out.println(" ");
        System.out.println("Stored Usernames and Passwords:");
        System.out.println("Username: admin, Password: admin");
        System.out.println("Username: teacher, Password: teacher");
    }

    // Method to add a student
    public void addStudent(Scanner scanner) {
        if (!isAdminOrTeacher) {
            System.out.println("Access denied. Only teachers and administrators can add students.");
            return;
        }
        // validate input to only number
        int id = 0;
        while (true) {
            System.out.print("Enter student ID: ");
            if (scanner.hasNextInt()) {
                id = scanner.nextInt();
                break;
            } else {
                System.out.println("Please enter the student ID in number format.");
                scanner.next(); // Consume invalid input
            }
        }
        scanner.nextLine(); // Consume newline
        if (isDuplicateStudentId(id)) {
            System.out.println("Student with ID " + id + " already exists.");
            return;
        }
        // validate name to only alphabets and spaces
        String name;
        while (true) {
            System.out.print("Enter student name: ");
            name = scanner.nextLine();
            if (name.matches("[a-zA-Z ]+")) {
                name = capitalizeEachWord(name);
                break;
            } else {
                System.out.println("Name should contain only alphabetic characters.");
            }
        }
        // validate course name as alphabetic characters
        String course;
        while (true) {
            System.out.print("Enter student course: ");
            course = scanner.nextLine();
            if (course.matches("[a-zA-Z ]+")) {
                course = capitalizeEachWord(course);
                break;
            } else {
                System.out.println("Course name should contain only alphabetic characters.");
            }
        }
        Student student = new Student(name, id, course);
        students.add(student);
    }

    // Method to check if student ID is duplicate
    public boolean isDuplicateStudentId(int id) {
        for (Student student : students) {
            if (student.getId() == id) {
                return true;
            }
        }
        return false;
    }

    // Method to add grades for a student
    public void addGrade(int id, Scanner scanner) {
        if (!isAdminOrTeacher) {
            System.out.println("Access denied. Only teachers and administrators can add grades.");
            return;
        }

        if (!isValidStudentId(id)) {
            System.out.println("Invalid student ID.");
            return;
        }

        // validate subject input in number only
        int numSubjects = 0;
        while (true) {
            System.out.print("Enter the number of subjects: ");
            if (scanner.hasNextInt()) {
                numSubjects = scanner.nextInt();
                break;
            } else {
                System.out.println("Please enter in number format.");
                scanner.next(); // Consume invalid input
            }
        }

        scanner.nextLine(); // Consume newline

        for (int i = 0; i < numSubjects; i++) {
            // validate subject name to be alphabetic characters only
            String subject;
            while (true) {
                System.out.print("Enter subject " + (i + 1) + ": ");
                subject = scanner.nextLine();
                if (subject.matches("[a-zA-Z ]+")) {
                    subject = capitalizeEachWord(subject);
                    break;
                } else {
                    System.out.println("subject name should contain only alphabetic characters.");
                }
            }

            if (isDuplicateSubject(id, subject)) {
                System.out.println("Subject " + subject + " already exists for student with ID " + id);
                continue;
            }
            System.out.print("Enter grade for subject " + subject + ": ");
            String grade = scanner.nextLine();
            int studentIndex = findStudentIndexById(id);
            students.get(studentIndex).addGrade(subject, grade);

            // Check if grade is in numerical system (0 to 100)
            if (grade.matches("[0-9]+")) {
                int numericGrade = Integer.parseInt(grade);
                // Convert numerical grade to alphabetical grade
                if (numericGrade >= 90) {
                    grade = "A+";
                } else if (numericGrade >= 85) {
                    grade = "A";
                } else if (numericGrade >= 80) {
                    grade = "A-";
                } else if (numericGrade >= 75) {
                    grade = "B+";
                } else if (numericGrade >= 70) {
                    grade = "B";
                } else if (numericGrade >= 65) {
                    grade = "B-";
                } else if (numericGrade >= 60) {
                    grade = "C+";
                } else if (numericGrade >= 55) {
                    grade = "C";
                } else if (numericGrade >= 50) {
                    grade = "C-";
                } else if (numericGrade >= 45) {
                    grade = "D+";
                } else if (numericGrade >= 40) {
                    grade = "D";
                } else {
                    grade = "F";
                }
            } else {
                // Check if grade is already in alphabetical system (A+ to Z-)
                if (!grade.matches("[A-Za-z+-]+")) {
                    System.out.println(
                            "Invalid grade format. Grade must be in either alphabetical system (A+ to Z-) or numerical system (0 to 100).");
                    return;
                }
            }
        }
    }

    // Method to check if student ID is valid
    public boolean isValidStudentId(int id) {
        for (Student student : students) {
            if (student.getId() == id) {
                return true;
            }
        }
        return false;
    }

    // Method to check if subject is duplicate for a student
    public boolean isDuplicateSubject(int id, String subject) {
        int studentIndex = findStudentIndexById(id);
        if (studentIndex != -1) {
            Student student = students.get(studentIndex);
            return student.getGrades().containsKey(subject);
        }
        return false;
    }

    // Method to mark attendance for a student
    public void markAttendance(int id, Scanner scanner) {
        if (!isAdminOrTeacher) {
            System.out.println("Access denied. Only teachers and administrators can mark attendance.");
            return;
        }

        if (!isValidStudentId(id)) {
            System.out.println("Invalid student ID.");
            return;
        }

        String dateInput;
        LocalDate date;

        while (true) {
            System.out.print(
                    "Automatically insert today's date (t), yesterday's date (y), or enter a custom date (YYYY-MM-DD): ");
            dateInput = scanner.nextLine();
            if (dateInput.equalsIgnoreCase("t")) {
                date = LocalDate.now();
                break;
            } else if (dateInput.equalsIgnoreCase("y")) {
                date = LocalDate.now().minusDays(1);
                break;
            } else if (dateInput.matches("\\d{4}-\\d{2}-\\d{2}")) {
                date = LocalDate.parse(dateInput, DateTimeFormatter.ISO_DATE);
                break;
            } else {
                System.out.println(
                        "Please enter 't' for today's date, 'y' for yesterday's date, or a valid date in YYYY-MM-DD format.");
            }
        }

        if (date.isAfter(LocalDate.now())) {
            System.out.println("Invalid date. Date cannot be in the future.");
            return;
        }
        String dateString = date.format(DateTimeFormatter.ISO_DATE);

        if (isDuplicateAttendanceDate(id, dateString)) {
            System.out.println("Attendance for date " + dateString + " already marked for student with ID " + id);
            return;
        }
        System.out.print("Is the student present? (Y/N): ");
        char attendanceChar = scanner.nextLine().charAt(0);
        boolean present = attendanceChar == 'Y' || attendanceChar == 'y';
        int studentIndex = findStudentIndexById(id);
        students.get(studentIndex).markAttendance(dateString, present);
    }

    // Method to check if attendance for a date is duplicate for a student
    public boolean isDuplicateAttendanceDate(int id, String date) {
        int studentIndex = findStudentIndexById(id);
        if (studentIndex != -1) {
            Student student = students.get(studentIndex);
            return student.getAttendance().containsKey(date);
        }
        return false;
    }

    // Method to find student index by ID
    private int findStudentIndexById(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students.get(i).getId() == id) {
                return i;
            }
        }
        return -1; // If student with given ID is not found
    }

    // Method to display list of students
    public void displayStudents() {
        System.out.println("Student List:");
        for (Student student : students) {
            System.out.println(
                    "Name: " + student.getName() + ", ID: " + student.getId() + ", Course: " + student.getCourse());
        }
    }

    // Method to display grades for a student
    public void displayGrades(int id) {
        for (Student student : students) {
            if (student.getId() == id) {
                System.out.println("Grades for " + student.getName() + ":");
                // Displaying grades for all subjects
                for (Map.Entry<String, String> entry : student.getGrades().entrySet()) {
                    String subject = entry.getKey();
                    String grade = entry.getValue();
                    if (grade.matches("[0-9]+")) {
                        int numericGrade = Integer.parseInt(grade);
                        grade = convertToAlphabetGrade(numericGrade);
                    }
                    System.out.println(subject + ": " + grade);
                }
                return;
            }
        }
        System.out.println("Student with ID " + id + " not found.");
    }

    // Method to convert numerical grade to alphabetical grade
    private String convertToAlphabetGrade(int numericGrade) {
        if (numericGrade >= 90) {
            return "A+";
        } else if (numericGrade >= 85) {
            return "A";
        } else if (numericGrade >= 80) {
            return "A-";
        } else if (numericGrade >= 75) {
            return "B+";
        } else if (numericGrade >= 70) {
            return "B";
        } else if (numericGrade >= 65) {
            return "B-";
        } else if (numericGrade >= 60) {
            return "C+";
        } else if (numericGrade >= 55) {
            return "C";
        } else if (numericGrade >= 50) {
            return "C-";
        } else if (numericGrade >= 45) {
            return "D+";
        } else if (numericGrade >= 40) {
            return "D";
        } else {
            return "F";
        }
    }

    // Method to display attendance for a student
    public void displayAttendance(int id) {
        for (Student student : students) {
            if (student.getId() == id) {
                System.out.println("Attendance for " + student.getName() + ":");
                // Displaying attendance for all dates
                for (Map.Entry<String, Boolean> entry : student.getAttendance().entrySet()) {
                    System.out.println(entry.getKey() + ": " + (entry.getValue() ? "Present" : "Absent"));
                }
                return;
            }
        }
        System.out.println("Student with ID " + id + " not found.");
    }

    // Method to modify student record
    public void modifyStudent(int id) {
        if (!isAdminOrTeacher) {
            System.out.println("Access denied. Only teachers and administrators can modify student records.");
            return;
        }

        Iterator<Student> iterator = students.iterator();
        while (iterator.hasNext()) {
            Student student = iterator.next();
            if (student.getId() == id) {
                iterator.remove();
                System.out.println("Student with ID " + id + " deleted successfully.");
                return;
            }
        }
        System.out.println("Student with ID " + id + " not found.");
    }

    // Utility method to capitalize each word in a string
    private String capitalizeEachWord(String str) {
        StringBuilder result = new StringBuilder();
        boolean capitalizeNext = true;
        for (char c : str.toCharArray()) {
            if (Character.isWhitespace(c)) {
                capitalizeNext = true;
            } else if (capitalizeNext) {
                c = Character.toTitleCase(c);
                capitalizeNext = false;
            }
            result.append(c);
        }
        return result.toString();
    }

    public boolean getIsAdminOrTeacher() {
        return isAdminOrTeacher;
    }

    public void saveStudentsToFile() {
        try (PrintWriter writer = new PrintWriter(new FileWriter(fileName))) {
            for (Student student : students) {
                writer.println(student.getName() + "," + student.getId() + "," + student.getCourse());
                for (Map.Entry<String, String> entry : student.getGrades().entrySet()) {
                    writer.println("Grade," + student.getId() + "," + entry.getKey() + "," + entry.getValue());
                }
                for (Map.Entry<String, Boolean> entry : student.getAttendance().entrySet()) {
                    writer.println("Attendance," + student.getId() + "," + entry.getKey() + "," + entry.getValue());
                }
            }
            System.out.println("Data saved to file: " + fileName);
        } catch (IOException e) {
            System.out.println("Error saving data to file: " + e.getMessage());
        }
    }

    public void loadStudentsFromFile() {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length > 0) {
                    if (parts[0].equals("Grade")) {
                        int id = Integer.parseInt(parts[1]);
                        String subject = parts[2];
                        String grade = parts[3];
                        for (Student student : students) {
                            if (student.getId() == id) {
                                student.addGrade(subject, grade);
                                break;
                            }
                        }
                    } else if (parts[0].equals("Attendance")) {
                        int id = Integer.parseInt(parts[1]);
                        String date = parts[2];
                        boolean present = Boolean.parseBoolean(parts[3]);
                        for (Student student : students) {
                            if (student.getId() == id) {
                                student.markAttendance(date, present);
                                break;
                            }
                        }
                    } else {
                        int id = Integer.parseInt(parts[1]);
                        String name = parts[0];
                        String course = parts[2];
                        students.add(new Student(name, id, course));
                    }
                }
            }
            System.out.println("Data loaded from file: " + fileName);
        } catch (IOException e) {
            System.out.println("Error loading data from file: " + e.getMessage());
        }
    }

    public void deleteStudentDataFromFile() {
        try {
            File file = new File(fileName);
            if (file.delete()) {
                System.out.println("Student data deleted from file successfully.");
            } else {
                System.out.println("Error deleting student data from file.");
            }
        } catch (Exception e) {
            System.out.println("Error deleting student data from file: " + e.getMessage());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StudentManagementSystem sms = new StudentManagementSystem();

        // sms.loadStudentsFromFile(); // Load data from file

        System.out.println("Welcome to Student Management System");

        sms.login(); // Display login menu

        while (true) {
            if (sms.getIsAdminOrTeacher()) {
                System.out.println("\nStudent Management System Menu:");
                System.out.println("1. Add Student");
                System.out.println("2. Add Grade");
                System.out.println("3. Mark Attendance");
                System.out.println("4. Display Students");
                System.out.println("5. Display Grades");
                System.out.println("6. Display Attendance");
                System.out.println("7. Modify Student");
                System.out.println("8. Login");
                System.out.println("9. Save Data to File");
                System.out.println("10. Exit");
            } else {
                System.out.println("\nStudent Management System Menu:");
                System.out.println("4. Display Students");
                System.out.println("5. Display Grades");
                System.out.println("6. Display Attendance");
                System.out.println("8. Login");
                System.out.println("10. Exit");
            }
            int choice = 0;
            while (choice < 1 || choice > 10) {
                System.out.print("\nEnter your choice: ");
                if (scanner.hasNextInt()) {
                    choice = scanner.nextInt();
                    if (choice < 1 || choice > 10) {
                        System.out.println("Please enter a valid value.");
                    }
                } else {
                    System.out.println("Please enter a valid value.");
                    scanner.next(); // Consume invalid input
                }
            }
            // scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    scanner.nextLine(); // Consume newline
                    sms.addStudent(scanner);
                    break;
                case 2:
                    int gradeId = 0;
                    while (true) {
                        System.out.print("Enter student ID: ");
                        if (scanner.hasNextInt()) {
                            gradeId = scanner.nextInt();
                            break;
                        } else {
                            System.out.println("Please enter the student ID in number format.");
                            scanner.next(); // Consume invalid input
                        }
                    }
                    scanner.nextLine(); // Consume newline
                    sms.addGrade(gradeId, scanner);
                    break;
                case 3:
                    int attendanceId = 0;
                    while (true) {
                        System.out.print("Enter student ID: ");
                        if (scanner.hasNextInt()) {
                            attendanceId = scanner.nextInt();
                            break;
                        } else {
                            System.out.println("Please enter the student ID in number format.");
                            scanner.next(); // Consume invalid input
                        }
                    }
                    scanner.nextLine(); // Consume newline
                    sms.markAttendance(attendanceId, scanner);
                    break;
                case 4:
                    sms.displayStudents();
                    break;
                case 5:
                    int displayGradeId = 0;
                    while (true) {
                        System.out.print("Enter student ID: ");
                        if (scanner.hasNextInt()) {
                            displayGradeId = scanner.nextInt();
                            break;
                        } else {
                            System.out.println("Please enter the student ID in number format.");
                            scanner.next(); // Consume invalid input
                        }
                    }
                    sms.displayGrades(displayGradeId);
                    break;
                case 6:
                    int displayAttendanceId = 0;
                    while (true) {
                        System.out.print("Enter student ID: ");
                        if (scanner.hasNextInt()) {
                            displayAttendanceId = scanner.nextInt();
                            break;
                        } else {
                            System.out.println("Please enter the student ID in number format.");
                            scanner.next(); // Consume invalid input
                        }
                    }
                    sms.displayAttendance(displayAttendanceId);
                    break;
                case 7:
                    if (sms.getIsAdminOrTeacher()) {
                        int modifyId = 0;
                        while (true) {
                            System.out.print("Enter student ID to modify: ");
                            if (scanner.hasNextInt()) {
                                modifyId = scanner.nextInt();
                                break;
                            } else {
                                System.out.println("Please enter the student ID in number format.");
                                scanner.next(); // Consume invalid input
                            }
                        }
                        sms.modifyStudent(modifyId);
                    } else {
                        System.out
                                .println("Access denied. Only teachers and administrators can modify student records.");
                    }
                    break;
                case 8:
                    sms.login(); // Display login menu
                    break;
                case 9:
                    sms.saveStudentsToFile(); // Save data to file
                    break;
                case 10:
                    sms.saveStudentsToFile(); // Save students to file before exiting
                    System.out.println("Exiting...");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice, please try again.");
            }
        }
    }
}
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Student {
    private String name;
    private int id;
    private String course;
    private Map<String, String> grades; // Storing grades as String
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
        if (!attendance.containsKey(date)) {
            attendance.put(date, present);
        } else {
            System.out.println("Attendance for " + date + " already marked.");
        }
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

    public StudentManagementSystem() {
        students = new ArrayList<>();
        isAdminOrTeacher = false;
    }

    public boolean getIsAdminOrTeacher() {
        return isAdminOrTeacher;
    }

    public void login() {
        Scanner scanner = new Scanner(System.in);
        System.out.println(" ");
        System.out.println("Login Menu:");
        System.out.println("1. Admin");
        System.out.println("2. Teacher");
        System.out.println("3. Student");
        System.out.print("Enter your choice: ");
        int choice = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        switch (choice) {
            case 1:
            case 2:
                authenticate();
                break;
            case 3:
                System.out.println("Logged in as student");
                break;
            default:
                System.out.println("Invalid choice.");
        }
    }

    public void authenticate() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        // For simplicity, let's consider admin and teacher credentials as "admin" and
        // "teacher" respectively
        if ("admin".equals(username) && "admin".equals(password)) {
            isAdminOrTeacher = true;
            System.out.println("Logged in as admin");
            displayCredentials();
        } else if ("teacher".equals(username) && "teacher".equals(password)) {
            isAdminOrTeacher = true;
            System.out.println("Logged in as teacher");
        } else {
            System.out.println("Invalid username or password. Access denied.");
        }
    }

    public void displayCredentials() {
        System.out.println("Stored Usernames and Passwords:");
        System.out.println("Username: admin, Password: admin");
        System.out.println("Username: teacher, Password: teacher");
    }

    public void addStudent(Scanner scanner) {
        if (!isAdminOrTeacher) {
            System.out.println("Access denied. Only teachers and administrators can add students.");
            return;
        }
        System.out.print("Enter student ID: ");
        int id = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        if (isDuplicateStudentId(id)) {
            System.out.println("Student with ID " + id + " already exists.");
            return;
        }
        System.out.print("Enter student name: ");
        String name = capitalizeEachWord(scanner.nextLine());
        System.out.print("Enter student course: ");
        String course = scanner.nextLine();
        Student student = new Student(name, id, course);
        students.add(student);
    }

    public boolean isDuplicateStudentId(int id) {
        for (Student student : students) {
            if (student.getId() == id) {
                return true;
            }
        }
        return false;
    }

    public void addGrade(int id, Scanner scanner) {
        if (!isAdminOrTeacher) {
            System.out.println("Access denied. Only teachers and administrators can add grades.");
            return;
        }

        if (!isValidStudentId(id)) {
            System.out.println("Invalid student ID.");
            return;
        }

        System.out.print("Enter the number of subjects: ");
        int numSubjects = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        for (int i = 0; i < numSubjects; i++) {
            System.out.print("Enter subject " + (i + 1) + ": ");
            String subject = capitalizeEachWord(scanner.nextLine());
            if (isDuplicateSubject(id, subject)) {
                System.out.println("Subject " + subject + " already exists for student with ID " + id);
                continue;
            }
            System.out.print("Enter grade for subject " + subject + ": ");
            String grade = scanner.nextLine();
            int studentIndex = findStudentIndexById(id);
            students.get(studentIndex).addGrade(subject, grade);
        }
    }

    public boolean isValidStudentId(int id) {
        for (Student student : students) {
            if (student.getId() == id) {
                return true;
            }
        }
        return false;
    }

    public boolean isDuplicateSubject(int id, String subject) {
        int studentIndex = findStudentIndexById(id);
        if (studentIndex != -1) {
            Map<String, String> grades = students.get(studentIndex).getGrades();
            return grades.containsKey(subject);
        }
        return false;
    }

    public void markAttendance(int id, Scanner scanner) {
        if (!isAdminOrTeacher) {
            System.out.println("Access denied. Only teachers and administrators can mark attendance.");
            return;
        }

        if (!isValidStudentId(id)) {
            System.out.println("Invalid student ID.");
            return;
        }

        System.out.print("Enter date (YYYY-MM-DD): ");
        String date = scanner.nextLine();
        int studentIndex = findStudentIndexById(id);
        students.get(studentIndex).markAttendance(date, true); // Marking attendance as present
    }

    private int findStudentIndexById(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students.get(i).getId() == id) {
                return i;
            }
        }
        return -1; // If student with given ID is not found
    }

    public void displayStudents() {
        System.out.println("Student List:");
        for (Student student : students) {
            System.out.println(
                    "Name: " + student.getName() + ", ID: " + student.getId() + ", Course: " + student.getCourse());
        }
    }

    public void displayGrades(int id) {
        for (Student student : students) {
            if (student.getId() == id) {
                System.out.println("Grades for " + student.getName() + ":");
                // Displaying grades for all subjects
                for (Map.Entry<String, String> entry : student.getGrades().entrySet()) {
                    System.out.println(entry.getKey() + ": " + entry.getValue());
                }
                return;
            }
        }
        System.out.println("Student with ID " + id + " not found.");
    }

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
}

public class Mains {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StudentManagementSystem sms = new StudentManagementSystem();

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
                System.out.println("7. Login");
                System.out.println("8. Exit");
            } else {
                System.out.println("\nStudent Management System Menu:");
                System.out.println("4. Display Students");
                System.out.println("5. Display Grades");
                System.out.println("6. Display Attendance");
                System.out.println("7. Login");
                System.out.println("8. Exit");
            }
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    scanner.nextLine(); // Consume newline
                    sms.addStudent(scanner);
                    break;
                case 2:
                    System.out.print("Enter student ID: ");
                    int gradeId = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                    sms.addGrade(gradeId, scanner);
                    break;
                case 3:
                    System.out.print("Enter student ID: ");
                    int attendanceId = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                    sms.markAttendance(attendanceId, scanner);
                    break;
                case 4:
                    sms.displayStudents();
                    break;
                case 5:
                    System.out.print("Enter student ID: ");
                    int displayGradeId = scanner.nextInt();
                    sms.displayGrades(displayGradeId);
                    break;
                case 6:
                    System.out.print("Enter student ID: ");
                    int displayAttendanceId = scanner.nextInt();
                    sms.displayAttendance(displayAttendanceId);
                    break;
                case 7:
                    sms.login(); // Display login menu
                    break;
                case 8:
                    System.out.println("Exiting...");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice, please try again.");
            }
        }
    }
}

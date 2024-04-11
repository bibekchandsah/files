import java.util.Scanner;

class InvalidAgeException extends Exception {
    public InvalidAgeException(String message) {
        super(message);
    }
}

public class AgeValidator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter your age: ");
            try {
                int age = scanner.nextInt();
                if (age < 0 || age > 120) {
                    throw new InvalidAgeException("Invalid age: Please enter a valid age between 0 and 120.");
                } else {
                    System.out.println("Your entered age: " + age);
                }
            } catch (InvalidAgeException e) {
                System.out.println(e.getMessage());
                break;
            }
        }
        scanner.close();
    }
}

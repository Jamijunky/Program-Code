
import java.util.Scanner;

public class hehe {

    public static void main(String[] args) {
        System.out.print("Enter radius: ");
        try (Scanner sc = new Scanner(System.in)) {
            double radius = sc.nextDouble();
            double result = 3.14 * radius * radius;

            System.out.println("Area of circle: " + result);

        }

    }
}

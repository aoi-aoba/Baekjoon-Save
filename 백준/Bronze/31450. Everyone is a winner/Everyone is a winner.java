import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt(), k = sc.nextInt();
        System.out.println((m % k == 0) ? "Yes" : "No");
    }
}
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(true) {
            int a = sc.nextInt(), b = sc.nextInt();
            if (a == 0 && b == 0) return;
            else System.out.println(a + b);
        }
    }
}
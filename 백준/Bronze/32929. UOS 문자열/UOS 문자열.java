import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long x = Long.parseLong(br.readLine());
        if(x % 3 == 0) System.out.println("S");
        else if(x % 3 == 1) System.out.println("U");
        else System.out.println("O");
    }
}
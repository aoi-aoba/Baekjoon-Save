import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(br.readLine());
        System.out.printf("The largest square has side length %d.\n", (int)Math.floor(Math.sqrt(N)));
        br.close();
    }
}
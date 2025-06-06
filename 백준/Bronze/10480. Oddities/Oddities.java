import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int i=0; i<T; i++) {
            int temp = Integer.parseInt(br.readLine());
            System.out.println(temp + " is " + ((temp % 2 == 0) ? "even" : "odd"));
        }
        br.close();
    }
}
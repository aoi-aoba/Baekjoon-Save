import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int B = Integer.parseInt(br.readLine());
        int P = 5 * B - 400;
        System.out.println(P);
        if(P < 100) System.out.println(1);
        else if(P == 100) System.out.println(0);
        else System.out.println(-1);
    }
}
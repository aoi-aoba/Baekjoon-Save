import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), res = 0;
        for(int i = 0; i < N; i++) {
            res += (Integer.parseInt(br.readLine()) % 2 == 1) ? 1 : 0;
        }
        System.out.print(res);
    }
}
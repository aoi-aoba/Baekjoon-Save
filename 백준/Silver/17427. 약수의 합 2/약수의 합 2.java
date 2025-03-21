import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine()), result = 0;
        for(int i=1; i<=n; i++)
            result += i * (n / i);
        System.out.println(result);
        br.close();
    }
}
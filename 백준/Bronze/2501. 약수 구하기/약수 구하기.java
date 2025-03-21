import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int num = 0;
        for(int i=1; i<=n; i++) {
            if(n % i == 0) num++;
            if(num == k) {
                System.out.println(i);
                return;
            }
        }
        if(num < k) System.out.println(0);
    }
}
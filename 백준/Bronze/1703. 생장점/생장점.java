import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int tree = 1;
            if(N == 0) break;
            for(int i=0; i<2 * N; i++) {
                int M = Integer.parseInt(st.nextToken());
                if(i % 2 == 0) tree *= M;
                else tree -= M;
            }
            sb.append(tree).append("\n");
        }
        System.out.print(sb);
        br.close();
    }
}
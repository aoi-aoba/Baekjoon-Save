import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        while(true) {
            st = new StringTokenizer(br.readLine());
            long[] arr = new long[3];
            for(int i=0; i<3; i++) arr[i] = Integer.parseInt(st.nextToken());
            if(arr[0] == arr[1] && arr[1] == arr[2]) break;
            Arrays.sort(arr);
            if(arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2])
                sb.append("right").append("\n");
            else sb.append("wrong").append("\n");
        }
        System.out.print(sb);
        br.close();
    }
}
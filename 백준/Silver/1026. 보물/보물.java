import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        Integer[] B = new Integer[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) A[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) B[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(A);
        Arrays.sort(B, Collections.reverseOrder());

        int res = 0;
        for(int i = 0; i < N; i++) {
            res += A[i] * B[i];
        }
        System.out.println(res);
    }
}
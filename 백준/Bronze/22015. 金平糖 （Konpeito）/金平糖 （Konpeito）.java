import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[3];
        int arrSum = 0;
        for(int i=0; i<3; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            arrSum += arr[i];
        }
        Arrays.sort(arr);
        System.out.println(3*arr[2]-arrSum);

    }
}
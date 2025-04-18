import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[9];
        int sum = 0;
        for(int i=0; i<9; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            sum += arr[i];
        }
        sum -= 100;
        boolean isFound = false;
        for(int i=0; i<9; i++) {
            for(int j=i+1; j<9; j++) {
                if(arr[i] + arr[j] == sum) {
                    arr[i] = 0;
                    arr[j] = 0;
                    isFound = true;
                    break;
                }
            }
            if(isFound) break;
        }
        for(int i=0; i<9; i++)
            if(arr[i] != 0) System.out.println(arr[i]);
        br.close();
    }
}
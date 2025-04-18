import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = read();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = read();
        long sum = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) sum += Math.abs(arr[i] - arr[j]);
        bw.write(String.valueOf(sum));
        bw.flush();
    }
    private static int read() throws IOException {
        int c, n = System.in.read() & 15;
        while ((c = System.in.read()) > 32) n = (n << 3) + (n << 1) + (c & 15);
        return n;
    }
}
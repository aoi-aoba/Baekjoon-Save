import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        bw.write(String.valueOf((long)(Math.pow(Integer.parseInt(st.nextToken()), 2))*Long.parseLong(st.nextToken())));
        bw.flush();
    }
}
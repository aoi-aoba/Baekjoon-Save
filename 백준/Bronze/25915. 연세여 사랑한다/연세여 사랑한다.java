import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char ch = br.readLine().charAt(0);
        System.out.println(84 + (ch > 'I' ? ch - 'I' : 'I' - ch));
    }
}
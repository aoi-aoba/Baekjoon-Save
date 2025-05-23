import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 5; j++) sb.append("@".repeat(N));
            sb.append("\n");
        }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < N; j++) sb.append("@".repeat(N)).append("\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 5; j++) sb.append("@".repeat(N));
            sb.append("\n");
        }

        System.out.println(sb);
    }
}
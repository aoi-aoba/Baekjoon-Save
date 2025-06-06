import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        Deque<int[]> deque = new ArrayDeque<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) deque.addLast(new int[] {i, Integer.parseInt(st.nextToken())});

        while (deque.size() > 1) {
            int[] arr = deque.pollFirst();
            sb.append(arr[0]).append(" ");
            int num = arr[1];

            if (num > 0) for (int i = 1; i < num; i++) deque.offerLast(deque.pollFirst());
            else for (int i = num; i < 0; i++) deque.offerFirst(deque.pollLast());
        }
        
        sb.append(deque.pollFirst()[0]);
        System.out.println(sb);
        br.close();
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Queue<Integer> queue = new LinkedList<>();
        int N = Integer.parseInt(br.readLine());
        for(int i=1; i<=N; i++) queue.add(i);
        while(true) {
            System.out.print(queue.remove() + " ");
            if(queue.isEmpty()) break;
            queue.add(queue.remove());
        }
        br.close();
    }
}
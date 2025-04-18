import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), cnt = 0;
        Set<String> hashSet = new HashSet<>();
        while (N-- > 0) hashSet.add(br.readLine());
        while (M-- > 0) {
            String str = br.readLine();
            if (hashSet.contains(str)) cnt++;
        }
        System.out.println(cnt);
        br.close();
    }
}
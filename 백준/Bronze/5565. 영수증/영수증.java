import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tot = Integer.parseInt(br.readLine());
        for(int i=0; i<9; i++)
            tot -= Integer.parseInt(br.readLine());
        System.out.println(tot);
        br.close();
    }
}
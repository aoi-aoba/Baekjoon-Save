import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        if(N % 2 == 0) System.out.println("SciComLove");
        else System.out.println("evoLmoCicS");
        br.close();
    }
}